#include <MKL25Z4.h>

#include <Lib/MinuteTimer/MinuteTimer.h>

int increment_pin = 0;
int decrement_pin = 1;
int reset_pin = 2;

MinuteTimer mt(increment_pin, decrement_pin, reset_pin);

int main(){

  while(true){

    if(!mt.readIncrementButton()){
      mt.increment();
    }

    if(!mt.readDecrementButton()){
      mt.decrement();
    }

    if(!mt.readResetButton()){
      mt.reset();
    }
  }

  return 0;
}
