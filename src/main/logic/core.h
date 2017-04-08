Logger logger = Logger();

/**
 * Checks if the current environment is a DEV environment.
 *
 * @return true, if the environment is in development
 */
bool isDevEnvironment()
{
    return CONF_GAME_ENV_PROFILE == DEV;
}

/**
 * "Pausing" the console screen.
 */
void pause()
{
    getch();
}

/**
 * Clears the console screen.
 */
void clearScr()
{
    system("CLS");
}

/**
 * Converts given number to string.
 *
 * @param number the number to convert
 * @return the converted number string
 */
std::string formatNumber(int number)
{
    return static_cast<std::ostringstream*>( &(std::ostringstream() << number) )->str();
}

/**
 * Sleep thread until given milliseconds.
 *
 * @param ms the milliseconds
 */
void sleep(unsigned ms)
{
    Sleep(ms);
}

/**
 * Sleep thread until given seconds.
 *
 * @param s the seconds
 */
void sleepSecs(int s)
{
    sleep(s * 1000);
}
