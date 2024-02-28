#include <ctime>
#include "Time.h"

Time now() {
    time_t clock = time(0);
    long h = localtime(&clock)->tm_hour;
    long m = localtime(&clock)->tm_min;
    long s = localtime(&clock)->tm_sec;

    return Time(h, m, s);
}

int main() {
    std::cout << "At the tone, the time will be " << now() << std::endl;
}