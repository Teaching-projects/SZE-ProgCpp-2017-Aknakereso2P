/**
 * Prints the given message to the console.
 *
 * @param m the message
 */
static void print(std::string m)
{
    std::cout << m;
}

/**
 * Prints the given character to the console.
 *
 * @param c the character
 */
static void print(char c)
{
    std::cout << c;
}

/**
 * Prints a line break to the console.
 */
static void println()
{
    std::cout << std::endl;
}

/**
 * Prints a line break with the given message to the console.
 *
 * @param m the message
 */
static void println(std::string m)
{
    std::cout << m << std::endl;
}

/**
 * Clears the console.
 */
static void core_clearScr()
{
    system("CLS");
}

/**
 * Pauses the console.
 */
static int core_pauseScr()
{
    return getch();
}

/**
 * Sleep thread until given milliseconds.
 *
 * @param ms the milliseconds
 */
static void core_sleep(unsigned ms)
{
    Sleep(ms);
}

/**
 * Sleep thread until given seconds.
 *
 * @param s the seconds
 */
static void core_sleepSecs(int s)
{
    core_sleep(s * 1000);
}

/**
 * Checks if the current environment is a DEV environment.
 *
 * @return true, if the environment is in development
 */
static bool core_isDevEnvironment()
{
    return CONF_GAME_ENV_PROFILE == DEV;
}

/**
 * Converts given number to string.
 *
 * @param number the number to convert
 * @return the converted number string
 */
static std::string core_formatNumber(int number)
{
    return static_cast<std::ostringstream*>( &(std::ostringstream() << number) )->str();
}