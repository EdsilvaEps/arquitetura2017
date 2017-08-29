#include <MKL25Z4.h>
#include <Lib/Display/dsf_SerialDisplays.h>
#include <Lib/GPIO/mkl_GPIOPort.h>
#include <Lib/Multiplexer/Multiplexer.h>
#include <Lib/TPM/TPM_Delay/mkl_TPMDelay.h>
#include <Lib/Onoff/Onoff.h>

dsf_SerialDisplays display(gpio_PTA1, gpio_PTA2, gpio_PTA4);

Onoff onoffButton(gpio_PTD4, gpio_PTB19);

Multiplexer multiplex;
mkl_TPMDelay delay(tpm_TPM0);

uint32_t debounceTime = 24576;

bool flagonOff = false;
bool flagTest = false;
uint8_t temperatura = 45;
uint8_t contador = 19;

int main(void){

  display.clearDisplays();

  delay.setFrequency(tpm_div128);
  delay.startDelay(10);

  while(true){

    uint8_t resultMultiplex = multiplex.select(1, contador, temperatura);

    display.writeWord(resultMultiplex, 1);

    if(!onoffButton.read() && delay.timeoutDelay()){
      delay.startDelay(debounceTime);

      flagonOff = !flagonOff;
      onoffButton.ledStandby(flagonOff);
    }

    if(flagonOff){

    }




  }

  return 0;
}

