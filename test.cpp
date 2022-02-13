#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "cookie.h"

// Testing the helper functions of most_active_cookie on bad inputs

TEST_CASE("get_cookie Test 1") {
    REQUIRE(get_cookie("4sMM2LxV07bPJzwf,2018-12-07T23:30:00+00:00") == "4sMM2LxV07bPJzwf");
}

TEST_CASE("get_cookie Test 2") {
    REQUIRE(get_cookie("cookie") == "");
}

TEST_CASE("get_day Test 1") {
    REQUIRE(get_day("4sMM2LxV07bPJzwf,2018-12-07T23:30:00+00:00") == "2018-12-07");
}

TEST_CASE("get_day Test 2") {
    REQUIRE(get_day("time") == "");
}

TEST_CASE("get_day Test 3") {
    REQUIRE(get_day("cookie, time") == "");
}

