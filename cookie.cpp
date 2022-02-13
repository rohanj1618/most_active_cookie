#include "cookie.h"

std::string get_cookie(std::string line) {
    if (line.find(",") == std::string::npos) {
        return "";
    }
    std::string cookie = line.substr(0, line.find(","));
    return cookie;
}

std::string get_day(std::string line) {
    if (line.find(",") == std::string::npos) {
        return "";
    }
    std::string time = line.substr(line.find(",") + 1);
    if (time.find("T") == std::string::npos) {
        return "";
    }
    std::string day = time.substr(0, time.find("T")); 
    return day;
}