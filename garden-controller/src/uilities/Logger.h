#ifndef __LOGGER__
#define __LOGGER__

#include <Arduino.h>

class Logger {

public:
    /** 
     * Singleton should not be clonable.
     */
    Logger(Logger &other) = delete;

    /**
     * Singletons should not be assignable.
     */
    void operator=(const Logger &) = delete;

    static Logger* getLogger();

    void log(const String msg);

private:
    Logger(){}

    static Logger* logger;

};

#endif