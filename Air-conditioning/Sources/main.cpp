#include <MKL25Z4.h>
#include <Lib/InterruptTimer/InterruptTimer.h>
#include <Lib/FrequencyDivider/FrequencyDivider.h>
#include <Lib/MinuteTimer/MinuteTimer.h>
#include <Lib/Digital/Digital.h>
#include <Lib/Multiplexer/Multiplexer.h>
#include <Lib/Display/Display.h>

int ONOFF_PIN = 0;

int INCREMENT_PIN = 2;
int DECREMENT_PIN = 3;
int RESET_PIN = 4;

int SCLK_PIN = 5;
int RCLK_PIN = 6;
int DIO_PIN = 7;

enum class STATE{
  STATE1, STATE2, STATE3
};

uint8_t resultMultiplex;

Digital onoff;
Digital led1;
Digital led2;

InterruptTimer interrupt1(100, 0);
FrequencyDivider freqDivider(100);
MinuteTimer controller(INCREMENT_PIN, DECREMENT_PIN, RESET_PIN);
Multiplexer multiplex;
Display disp(SCLK_PIN, RCLK_PIN, DIO_PIN);

extern "C" {
  void PIT_IRQHandler(void){

    if(interrupt1.isInterrupt()){
      interrupt1.clearFlagInterrupt();
      freqDivider.clockDiv();
    }
  }
}

int main(){

  STATE s = STATE::STATE1;

  onoff.pinMode(ONOFF_PIN, INPUT);
  led1.greenLed();
  led2.blueLed();
  interrupt1.start();

  while(true){

    resultMultiplex = multiplex.select(controller.isDecrement(), controller.getSleepTime(), 77);

    if(controller.receiveClock(freqDivider.getFlag())){
      freqDivider.setFlag();
    }

    switch(s){
      case STATE::STATE1:

        led1.onGreenLed();
        disp.showNumber(0, 0);
        led2.offBlueLed();

        if(!onoff.read()){
          s = STATE::STATE2;
        }

        break;
      case STATE::STATE2:

        led1.offGreenLed();
        led2.offBlueLed();
        disp.showNumber(resultMultiplex, 1);
        if(!controller.readIncrementButton()){
          controller.increment();
        }
        if(!controller.readResetButton()){
          controller.reset();
        }
        if(!controller.readDecrementButton()){
          controller.decrement();
          s = STATE::STATE3;
        }

        if(!onoff.read()){
          s = STATE::STATE1;
        }

        break;
      case STATE::STATE3:

        disp.showNumber(resultMultiplex, 2);
        led2.onBlueLed();

        if(!controller.readIncrementButton()){
          controller.increment();
        }

        if(!controller.readResetButton()){
          controller.reset();
          s = STATE::STATE2;
        }
        if(!controller.isDecrement()){
          s = STATE::STATE2;
        }

        if(!onoff.read()){
          s = STATE::STATE1;
        }

        break;
    }
  }

  return 0;
}
