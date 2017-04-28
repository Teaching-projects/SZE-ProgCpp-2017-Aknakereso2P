#include "logger.h"

/**
 * Static initialization.
 */
bool    Logger::INSTANCE_FLAG   = false;
Logger* Logger::INSTANCE        = NULL;

/**
 * Gets the instance.
 *
 * @return the logger
 */
Logger* Logger::getInstance()
{
    if(!INSTANCE_FLAG)
    {
        INSTANCE = new Logger();
        INSTANCE_FLAG = true;
    }
    return INSTANCE;
}

/**
 * Checks if the log level is ERROR.
 *
 * @return true, if the log level is ERROR
 */
bool Logger::isErrorEnabled(void)
{
    return level == LL_ERROR || level == WARN || level == INFO || level == DEBUG;
}

/**
 * Checks if the log level is WARN.
 *
 * @return true, if the log level is WARN
 */
bool Logger::isWarningEnabled(void)
{
    return level == WARN || level == INFO || level == DEBUG;
}

/**
 * Checks if the log level is INFO.
 *
 * @return true, if the log level is INFO
 */
bool Logger::isInformationEnabled(void)
{
    return level == INFO || level == DEBUG;
}

/**
 * Checks if the log level is DEBUG.
 *
 * @return true, if the log level is DEBUG
 */
bool Logger::isDebugEnabled(void)
{
    return level == DEBUG;
}

/**
 * Gets now.
 */
std::string Logger::getNow(void)
{
    char now[128];
    std::time_t t = std::time(0) ;
    std::strftime( now, sizeof(now), "%Y-%m-%d.%X", std::localtime(&t) ) ;
    return now;
}

/**
 * Log the given message with the given log level.
 *
 * @param l the log level
 * @param m the message
 */
void Logger::log(std::string l, std::string m)
{
    std::cout << "[" << l << "]";
    std::cout << " " << getNow() << " ";
    std::cout << "- " << m << std::endl;
}

/**
 * Log ERROR with the given message.
 *
 * @param m the message
 */
void Logger::logError(std::string m)
{
    if(isErrorEnabled())
    {
        log( CONST_LOGGER_LOG_LEVEL_ERROR, m );
    }
}

/**
 * Log WARNING with the given message.
 *
 * @param m the message
 */
void Logger::logWarn(std::string m)
{
    if(isWarningEnabled())
    {
        log( CONST_LOGGER_LOG_LEVEL_WARNING, m );
    }
}

/**
 * Log INFORMATION with the given message.
 *
 * @param m the message
 */
void Logger::logInfo(std::string m)
{
    if(isInformationEnabled())
    {
        log( CONST_LOGGER_LOG_LEVEL_INFORMATION, m );
    }
}

/**
 * Log DEBUG with the given message.
 *
 * @param m the message
 */
void Logger::logDebug(std::string m)
{
    if(isDebugEnabled())
    {
        log( CONST_LOGGER_LOG_LEVEL_DEBUG, m );
    }
}
