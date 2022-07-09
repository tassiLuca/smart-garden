#ifndef __LOGGER__
#define __LOGGER__

/**
 * @brief A logger object to log messages.
 */
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

    /**
     * @brief Get the Logger.
     * @return Logger* return the logger object.
     */
    static Logger* getLogger();

    /**
     * @brief Logs (prints) the message given in input. 
     * @param msg the message string to log
     */
    void log(const String msg);

private:
    Logger(){}
    static Logger* logger;

};

#endif