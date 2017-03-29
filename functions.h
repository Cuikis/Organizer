#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>

#include "group.h"
#include "subgroup.h"
#include "child.h"

void    allocate(Group);

std::vector<std::vector<std::vector<int> > >    generateList(Subgroup fifthFemale,Subgroup fifthMale,Subgroup sixthFemale, Subgroup sixthMale,
                                                             Subgroup firstFemale,Subgroup firstMale,Subgroup secondFemale,Subgroup secondMale);

void    assignList(std::vector<std::vector<std::vector<int> > >,Subgroup&);

void    invalidateMe(Subgroup &);

void    assignID(Subgroup &);

void    assignment(Subgroup &fifthFemale, Subgroup &fifthMale, Subgroup &sixthFemale, Subgroup &sixthMale,
                   Subgroup &firstFemale, Subgroup &firstMale, Subgroup &secondFemale, Subgroup &secondMale,
                   std::vector<std::vector<std::vector<int> > >);

#endif // FUNCTIONS_H
