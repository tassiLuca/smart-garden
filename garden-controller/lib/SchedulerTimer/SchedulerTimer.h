#ifndef __TIMER__
#define __TIMER__

class SchedulerTimer {
    
public:  
    SchedulerTimer();
    void setupFreq(int freq);  
    /* period in ms */
    void setupPeriod(int period);  
    void waitForNextTick();

};

#endif