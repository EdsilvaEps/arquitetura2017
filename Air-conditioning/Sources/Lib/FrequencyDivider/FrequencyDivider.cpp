#include "FrequencyDivider.h"

FrequencyDivider::FrequencyDivider(uint32_t divider){
	_divider = divider;
}

void FrequencyDivider::reset(){
	_counter = 1;
	_flag = false;
}

void FrequencyDivider::clockDiv(){
	if(_counter == _divider){
		_counter = 1;
		_flag = true;
	}
	else{
		_counter++;
		_flag = false;
	}
}

uint8_t FrequencyDivider::getFlag(){
	return _flag;
}

void FrequencyDivider::setFlag(){
	_flag = false;
}
