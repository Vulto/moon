#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int day = tm.tm_mday;
  int month = tm.tm_mon + 1;
  int year = tm.tm_year + 1900;

  // Calculate the moon phase using the algorithm from
  // https://www.calculatorcat.com/moon_phases/phasenow.php
  int century = year / 100;
  int mod1 = year % 100;
  int mod2 = month + 12 * ((14 - month) / 12) - 2;
  int mod3 = (day + mod1 + mod1 / 4 + century / 4 - 2 * century) % 7;
  int phase = (mod1 + mod1 / 4 + mod3 + mod3 / 7) % 7;

  // Display the moon phase using Unicode characters
  switch (phase) {
    case 0:
      printf("\'\u263E\' New Moon\n");
      break;
    case 1:
      printf("\u263E Waxing Crescent Moon\n");
      break;
    case 2:
      printf("\u263E First Quarter Moon\n");
      break;
    case 3:
      printf("\u263E Waxing Gibbous Moon\n");
      break;
    case 4:
      printf("\u263E Full Moon\n");
      break;
    case 5:
      printf("\u263E Waning Gibbous Moon\n");
      break;
    case 6:
      printf("\u263E Last Quarter Moon\n");
      break;
    case 7:
      printf("\u263E Waning Crescent Moon\n");
      break;
  }

  return 0;
}