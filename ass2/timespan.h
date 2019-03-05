//
// Created by SooYeon Kim on 4/2/2018.
//

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>
using namespace std;

class TimeSpan {
private:
    int hours, minutes, seconds;
    // simplify the time not less than 0 and not more than 59
    // make 0 < minutes < 59 and 0 < seconds < 59
    TimeSpan simplify() const;
public:
    // constructor
    TimeSpan(double hours = 0, double minutes = 0, double seconds = 0);
    // destructor
    ~TimeSpan();

    // friend function
    // make minutes and seconds to two digits
    friend ostream &operator<<(ostream &out, const TimeSpan &t);

    // return true if the times are equal, false otherwise
    bool operator==(const TimeSpan& t) const;
    // return true if the times are different, false otherwise
    bool operator!=(const TimeSpan& t) const;
    // return true if the parameter time is greater than the current object,
    // false otherwise
    bool operator>(const TimeSpan& t) const;
    // return true if the parameter time is less than the current object,
    // false otherwise
    bool operator<(const TimeSpan& t) const;
    // return true if the parameter time is greater than or equal to
    // the current object, false otherwise
    bool operator>=(const TimeSpan& t) const;
    // return true if the parameter time is less than or equal to
    // the current object, false otherwise
    bool operator<=(const TimeSpan& t) const;

    // Op Overloads
    TimeSpan operator+(const TimeSpan &t) const;
    TimeSpan operator-(const TimeSpan &t) const;
    TimeSpan operator*(const TimeSpan &t) const;
    TimeSpan operator*(const int num) const;
    TimeSpan& operator+=(const TimeSpan &t);
    TimeSpan& operator-=(const TimeSpan &t);
};

#endif //ASS2_TIMESPAN_H
