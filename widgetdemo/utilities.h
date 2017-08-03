#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
#include <chrono>
#include <ratio>
#include <ctime>

namespace TT
{


//template<typename charT, typename char_traits>
//std::basic_ostream<charT, char_traits>& log(std::basic_ostream<charT, char_traits>& ostream)

#define LOG(...){\
    std::chrono::time_point<std::chrono::system_clock> tp{std::chrono::system_clock::now()};\
    std::time_t time{std::chrono::system_clock::to_time_t(tp)};\
    std::string time_str{std::ctime(&time)};\
    ostream << "[" << time_str << "]" << __LINE__ << __FILE__ << __VA_ARGS__ << std::endl;\
}

}

#endif // UTILITIES_H
