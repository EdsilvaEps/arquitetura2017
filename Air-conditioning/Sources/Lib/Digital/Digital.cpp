#include "Digital.h"

void Digital::pinMode(uint8_t pin, uint8_t mode){

  _pin = pin;

  switch(pin){
    case 0:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTA_MASK;
      PORTA->PCR[1] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTA->PDDR |= (1U << 1U);
      }
      else if(mode == INPUT){
        PORTA->PCR[1] |= PORT_PCR_PE(1);
        PORTA->PCR[1] |= PORT_PCR_PS(1);
        PTA->PDDR &= ~(1U << 1U);
      }
      break;
    case 1:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTA_MASK;
      PORTA->PCR[2] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTA->PDDR |= (1U << 2U);
      }
      else if(mode == INPUT){
        PORTA->PCR[2] |= PORT_PCR_PE(1);
        PORTA->PCR[2] |= PORT_PCR_PS(1);
        PTA->PDDR &= ~(1U << 2U);
      }
      break;
    case 2:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTD_MASK;
      PORTD->PCR[4] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTD->PDDR |= (1U << 4U);
      }
      else if(mode == INPUT){
        PORTD->PCR[11] |= PORT_PCR_PE(1);
        PORTD->PCR[11] |= PORT_PCR_PS(1);
        PTD->PDDR &= ~(1U << 4U);
      }
      break;
    case 3:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTA_MASK;
      PORTA->PCR[12] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTA->PDDR |= (1U << 12U);
      }
      else if(mode == INPUT){
        PORTA->PCR[12] |= PORT_PCR_PE(1);
        PORTA->PCR[12] |= PORT_PCR_PS(1);
        PTA->PDDR &= ~(1U << 12U);
      }
      break;
    case 4:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTA_MASK;
      PORTA->PCR[4] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTA->PDDR |= (1U << 4U);
      }
      else if(mode == INPUT){
        PORTA->PCR[4] |= PORT_PCR_PE(1);
        PORTA->PCR[4] |= PORT_PCR_PS(1);
        PTA->PDDR &= ~(1U << 4U);
      }
      break;
    case 5:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTA_MASK;
      PORTA->PCR[5] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTA->PDDR |= (1U << 5U);
      }
      else if(mode == INPUT){
        PTA->PDDR &= ~(1U << 5U);
        PORTA->PCR[5] |= PORT_PCR_PE(1);
        PORTA->PCR[5] |= PORT_PCR_PS(1);
      }
      break;
    case 6:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTC_MASK;
      PORTC->PCR[8] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTC->PDDR |= (1U << 8U);
      }
      else if(mode == INPUT){
        PORTC->PCR[8] |= PORT_PCR_PE(1);
        PORTC->PCR[8] |= PORT_PCR_PS(1);
        PTC->PDDR &= ~(1U << 8U);
      }
      break;
    case 7:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTC_MASK;
      PORTC->PCR[9] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTC->PDDR |= (1U << 9U);
      }
      else if(mode == INPUT){
        PORTC->PCR[9] |= PORT_PCR_PE(1);
        PORTC->PCR[9] |= PORT_PCR_PS(1);
        PTC->PDDR &= ~(1U << 9U);
      }
      break;
    case 8:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTA_MASK;
      PORTA->PCR[13] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTA->PDDR |= (1U << 13U);
      }
      else if(mode == INPUT){
        PORTA->PCR[13] |= PORT_PCR_PE(1);
        PORTA->PCR[13] |= PORT_PCR_PS(1);
        PTA->PDDR &= ~(1U << 13U);
      }
      break;
    case 9:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTD_MASK;
      PORTD->PCR[5] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTD->PDDR |= (1U << 5U);
      }
      else if(mode == INPUT){
        PORTD->PCR[5] |= PORT_PCR_PE(1);
        PORTD->PCR[5] |= PORT_PCR_PS(1);
        PTD->PDDR &= ~(1U << 5U);
      }
      break;
    case 10:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTD_MASK;
      PORTD->PCR[0] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTD->PDDR |= (1U << 0U);
      }
      else if(mode == INPUT){
        PORTD->PCR[0] |= PORT_PCR_PE(1);
        PORTD->PCR[0] |= PORT_PCR_PS(1);
        PTD->PDDR &= ~(1U << 0U);
      }
      break;
    case 11:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTD_MASK;
      PORTD->PCR[2] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTD->PDDR |= (1U << 2U);
      }
      else if(mode == INPUT){
        PORTD->PCR[2] |= PORT_PCR_PE(1);
        PORTD->PCR[2] |= PORT_PCR_PS(1);
        PTD->PDDR &= ~(1U << 2U);
      }
      break;
    case 12:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTD_MASK;
      PORTD->PCR[3] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTD->PDDR |= (1U << 3U);
      }
      else if(mode == INPUT){
        PORTD->PCR[3] |= PORT_PCR_PE(1);
        PORTD->PCR[3] |= PORT_PCR_PS(1);
        PTD->PDDR &= ~(1U << 3U);
      }
      break;
    case 13:
      SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTD_MASK;
      PORTD->PCR[1] = PORT_PCR_MUX(1U);

      if(mode == OUTPUT){
        PTD->PDDR |= (1U << 1U);
      }
      else if(mode == INPUT){
        PORTD->PCR[1] |= PORT_PCR_PE(1);
        PORTD->PCR[1] |= PORT_PCR_PS(1);
        PTD->PDDR &= ~(1U << 1U);
      }
      break;
  }
}

