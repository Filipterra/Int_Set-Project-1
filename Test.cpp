/*
 * Test.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author: Filip Przybysz
 */

#ifdef DEBUG
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "Test.hpp"
#include "Class_Set.hpp"
using namespace std;

#define TABLE_SIZE 100

void Fill_rand(int T[], int n)
{
	srand(time(NULL));
for (int i=0; i<n; i++)
{
	srand(rand());
	T[i]=(rand()%(MAX_INT_VAL*2-1)-MAX_INT_VAL+1);
}
}

//operator =
bool Test0()
{
bool h=0;
int* T=new int[10];
Fill_rand(T,10);
Set& A=*(new Set(10,T[0],T[1],T[2],T[3],T[4],T[5],T[6],T[7],T[8],T[9]));
Set& B=*(new Set(0));
B=A;
if (A==B) h=1;

delete &A;
delete &B;
delete T;

return h;
}

//operator + int
bool Test1()
{
bool h=0;
int* T=new int[10];
Fill_rand(T,10);
Set& A=*(new Set(10,T[0],T[1],T[2],T[3],T[4],T[5],T[6],T[7],T[8],T[9]));
Set& B=*(new Set(0));
for (unsigned int i=0; i<10; i++) B=B+T[i];
if (A==B) h=1;

delete &A;
delete &B;
delete T;

return h;
}

//operator += int
bool Test2()
{
bool h=0;
int* T=new int[TABLE_SIZE];
Fill_rand(T,TABLE_SIZE);
Set& A=*(new Set(0));
Set& B=*(new Set(0));
for (unsigned int i=0; i<TABLE_SIZE; i++) A=A+T[i];
for (unsigned int i=0; i<TABLE_SIZE; i++) B+=T[i];
if (A==B) h=1;

delete &A;
delete &B;
delete T;

return h;
}

//operator + Set
bool Test3()
{
bool h=0;
int* T=new int[TABLE_SIZE];
Fill_rand(T,TABLE_SIZE);
Set& A=*(new Set(0));
Set& B=*(new Set(0));
for (unsigned int i=0; i<TABLE_SIZE; i++) A+=T[i];
B=B+A;
if (A==B) h=1;

delete &A;
delete &B;
delete T;

return h;
}

//operator += Set
bool Test4()
{
bool h=0;
int* T=new int[TABLE_SIZE];
Fill_rand(T,TABLE_SIZE);
Set& A=*(new Set(0));
Set& B=*(new Set(0));
for (unsigned int i=0; i<TABLE_SIZE; i++) A+=T[i];
B+=A;
if (A==B) h=1;

delete &A;
delete &B;
delete T;

return h;
}

//operator - int
bool Test5()
{
bool h=1;
int* T=new int[TABLE_SIZE];
Fill_rand(T,TABLE_SIZE);
Set& A=*(new Set(0));
for (unsigned int i=1; i<MAX_INT_VAL*2; i++) *(A.Elements+i)=1;
for (unsigned int i=0; i<TABLE_SIZE; i++) A=A-T[i];;
for (unsigned int i=0; i<TABLE_SIZE; i++) if (*(A.Elements+T[i]+MAX_INT_VAL)>0) {h=0; break;}

delete &A;
delete T;

return h;
}

//operator -= int
bool Test6()
{
bool h=1;
int* T=new int[TABLE_SIZE];
Fill_rand(T,TABLE_SIZE);
Set& A=*(new Set(0));
for (unsigned int i=1; i<MAX_INT_VAL*2; i++) *(A.Elements+i)=1;
for (unsigned int i=0; i<TABLE_SIZE; i++) A-=T[i];
for (unsigned int i=0; i<TABLE_SIZE; i++) if (*(A.Elements+T[i]+MAX_INT_VAL)>0) {h=0; break;}

delete &A;
delete T;

return h;
}

//operator - Set
bool Test7()
{
bool h=1;
int* T=new int[TABLE_SIZE];
Fill_rand(T,TABLE_SIZE);
Set& A=*(new Set(0));
Set& B=*(new Set(0));
for (unsigned int i=1; i<MAX_INT_VAL*2; i++) *(A.Elements+i)=1;
for (unsigned int i=0; i<TABLE_SIZE; i++) B+=T[i];
A=A-B;
for (unsigned int i=0; i<TABLE_SIZE; i++) if (*(A.Elements+T[i]+MAX_INT_VAL)>0) {h=0; break;}

delete &A;
delete &B;
delete T;

return h;
}

//operator -= Set
bool Test8()
{
bool h=1;
int* T=new int[TABLE_SIZE];
Fill_rand(T,TABLE_SIZE);
Set& A=*(new Set(0));
Set& B=*(new Set(0));
for (unsigned int i=1; i<MAX_INT_VAL*2; i++) *(A.Elements+i)=1;
for (unsigned int i=0; i<TABLE_SIZE; i++) B+=T[i];
A-=B;
for (unsigned int i=0; i<TABLE_SIZE; i++) if (*(A.Elements+T[i]+MAX_INT_VAL)>0) {/*cout<<B<<endl<<T[i]-MAX_INT_VAL<<"="<<*(A.Elements+T[i]-MAX_INT_VAL)<<endl;*/ h=0; break;};

delete &A;
delete &B;
delete T;

return h;
}

//operator * Set
bool Test9()
{
bool h=0;
int* T=new int[TABLE_SIZE];
Fill_rand(T,TABLE_SIZE);
Set& A=*(new Set(0));
Set& B=*(new Set(0));
for (unsigned int i=1; i<MAX_INT_VAL*2; i++) *(A.Elements+i)=TABLE_SIZE+1;
for (unsigned int i=0; i<TABLE_SIZE; i++) B+=T[i];
A=A*B;
if (A==B) h=1;

delete &A;
delete &B;
delete T;

return h;
}

//operator *= Set
bool Test10()
{
bool h=0;
int* T=new int[TABLE_SIZE];
Fill_rand(T,TABLE_SIZE);
Set& A=*(new Set(0));
Set& B=*(new Set(0));
for (unsigned int i=1; i<MAX_INT_VAL*2; i++) *(A.Elements+i)=TABLE_SIZE+1;
for (unsigned int i=0; i<TABLE_SIZE; i++) B+=T[i];
A*=B;
if (A==B) h=1;

delete &A;
delete &B;
delete T;

return h;
}

//calling all test and displaying results
void Test_all()
{
unsigned int TestAmt=11;
bool TestTab[TestAmt];
TestTab[0]=Test0();
TestTab[1]=Test1();	TestTab[2]=Test2();	TestTab[3]=Test3();	TestTab[4]=Test4();	TestTab[5]=Test5();
TestTab[6]=Test6();	TestTab[7]=Test7();	TestTab[8]=Test8();	TestTab[9]=Test9();	TestTab[10]=Test10();
for (unsigned int i=0; i<TestAmt; i++)
{
cout<<"Test"<<i<<" result = "<<TestTab[i]<<endl;
}
}
#endif
