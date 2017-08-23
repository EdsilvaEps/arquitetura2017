#ifndef SOURCES_DIGITAL_H_
#define SOURCES_DIGITAL_H_

#include <Lib/Enums.h>
#include <MKL25Z4.h>

/**
 * Class Digital - Represent the GPIO of the MKL25Z board
 * @author Salmiakki Team
 * @version 1.0, 2017-08-23
 */
class Digital{

  public:
    /**
     * Defines the pin as GPIO
     * @param pin The pin number to connect port
     * @param mode The mode of the port (INPUT or OUTPUT)
     */
    void pinMode(uint8_t pin, uint8_t mode);

    /**
     * Set the output value of the port
     * @param value HIGH or LOW value
     */
    void write(uint8_t value);

    /**
     * Read the input value of the port
     * @return HIGH or LOW value
     */
    uint8_t read();

    /**
     * Configure the BLUE LED of the MKL25Z board
     */
    void blueLed();

    /**
     * Configure the RED LED of the MKL25Z board
     */
    void redLed();

    /**
     * Configure the GREEN LED of the MKL25Z board
     */
    void greenLed();

    /**
     * Turn on BLUE LED
     */
    void onBlueLed();

    /**
     * Turn on RED LED
     */
    void onRedLed();

    /**
     * Turn on GREEN LED
     */
    void onGreenLed();

    /**
     * Turn off BLUE LED
     */
    void offBlueLed();

    /**
     * Turn off RED LED
     */
    void offRedLed();

    /**
     * Turn off GREEN LED
     */
    void offGreenLed();

    /**
     * @deprecated
     * Wait a inconclusive number of cycles
     */
    void delay();
  private:
    /** Physical pin of the board (identical to Arduino)*/
    uint8_t _pin;
};

#endif /* SOURCES_DIGITAL_H_ */

