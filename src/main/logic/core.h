/**
 * Prints the given message to the console.
 *
 * @param m the message
 */
void print(std::string m)
{
    std::cout << m;
}

/**
 * Prints a line break to the console.
 */
void println()
{
    std::cout << std::endl;
}

/**
 * Prints a line break with the given message to the console.
 *
 * @param m the message
 */
void println(std::string m)
{
    std::cout << m << std::endl;
}

/**
 * Checks if the current environment is a DEV environment.
 *
 * @return true, if the environment is in development
 */
bool core_isDevEnvironment()
{
    return CONF_GAME_ENV_PROFILE == DEV;
}

/**
 * "Pausing" the console screen.
 */
void core_pause()
{
    getch();
}

/**
 * Sleep thread until given milliseconds.
 *
 * @param ms the milliseconds
 */
void core_sleep(unsigned ms)
{
    Sleep(ms);
}

/**
 * Sleep thread until given seconds.
 *
 * @param s the seconds
 */
void core_sleepSecs(int s)
{
    core_sleep(s * 1000);
}

/**
 * Clears the console screen.
 */
void core_clearScr()
{
    system("CLS");
}

/**
 * Converts given number to string.
 *
 * @param number the number to convert
 * @return the converted number string
 */
std::string core_formatNumber(int number)
{
    return static_cast<std::ostringstream*>( &(std::ostringstream() << number) )->str();
}

/**
 * Checks if the given value is in the given values array.
 *
 * @param value the value for search
 * @param values the array
 * @param length the length of the array
 * @return true, if the value is in the given values array
 */
bool core_contains( int value, int values[], int length )
{
    for( int i = 0; i<length; i++ )
    {
        if( values[i] == value )
        {
            return true;
        }
    }
    return false;
}
