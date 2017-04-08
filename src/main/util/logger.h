/**
 * The Class Logger.
 */
class Logger
{
    private:
        /**
         * Checks if the log level is ERROR.
         *
         * @return true, if the log level is ERROR
         */
        bool isErrorEnabled()
        {
            return CONF_GAME_ENV_LOG_LEVEL == LL_ERROR
                || CONF_GAME_ENV_LOG_LEVEL == WARN
                || CONF_GAME_ENV_LOG_LEVEL == INFO
                || CONF_GAME_ENV_LOG_LEVEL == DEBUG;
        }

        /**
         * Checks if the log level is WARN.
         *
         * @return true, if the log level is WARN
         */
        bool isWarningEnabled()
        {
            return CONF_GAME_ENV_LOG_LEVEL == WARN
                || CONF_GAME_ENV_LOG_LEVEL == INFO
                || CONF_GAME_ENV_LOG_LEVEL == DEBUG;
        }

        /**
         * Checks if the log level is INFO.
         *
         * @return true, if the log level is INFO
         */
        bool isInformationEnabled()
        {
            return CONF_GAME_ENV_LOG_LEVEL == INFO
                || CONF_GAME_ENV_LOG_LEVEL == DEBUG;
        }

        /**
         * Checks if the log level is DEBUG.
         *
         * @return true, if the log level is DEBUG
         */
        bool isDebugEnabled()
        {
            return CONF_GAME_ENV_LOG_LEVEL == DEBUG;
        }

        /**
         * Log the given message with the given log level.
         *
         * @param l the log level
         * @param m the message
         */
        void log(std::string l, std::string m)
        {
            std::cout << "[" << l << "]";
            std::cout << " " << getNow() << " ";
            std::cout << "- " << m << std::endl;
        }

        /**
         * Gets now.
         */
        time_t getNow()
        {
            time_t  timev;
            return time(&timev);
        }

    public:
        /**
         * Log ERROR with the given message.
         *
         * @param m the message
         */
         void logError(std::string m)
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
        void logWarn(std::string m)
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
        void logInfo(std::string m)
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
        void logDebug(std::string m)
        {
            if(isDebugEnabled())
            {
                log( CONST_LOGGER_LOG_LEVEL_DEBUG, m );
            }
        }

};
