//
// Created by SooYeon Kim on 4/2/2018.
//

#include "timespan.h"
#include <iostream>
using namespace std;

// constructor
TimeSpan::TimeSpan(double hours, double minutes, double seconds)
        : hours(hours), minutes(minutes), seconds(seconds) {
    this->hours = 0;
    this->minutes = 0;
    this->seconds = static_cast<int>((hours * 60 * 60) + (minutes * 60)
                                     +seconds);
}

// destructor
TimeSpan::~TimeSpan() {
    // nothing to do
}

// simplify the time not less than 0 and not more than 59
// make 0 < minutes < 59 and 0 < seconds < 59
TimeSpan TimeSpan::simplify() const {
    TimeSpan time = *this;

    while (time.minutes < 0 || time.minutes > 59 || time.seconds < 0 ||
            time.seconds > 59) {
        if (time.minutes < 0) {
            time.hours -= 1;
            time.minutes += 60;
        } else if (time.minutes > 59) {
            time.minutes -= 60;
            time.hours += 1;
        } else if (time.seconds < 0) {
            time.minutes -= 1;
            time.seconds += 60;
        } else if (time.seconds > 59) {
            time.seconds -= 60;
            time.minutes += 1;
        }
    }
    return time;
}

// friend function
// make minutes and seconds to two digits
ostream &operator<<(ostream &out, const TimeSpan &t) {
    TimeSpan simplifiedT = t.simplify();

    if (simplifiedT.seconds == 0) {
        out << simplifiedT.hours << ":" << simplifiedT.minutes << ":" << "00";
        return out;
    } else if (simplifiedT.minutes == 0) {
        out << simplifiedT.hours << ":" << "00" << ":";
        if (simplifiedT.seconds < 10) {
            out << "0" << simplifiedT.seconds;
            return out;
        } else {
            out << simplifiedT.seconds;
            return out;
        }
    } else {
        out << simplifiedT.hours << ":" << simplifiedT.minutes << ":" <<
            simplifiedT.seconds;
        return out;
    }
}

// return true if the times are equal, false otherwise
bool TimeSpan::operator==(const TimeSpan& t) const {
    return (t.seconds == seconds && t.minutes == minutes && t.hours == hours);
}

// return true if the times are different, false otherwise
bool TimeSpan::operator!=(const TimeSpan& t) const {
    return (t.seconds != seconds || t.minutes != minutes || t.hours != hours);
}

// return true if the parameter time is greater than the current object,
// false otherwise
bool TimeSpan::operator>(const TimeSpan& t) const {
    return (t.seconds > seconds && t.minutes > minutes && t.hours > hours);
}

// return true if the parameter time is less than the current object,
// false otherwise
bool TimeSpan::operator<(const TimeSpan& t) const {
    return (t.seconds < seconds && t.minutes < minutes && t.hours < hours);
}

// return true if the parameter time is greater than or equal to
// the current object, false otherwise
bool TimeSpan::operator>=(const TimeSpan& t) const {
    return *this == t || *this > t;
}

// return true if the parameter time is less than or equal to
// the current object, false otherwise
bool TimeSpan::operator<=(const TimeSpan& t) const {
    return *this == t || *this < t;
}

// operator+
// overloaded +:
// addition of 2 times, current object and parameter
TimeSpan TimeSpan::operator+(const TimeSpan &t) const {
    TimeSpan add;

    add.seconds = t.seconds + seconds;
    add.minutes = t.minutes + minutes;
    add.hours = t.hours + hours;
    add.simplify();

    return add;
}

// operator-
// overloaded -:
// subtraction of 2 times, current object and parameter
TimeSpan TimeSpan::operator-(const TimeSpan &t) const {
    TimeSpan sub;

    sub.seconds = seconds - t.seconds;
    sub.minutes = minutes - t.minutes;
    sub.hours = hours - t.hours;
    sub.simplify();

    return sub;
}

// operator*
// overloaded *:
// multiplication of 2 times, current object and parameter
TimeSpan TimeSpan::operator*(const TimeSpan &t) const {
    TimeSpan mult;

    mult.seconds = t.seconds * seconds;
    mult.minutes = t.minutes * minutes;
    mult.hours = t.hours * hours;

    mult.simplify();

    return mult;
}

// operator*
// overloaded *:
// multiplication of 1 time and 1 integer,
// current object time and parameter integer
TimeSpan TimeSpan::operator*(const int num) const {
    TimeSpan result = *this;

    result.seconds *= num;
    result.minutes *= num;
    result.hours *= num;

    return result;
}

// operator+=
// overloaded +=:
// current object = current object + parameter
TimeSpan& TimeSpan::operator+=(const TimeSpan &t) {
    seconds += t.seconds;
    minutes += t.minutes;
    hours += t.hours;

    simplify();

    return *this;
}

// operator-=
// overloaded -=:
// current object = current object - parameter
TimeSpan& TimeSpan::operator-=(const TimeSpan &t) {
    seconds -= t.seconds;
    minutes -= t.minutes;
    hours -= t.hours;

    simplify();

    return *this;
}
