//
// Created by SooYeon Kim on 4/24/2018.
//

#include "timespan.h"
#include <iomanip>

// returns the TimeSpan in 00:00:00 format
ostream &operator<<(ostream &out, const TimeSpan &ts) {
    out << ts.hours << ":" << std::setw(2) << std::setfill('0')
        << ts.minutes << ":" << std::setw(2) << std::setfill('0') << ts.seconds;
    return out;
}

// Constructor
TimeSpan::TimeSpan(double hours, double minutes, double seconds)
        : hours {hours}, minutes {minutes}, seconds {seconds} {
    (*this).simplify();
}

// Destructor
TimeSpan::~TimeSpan() {}

// Checks if two TimeSpans are equal
// return true for equal, false for unequal
bool TimeSpan::operator==(const TimeSpan &ts) const {
    return (hours == ts.hours && minutes == ts.minutes &&
            seconds == ts.seconds);
}

// Checks if two TimeSpans are unequal
// return true for unequal, false for equal
bool TimeSpan::operator!=(const TimeSpan &ts) const {
    return !(*this == ts);
}

// Checks if given TimeSpan is greater than compared TimeSpan
// return true for greater, false otherwise
bool TimeSpan::operator>(const TimeSpan &ts) const {
    return totalSeconds > ts.totalSeconds;
}

// Checks if given TimeSpan is less than compared TimeSpan
// return true for less, false otherwise
bool TimeSpan::operator<(const TimeSpan &ts) const {
    return totalSeconds < ts.totalSeconds;
}

// Checks if given TimeSpan is greater than or equal to compared TimeSpan
// return true for greater or equal, false otherwise
bool TimeSpan::operator>=(const TimeSpan &ts) const {
    return totalSeconds >= ts.totalSeconds;
}

// Checks if given TimeSpan is less than or equal to compared TimeSpan
// return true for less than or equal, false otherwise
bool TimeSpan::operator<=(const TimeSpan &ts) const {
    return totalSeconds <= ts.totalSeconds;
}

// Creates and returns a simplified new TimeSpan that
// is the sum of the two TimeSpans
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const {
    TimeSpan sum;
    sum.hours = (hours + ts.hours);
    sum.minutes = (minutes + ts.minutes);
    sum.seconds = (seconds + ts.seconds);
    return sum.simplify();
}

// Creates and returns a simplified new TimeSpan that
// is the difference of the two TimeSpans
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const {
    TimeSpan diff;
    diff.hours = (hours - ts.hours);
    diff.minutes = (minutes - ts.minutes);
    diff.seconds = (seconds - ts.seconds);
    return diff.simplify();
}

// Add a TimeSpan to given TimeSpan
// returns the added TimeSpan
TimeSpan &TimeSpan::operator+=(const TimeSpan &ts) {
    hours += ts.hours;
    minutes += ts.minutes;
    seconds += ts.seconds;
    return (*this).simplify();
}

// Subtract a TimeSpan to given TimeSpan
// returns the subtracted TimeSpan
TimeSpan &TimeSpan::operator-=(const TimeSpan &ts) {
    hours -= ts.hours;
    minutes -= ts.minutes;
    seconds -= ts.seconds;
    return (*this).simplify();
}

// Multiplies a number to given TimeSpan
// returns the multiplied TimeSpan
TimeSpan TimeSpan::operator*(const int &num)  {
    TimeSpan product;
    product.hours = hours * num;
    product.minutes = minutes * num;
    product.seconds = seconds * num;
    return product.simplify();
}

// Modifies a TimeSpan to a correct format of TimeSpan
TimeSpan &TimeSpan::simplify() {
    totalSeconds = static_cast<int>(seconds + (minutes * 60)
                                    + (hours * 60 * 60));
    seconds = totalSeconds % 60;
    minutes = (totalSeconds / 60) % 60;
    hours = (totalSeconds / 60) / 60;
    return (*this);
}
