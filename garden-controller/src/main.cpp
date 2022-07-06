#include <Arduino.h>

#include "serialcomm/MsgService.h"
#include "scheduler/Scheduler.h"
#include "model/SmartGarden.h"
#include "tasks/main/MainTask.h"

Scheduler* scheduler;

void setup() {
    Serial.begin(9600);
    pinMode(12, OUTPUT);
    scheduler = new Scheduler(500);
    MsgService.init();
    // Creates all the tasks
    Task* mainTask = new MainTask(1000);
    mainTask->activate();
    scheduler->addTask(mainTask);
}

void loop() {
    scheduler->schedule();
}