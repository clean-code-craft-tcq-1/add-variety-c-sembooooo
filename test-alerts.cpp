#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "test_stub.h"
#include "typewise-alert.h"
#include <string.h>
#include <stdio.h>

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


/* using philosophy of art of readable code */
TEST_CASE("Check if Alert is being called in Check and Alert with inferbreach return value")
{
  BatteryCharacter battery;
  battery.Alert = &AlertTestDouble;
  checkAndAlert(battery,20.5);
  REQUIRE(GetCall_AlertTestDouble() == 1);
  REQUIRE(GetPar_breach() == TOO_HIGH);
}

TEST_CASE("Evaluate BreachTypeToString conversion") {
  REQUIRE(strcmp(BreachTypeToString(TOO_LOW),"too low") == 0);
  REQUIRE(strcmp(BreachTypeToString(TOO_HIGH),"too high") == 0);
  REQUIRE(strcmp(BreachTypeToString(NORMAL),"normal") == 0);
}
TEST_CASE("test") {
  FILE *fptr = freopen("./file.txt", "w+", stdout);
  printf("this is atest string");
  fclose(fptr);
  REQUIRE(1);
}
