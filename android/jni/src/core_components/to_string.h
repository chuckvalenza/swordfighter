/**
 * to_string.h
 *
 * Description: Implement to_string method (left out of android NDK)
 */

#ifndef SWORD_FIGHTER_TO_STRING_H
#define SWORD_FIGHTER_TO_STRING_H

#include <string>
#include <sstream>

template <typename T>
std::string to_string(T value)
{
    std::ostringstream os;
    os << value;
    return os.str();
}

template <typename T>
const char* to_c_string(T value)
{
	std::string s = to_string(value);
	return to_string(value).c_str();
}

#endif //SWORD_FIGHTER_TO_STRING_H
