/**
 * @file Time.h
 * @author kennyrogers92 (kenraposas92@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
    private:
        long hour, min, sec;
        static bool ampm_style;
        void adjust() {
            // adjust the seconds
            if (sec < 0) {
                long change = (-sec)/60 + 1;
                sec += change *60;
                min -= change;
            }
            if (sec > 59) {
                long change = sec/60;
                sec -= change*60;
                min += change;
            }

            // adjust the minutes
            if (min < 0) {
                long change = (-min)/60 + 1;
                min += change*60;
                hour -= change;
            }
            if (min > 59) {
                long change = min/60;
                min -= change*60;
                hour += change;
            }

            // adjust the hour
            if (hour < 0) {
                long change = (-hour)/24 + 1;
                hour += change*24;
            }
            if (hour > 23) {
                hour %= 24;
            }
        }
    public:
        // Constructors
        // Default Constructor: Construct 00:00:00
        Time() { 
            hour = min = sec = 0;
        }

        // Construct HH:MM:SS
        Time(int H, int M, int S) {
            hour = H;
            min = M;
            sec = S;
            adjust();
        }

        // Operations
        Time operator+(long n) const {
            Time T = *this;
            T.sec += n;
            T.adjust();
            return T;
        }

        Time operator-(long n) const {
            Time T = *this;
            T.sec -= n;
            T.adjust();
            return T;
        }

        Time operator++() {
            ++sec;
            adjust();
            return *this;
        }

        Time operator--() {
            --sec;
            adjust();
            return *this;
        }

        // Get methods
        int get_hour() const {
            return hour;
        }

        int get_minute() const {
            return min;
        }

        int get_second() const {
            return sec;
        }

        static void ampm() {
            ampm_style = true;
        }

        static void military() {
            ampm_style = false;
        }

        static bool is_ampm() {
            return ampm_style;
        }
};

Time operator+(long n, const Time& T) {
    return T+n;
}

Time operator-(long n, const Time& T) {
    return T-n;
}
    
std::ostream& operator<<(std::ostream& os, const Time& T) {
    long h = T.get_hour();
    long m = T.get_minute();
    long s = T.get_second();

    // am-pm style
    if (T.is_ampm()) {
        if (h == 0) {
            os << 12;
        }
        else if (h > 12) {
            os << h-12;
        }
        else {
            os << h;
        }
        os << ":";
        if (m < 10) os << 0;
        os << m;
        os << ":";
        if (s < 10) os << 0;
        os << s;

        if (h < 12) {
            os << " am";
        }
        else {
            os << " pm";
        }
    }
    // military time
    else {
        os << h << ";";
        if (m < 10) os << 0;
        os << m << ":";
        if (s < 10) os << 0;
        os << s;
    }
    return os;
}

bool Time::ampm_style = true;

#endif