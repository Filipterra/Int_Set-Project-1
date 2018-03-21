/*
 * Class_Set.cpp
 *
 *  Created on: Mar 11, 2018
 *      Author: Filip
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdarg.h>
#include "Class_Set.hpp"
using namespace std;

//Creating a new set by user
Set::Set (const char* nam)
{
    Name=new char[strlen(nam)+1];
    strcpy(Name,nam);
    Elements=new int[2*MAX_INT_VAL] {};
    cout<<"Integer set "<<this->Name<<" has been added."<<endl;
}

//Creating a temporary set used in adding new elements
Set::Set (const Set& S)
{
    Name=new char[strlen("@temporary")+1];
    strcpy(Name,"@temporary");
    Elements=new int[2*MAX_INT_VAL];
    for (int i=0; i<2*MAX_INT_VAL; i++)
    {
        *(Elements+i)=*(S.Elements+i);
    }
#ifdef DEBUG
    cout<<"Temporary integer set has been created."<<endl;
#endif
}

//Creating a temporary set used in operations on sets
Set::Set (int num, ...)
{
    Name=new char[strlen("@temporary")+1];
    strcpy(Name,"@temporary");
    Elements=new int[2*MAX_INT_VAL] {};

    va_list val;
    va_start(val, num);
    for (int i=0; i<num; i++)
    {
        int el=va_arg(val,int);
        (*(Elements+el+MAX_INT_VAL))++;
    }
    va_end(val);
#ifdef DEBUG
    cout<<"Temporary integer set has been created."<<endl;
#endif
}

//Cleaning after the set
Set::~Set()
{
#ifdef DEBUG
    cout<<"Integer set "<<Name<<" has been destroyed."<<endl;
#else
    if (strcmp(Name,"@temporary")) cout<<"Integer set "<<Name<<" has been destroyed."<<endl;
#endif
    delete Name;
    delete Elements;
}

//Displaying set's properties
ostream& operator<< (std::ostream &os, const Set& S)
{
    cout<<S.Name<<": {";
    for (int i=0; i<2*MAX_INT_VAL ; i++)
    {
        for (int j=0; j<*(S.Elements+i); j++)
        {
            cout<<" "<<i-MAX_INT_VAL;
        }
    }
    cout<<"}"<<endl;
    return os;
}
/*
//Adding a number to set
Set Set::operator+ (int i) const
{
if (i<100 && i>-100) (*(Elements+i+MAX_INT_VAL))++;
else cout<<"Error. Number has too many digits."<<endl;
}

//Removing a numer from set
Set Set::operator- (int i) const
{
if (i<100 && i>-100)
{
if ((*(Elements+i+MAX_INT_VAL))>0) (*(Elements+i+MAX_INT_VAL))--;
}
else cout<<"Error. Number has too many digits."<<endl;
}

//Returning a sum of sets
Set Set::operator+ (const Set& B) const
{
    Set Tmp(0);
    for (int i=0; i<2*MAX_INT_VAL; i++)
    {
        *(Tmp.Elements+i)+=*(B.Elements+i);
    }
    const Set& rtmp=Tmp;
    return Set(rtmp);
}
//Assigning a sum of sets to the set
Set& Set::operator+= (const Set &B)
{
    *this=(*this+B);
    return *this;
}

//Returning a set difference
Set Set::operator- (const Set &B) const
{
    vector<int> Tmp=this->Elements;
    for (unsigned int i=0; i<B.Elements.size(); i++)
    {
        for (unsigned int j=0; j<Tmp.size() && Tmp[j]<=B.Elements[i]; j++)
        {
            if (Tmp[j]==B.Elements[i])
            {
                Tmp.erase(Tmp.begin()+j); //erasing elements from copy of set A if they belong to set B
                break;
            }
        }
    }
    return Set(Tmp);
}

//Assigning a set difference to the set
Set& Set::operator-= (const Set &B)
{
    *this=(*this-B);
    return *this;
}

//Returning an intersection of sets
Set Set::operator* (const Set &B) const
{
    vector<int> Tmp;
    for (unsigned int i=0; i<B.Elements.size(); i++)
    {
        for (unsigned int j=0; j<this->Elements.size() && this->Elements[j]<=B.Elements[i]; j++)
        {
            if (this->Elements[j]==B.Elements[i])
            {
                Tmp.push_back(B.Elements[i]); //adding elements to temporary set if they belong to both sets
            }
        }
    }
    return Set(Tmp);
}

//Assigning an intersection of sets to the set
Set& Set::operator*= (const Set &B)
{
    *this=(*this*B);
    return *this;
}
*/
//Assigning the contents of a set to the set without changing it's name
Set& Set::operator= (const Set &B)
{
    for (int i=0; i<2*MAX_INT_VAL; i++)
    {
        *(Elements+i)=*(B.Elements+i);
    }
    return *this;
}
