/*
 * Class_Set.cpp
 *
 *  Created on: Mar 11, 2018
 *      Author: Filip
 */

#include <iostream>
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

//Temporary clone of a set for operation's sake
Set::Set (const Set& S)
{
    Name=new char[strlen("@temporary")+1];
    strcpy(Name,"@temporary");
    Elements=new int[2*MAX_INT_VAL];
    for (int i=1; i<2*MAX_INT_VAL; i++)
    {
        *(Elements+i)=*(S.Elements+i);
    }
#ifdef DEBUG
    cout<<"Temporary integer set has been created."<<endl;
#endif
}

//Constructor with initial values for the sake of testing
Set::Set (int num, ...)
{
    Name=new char[strlen("@temporary")+1];
    strcpy(Name,"@temporary");
    Elements=new int[2*MAX_INT_VAL] {};

    if (num>0)
    {
        va_list val;
    va_start(val, num);
    for (int i=0; i<num; i++)
    {
        int el=va_arg(val,int);
        (*(Elements+el+MAX_INT_VAL))++;
    }
    va_end(val);
    }
#ifdef DEBUG
    cout<<"Temporary integer set has been created."<<endl;
#endif
}

/*
//
Set::Set (Set&& S)
{
Name=S.Name;
Elements=S.Elements;
S.Name=nullptr;
S.Elements=nullptr;
#ifdef DEBUG
    cout<<"Temporary integer set has been created."<<endl;
#endif
}
*/

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
#ifdef DEBUG
    cout<<S.Name<<": ";
#else
    if (strcmp(S.Name,"@temporary")) cout<<S.Name<<": ";
#endif
    cout<<"{ ";
    for (int i=1; i<2*MAX_INT_VAL ; i++)
    {
        for (int j=0; j<*(S.Elements+i); j++)
        {
            cout<<i-MAX_INT_VAL<<", ";
        }
    }
    cout<<"}"<<endl;
    return os;
}

//Returning a sum of set and a one-element set
Set Set::operator+ (int i) const
{
Set Tmp(*this);
if (i<100 && i>-100) (*(Tmp.Elements+i+MAX_INT_VAL))++;
else cout<<"Error. Number has too many digits."<<endl;
return Set(move(Tmp));
}

//Adding a number to the set
Set Set::operator+= (int i)
{
if (i<100 && i>-100) (*(Elements+i+MAX_INT_VAL))++;
else cout<<"Error. Number has too many digits."<<endl;
return *this;
}

//Returning a difference of the set and a one-element set
Set Set::operator- (int i) const
{
Set Tmp(*this);
if (i<100 && i>-100)
{
if ((*(Tmp.Elements+i+MAX_INT_VAL))>0) (*(Tmp.Elements+i+MAX_INT_VAL))--;
}
else cout<<"Error. Number has too many digits."<<endl;
return Set(move(Tmp));
}

//Removing a number from set
Set Set::operator-= (int i)
{
if (i<100 && i>-100)
{
if ((*(Elements+i+MAX_INT_VAL))>0) (*(Elements+i+MAX_INT_VAL))--;
}
else cout<<"Error. Number has too many digits."<<endl;
return *this;
}

//Returning a sum of sets
Set Set::operator+ (const Set& B) const
{
    Set Tmp(*this);
    for (int i=1; i<2*MAX_INT_VAL; i++)
    {
        *(Tmp.Elements+i)+=*(B.Elements+i);
    }
    return Set(move(Tmp));
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
    Set Tmp(*this);
    for (int i=1; i<2*MAX_INT_VAL; i++)
    {
    	if (*(Tmp.Elements+i)>*(B.Elements+i)) *(Tmp.Elements+i)-=*(B.Elements+i);
    	else *(Tmp.Elements+i)=0;
    }
    return Set(move(Tmp));
}

//Assigning a set difference to the set
Set& Set::operator-= (const Set &B)
{
    if (this!=&B) *this=(*this-B);
    else
    {
    	for (int i=1; i<2*MAX_INT_VAL; i++) *(Elements+i)=0;
    }
    return *this;
}

//Returning an intersection of sets
Set Set::operator* (const Set &B) const
{
	Set Tmp(*this);
	    for (int i=1; i<2*MAX_INT_VAL; i++)
	    {
	    *(Tmp.Elements+i)=min(*(Tmp.Elements+i),*(B.Elements+i));
	    }
	    return Set(move(Tmp));
}

//Assigning an intersection of sets to the set
Set& Set::operator*= (const Set &B)
{
	if (this!=&B) *this=(*this*B);
    return *this;
}

//Assigning the contents of a set to the set without changing it's name
Set& Set::operator= (const Set &B)
{
	if (this !=&B)
	{
    for (int i=1; i<2*MAX_INT_VAL; i++)
    {
        *(Elements+i)=*(B.Elements+i);
    }
	}
    return *this;
}

/*
//
Set& Set::operator= (Set&& S)
{
	if (this !=&S)
	{
		delete Name;
		delete Elements;
		Name=S.Name;
		Elements=S.Elements;
		S.Name=nullptr;
		S.Elements=nullptr;
	}
	return *this;
}
*/

//comparison of sets' elements
bool Set::operator== (const Set& B) const
{
	if (this !=&B)
		{
	    for (int i=1; i<2*MAX_INT_VAL; i++)
	    {
	        if((*(Elements+i))!=(*(B.Elements+i))) return false;
	    }
		}
	return true;
}
