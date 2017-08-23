#include <MKL25Z4.h>

#include <Lib/Multiplexer/Multiplexer.h>

Multiplexer mult;

int main(){

  uint8_t SEL = 0;
  uint8_t A = 2;
  uint8_t B = 3;
  uint8_t result;

  while(true){

    result = mult.select(SEL, A, B);
  }


    return 0;
}
