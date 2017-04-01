#include "functions.h"

void    allocate(Group _group)
{
    // Creates the four cuorse subgroup
    Subgroup fifth(_group,5);
    Subgroup sixth(_group,6);
    Subgroup first(_group,1);
    Subgroup second(_group,2);


    // Then the two gender subgroup for each course subgroup
    Subgroup fifthFemale(fifth,7);
    Subgroup fifthMale(fifth,8);

    Subgroup sixthFemale(sixth,7);
    Subgroup sixthMale(sixth,8);

    Subgroup firstFemale(first,7);
    Subgroup firstMale(first,8);

    Subgroup secondFemale(second,7);
    Subgroup secondMale(second,8);

    // Generates the list
    std::vector<std::vector<std::vector<int> > > list = generateList(fifthFemale,fifthMale,sixthFemale,sixthMale,
                                                                     firstFemale,firstMale,secondFemale,secondMale);

    assignment(fifthFemale,fifthMale,sixthFemale,sixthMale,
               firstFemale,firstMale,secondFemale,secondMale,list);
}



std::vector<std::vector<std::vector<int> > >    generateList(Subgroup fifthFemale,Subgroup fifthMale,Subgroup sixthFemale, Subgroup sixthMale,
                                                             Subgroup firstFemale,Subgroup firstMale,Subgroup secondFemale,Subgroup secondMale)
{
    // Generates the big list that contains all childs ID
    std::vector<std::vector<std::vector<int> > > list;

    std::vector<std::vector<int> >  aux5;
    std::vector<std::vector<int> >  aux6;
    std::vector<std::vector<int> >  aux1;
    std::vector<std::vector<int> >  aux2;

    std::vector<int>    auxFemale5;
    std::vector<int>    auxMale5;

    std::vector<int>    auxFemale6;
    std::vector<int>    auxMale6;

    std::vector<int>    auxFemale1;
    std::vector<int>    auxMale1;

    std::vector<int>    auxFemale2;
    std::vector<int>    auxMale2;



    // Fills it with the proper amount of zeros
    // Fifth Female
    for( unsigned i = 0; i<fifthFemale.mChilds.size(); i++ )
    {
        auxFemale5.push_back(0);
    }

    // Fifth Male
    for( unsigned i = 0; i<fifthMale.mChilds.size(); i++ )
    {
        auxMale5.push_back(0);
    }

    aux5.push_back(auxFemale5);
    aux5.push_back(auxMale5);


    // Sixth Female
    for( unsigned i = 0; i<sixthFemale.mChilds.size(); i++ )
    {
        auxFemale6.push_back(0);
    }

    // Sixth Male
    for( unsigned i = 0; i<sixthMale.mChilds.size(); i++ )
    {
        auxMale6.push_back(0);
    }

    aux6.push_back(auxFemale6);
    aux6.push_back(auxMale6);


    // First Female
    for( unsigned i = 0; i<firstFemale.mChilds.size(); i++ )
    {
        auxFemale1.push_back(0);
    }

    // First Male
    for( unsigned i = 0; i<firstMale.mChilds.size(); i++ )
    {
        auxMale1.push_back(0);
    }

    aux1.push_back(auxFemale1);
    aux1.push_back(auxMale1);


    // Second Female
    for( unsigned i = 0; i<secondFemale.mChilds.size(); i++ )
    {
        auxFemale2.push_back(0);
    }

    // Second Male
    for( unsigned i = 0; i<secondMale.mChilds.size(); i++ )
    {
        auxMale2.push_back(0);
    }

    aux2.push_back(auxFemale2);
    aux2.push_back(auxMale2);


    // Finally, the list
    list.push_back(aux5);
    list.push_back(aux6);
    list.push_back(aux1);
    list.push_back(aux2);

    return list;

}



void    assignList(std::vector<std::vector<std::vector<int> > > list, Subgroup &subgroup)
{
    for( unsigned i=0; i<subgroup.mChilds.size(); i++ )
    {
        subgroup.mChilds[i].list = list;
    }
}



void    assignID(Subgroup &subgroup)
{
    for( int i=0; (unsigned)i<subgroup.mChilds.size(); i++)
    {
        subgroup.mChilds[i].setID(i);
    }
}



