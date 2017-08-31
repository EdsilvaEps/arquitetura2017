#ifndef FREQUENCYDIVIDER_H_
#define FREQUENCYDIVIDER_H_

#include <stdint.h>

/**
 * Class FrequencyDivider - Represent a frequency divider device
 * @author Salmiakki Team
 * @version 2.0, 2017-08-30
 */

 class FrequencyDivider{
	public:
	 	/**
	 	 * Constructor class
	 	 * @param input - Clock with original frequency
	 	 * @param reset - Reset the internal counter
	 	 * @param divider - Number of times the clock will be divided
	 	 */
	 	FrequencyDivider(uint32_t divider);

	 	/**
	 	 * Reset counter
	 	 */
	 	void reset();
	 	/**
	 	 * Calculates the clock division
	 	 */
	 	void clockDiv();

	 	/**
	 	 * Take the current state of the flag
	 	 * @return State of flag (TRUE or FALSE)
	 	 */
	 	uint8_t getFlag();

	 	/**
	 	 * Informs if the flag has been detected
	 	 * @param flag
	 	 */
	 	void setFlag();

	private:

		/** Number of times the clock is being divided */
		uint32_t _divider;

		/** Aux counter */
		uint32_t _counter = 1;

		/** Flag that informs if the counter is equal to the divisor */
		uint8_t _flag = false;

 };

#endif
