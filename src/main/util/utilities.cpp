#include "utilities.h"

/**
 * Prints the given message to the console.
 *
 * @param m the message
 */
void Utilities::print(std::string m)
{
    std::cout << m;
}

/**
 * Prints the given message to the console.
 *
 * @param m the message
 */
void Utilities::print(std::string *m)
{
    std::cout << m;
}

/**
 * Prints the given character to the console.
 *
 * @param c the character
 */
void Utilities::print(char c)
{
    std::cout << c;
}

/**
 * Prints a line break to the console.
 */
void Utilities::println()
{
    std::cout << std::endl;
}

/**
 * Prints a line break with the given message to the console.
 *
 * @param m the message
 */
void Utilities::println(std::string m)
{
    std::cout << m << std::endl;
}

/**
 * Clears the console.
 */
void Utilities::core_clearScr()
{
    system("CLS");
}

/**
 * Pauses the console.
 */
void Utilities::core_pauseScr()
{
    system("PAUSE");
}

/**
 * Checks if the current environment is a DEV environment.
 *
 * @return true, if the environment is in development
 */
bool Utilities::core_isDevEnvironment()
{
    return CONF_GAME_ENV_PROFILE == DEV;
}

/**
 * Converts given number to string.
 *
 * @param number the number to convert
 * @return the converted number string
 */
std::string Utilities::core_formatNumber(int number)
{
    return static_cast<std::ostringstream*>( &(std::ostringstream() << number) )->str();
}
