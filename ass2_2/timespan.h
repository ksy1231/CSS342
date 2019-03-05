//
// Created by SooYeon Kim on 4/24/2018.
//

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>

using namespace std;

class TimeSpan {
    friend ostream& operator<<(ostream &out, const TimeSpan &ts);
public:
    // Constructor
    TimeSpan(double hours = 0.0, double minutes = 0, double seconds = 0);

    // Destructor
    ~TimeSpan();

    // Checks if two TimeSpans are equal
    // return true for equal, false for unequal
    bool operator==(const TimeSpan &ts) const;

    // Checks if two TimeSpans are unequal
    // return true for unequal, false for equal
    bool operator!=(const TimeSpan &ts) const;

    // Checks if given TimeSpan is greater than compared TimeSpan
    // return true for greater, false otherwise
    bool operator>(const TimeSpan &ts) const;

    // Checks if given TimeSpan is less than compared TimeSpan
    // return true for less, false otherwise
    bool operator<(const TimeSpan &ts) const;

    // Checks if given TimeSpan is greater than or equal to compared TimeSpan
    // return true for greater or equal, false otherwise
    bool operator>=(const TimeSpan &ts) const;

    // Checks if given TimeSpan is less than or equal to compared TimeSpan
    // return true for less than or equal, false otherwise
    bool operator<=(const TimeSpan &ts) const;

    // Creates and returns a new TimeSpan that is the sum of the two TimeSpans
    TimeSpan operator+(const TimeSpan &ts) const;

    // Creates and returns a new TimeSpan that
    // is the difference of the two TimeSpans
    TimeSpan operator-(const TimeSpan &ts) const;

    // Add a TimeSpan to given TimeSpan
    // returns the added TimeSpan
    TimeSpan &operator+=(const TimeSpan &ts);

    // Subtract a TimeSpan to given TimeSpan
    // returns the subtracted TimeSpan
    TimeSpan &operator-=(const TimeSpan &ts);

    // Multiplies a number to given TimeSpan
    // returns the multiplied TimeSpan
    TimeSpan operator*(const int &num);

private:
    // Hours in TimeSpan
    double hours;
    // Minutes in TimeSpan
    double minutes;
    // Seconds in TimeSpan
    double seconds;
    // Total number of Seconds in TimeSpan
    int totalSeconds;
    // Modifies a TimeSpan to a correct format of TimeSpan
    TimeSpan &simplify();
};


#endif //ASS2_TIMESPAN_H
