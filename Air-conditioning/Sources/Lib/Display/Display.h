#ifndef Display_h
#define Display_h

#include <Lib/Digital/Digital.h>

/**
 * Class Display - Represent the module 74HC595 with 4 digits
 * @author Salmiakki Team
 * @version 1.0, 2017-08-23
 */
class Display{

  private:

    /** Digital port associated with SCLK pin of the module */
    Digital _SCLK;

    /** Digital port associated with RCLK pin of the module */
    Digital _RCLK;

    /** Digital port associated with DIO pin of the module */
    Digital _DIO;

    /** Array that relates an integer number with the respective segments */
    uint8_t _number[10];

  public:

    /**
     * Constructor class -
     * @param SCLK The number of the pin connected to the SCLK pin of the module
     * @param RCLK The number of the pin connected to the RCLK pin of the module
     * @param DIO  The number of the pin connected to the DIO pin of the module
     */
    Display(uint8_t SCLK, uint8_t RCLK, uint8_t DIO);

    /**
     * Send a number (less then 99) to module and set the LED port
     * @param number Natural number
     * @param port Led active
     */
    void showNumber(uint8_t number, uint8_t port);


  private:

    /**
     * Defines a vector that associates an integer with the segments of the module
     */
    void configSegments();

    /**
     * Set the segments that will be turned on and off
     * @param byte Bit x Segment relation
     */
    void send(uint8_t byte);

    /**
     * Set the segments and select which led will be shown
     * @param byte Bit x Segments relation
     * @param port Define which led will appear the byte
     */
    void send(uint8_t byte, uint8_t port);

};

#endif
