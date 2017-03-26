#ifndef CHILD_H
#define CHILD_H

#include <iostream>
#include <string>


class Child
{
public:
    // Constructors
    Child();
    Child(std::string _name, int _course, char _gender);

    // Members
    std::string mName;      // Child's name
    int         mCourse;    // Child's course: 5, 6, 1, 2
    char        mGender;    // Child's gender: M (male) or H (female)

    int         mError;     // If any parameters is not valid, this variable value is 1

    unsigned    maxNameLength = 35; // Maximum length for a name

    // Methods
    void showChild();       // Print data
};

#endif // CHILD_H
