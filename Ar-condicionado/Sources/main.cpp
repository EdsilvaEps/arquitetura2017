#include <MKL25Z4.h>
#include <Lib/Display/dsf_SerialDisplays.h>
#include <Lib/GPIO/mkl_GPIOPort.h>
#include <Lib/Multiplexer/Multiplexer.h>
#include <Lib/TPM/TPM_Delay/mkl_TPMDelay.h>

dsf_SerialDisplays display(gpio_PTB2, gpio_PTB1, gpio_PTA12);

mkl_GPIOPort onoffButton(gpio_PTB10);

Multiplexer multiplex;
mkl_TPMDelay delay(tpm_TPM0);

uint32_t debounceTime = 24576;

bool flagTest = false;
uint8_t temperatura = 45;
uint8_t contador = 19;

int main(void){

  display.clearDisplays();

  onoffButton.setPortMode(gpio_input);
  onoffButton.setPullResistor(gpio_pullUpResistor);

  delay.setFrequency(tpm_div128);
  delay.startDelay(10);

  while(true){

    uint8_t resultMultiplex = multiplex.select(flagTest,contador, temperatura);

    display.writeWord(resultMultiplex,flagTest+1);

    if(!onoffButton.readBit() && delay.timeoutDelay()){

      flagTest = !flagTest;
      delay.startDelay(debounceTime);
    }

  }

  return 0;
}

