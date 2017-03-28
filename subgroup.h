#ifndef SUBGROUP_H
#define SUBGROUP_H

#include "group.h"

class Subgroup : public Group
{
public:
    Subgroup();
    /*
     * 5 -> Subgroup by 5 course
     * 6 -> Subgroup by 6 course
     * 1 -> Subgroup by 1 course
     * 2 -> Subgroup by 2 course
     * 7 -> Subgroup by female
     * 8 -> Subgroup by male
     * */
    Subgroup(Group _group, int _kindSubgroup);
};

#endif // SUBGROUP_H
