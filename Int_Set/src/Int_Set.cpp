//============================================================================
// Name        : Int_Set.cpp
// Author      : Filip Przybysz
// Version     :
// Copyright   : Open Source
// Description : Sets of integers complete with operations on them
//============================================================================

#include <iostream>
#include "Class_Set.hpp"
using namespace std;

int main() {
	cout<<"Test."<<endl;
	Set A("A");
	A+=0;
	cout<<A;
	A+=1;
	cout<<A;
	A+=2;
	cout<<A;
	A=A+3+4+100;
	cout<<A;
	Set B("B");
	B=A;
	cout<<B;
	B-=3;
	B-=6;
	cout<<B;
	A+=B;
	cout<<A;
	A-=B;
	cout<<A;
	Set C("C");
	C=C+0+2+4+6+8+9+5;
	Set D("D");
	D=D+1+3+5+7+9;
	cout<<C<<D;
	C*=D;
	cout<<C;
	return 0;
}
