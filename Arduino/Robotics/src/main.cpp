#include <Arduino.h>
#include <Servo.h>

int motor1Pin1 = 4;
int motor1Pin2 = 5;
int motor2Pin1 = 6;
int motor2Pin2 = 7;
int trigPin = 8;
int echoPin = 9;
int motorPin = 3;
double long distance;
Servo myservo;

void setup() {
// write your initialization code here
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(motorPin, OUTPUT);
    myservo.attach(3);
}

void loop() {
// write your code here

    myservo.write(90);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(2);
    digitalWrite(trigPin, LOW);

    distance = static_cast<double long>(pulseIn(echoPin, HIGH)) * 0.034 / 2;

    if (distance < 20) {
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);

        myservo.write(180);
        delay(1000);

        digitalWrite(trigPin, HIGH);
        delayMicroseconds(2);
        digitalWrite(trigPin, LOW);

        distance = static_cast<double long>(pulseIn(echoPin, HIGH)) * 0.034 / 2;

        if (distance > 20) {
            myservo.write(90);
            digitalWrite(motor1Pin2, HIGH);
            delay(1000);
            digitalWrite(motor1Pin2, LOW);
            delay(500);

        } else {
            myservo.write(0);
            delay(500);

            digitalWrite(trigPin, HIGH);
            delayMicroseconds(2);
            digitalWrite(trigPin, LOW);

            distance = static_cast<double long>(pulseIn(echoPin, HIGH)) * 0.034 / 2;

            if (distance > 20) {
                myservo.write(90);
                digitalWrite(motor2Pin2, HIGH);
                delay(500);
                digitalWrite(motor2Pin2 , LOW);
                delay(500);

            }
        }

    } else {
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        digitalWrite(motor2Pin1, LOW);
        delay(500);
    }

}