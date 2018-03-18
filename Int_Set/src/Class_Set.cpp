/*
 * Class_Set.cpp
 *
 *  Created on: Mar 11, 2018
 *      Author: filip
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "Class_Set.hpp"
using namespace std;

//Creating a new set by user
Set::Set (std::string name)
{
	Name=name;
    cout<<"Integer set "<<name<<" has been added."<<endl;
}

//Creating a temporary set used in adding new elements
Set::Set (int a)
{
    if (a<100)
    {
    	Name="temporary";
        Elements.push_back(a);
        cout<<"Temporary integer set has been created."<<endl;
    }
    else
    {
        cout<<"Error. Element exceeds maximum value and therefore has not been added."<<endl;
    }
}

//Creating a temporary set used in operations on sets
Set::Set (vector<int> T)
{
		Name="temporary";
		Elements=T;
		cout<<"Temporary integer set has been created."<<endl;
}

//Cleaning after the set
Set::~Set()
{
    Elements.clear();
    cout<<"Integer set "<<Name<<" has been destroyed."<<endl;
    Name.clear();
}

//Displaying set's properties
ostream& operator<< (std::ostream &os, const Set& S)
{
	cout<<S.Name<<":";
    if (!(S.Elements.empty()))
    {
        for (unsigned int i=0; i<S.Elements.size(); i++)
        {
            os<<" "<<S.Elements[i];
        }
        os<<endl;
    }
    else cout<<"Empty set."<<endl;
    return os;
}

//Returning a sum of sets
Set Set::operator+ (const Set& B) const
{
    vector<int> Tmp=this->Elements;
    Tmp.insert(Tmp.end(),B.Elements.begin(),B.Elements.end());
    sort (Tmp.begin(),Tmp.end());
    return Set(Tmp);
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
    Tmp.resize(Tmp.size());
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
    Tmp.resize(Tmp.size());
    return Set(Tmp);
}

//Assigning an intersection of sets to the set
Set& Set::operator*= (const Set &B)
{
	*this=(*this*B);
    return *this;
}

//Assigning the contents of a set to the set without changing it's name
Set& Set::operator= (const Set &B)
{
	this->Elements=B.Elements;
	return *this;
}
