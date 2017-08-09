#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
#include <chrono>
#include <ratio>
#include <ctime>

#include <QApplication>
#include <QFile>



//template<typename charT, typename char_traits>
//std::basic_ostream<charT, char_traits>& log(std::basic_ostream<charT, char_traits>& ostream)

#define LOG(...){\
    std::chrono::time_point<std::chrono::system_clock> tp{std::chrono::system_clock::now()};\
    std::time_t time{std::chrono::system_clock::to_time_t(tp)};\
    std::string time_str{std::ctime(&time)};\
    time_str.resize(time_str.size()-1);\
    std::clog << "[" << time_str << __FILE__ << "]" <<__LINE__ << "  " << __VA_ARGS__ << std::endl;\
}





class CommonHelper
{
public:
    static void setStyle(const QString &style)noexcept
    {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};







#endif // UTILITIES_H
