#ifndef ENUMS_H_INCLUDED
#define ENUMS_H_INCLUDED

/**
 * The Enum EnvProfile.
 */
enum EnvProfile
{
    DEV, PROD
};

/**
 * The Enum LogLevel.
 */
enum LogLevel
{
    DEBUG, INFO, WARN, LL_ERROR
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
    FP_RIGHT_OVER, // field place a the right over
    END
};

#endif // ENUMS_H_INCLUDED
