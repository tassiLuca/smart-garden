#include <Arduino.h>

#include "comm/MsgService.h"
#include "scheduler/Scheduler.h"
#include "uilities/Logger.h"
#include "tasks/main/MainTask.h"
#include "tasks/irrigation/IrrigationTask.h"
#include "model/SmartGardenImpl.h"

SmartGarden* garden;
Scheduler* scheduler;

void setup() {
    Serial.begin(9600);
    scheduler = new Scheduler(100);
    MsgService.init();
    garden = new SmartGardenImpl();
    // Creates all the tasks
    Task* main = new MainTask(500, garden);
    Task* irrigation = new IrrigationTask(100, garden);
    scheduler->addTask(main);
    scheduler->addTask(irrigation);
    Logger::getLogger()->log("ENDED SETUP");
}

void loop() {
    scheduler->schedule();
}