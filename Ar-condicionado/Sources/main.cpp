#include <MKL25Z4.h>
#include <Lib/PIT/PITPeriodicInterrupt/mkl_PITPeriodicInterrupt.h>
#include <Lib/Display/dsf_SerialDisplays.h>

dsf_SerialDisplays display(gpio_PTC7, gpio_PTC0, gpio_PTC3);
mkl_PITInterruptInterrupt pit(PIT_Ch0);

extern "C" {
  void PIT_IRQHandler(void){
    disp.updateDisplays();
  }
}

int main(void){

  pit.enablePeripheralModule();
  pit.setPeriod(0x4e20);
  pit.resetCounter();
  pit.enableTimer();
  pit.enableInterruptRequests();
  display.clearDisplays();
  display.writeWord(2222);

  while(true){

  }

  return 0;
}

