#ifndef __SETUP__
#define __SETUP__

#define L1_PIN 3
#define L2_PIN 4
#define L3_PIN 5
#define L4_PIN 6

#define SERVO_MOTOR_PIN 11

// Display infos.
// Keep in mind, since we are using Arduino Uno:
// +-------------+-------------+
// + Display Pin + Arduino Pin +
// +-------------+-------------+
// +     SCL     +      A5     +
// +     SDA     +      A4     +
// +-------------+-------------+
// Refer to [https://www.arduino.cc/en/reference/wire] 
#define DISPLAY_COLS 16
#define DISPLAY_ROWS 2

/*

{
    "action": "new-data" / "update-state" / "manual-control"
    "data": {
        "temperature": ....
        "lightness": ....
    }
    /
    "data": {
        "led1": "on" / "off"
        "led2": "on" / "off"
        "led3": 0..255
        "led4": 0..255
        "irrigation": "on"
        "speed": 0..10
    }
    / 
    "data" {
        "new-state": "manual" / "auto"
    }

}

*/

#endif