#include <MKL25Z4.h>

#include <Lib/Display/Display.h>


int SCLK_PIN = 0;
int RCLK_PIN = 1;
int DIO_PIN = 2;

Display disp(SCLK_PIN, RCLK_PIN, DIO_PIN);


int main(){


  while(true){

    disp.showNumber(15,1);
    disp.showNumber(30,2);
  }


    return 0;
}
