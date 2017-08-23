#ifndef SOURCES_FREQUENCYDIVIDER_H_
#define SOURCES_FREQUENCYDIVIDER_H_

#include <stdint.h>

/**
 * Class FrequencyDivider - Represent a frequency divider device
 * @author Salmiakki Team
 * @version 1.0, 2017-08-23
 */
class FrequencyDivider{

  public:

    /**
     * Constructor class - Enter with the number of times the clock will be divided
     * @param divider Clock divider
     */
    FrequencyDivider(uint32_t divider);

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
