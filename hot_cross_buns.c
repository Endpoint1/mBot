#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMCore.h>

MeDCMotor motor_9(9);
MeDCMotor motor_10(10);

void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
        	leftSpeed = speed;
        	rightSpeed = speed;
      }else if(direction == 2){
        	leftSpeed = -speed;
        	rightSpeed = -speed;
      }else if(direction == 3){
        	leftSpeed = -speed;
        	rightSpeed = speed;
      }else if(direction == 4){
        	leftSpeed = speed;
        	rightSpeed = -speed;
      }
      motor_9.run((9)==M1?-(leftSpeed):(leftSpeed));
      motor_10.run((10)==M1?-(rightSpeed):(rightSpeed));
}

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeRGBLed rgbled_7(7, 7==7?2:4);
MeBuzzer buzzer;



void setup(){
    rgbled_7.setColor(0,60,0,0);
    rgbled_7.show();
    move(1,50);
    for(int __i__=0;__i__<2;++__i__)
    {
        move(2,100);
        buzzer.tone(247, 500);
        delay(20);
        move(1,100);
        buzzer.tone(220, 500);
        delay(20);
        move(2,100);
        buzzer.tone(98, 500);
        delay(20);
        rgbled_7.setColor(0,0,0,60);
        rgbled_7.show();
        _delay(1);
    }
    move(4,100);
    rgbled_7.setColor(0,0,60,0);
    rgbled_7.show();
    _delay(5);
    for(int __i__=0;__i__<4;++__i__)
    {
        move(1,100);
        buzzer.tone(98, 250);
        delay(20);
        move(2,100);
        rgbled_7.setColor(0,60,0,0);
        rgbled_7.show();
    }
    for(int __i__=0;__i__<4;++__i__)
    {
        buzzer.tone(220, 250);
        delay(20);
        rgbled_7.setColor(0,0,0,60);
        rgbled_7.show();
    }
    move(3,100);
    rgbled_7.setColor(0,0,60,0);
    rgbled_7.show();
    _delay(5);
    for(int __i__=0;__i__<1;++__i__)
    {
        move(4,100);
        buzzer.tone(247, 500);
        delay(20);
        move(3,100);
        buzzer.tone(220, 500);
        delay(20);
        move(4,100);
        buzzer.tone(98, 500);
        delay(20);
        rgbled_7.setColor(0,60,0,0);
        rgbled_7.show();
        _delay(1);
    }
    rgbled_7.setColor(2,0,60,0);
    rgbled_7.show();
    rgbled_7.setColor(1,0,0,60);
    rgbled_7.show();
    move(4,0);

}

void loop(){


    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){

}
