#include <MKL25Z4.h>
#include <Lib/Digital/Digital.h>


int input_Pin = 0;
int output_Pin = 1;


Digital inputPin;
Digital outPutPin;

Digital led1;
Digital led2;
Digital led3;


int main(){

  inputPin.pinMode(input_Pin, INPUT);
  outPutPin.pinMode(output_Pin, OUTPUT);

  led1.redLed();
  led2.greenLed();
  led3.blueLed();


  while(true){

    if(inputPin.read()){
      led1.onRedLed();
      led2.offBlueLed();
    }

    led2.onBlueLed();
    led1.offRedLed();
	}

    return 0;
}
