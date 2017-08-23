#include <MKL25Z4.h>

#include <Lib/InterruptTimer/InterruptTimer.h>

InterruptTimer it(10, 0);
InterruptTimer it2(1, 1);

extern "C" {
  void PIT_IRQHandler(void){

    if(it.isInterrupt()){
      it.clearFlagInterrupt();
      //do something
    }

    if(it2.isInterrupt()){
      it2.clearFlagInterrupt();
      //do something
    }

  }
}

int main(){

  it.start();
  it2.start();

  while(true){}

  return 0;
}
