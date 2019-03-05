//
// Created by SooYeon Kim on 5/26/2018.
//

#ifndef ASS5_6_PERSON_H
#define ASS5_6_PERSON_H

#include <string>

class Person
{
private:
    std::string firstName;
    std::string lastName;

    void setUnknownName();


public:
    Person();
    Person(const std::string firstName, const std::string lastName);
    virtual ~Person();
    const std::string getFirstName() const;
    void setFirstName(const std::string firstName);
    const std::string getLastName() const;
    void setLastName(const std::string lastName);

};

#endif //ASS5_6_PERSON_H
