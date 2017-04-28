#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <ctime>
#include <iostream>

#include "../runner/configs.h"

#include "consts.h"
#include "enums.h"

/**
 * The Class Logger.
 */
class Logger
{
    private:
        static bool     INSTANCE_FLAG;
        static Logger*  INSTANCE;

        LogLevel level;

        /**
         * Instantiates a new logger.
         */
        Logger()
        {
            level = CONF_GAME_ENV_LOG_LEVEL;
        }

    public:
        static Logger* getInstance();
        void logError(std::string m);
        void logWarn(std::string m);
        void logInfo(std::string m);
        void logDebug(std::string m);

    private:
        bool isErrorEnabled(void);
        bool isWarningEnabled(void);
        bool isInformationEnabled(void);
        bool isDebugEnabled(void);
        std::string getNow(void);
        void log(std::string l, std::string m);
};

#endif // LOGGER_H_INCLUDED
