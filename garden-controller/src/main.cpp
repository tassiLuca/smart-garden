#include <Arduino.h>

#include "comm/MsgService.h"
#include "comm/MsgServiceBT.h"
#include "scheduler/Scheduler.h"
#include "tasks/main/MainTask.h"
#include "tasks/irrigation/IrrigationTask.h"
#include "model/SmartGardenImpl.h"

MsgServiceBT BT(7,8);
SmartGarden* garden;
Scheduler* scheduler;

void setup() {
    pinMode(2, OUTPUT);
    Serial.begin(9600);
    MsgService.init();
    BT.init();
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