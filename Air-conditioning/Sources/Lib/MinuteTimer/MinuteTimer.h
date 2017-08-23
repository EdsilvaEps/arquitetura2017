#ifndef SOURCES_MINUTETIMER_H_
#define SOURCES_MINUTETIMER_H_

#include <stdint.h>
#include <Lib/Digital/Digital.h>

/**
 * Class MinuteTimer - Represent the controller time of air-conditioning
 * @author Salmiakki Team
 * @version 1.0, 2017-08-23
 */
class MinuteTimer{

  public:
    /**
     * Constructor class - Set the input pins to control the timer
     * @param incrementButton - Pin related to the increase of time
     * @param decrementButton - Pin related to the decrease of time
     * @param resetButton - Pin related to the reset time
     */
    MinuteTimer(uint8_t incrementButton, uint8_t decrementButton, uint8_t resetButton);

    /**
     * Increment time by 10
     */
    void increment();

    /**
     * Decrement time by 1
     */
    void decrement();

    /**
     * Timer equal zero
     */
    void reset();

    /**
     * Get current time
     * @return Current time
     */
    uint8_t getSleepTime();

    /**
     * Read state of increment button
     * @return State of the button (HIGH or LOW)
     */
    uint8_t readIncrementButton();

    /**
     * Read state of decrement button
     * @return State of the button (HIGH or LOW)
     */
    uint8_t readDecrementButton();

    /**
     * Read state of reset button
     * @return State of the button (HIGH or LOW)
     */
    uint8_t readResetButton();

    /**
     * Check input clock
     * @param pulse Output of frequency divider
     * @return True if pulse is true and FALSE other case
     */
    uint8_t receiveClock(bool pulse);

    /**
     * Check if decrement is ON
     * @return TRUE if decrement in progress and FALSE other case
     */
    uint8_t isDecrement();

  private:

    /** Digital port associated with increment pin */
    Digital _incrementButton;

    /** Digital port associated with decrement pin */
    Digital _decrementButton;

    /** Digital port associated with reset pin */
    Digital _resetButton;

    /** Current time of controller */
    uint8_t _sleepTime = 0;

    /** Current state of decrement*/
    uint8_t _decrementFlag = false;
};

#endif
