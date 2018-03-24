/*
 * GUI.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: Filip Przybysz
 */

#ifndef DEBUG
#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <ios>
#include <limits>
#include "Class_Set.hpp"
using namespace std;

vector<Set*>SetList;

bool Is_num(string B, int* b) //checking weather the string contains a number from given range
{
	if (!isdigit(B[0]) && B[0]!='-')
		{
		cout<<"Argument not a numeric value."<<endl;
		return false;
		}
	for (unsigned int i=1; i<B.size(); i++)
		{
			if (!isdigit(B[i]))
			{
			cout<<"Argument not a numeric value."<<endl;
			return false;
			}
		}
	*b=stoi(B);
	if (*b<=-100 || *b>=100)
		{
			cout<<"Improper value."<<endl;
			return false;
		}
	return true;
}

bool Find_set(string A, Set** a) //finding a set of given name in SetList
{
	for (unsigned int i=0; i<SetList.size(); i++)
		{
		if (!A.compare(Ret_name(*SetList[i])))
		{
		*a=SetList[i];
		return true;
		}
		}
	return false;
}

void Help()
{
	cout<<"Command structure: 'name of operation' 'left operand' 'right operand'"<<endl<<"Command list:"<<endl;
	cout<<"exit - exits the application (no operands)"<<endl<<"new - creating a new set with given name (only LO)"<<endl;
	cout<<"del - deleting a set with given name (only LO)"<<endl<<"show - displays contents of a set with given name (only LO)"<<endl<<"showsl - displaying the list of existing sets (no operands)"<<endl;
	cout<<"comp - comparing the contents of two sets"<<endl<<"asgn - assigning the contents of a set (RO) to a set (LO)"<<endl;
	cout<<"addi - adding an integer (RO) to a set (LO)"<<endl<<"saddi - showing the result of adding an integer (RO) to a set (LO) without doing it"<<endl;
	cout<<"adds - adding a set (RO) to a set (LO)"<<endl<<"sadds - showing the result of adding a set (RO) to a set (LO) without doing it"<<endl;
	cout<<"subi - subtracting an integer (RO) from a set (LO)"<<endl<<"ssubi - showing the result of subtracting an integer (RO) from a set (LO) without doing it"<<endl;
	cout<<"adds - subtracting a set (RO) from a set (LO)"<<endl<<"sadds - showing the result of subtracting a set (RO) from a set (LO) without doing it"<<endl;
	cout<<"ints - assigning an intersection of a set (RO) and a set (LO) to the set (LO)"<<endl<<"sadds - showing the result of assigning an intersection of a set (RO) and a set (LO) to the set (LO) without doing it"<<endl;
}

bool Menu()
{
	string op,A,B;
	cin>>op;
	if (!op.compare("new")) //creating new sets
		{
		cin>>A;
		cin.ignore(numeric_limits<streamsize>::max(),'\n'); //clearing the buffer
		if(!isalpha(A[0]))
			{
			cout<<"Set's name must begin with a letter."<<endl;
			return true;
			}
			Set* tmp;
			if (Find_set(A,&tmp))
			{
			cout<<"Set's name already taken."<<endl;
			return true;
			}
		SetList.push_back(new Set(A.c_str()));
		return true;
		}

	if (!op.compare("del")) //deleting sets
		{
		cin>>A;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		for (unsigned int i=0; i<SetList.size(); i++)
				{
				if (!A.compare(Ret_name(*SetList[i])))
				{
				delete SetList[i];
				SetList.erase(SetList.begin()+i);
				return true;
				}
				}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("show")) //displaying set's contents
		{
		cin>>A;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		Set* a;
		if (Find_set(A,&a))
		{
		cout<<*a;
		return true;
		}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("comp")) //comparing sets
		{
		cin>>A>>B;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		Set* a=nullptr;
		Set* b=nullptr;
		if (Find_set(A,&a) && Find_set(B,&b))
		{
		(*a==*b) ? cout<<"true"<<endl : cout<<"false"<<endl;
		return true;
		}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("addi")) //adding an integer to the set
		{
		cin>>A>>B;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		int b;
		if (!Is_num(B,&b)) return true;
		Set* a;
		if (Find_set(A,&a))
		{
		*a+=b;
		cout<<*a;
		return true;
		}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("saddi")) //displaying the result of adding an integer to the set
		{
		cin>>A>>B;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		int b;
		if (!Is_num(B,&b)) return true;
		Set* a;
		if (Find_set(A,&a))
		{
		cout<<*a+b;
		return true;
		}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("adds")) //adding contents of R-set to L-set
		{
		cin>>A>>B;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		Set* a=nullptr;
		Set* b=nullptr;
		if (Find_set(A,&a) && Find_set(B,&b))
		{
		*a+=*b;
		cout<<*a;
		return true;
		}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("sadds")) //displaying the result of adding contents of R-set to L-set
		{
		cin>>A>>B;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		Set* a=nullptr;
		Set* b=nullptr;
		if (Find_set(A,&a) && Find_set(B,&b))
		{
		cout<<*a+*b;
		return true;
		}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("asgn")) //assigning contents of R-set to L-set
		{
		cin>>A>>B;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		Set* a=nullptr;
		Set* b=nullptr;
		if (Find_set(A,&a) && Find_set(B,&b))
		{
		*a=*b;
		cout<<*a;
		return true;
		}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("subi")) //removing an integer from the set
		{
		cin>>A>>B;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		int b;
		if (!Is_num(B,&b)) return true;
		Set* a;
		if (Find_set(A,&a))
		{
		*a-=b;
		cout<<*a;
		return true;
		}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("ssubi")) //displaying the result of removing an integer from the set
		{
		cin>>A>>B;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		int b;
		if (!Is_num(B,&b)) return true;
		Set* a;
		if (Find_set(A,&a))
		{
		cout<<*a-b;
		return true;
		}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("subs")) //subtracting the contents of R-set from L-set
		{
		cin>>A>>B;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		Set* a=nullptr;
		Set* b=nullptr;
		if (Find_set(A,&a) && Find_set(B,&b))
		{
		*a-=*b;
		cout<<*a;
		return true;
		}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("ssubs")) //displaying the result of subtracting the contents of R-set from L-set
		{
		cin>>A>>B;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		Set* a=nullptr;
		Set* b=nullptr;
		if (Find_set(A,&a) && Find_set(B,&b))
		{
		cout<<*a-*b;
		return true;
		}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("ints")) //assigning an intersection of R-set and L-set to the L-set
		{
		cin>>A>>B;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		Set* a=nullptr;
		Set* b=nullptr;
		if (Find_set(A,&a) && Find_set(B,&b))
		{
		(*a)*=(*b);
		cout<<*a;
		return true;
		}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("sints")) //displaying the result of intersection of R-set and L-set
		{
		cin>>A>>B;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		Set* a=nullptr;
		Set* b=nullptr;
		if (Find_set(A,&a) && Find_set(B,&b))
		{
		cout<<(*a)*(*b);
		return true;
		}
		cout<<"Non-existing set."<<endl;
		return true;
		}

	if (!op.compare("help")) //showing command list
		{
		Help();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		return true;
		}

	if (!op.compare("showsl")) //showing command list
		{
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		for (unsigned int i=0; i<SetList.size(); i++)
		{
		cout<<Ret_name(*SetList[i])<<"\t";
		}
		cout<<endl;
		return true;
		}

	if (!op.compare("exit")) //exiting the program
		{
		for (unsigned int i=0; i<SetList.size(); i++) delete SetList[i];
		return false;
		}

	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout<<"Unknown command. Please consult the command list by typing in 'help'."<<endl;
	return true;
}
#endif
