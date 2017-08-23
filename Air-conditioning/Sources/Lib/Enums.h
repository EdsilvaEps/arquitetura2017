#ifndef SOURCES_ENUMS_H_
#define SOURCES_ENUMS_H_

/**
 * Operation mode of GPIO port
 */
enum {INPUT = 0, OUTPUT};

/**
 * State of GPIO port
 */
enum {LOW = 0, HIGH};


/**
 * The physical pins of the board MKL25Z (identical to the Arduino)
 */
enum {D0 = 0, D1, D2 ,D3 ,D4 ,D5 ,D6 ,D7 ,D8 ,D9 ,D10 ,D11 ,D12 ,D13};
#endif
