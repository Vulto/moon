#include <stdio.h>
#include <math.h>
#include <time.h>

#define NEW_MOON "🌑"
#define WAXING_CRESCENT "🌒"
#define FIRST_QUARTER "🌓"
#define WAXING_GIBBOUS "🌔"
#define FULL_MOON "🌕"
#define WANING_GIBBOUS "🌖"
#define LAST_QUARTER "🌗"
#define WANING_CRESCENT "🌘"

int calculateMoonPhase(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }

    int a = year / 100;
    int b = 2 - a + a / 4;
    int jd = (int)(365.25 * (year + 4716)) + (int)(30.6001 * (month + 1));

    jd += day + b - 1524.5;

    int totalDays = jd - 2451550.1;
    int cycles = totalDays / 29.53058867;

    double fraction = totalDays / 29.53058867 - cycles;

    int phase = (int)round(fraction * 8) & 7;

    return phase;
}

const char* getMoonPhaseSymbol(int phase) {
    switch (phase) {
        case 0:
            return NEW_MOON;
        case 1:
            return WAXING_CRESCENT;
        case 2:
            return FIRST_QUARTER;
        case 3:
            return WAXING_GIBBOUS;
        case 4:
            return FULL_MOON;
        case 5:
            return WANING_GIBBOUS;
        case 6:
            return LAST_QUARTER;
        case 7:
            return WANING_CRESCENT;
        default:
            return "Unknown Moon Phase";
    }
}

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int day = tm.tm_mday;
    int month = tm.tm_mon + 1;
    int year = tm.tm_year + 1900;

    int phase = calculateMoonPhase(year, month, day);

    printf("%s\n", getMoonPhaseSymbol(phase));

    return 0;
}
