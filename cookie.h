#pragma once

#include <string>

// Helper functions for most_active_cookie program.

// Function which takes in a line of the log file and ouputs the cookie if the line is properly formatted
std::string get_cookie(std::string line);

// Function which takes in a line of the log file and outputs the day in UTC if the line is properly formatted. 
std::string get_day(std::string line);