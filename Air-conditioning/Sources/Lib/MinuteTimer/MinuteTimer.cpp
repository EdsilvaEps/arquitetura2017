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

	if(_sleepTime <= 0)
		_sleepTime = 0;
}

void MinuteTimer::reset(){
	_sleepTime = 0;
}

void MinuteTimer::receiveClock(bool pulse){

	if(pulse){
		decrement();
	}
}

uint8_t MinuteTimer::readIncrementButton(){
	return _incrementButton.read();
}

uint8_t MinuteTimer::readDecrementButton(){
	return _decrementButton.read();
}

uint8_t MinuteTimer::readResetButton(){
	return _resetButton.read();
}
