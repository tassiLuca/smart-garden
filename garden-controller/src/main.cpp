#include <Arduino.h>

#include "serialcomm/MsgService.h"
#include "scheduler/Scheduler.h"
#include "model/SmartGarden.h"

#include "tasks/main/MainTask.h"

Scheduler* scheduler;
SmartGarden* machine;

void setup() {
    Serial.begin(9600);
    scheduler = new Scheduler(500);
    MsgService.init();
    // Creates all the tasks
    Task* mainTask = new MainTask(1000);
    mainTask->activate();
    // Task* t2 = new DispensingTask(50, machine);
    // Task* t3 = new SelfTestingTask(500, machine);
    // Task* t4 = new CommunicationTask(1000, machine);
    scheduler->addTask(mainTask);
    // scheduler->addTask(t2);
    // scheduler->addTask(t3);
    // scheduler->addTask(t4);
}

void loop() {
    scheduler->schedule();
}