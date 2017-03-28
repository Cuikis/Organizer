#include "subgroup.h"

Subgroup::Subgroup()
{
}

Subgroup::Subgroup(Group _group, int _kindSubgroup)
{
    switch(_kindSubgroup)
    {
    case 1:
        this->mGroupName = _group.mGroupName + "->" + std::string("Primero");
        for( unsigned i=0; i<_group.mChilds.size(); i++)
        {
            if( _group.mChilds[i].mCourse == 1 )
            {
                this->mChilds.push_back(_group.mChilds[i]);
            }
        }
        break;
    case 2:
        this->mGroupName = _group.mGroupName + "->" + std::string("Segundo");
        for( unsigned i=0; i<_group.mChilds.size(); i++)
        {
            if( _group.mChilds[i].mCourse == 2 )
            {
                this->mChilds.push_back(_group.mChilds[i]);
            }
        }
        break;
    case 5:
        this->mGroupName = _group.mGroupName + "->" + std::string("Quinto");
        for( unsigned i=0; i<_group.mChilds.size(); i++)
        {
            if( _group.mChilds[i].mCourse == 5 )
            {
                this->mChilds.push_back(_group.mChilds[i]);
            }
        }
        break;
    case 6:
        this->mGroupName = _group.mGroupName + "->" + std::string("Sexto");
        for( unsigned i=0; i<_group.mChilds.size(); i++)
        {
            if( _group.mChilds[i].mCourse == 6 )
            {
                this->mChilds.push_back(_group.mChilds[i]);
            }
        }
        break;
    case 7:
        this->mGroupName = _group.mGroupName + "->" + std::string("Hembras");
        for( unsigned i=0; i<_group.mChilds.size(); i++)
        {
            if( _group.mChilds[i].mGender == 'H' || _group.mChilds[i].mGender == 'h' )
            {
                this->mChilds.push_back(_group.mChilds[i]);
            }
        }
        break;
    case 8:
        this->mGroupName = _group.mGroupName + "->" + std::string("Machos");
        for( unsigned i=0; i<_group.mChilds.size(); i++)
        {
            //std::cout << "Entro en caso M" << std::endl;
            if( _group.mChilds[i].mGender == 'M' || _group.mChilds[i].mGender == 'm' )
            {
                //std::cout << "Entro en coincidencia de genero" << std::endl;
                this->mChilds.push_back(_group.mChilds[i]);
            }
        }
        break;
    }
}
