#include <Stepper.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // RX, TX for Bluetooth

#define HALFSTEP 8
#define motorPin1  8    // Blue   on 28BYJ-48
#define motorPin2  9    // Pink   on 28BYJ-48
#define motorPin3  10   // Yellow on 28BYJ-48
#define motorPin4  11   // Orange on 28BYJ-48

Stepper stepper(2028, motorPin1, motorPin3, motorPin2, motorPin4); // Motor pins

long mySteps = 2048;              // Assuming a nominal 4096 steps per revolution
float mySpeed = 500.0;

void setup() {
  Serial.begin(9600); // Initialize Serial Monitor
  bluetooth.begin(9600);
}

void loop() {
   int lastButtonState = 0;

  if (bluetooth.available() >= 1) {
    int command = bluetooth.read();  // Read the command from Bluetooth

    // Handle button presses
    if (command >= 1 && command <= 6) {
      if (command != lastButtonState) {
        lastButtonState = command;
        moveStepper(command);
      }
    }
  }
}

void moveStepper(int buttonState) {
  int angle = 0;

  // Map the buttonState to angles
  switch (buttonState) {
    case 1:
      angle = 30;
      break;
    case 2:
      angle = 60;
      break;
    case 3:
      angle = 90;
      break;
    case 4:
      angle = 120;
      break;
    case 5:
      angle = 150;
      break;
    case 6:
      angle = 180;
      break;
    default:
      angle = 0; // Default to 0 if an unknown command is received
      break;
  }

  // Map the angle to steps based on your motor and requirements
  long steps = map(angle, 0, 180, 0, mySteps);

  // Move the stepper motor
  if (buttonState == 0) {
    // Stop the motor if the default state is encountered
    stepper.setSpeed(0);
    stepper.step(0);
  } else {
    stepper.setSpeed(mySpeed);
    stepper.step(steps);
  }

  // Display the received command and corresponding angle on the Serial Monitor
  Serial.print("Received Command: ");
  Serial.print(buttonState);
  Serial.print(", Corresponding Angle: ");
  Serial.println(angle);
}