void    assignment(Subgroup &fifthFemale, Subgroup &fifthMale, Subgroup &sixthFemale, Subgroup &sixthMale,
                   Subgroup &firstFemale, Subgroup &firstMale, Subgroup &secondFemale, Subgroup &secondMale,
                   std::vector<std::vector<std::vector<int> > > list)
{
    // Assigns the list to each child
    assignList(list,fifthFemale);
    assignList(list,fifthMale);

    assignList(list,sixthFemale);
    assignList(list,sixthMale);

    assignList(list,firstFemale);
    assignList(list,firstMale);

    assignList(list,secondFemale);
    assignList(list,secondMale);


    // Assigns their ID to each child
    assignID(fifthFemale);
    assignID(fifthMale);

    assignID(sixthFemale);
    assignID(sixthMale);

    assignID(firstFemale);
    assignID(firstMale);

    assignID(secondFemale);
    assignID(secondMale);

    // Invalidates each child himself
    invalidateMe(fifthFemale);
    invalidateMe(fifthMale);

    invalidateMe(sixthFemale);
    invalidateMe(sixthMale);

    invalidateMe(firstFemale);
    invalidateMe(firstMale);

    invalidateMe(secondFemale);
    invalidateMe(secondMale);

}



void    invalidateMe(Subgroup &subgroup)
{
    if( subgroup.mChilds.empty() )
    {
        return;
    }

    int course,gender,ID;

    switch (subgroup.mChilds[0].mCourse)
    {
    case 5:
        course = 0;
        break;
    case 6:
        course = 1;
        break;
    case 1:
        course = 2;
        break;
    case 2:
        course = 3;
        break;
    }

    if( subgroup.mChilds[0].mGender == 'H' || subgroup.mChilds[0].mGender == 'h' )
    {
        gender = 0;
    }
    else
    {
        gender = 1;
    }

    for( unsigned i=0; i<subgroup.mChilds.size(); i++)
    {
        ID = subgroup.mChilds[i].mID;
        subgroup.mChilds[i].setListHigh(course,gender,ID);
    }
}



std::vector<Group>  generateGroups(unsigned int _numberOfGroup,
                                   Subgroup fifthFemale, Subgroup fifthMale,
                                   Subgroup sixthFemale, Subgroup sixthMale,
                                   Subgroup firstFemale, Subgroup firstMale,
                                   Subgroup secondFemale, Subgroup secondMale)
{
    // Return value
    std::vector<Group>  groups;

    // Amount of childs in each subgroup
    int number5female   = fifthFemale.mChilds.size();
    int number5male     = fifthMale.mChilds.size();

    int number6female   = sixthFemale.mChilds.size();
    int number6male     = sixthMale.mChilds.size();

    int number1female   = firstFemale.mChilds.size();
    int number1male     = firstMale.mChilds.size();

    int number2female   = secondFemale.mChilds.size();
    int number2male     = secondMale.mChilds.size();

    // Total female and male childs
    int totalFemale = number5female + number6female +
                      number1female + number2female;

    int totalMale = number5male + number6male +
                      number1male + number2male;

    // Total 5, 6, 1 and 2 childs
    int total5 = number5female + number5male;
    int total6 = number6female + number6male;
    int total1 = number1female + number1male;
    int total2 = number2female + number2male;

    // Total childs
    int totalChilds = number5female + number5male + number6female + number6male +
                      number1female + number1male + number2female + number2male;

    std::vector<int> childsGroup = childsPerGroup(totalChilds,_numberOfGroup);



    return groups;
}


std::vector<int>  childsPerGroup(int _totalChilds,unsigned int _numberOfGroup)
{
    /* Number of childs in each group:
     * Example: we have 10 childs and want 3 groups
     *
     * 1) Integer part -> 10/3 = 3
     * 2) Remainder    -> 10%3 = 1
     * 3) Form a three-components vector with these values
     *    vector[0] = 4 -> means in the first group there are 4 childs
     *    vector[1] = 3 -> the second group has 3 childs
     *    vector[2] = 3 -> the third group has 3 childs too
     */
    int integerPart = _totalChilds/_numberOfGroup;

    int remainder   = _totalChilds%_numberOfGroup;

    std::vector<int> childsPerGroup;

    for( unsigned i = 0; i<_numberOfGroup; i++)
    {
        childsPerGroup.push_back(integerPart);
    }

    while( remainder > 0 )
    {
        for( unsigned i=0; i<_numberOfGroup && remainder > 0; i++, remainder--)
        {
            childsPerGroup[i]++;
        }
    }

    return childsPerGroup;
}
