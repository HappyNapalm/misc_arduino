#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include "utility/adafruit_MS_PWMServoDriver.h"

/*
 * 
 * Contract_IF_code 1.01
 * By Ian "CopperToad" Weber
 * Written for the use by Mike Rezl
 * Contact original author before making modifications
 * 
 */
 
 const uint8_t start_button = 13;
 const uint8_t limit_upper_left = 12;
 const uint8_t limit_upper_right = 11;
 const uint8_t limit_lower_left = 10;
 const uint8_t limit_lower_right = 9;
 const uint8_t motion_pin = 8;
 uint16_t safe_time = 0; //Ever even number should be 0.5 second

 bool red_button;
 bool upper_left;
 bool upper_right;
 bool lower_left;
 bool lower_right;
 bool still_here;

//establishes motor control board
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor_01 = AFMS.getMotor(1);
Adafruit_DCMotor *motor_02 = AFMS.getMotor(2);
//Adafruit_DCMotor *motor_03 = AFMS.getMotor(3);
//Adafruit_DCMotor *motor_04 = AFMS.getMotor(4);

const uint8_t motor_speed_run = 255; //establishes speed do not exceed 255
const uint8_t motor_full_stop = 0;

void setup() {
  //Timer 1 Setup
  noInterrupts();
  //Look up data sheets for more information
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 31250;            // compare match register 16MHz/256/[2Hz]
  //0.5 timer
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();
  
  //output
  Serial.begin(9600);
  Serial.println("Fired up and ready to serve!");
  AFMS.begin();
  
  //input
  pinMode (start_button,INPUT);
  pinMode (limit_upper_left,INPUT);
  pinMode (limit_upper_right,INPUT);
  pinMode (limit_lower_left,INPUT);
  pinMode (limit_lower_right,INPUT);
  pinMode (motion_pin,INPUT_PULLUP); //reverse logic, good for daisy chaining

  //Timer Start
  TCNT1H = 0;//clears timer High Byte
  safe_time = 0;//reset time counter
  TCNT1L = 0;//clears timer Low Byte  
}

ISR(TIMER1_COMPA_vect){//timer 1
  safe_time ++;
}

void loop() {
//Poll the input pins
  

//Button Qualifier
  if (red_button == HIGH && upper_left == LOW && upper_right == LOW){
    TCNT1H = 0;//clears timer High Byte
    safe_time = 0;//reset time counter
    TCNT1L = 0;//clears timer Low Byte
    while(safe_time < 5){
      forward_run();
      poll_sensors();
      if (upper_left == HIGH && upper_right == HIGH){
        total_stop();
        break;
      }
      else if(upper_left == HIGH && upper_right == LOW){
        total_stop();
        Serial.println("Upper Right No Contact");
        break;
      }
      else if(upper_left == LOW && upper_right == HIGH){
        total_stop();
        Serial.println("Upper Left No Contact");
        break;
      }
      else if(safe_time >= 4){
        total_stop();
        Serial.println("ERROR: Blockage");
        backward_run();
        break;
      }
    }
  }

  if (lower_left == LOW || lower_right == LOW){
    total_stop();
  }
  if (upper_left == HIGH || upper_right == HIGH){
    total_stop();
  }
//Motion Detector 
  if (still_here == HIGH && safe_time == 360){//Reverse Logic on prox. HIGH -> No one
    TCNT1H = 0;//clears timer High Byte
    safe_time = 0;//reset time counter
    TCNT1L = 0;//clears timer Low Byte
    while(safe_time < 5){
      backward_run();
      poll_sensors();
      if (lower_left == HIGH && lower_right == HIGH){
        total_stop();
        break;
      }
      else if(lower_left == HIGH && lower_right == LOW){
        total_stop();
        Serial.println("Lower Right No Contact");
        break;
      }
      else if(lower_left == LOW && lower_right == HIGH){
        total_stop();
        Serial.println("Lower Left No Contact");
        break;
      }
      else if(safe_time >= 4){
        total_stop();
        Serial.println("ERROR: Blockage");
        forward_run();
        break;
      }
    }
  }
//End of Loop
}


//Functions
void forward_run(){
  Serial.println("UP");
  motor_01 -> run(FORWARD);
  motor_02 -> run(FORWARD);
  motor_01 -> setSpeed(motor_speed_run);
  motor_02 -> setSpeed(motor_speed_run);
  
}

void total_stop(){
  Serial.println("STOP");
  motor_01 -> setSpeed(motor_full_stop);
  motor_02 -> setSpeed(motor_full_stop);
  motor_01 -> run(RELEASE);
  motor_02 -> run(RELEASE); 
}

void backward_run(){
  Serial.println("DOWN");
  motor_01 -> run(BACKWARD);
  motor_02 -> run(BACKWARD);
  motor_01 -> setSpeed(motor_speed_run);
  motor_02 -> setSpeed(motor_speed_run);
}

void poll_sensors(){
  red_button = digitalRead(start_button);
  upper_left = digitalRead(limit_upper_left);
  upper_right = digitalRead(limit_upper_right);
  lower_left = digitalRead(limit_lower_left);
  lower_right = digitalRead(limit_lower_right);
  still_here = digitalRead(motion_pin); 
}

