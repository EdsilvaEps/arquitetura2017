#include <MKL25Z4.h>
#include <Lib/Display/dsf_SerialDisplays.h>
#include <Lib/GPIO/mkl_GPIOPort.h>
#include <Lib/Multiplexer/Multiplexer.h>
#include <Lib/TPM/TPM_Delay/mkl_TPMDelay.h>
#include <Lib/Onoff/Onoff.h>
#include <Lib/MinuteTimer/MinuteTimer.h>
#include <Lib/PIT/PITPeriodicInterrupt/mkl_PITPeriodicInterrupt.h>
#include <Lib/FrequencyDivider/FrequencyDivider.h>

dsf_SerialDisplays display(gpio_PTA1, gpio_PTA2, gpio_PTD4);
Onoff onoffButton(gpio_PTA5, gpio_PTB19);
MinuteTimer timer(gpio_PTC8, gpio_PTC9);
Multiplexer multiplex;
mkl_TPMDelay delay(tpm_TPM0);
mkl_GPIOPort ledBlue(gpio_PTD1);
mkl_PITInterruptInterrupt pit(PIT_Ch0);
FrequencyDivider fd(100);

uint32_t debounceTime = 24576;
uint32_t pitTime = 0x30D3F;   // 10485760 hz = 1 s

enum STATE {
  STATE0, STATE1, STATE2
};

enum {
  LOW, HIGH
};

extern "C" {
  void PIT_IRQHandler(void) {
    pit.clearInterruptFlag();
    if(fd.clockDiv()) {
      timer.decrement();
    }
  }
}

int main(void) {

  delay.setFrequency(tpm_div128);
  delay.startDelay(10);

  ledBlue.setPortMode(gpio_output);
  ledBlue.writeBit(HIGH);

  display.clearDisplays();

  pit.enablePeripheralModule();
  pit.setPeriod(pitTime);
  pit.resetCounter();
  pit.enableTimer();
  pit.enableInterruptRequests();
  STATE s = STATE0;

  while (true) {

    display.updateDisplays();
    uint8_t resultMultiplex = multiplex.select(0, timer.getSleepTime(), 0x12);

    switch (s) {
      case STATE0:
        onoffButton.ledStandby(LOW);
        ledBlue.writeBit(HIGH);
        display.clearDisplays();

        if(!onoffButton.read() && delay.timeoutDelay()) {
          s = STATE1;
          delay.startDelay(debounceTime);
        }
        break;
      case STATE1:
        onoffButton.ledStandby(HIGH);
        ledBlue.writeBit(HIGH);
        display.writeWord(0x0, 2);

        if(!timer.readIncrementButton() && delay.timeoutDelay()) {
          delay.startDelay(debounceTime);
          timer.increment();
          s = STATE2;
        }

        if(!timer.readResetButton() && delay.timeoutDelay()) {
          delay.startDelay(debounceTime);
          timer.reset();
        }

        if(!onoffButton.read() && delay.timeoutDelay()) {
          s = STATE0;
          delay.startDelay(debounceTime);
        }
        break;
      case STATE2:
        ledBlue.writeBit(LOW);
        display.writeWord(resultMultiplex, 2);

        if(!timer.getSleepTime()) {
          s = STATE0;
        }
        if(!timer.readIncrementButton() && delay.timeoutDelay()) {
          delay.startDelay(debounceTime);
          timer.increment();
          if(!timer.getSleepTime())
            s = STATE1;
        }

        if(!timer.readResetButton() && delay.timeoutDelay()) {
          delay.startDelay(debounceTime);
          timer.reset();
          s = STATE1;
        }

        if(!onoffButton.read() && delay.timeoutDelay()) {
          s = STATE0;
          delay.startDelay(debounceTime);
        }
        break;
    }
  }

  return 0;
}

