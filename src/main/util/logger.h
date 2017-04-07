/**
 * Prints the given message.
 *
 * @param m the message
 */
void print(std::string m)
{
    std::cout << m;
}

/**
 * Prints a line break.
 */
void println()
{
    std::cout << std::endl;
}

/**
 * Prints a line break with the given message.
 *
 * @param m the message
 */
void println(std::string m)
{
    print(m);
    println();
}

/**
 * Clears the console screen.
 */
void clearScreen()
{
    system("CLS");
}

/**
 * Gets now.
 */
time_t getNow()
{
    time_t  timev;
    return time(&timev);
}

/**
 * Pausing console screen.
 */
void pauseScreen()
{
    getch();
}

/**
 * Exiting console screen.
 */
void exitScreen()
{
    println("Program exiting...");
    println("Please press any key to exit");
    pauseScreen();
}

/**
 * Prints ERROR level message with the given message content.
 *
 * @param m the message
 */
 void printError(std::string m)
{
    print(CONST_LOGGER_LOG_LEVEL_ERROR);
    //print(getNow() + " ");
    print(m);
}

/**
 * Prints ERROR level message with the given message content.
 *
 * @param m the message
 */
 void printlnError(std::string m)
{
    print(CONST_LOGGER_LOG_LEVEL_ERROR);
    //print(getNow() + " ");
    println(m);
}

/**
 * Prints WARNING level message with the given message content.
 *
 * @param m the message
 */
void printWarn(std::string m)
{
    print(CONST_LOGGER_LOG_LEVEL_WARNING);
    //print(getNow() + " ");
    print(m);
}

/**
 * Prints WARNING level message with the given message content.
 *
 * @param m the message
 */
void printlnWarn(std::string m)
{
    print(CONST_LOGGER_LOG_LEVEL_WARNING);
    //print(getNow() + " ");
    println(m);
}

/**
 * Prints INFORMATION level message with the given message content.
 *
 * @param m the message
 */
void printInfo(std::string m)
{
    print(CONST_LOGGER_LOG_LEVEL_INFORMATION);
    //print(getNow() + " ");
    print(m);
}

/**
 * Prints INFORMATION level message with the given message content.
 *
 * @param m the message
 */
void printlnInfo(std::string m)
{
    print(CONST_LOGGER_LOG_LEVEL_INFORMATION);
    //print(getNow() + " ");
    println(m);
}

/**
 * Prints DEBUG level message with the given message content.
 *
 * @param m the message
 */
void printDebug(std::string m)
{
    print(CONST_LOGGER_LOG_LEVEL_DEBUG);
    //print(getNow() + " ");
    println(m);
}

/**
 * Prints DEBUG level message with the given message content.
 *
 * @param m the message
 */
void printlnDebug(std::string m)
{
    print(CONST_LOGGER_LOG_LEVEL_DEBUG);
    //print(getNow() + " ");
    println(m);
}

/**
 * Converts given number to string.
 *
 * @param number the number to convert
 * @return the converted number string
 */
std::string convertNumberToString(int number)
{
    return static_cast<std::ostringstream*>( &(std::ostringstream() << number) )->str();
}
