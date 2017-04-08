#define CONST_GAME_NAME                     "Mineszwiper Game"

#define CONST_TAB                           "    "

#define CONST_MINEFIELD_HEADER              "ABCDEFGHIJKLMNOP"

#define CONST_PLAYER_ANONYMOUS_FIRSTNAME    "Anonymous"
#define CONST_PLAYER_ANONYMOUS_LASTNAME     "Anonymous"
#define CONST_PLAYER_ANONYMOUS_NICKNAME     "player"

#define CONST_LOGGER_LOG_LEVEL_ERROR        "ERROR"
#define CONST_LOGGER_LOG_LEVEL_WARNING      "WARN "
#define CONST_LOGGER_LOG_LEVEL_INFORMATION  "INFO "
#define CONST_LOGGER_LOG_LEVEL_DEBUG        "DEBUG"

/**
 * The Enum EnvProfile.
 */
enum EnvProfile
{
    DEV,
    PROD
};

/**
 * The Enum LogLevel.
 */
enum LogLevel
{
    DEBUG,
    INFO,
    WARN,
    LL_ERROR
};

/**
 * The Enum FieldPlace.
 */
enum FieldPlace
{
	FP_OVER, // field place at the above
	FP_LEFT_OVER, // field place at the left over
    FP_LEFT, // field place at the left
    FP_LEFT_UNDER, // field place at the left under
    FP_UNDER, // field place at the under
    FP_RIGHT_UNDER, // field place at the right under
    FP_RIGHT, // field place at the right
    FP_RIGHT_OVER // field place a the right over
};
