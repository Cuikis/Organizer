#ifndef CHILD_H
#define CHILD_H

#include <iostream>
#include <string>
#include <vector>


class Child
{
public:
    // Constructors
    Child();
    Child(std::string _name, int _course, char _gender);

    // Members
    std::string mName;                                                      // Child's name
    int         mCourse;                                                    // Child's course: 5, 6, 1, 2
    char        mGender;                                                    // Child's gender: M (male) or H (female)

    int         mError;                                                     // If any parameters is not valid, this variable value is 1

    unsigned    maxNameLength = 35;                                         // Maximum length for a name

    int         mID;                                                        // ID of child position in his own subgroup
                                                                            // (Group-> Course -> Gender -> Child ID)
    std::vector<std::vector<std::vector<int> > >   list;               // Contains an ID for each child (look above)

    // Methods
    void showChild();                // Print data
    void partnerCall(int,char,int);  // Updates the list because one partner has been assigned with this child

    void setID(int _ID);
    void setListHigh(int, int, int);
};

#endif // CHILD_H
