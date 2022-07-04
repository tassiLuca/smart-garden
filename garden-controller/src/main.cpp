#include <Arduino.h>

#include "serialcomm/MsgService.h"
#include "scheduler/Scheduler.h"
#include "model/SmartGarden.h"

Scheduler* scheduler;
SmartGarden* machine;

void setup() {
    Serial.begin(9600);
    scheduler = new Scheduler(50);
    MsgService.init();
    // Creates all the tasks
    // Task* t1 = new MainTask(100, machine);
    // Task* t2 = new DispensingTask(50, machine);
    // Task* t3 = new SelfTestingTask(500, machine);
    // Task* t4 = new CommunicationTask(1000, machine);
    // scheduler->addTask(t1);
    // scheduler->addTask(t2);
    // scheduler->addTask(t3);
    // scheduler->addTask(t4);
}

void loop() {
    scheduler->schedule();
}