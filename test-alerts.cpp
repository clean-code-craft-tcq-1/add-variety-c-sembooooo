#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "test_stub.h"
#include "typewise-alert.h"



static void CreateBatteryWith


TEST_CASE("infers the TOO_LOW breach") {
  REQUIRE(inferBreach(12.0, 20.0, 30.0) == TOO_LOW);
}

TEST_CASE("infers the TOO_HIGH breach") {
  REQUIRE(inferBreach(40.0, 20.0, 30.0) == TOO_HIGH);
}

TEST_CASE("infers the NORMAL : Value equal to lower limit") {
  REQUIRE(inferBreach(20.0, 20.0, 30.0) == NORMAL);
}

TEST_CASE("infers the NORMAL : Value equal to upper limit") {
  REQUIRE(inferBreach(30.0, 20.0, 30.0) == NORMAL);
}

TEST_CASE("Check if Alert is being called in Check and Alert with inferbreach return value")
{
  BatteryCharacter battery;
  battery.Alert = &AlertTestDouble;
  checkAndAlert(battery,20.5);
  REQUIRE(GetCall_AlertTestDouble() ,1);
  REQUIRE(GetPar_breach() ,TOO_HIGH);
}
