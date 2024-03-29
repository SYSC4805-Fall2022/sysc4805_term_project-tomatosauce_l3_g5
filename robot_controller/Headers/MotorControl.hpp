#ifndef MOTOR_CONTROL_HPP
#define MOTOR_CONTROL_HPP

#include <Arduino.h>
//pin 2 is for PIO_PDR_P25
//pin 35 is for PMC_PCER1_PID36
int left_side_dir_pin = 7;
int right_side_dir_pin = 6;
/**
Calculate the counter value for register at a specified frequency
**/
int calculateCounterLeft(int frequency){
	return (int)1000000/frequency;
}


int calculateCounterRight(int frequency){
  return (int)42000000/frequency;
}
/**
Calculate the counter for a duty cycle 
**/
int calculateDutyCycle(int counter, double dutyCycle){
  return (int)((double)dutyCycle*counter);
}
/**
Enable registers, sets appropriate bits, and configure pins
**/
void setupMotorControl(){
//direction pins
pinMode(left_side_dir_pin, OUTPUT); 
pinMode(right_side_dir_pin, OUTPUT);

//PWM for Left Side
PMC->PMC_PCER1 |= PMC_PCER1_PID36; // Enable Clock to PWM module
PIOC->PIO_ABSR |= PIO_PC3B_PWMH0; // Assign C3 to PWM module (Periph_B)
PIOC->PIO_PDR |= PIO_PDR_P3; // Release C3 from the PIO module
REG_PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(84);//Set PWM clock 1 MHz (Mck/2)
PWM->PWM_CH_NUM[0].PWM_CMR |= PWM_CMR_CPRE_CLKA // Set the clock source as CLKA
| PWM_CMR_CPOL; //Set output polarity be high.

PWM->PWM_ENA = PWM_ENA_CHID0; // Enable the PWM channel
//PWM for Right Side
PMC->PMC_PCER0 |= PMC_PCER0_PID27;//TC0 power ON - Timer Counter 0 channel 0
PIOB->PIO_PDR |= PIO_PDR_P25; // The pin is no more driven by GPIO
PIOB->PIO_ABSR |= PIO_PB25B_TIOA0;// B Assign B25 to alternative periph_B (TIOA0):

PMC->PMC_PCER0 |= PMC_PCER0_PID27;//TC0 power ON - Timer Counter 0 channel 0
PIOB->PIO_PDR |= PIO_PDR_P25; // The pin is no more driven by GPIO
PIOB->PIO_ABSR |= PIO_PB25B_TIOA0;// B Assign B25 to alternative periph_B (TIOA0):

TC0->TC_CHANNEL[0].TC_CMR = TC_CMR_TCCLKS_TIMER_CLOCK1 //MCK/2 = 42 MHz,
| TC_CMR_WAVE //Waveform mode
| TC_CMR_WAVSEL_UP_RC //Count UP mode till RC
| TC_CMR_ACPA_CLEAR //Clear TIOA0 on RA compare match
| TC_CMR_ACPC_SET // Set TIOA0 on RC compare match


| TC_CCR_CLKEN;//and enable  
TC0->TC_CHANNEL[0].TC_CCR = TC_CCR_SWTRG | TC_CCR_CLKEN;//and enable   //Software trigger TC0 channel 0 counter
}
/**
Turn left.
@param frequency the frequency of the pwm signal for the motors
@param dutyCycle the duty cycle range from 0 to 1 of the motors
**/
int left(int frequency, double dutyCycle){
  int counterLeft = calculateCounterLeft(frequency)-1;
  int counterRight = calculateCounterRight(frequency)-1;
  PWM->PWM_CH_NUM[0].PWM_CPRD = counterLeft;
  PWM->PWM_CH_NUM[0].PWM_CDTY = calculateDutyCycle(counterLeft, dutyCycle); //Set the duty cycle of left motors

  TC0->TC_CHANNEL[0].TC_RC =  counterRight;
  TC0->TC_CHANNEL[0].TC_RA = calculateDutyCycle(counterRight, dutyCycle); //Set the duty cycle of right motors
  digitalWrite(left_side_dir_pin, HIGH);
  digitalWrite(right_side_dir_pin, LOW);
  // return counterRight;
}
/**
Turn Right.
@param frequency the frequency of the pwm signal for the motors
@param dutyCycle the duty cycle range from 0 to 1 of the motors
**/
void right(int frequency, double dutyCycle){
  int counterLeft = calculateCounterLeft(frequency)-1;
  int counterRight = calculateCounterRight(frequency)-1;
  PWM->PWM_CH_NUM[0].PWM_CPRD = counterLeft;
  PWM->PWM_CH_NUM[0].PWM_CDTY = calculateDutyCycle(counterLeft, dutyCycle); //Set the duty cycle of left motors

  TC0->TC_CHANNEL[0].TC_RC =  counterRight;
  TC0->TC_CHANNEL[0].TC_RA = calculateDutyCycle(counterRight, dutyCycle); //Set the duty cycle of right motors
  digitalWrite(left_side_dir_pin, LOW);
  digitalWrite(right_side_dir_pin, HIGH);
}
/**
Go forward.
@param frequency the frequency of the pwm signal for the motors
@param dutyCycle the duty cycle range from 0 to 1 of the motors
**/
void forward(int frequency, double dutyCycle){
  int counterLeft = calculateCounterLeft(frequency)-1;
  int counterRight = calculateCounterRight(frequency)-1;
  PWM->PWM_CH_NUM[0].PWM_CPRD = counterLeft;
  PWM->PWM_CH_NUM[0].PWM_CDTY = calculateDutyCycle(counterLeft, dutyCycle); //Set the duty cycle of left motors

  TC0->TC_CHANNEL[0].TC_RC =  counterRight;
  TC0->TC_CHANNEL[0].TC_RA = calculateDutyCycle(counterRight, dutyCycle); //Set the duty cycle of right motors
  digitalWrite(left_side_dir_pin, LOW);
  digitalWrite(right_side_dir_pin, LOW);
}
/**
Go backwards.
@param frequency the frequency of the pwm signal for the motors
@param dutyCycle the duty cycle range from 0 to 1 of the motors
**/
void backwards(int frequency, double dutyCycle){

  int counterLeft = calculateCounterLeft(frequency)-1;
  int counterRight = calculateCounterRight(frequency)-1;
  PWM->PWM_CH_NUM[0].PWM_CPRD = counterLeft;
  PWM->PWM_CH_NUM[0].PWM_CDTY = calculateDutyCycle(counterLeft, dutyCycle);//Set the duty cycle of left motors

  TC0->TC_CHANNEL[0].TC_RC =  counterRight;
  TC0->TC_CHANNEL[0].TC_RA = calculateDutyCycle(counterRight, dutyCycle); //Set the duty cycle of right motors
  digitalWrite(left_side_dir_pin, HIGH);
  digitalWrite(right_side_dir_pin, HIGH);
}
/**
Stop the robot.
**/
void stop(){
  PWM->PWM_CH_NUM[0].PWM_CDTY = 0; //Set duty cycle to 0
  TC0->TC_CHANNEL[0].TC_RA =1; //Set the duty cycle to 0

}
#endif