#include <Arduino.h>

#include "serialcomm/MsgService.h"
#include "scheduler/Scheduler.h"
#include "uilities/Logger.h"
#include "tasks/main/MainTask.h"
#include "tasks/irrigation/IrrigationTask.h"

Scheduler* scheduler;

void setup() {
    Serial.begin(9600);
    scheduler = new Scheduler(100);
    MsgService.init();
    // Creates all the tasks
    Task* main = new MainTask(500);
    main->activate();
    //Task* irrigation = new IrrigationTask(100);
    //irrigation->activate();
    scheduler->addTask(main);
    //scheduler->addTask(irrigation);
    Logger::getLogger()->log("ENDED SETUP");
}

void loop() {
    scheduler->schedule();
}