#include "Display.h"

Display::Display(uint8_t SCLK, uint8_t RCLK, uint8_t DIO){

  _SCLK.pinMode(SCLK, OUTPUT);
  _RCLK.pinMode(RCLK, OUTPUT);
  _DIO.pinMode(DIO, OUTPUT);

  configSegments();
}

void Display::configSegments(){

  _number[0] = 0xC0;
  _number[1] = 0xF9;
  _number[2] = 0xA4;
  _number[3] = 0xB0;
  _number[4] = 0x99;
  _number[5] = 0x92;
  _number[6] = 0x82;
  _number[7] = 0xF8;
  _number[8] = 0x80;
  _number[9] = 0x90;

}

void Display::send(uint8_t byte){

  for(int bit = 8; bit >= 1; bit--){

    if(byte & 0x80)
      _DIO.write(HIGH);
    else
      _DIO.write(LOW);

    byte <<= 1;

    _SCLK.write(LOW);
    _SCLK.write(HIGH);
  }
}

void Display::send(uint8_t byte, uint8_t port){

  send(byte);
  send(port);

  _RCLK.write(LOW);
  _RCLK.write(HIGH);
}

void Display::showNumber(uint8_t number, uint8_t port){

  uint8_t unit = (uint8_t) (number % 10);
  uint8_t ten = (uint8_t) (number / 10);

  uint8_t multiplier = 0;

  if(port == 1)
    multiplier = 1;
  else if(port == 2)
    multiplier = 2;
  else
    port = 0;

  if(port > 0)
    send(_number[unit], multiplier * (1 << (port - 1)));

  if((number > 9) && (port > 0))
    send(_number[ten], multiplier * (1 << (port - 1)));
}
