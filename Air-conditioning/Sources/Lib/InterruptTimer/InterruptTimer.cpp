#include "InterruptTimer.h"

InterruptTimer::InterruptTimer(uint32_t frequency, uint8_t channel){

  frequency = (uint32_t) (10485760/frequency);

    if((frequency < 0xFFFFFFFF)&&(channel <= 1)){

      _channel = channel;
      SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_PIT_MASK;
      PIT_BASE_PTR->MCR &= ~(PIT_MCR_MDIS_MASK | PIT_MCR_FRZ_MASK);
      PIT_LDVAL_REG(PIT,channel) = frequency;
      PIT_TCTRL_REG(PIT,channel) |= PIT_TCTRL_TIE_MASK;
      NVIC_EnableIRQ(PIT_IRQn);
    }
}

void InterruptTimer::start(){
  PIT_TCTRL_REG(PIT, _channel) |= PIT_TCTRL_TEN_MASK;
}

void InterruptTimer::stop(){
  PIT_TCTRL_REG(PIT, _channel) &= ~PIT_TCTRL_TEN_MASK;
}

uint8_t InterruptTimer::isInterrupt(){
  PIT_TFLG_REG(PIT, _channel);
}

void InterruptTimer::clearFlagInterrupt(){
  PIT_TFLG_REG(PIT, _channel) = PIT_TFLG_TIF_MASK;
}
