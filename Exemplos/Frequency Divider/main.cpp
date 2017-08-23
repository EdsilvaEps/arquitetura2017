#include <MKL25Z4.h>

#include <Lib/FrequencyDivider/FrequencyDivider.h>

FrequencyDivider fd(2);

int main(){



  while(true){

    fd.clockDiv();

    if(fd.getFlag()){
      fd.setFlag();
      //
      //Frequencia da placa dividida por 2
      //
    }
  }


    return 0;
}