void Digital::write(uint8_t value){

  switch(_pin){
    case 0:
      if(value == HIGH){
        PTA->PDOR |= (1U << 1U);
      }
      else if(value == LOW){
        PTA->PDOR &= ~(1U << 1U);
      }
      break;
    case 1:
      if(value == HIGH){
        PTA->PDOR |= (1U << 2U);
      }
      else if(value == LOW){
        PTA->PDOR &= ~(1U << 2U);
      }
      break;
    case 2:
      if(value == HIGH){
        PTD->PDOR |= (1U << 4U);
      }
      else if(value == LOW){
        PTD->PDOR &= ~(1U << 4U);
      }
      break;
    case 3:
      if(value == HIGH){
        PTA->PDOR |= (1U << 12U);
      }
      else if(value == LOW){
        PTA->PDOR &= ~(1U << 12U);
      }
      break;
    case 4:
      if(value == HIGH){
        PTA->PDOR |= (1U << 4U);
      }
      else if(value == LOW){
        PTA->PDOR &= ~(1U << 4U);
      }
      break;
    case 5:
      if(value == HIGH){
        PTA->PDOR |= (1U << 5U);
      }
      else if(value == LOW){
        PTA->PDOR &= ~(1U << 5U);
      }
      break;
    case 6:
      if(value == HIGH){
        PTC->PDOR |= (1U << 8U);
      }
      else if(value == LOW){
        PTC->PDOR &= ~(1U << 8U);
      }
      break;
    case 7:
      if(value == HIGH){
        PTC->PDOR |= (1U << 9U);
      }
      else if(value == LOW){
        PTC->PDOR &= ~(1U << 9U);
      }
      break;
    case 8:
      if(value == HIGH){
        PTA->PDOR |= (1U << 13U);
      }
      else if(value == LOW){
        PTA->PDOR &= ~(1U << 13U);
      }
      break;
    case 9:
      if(value == HIGH){
        PTD->PDOR |= (1U << 5U);
      }
      else if(value == LOW){
        PTD->PDOR &= ~(1U << 5U);
      }
      break;
    case 10:
      if(value == HIGH){
        PTD->PDOR |= (1U << 0U);
      }
      else if(value == LOW){
        PTD->PDOR &= ~(1U << 0U);
      }
      break;
    case 11:
      if(value == HIGH){
        PTD->PDOR |= (1U << 2U);
      }
      else if(value == LOW){
        PTD->PDOR &= ~(1U << 2U);
      }
      break;
    case 12:
      if(value == HIGH){
        PTD->PDOR |= (1U << 3U);
      }
      else if(value == LOW){
        PTD->PDOR &= ~(1U << 3U);
      }
      break;
    case 13:
      if(value == HIGH){
        PTD->PDOR |= (1U << 1U);
      }
      else if(value == LOW){
        PTD->PDOR &= ~(1U << 1U);
      }
      break;
  }
}

uint8_t Digital::read(){

  switch(_pin){
    case 0:
      return (PTA->PDIR & (1U << 1U)) ? 1 : 0;
    case 1:
      return (PTA->PDIR & (1U << 2U)) ? 1 : 0;
    case 2:
      return (PTD->PDIR & (1U << 4U)) ? 1 : 0;
    case 3:
      return (PTA->PDIR & (1U << 12U)) ? 1 : 0;
    case 4:
      return (PTA->PDIR & (1U << 4U)) ? 1 : 0;
    case 5:
      return (PTA->PDIR & (1U << 5U)) ? 1 : 0;
    case 6:
      return (PTC->PDIR & (1U << 8U)) ? 1 : 0;
    case 7:
      return (PTC->PDIR & (1U << 9U)) ? 1 : 0;
    case 8:
      return (PTC->PDIR & (1U << 13U)) ? 1 : 0;
    case 9:
      return (PTD->PDIR & (1U << 5U)) ? 1 : 0;
    case 10:
      return (PTD->PDIR & (1U << 0U)) ? 1 : 0;
    case 11:
      return (PTD->PDIR & (1U << 2U)) ? 1 : 0;
    case 12:
      return (PTD->PDIR & (1U << 3U)) ? 1 : 0;
    case 13:
      return (PTD->PDIR & (1U << 1U)) ? 1 : 0;
  }
}

void Digital::delay(){

  volatile unsigned int i;

  for(i = 0; i < (480076); i++){

    __asm__("nop");

  }
}

void Digital::blueLed(){

  SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTD_MASK;
  PORTD->PCR[1] = PORT_PCR_MUX(1U);
  PTD->PDDR |= (1U << 1U);
  PTD->PDOR |= (1U << 1U);
}

void Digital::onBlueLed(){
  PTD->PDOR &= ~(1U << 1U);
}

void Digital::offBlueLed(){

  PTD->PDOR |= (1U << 1U);
}

void Digital::redLed(){

  SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTB_MASK;
  PORTB->PCR[18] = PORT_PCR_MUX(1U);
  PTB->PDDR |= (1U << 18U);
  PTB->PDOR |= (1U << 18U);
}

void Digital::onRedLed(){
  PTB->PDOR &= ~(1U << 18U);
}

void Digital::offRedLed(){
  PTB->PDOR |= (1U << 18U);
}

void Digital::greenLed(){
  SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTB_MASK;
  PORTB->PCR[19] = PORT_PCR_MUX(1U);
  PTB->PDDR |= (1U << 19U);
  PTB->PDOR |= (1U << 19U);
}

void Digital::onGreenLed(){
  PTB->PDOR &= ~(1U << 19U);
}

void Digital::offGreenLed(){
  PTB->PDOR |= (1U << 19U);
}
