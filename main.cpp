#include "cookie.h"

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

/*
    Main Method for most_active_cookie, which take in a csv file and returns the most active cookie. 
*/

int main(int argc, char **argv) {

    std::string err_msg = "Proper Usage: ./most_active_cookie cookie_log.csv -d 2018-12-09";

    if (argc !=4) {
        std::cerr << err_msg << std::endl;
        return -1;
    }

    std::string log_filename = argv[1];
    std::string flag = argv[2];
    std::string given_day = argv[3];

    // Check for correct flag
    if (flag != "-d") {
        std::cerr << err_msg << std::endl;
        return -1;
    }

    // Opening Log File
    std::ifstream log_file(log_filename);
    if (!log_file) {
        std::cerr << "Can't open log file" << std::endl;
        return -1;
    }

    // Reading Log File, creating unordered_map of frequencies of each of the cookies on the given day
    std::string line;
    std::unordered_map<std::string, int> freqs;
    while (std::getline(log_file, line)) {
        std::string cookie = get_cookie(line);
        std::string day = get_day(line);
        // Check whether day matches given day 
        if (day == given_day) {
            freqs[cookie] += 1;
        }
    }

    // Finding the maximum frequency of all cookies
    int maxFreq = 0;
    for (auto freq : freqs) {
        if (freq.second > maxFreq) {
            maxFreq = freq.second;
        }
    }

    // Printing out all the most frequent cookies
    for (auto freq : freqs) {
        if (freq.second == maxFreq) {
            std::cout << freq.first << std::endl;
        }
    }

}