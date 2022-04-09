#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor_leftrear  (2, MOTOR12_64KHZ);
AF_DCMotor motor_rightrear (3, MOTOR12_64KHZ);
AF_DCMotor motor_rightfront(4, MOTOR12_64KHZ);
AF_DCMotor motor_leftfront (1, MOTOR12_64KHZ);

Servo myServo1;

int trigPin = A0, echoPin = A1;
float duration_us, distance_cm, distance_cm1, distance_cm2;
int previous_distance, current_distance, max_distance=0, i=0;

int angle=0,previous_angle,angleState=0;
bool counter;

const int avoiding_distance = 30;

void setup() {
 motor_leftrear.setSpeed(150);
 motor_rightrear.setSpeed(150);
 motor_rightfront.setSpeed(150);
 motor_leftfront.setSpeed(150);
 Serial.begin(9600);
 pinMode(echoPin,INPUT); pinMode(trigPin,OUTPUT);

 myServo1.attach(10);
}

void forward(int time) {
 motor_leftrear.run(FORWARD);
 motor_rightrear.run(FORWARD);
 motor_rightfront.run(FORWARD);
 motor_leftfront.run(FORWARD);
 delay(time);
}

void backward(int time) {
 motor_leftrear.run(BACKWARD);
 motor_rightrear.run(BACKWARD);
 motor_rightfront.run(BACKWARD);
 motor_leftfront.run(BACKWARD);
 delay(time); 
}

void right_forward(int time) {
 motor_leftrear.run(RELEASE);
 motor_rightrear.run(FORWARD);
 motor_rightfront.run(RELEASE);
 motor_leftfront.run(FORWARD);
 delay(time);
}

void left_forward(int time) {
 motor_leftrear.run(FORWARD);
 motor_rightrear.run(RELEASE);
 motor_rightfront.run(FORWARD);
 motor_leftfront.run(RELEASE);
 delay(time);
}

void left_backward(int time) {
 motor_leftrear.run(RELEASE);
 motor_rightrear.run(BACKWARD);
 motor_rightfront.run(RELEASE);
 motor_leftfront.run(BACKWARD);
 delay(time);
}

void right_backward(int time) {
 motor_leftrear.run(BACKWARD);
 motor_rightrear.run(RELEASE);
 motor_rightfront.run(BACKWARD);
 motor_leftfront.run(RELEASE);
 delay(time);
}

void right_translation(int time) {
 motor_leftrear.run(BACKWARD);
 motor_rightrear.run(FORWARD);
 motor_rightfront.run(BACKWARD);
 motor_leftfront.run(FORWARD);
 delay(time);
}

void left_translation(int time) {
 motor_leftrear.run(FORWARD);
 motor_rightrear.run(BACKWARD);
 motor_rightfront.run(FORWARD);
 motor_leftfront.run(BACKWARD);
 delay(time);
}


void counterclockwise_rotation(int time) {
 motor_leftrear.run(BACKWARD);
 motor_rightrear.run(FORWARD);
 motor_rightfront.run(FORWARD);
 motor_leftfront.run(BACKWARD);
 delay(time);
}

void clockwise_rotation(int time) {
 motor_leftrear.run(FORWARD);
 motor_rightrear.run(BACKWARD);
 motor_rightfront.run(BACKWARD);
 motor_leftfront.run(FORWARD);
 delay(time);
}

void stationary(int time) {
 motor_leftrear.run(RELEASE);
 motor_rightrear.run(RELEASE);
 motor_rightfront.run(RELEASE);
 motor_leftfront.run(RELEASE); 
 delay(time); 
}
