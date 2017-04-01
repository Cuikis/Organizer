#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>

#include "group.h"
#include "subgroup.h"
#include "child.h"

/* Divides the group received in 4 subgroups, one for course,
 * and each of these in 2 subgroups, male and female.
 *
 * Then generates a list to keep track of who child has been
 * associated with another, and fills it with zeros (means
 * noone has been matched) except for the position of a child
 * himself/herself (in order to not be linked to himself/herself)
 */
void    allocate(Group);


/* Generates a list depends of the childs in the following way:
 *
 * vector of course:
 * vector[0] -> 5
 * vector[1] -> 6
 * vector[2] -> 1
 * vector[3] -> 2
 *
 * Then, each element of this previous vector contains
 * a two-components vector, in the following way:
 *
 * vector[0][0] -> 5 female
 * vector[0][1] -> 5 male
 *
 * Lastly, each of these two-components vector has
 * an integer number for each child of the group to
 * count how many times the owner of the list has
 * been associated with him
 */
std::vector<std::vector<std::vector<int> > >    generateList(Subgroup fifthFemale,Subgroup fifthMale,Subgroup sixthFemale, Subgroup sixthMale,
                                                             Subgroup firstFemale,Subgroup firstMale,Subgroup secondFemale,Subgroup secondMale);


// Assign the list to each child of the subgroup
void    assignList(std::vector<std::vector<std::vector<int> > >,Subgroup&);


/* Set a high number in the position of the list that
 * correspond with the own child
 */
void    invalidateMe(Subgroup &);



// Gives every child his own ID number of the final vector of the list
void    assignID(Subgroup &);


// Assigns the list, invalidate each one and gives his ID number too
void    assignment(Subgroup &fifthFemale, Subgroup &fifthMale, Subgroup &sixthFemale, Subgroup &sixthMale,
                   Subgroup &firstFemale, Subgroup &firstMale, Subgroup &secondFemale, Subgroup &secondMale,
                   std::vector<std::vector<std::vector<int> > >);


// Creates as many groups as the given value
std::vector<Group>  generateGroups(unsigned int _numberOfGroup,
                                   Subgroup fifthFemale,Subgroup fifthMale,
                                   Subgroup sixthFemale,Subgroup sixthMale,
                                   Subgroup firstFemale,Subgroup firstMale,
                                   Subgroup secondFemale,Subgroup secondMale);



// Calculates how many childs per group must be
std::vector<int>  childsPerGroup(int _totalChilds, unsigned int _numberOfGroup);

#endif // FUNCTIONS_H
