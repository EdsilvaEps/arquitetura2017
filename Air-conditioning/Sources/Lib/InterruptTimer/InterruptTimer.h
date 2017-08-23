#ifndef SOURCES_LIB_INTERRUPTTIMER_INTERRUPTTIMER_H_
#define SOURCES_LIB_INTERRUPTTIMER_INTERRUPTTIMER_H_

#include <MKL25Z4.h>
#include <Lib/Enums.h>

/**
 * Class InterruptTimer - Represent the Periodic Interrupt Timer (PIT) of MKL25Z board
 * @author Salmiakku Team
 * @version 1.0, 2017-08-23
 */
class InterruptTimer{

  public:

    /**
     * Constructor class - Set the frequency interrupt and channel
     * @param frequency - Frequency of interruption
     * @param channel - Channel of interruption (0 or 1)
     */
    InterruptTimer(uint32_t frequency, uint8_t channel);

    /**
     * Initiate PIT
     */
    void start();

    /**
     * Pause PIT
     */
    void stop();

    /**
     * Check if channel have an interrupt request
     * @return TRUE or FALSE
     */
    uint8_t isInterrupt();

    /**
     * Clears the interrupt flag, when occur an interrupt
     */
    void clearFlagInterrupt();

  private:

    /** Channel of PIT */
    uint8_t _channel;
};

#endif
