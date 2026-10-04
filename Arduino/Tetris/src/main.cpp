#include <Arduino.h>
#include <ezButton.h>
#include <LedControl.h>

int VRX_PIN = A2;
int VRY_PIN = A3;
int SW_PIN = 11;
int DIN_PIN = 2;
int CS_PIN = 3;
int CLK_PIN = 4;

int xValue = 0;
int yValue = 0;
int bValue = 0;

ezButton button(SW_PIN);

void setup() {
    Serial.begin(9600);
    button.setDebounceTime(50);
}

void loop() {
    button.loop();

    xValue = analogRead(VRX_PIN);
    yValue = analogRead(VRY_PIN);

    bValue = button.getState();

}