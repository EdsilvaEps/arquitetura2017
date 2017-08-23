#include "MinuteTimer.h"

MinuteTimer::MinuteTimer(uint8_t incrementButton, uint8_t decrementButton, uint8_t resetButton){

	_incrementButton.pinMode(incrementButton, INPUT);
	_decrementButton.pinMode(decrementButton, INPUT);
	_resetButton.pinMode(resetButton, INPUT);

}

void MinuteTimer::increment(){

	if(_sleepTime >= 90)
		_sleepTime = 0;

	_sleepTime += 10;

}

uint8_t MinuteTimer::getSleepTime(){
	return _sleepTime;
}

void MinuteTimer::decrement(){

	_sleepTime -= 1;
	_decrementFlag = true;

	if(_sleepTime <= 0){
	  _sleepTime = 0;
	  _decrementFlag = false;
	}
}

uint8_t MinuteTimer::isDecrement(){
  return _decrementFlag;
}

void MinuteTimer::reset(){

	_sleepTime = 0;
}

uint8_t MinuteTimer::receiveClock(bool pulse){

	if(pulse){
		decrement();
		return true;
	}
	return false;
}

uint8_t MinuteTimer::readIncrementButton(){
	return _incrementButton.read();
}

uint8_t MinuteTimer::readDecrementButton(){
  _decrementFlag = true;
	return _decrementButton.read();
}

uint8_t MinuteTimer::readResetButton(){
	return _resetButton.read();
}
