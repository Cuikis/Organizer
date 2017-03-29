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

    for( unsigned i=0; i<firstFemale.mChilds.size(); i++)
    {
        std::cout << firstFemale.mChilds[i].mName << "; ID: " << firstFemale.mChilds[i].mID << std::endl;
    }

//    for( unsigned i=0; i<firstFemale.mChilds[0].list.size();i++)
//    {
//        for(unsigned j=0; j<firstFemale.mChilds[0].list[i].size();j++)
//        {
//            for(unsigned k=0; k<firstFemale.mChilds[0].list[i][j].size();k++)
//            {
//                std::cout << "Contador: " << firstFemale.mChilds[0].list[i][j][k] << std::endl;
//            }
//        }
//    }

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
