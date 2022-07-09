#include <Arduino.h>

#include "comm/BluetoothMsgService.h"
#include "comm/SerialMsgService.h"
#include "scheduler/Scheduler.h"
#include "tasks/main/MainTask.h"
#include "tasks/irrigation/IrrigationTask.h"
#include "model/SmartGardenImpl.h"

SmartGarden* garden;
Scheduler* scheduler;

void setup() {
    pinMode(2, OUTPUT);
    Serial.begin(9600);
    MsgService.init();
    BTMsgService.init();
    scheduler = new Scheduler(100);
    garden = new SmartGardenImpl();
    // Creates all the tasks
    Task* main = new MainTask(500, garden);
    Task* irrigation = new IrrigationTask(100, garden);
    scheduler->addTask(main);
    scheduler->addTask(irrigation);
}

void loop() {
    scheduler->schedule();
}