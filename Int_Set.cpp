//============================================================================
// Name        : Int_Set.cpp
// Author      : Filip Przybysz
// Tutor	   : Aleksandra Paśnikowska
// Version     :
// Copyright   : Open Source
// Description : Sets of integers complete with operations on them
//============================================================================

#include <iostream>
#include "Class_Set.hpp"
#ifdef _DEBUG
#include "Test.hpp"
#else
#include "GUI.hpp"
#endif
using namespace std;

int main()
{

#ifdef _DEBUG
    Test_all();
#else
    cout<<"Welcome to simple presentation of functionalities of a class emulating an integer set."<<endl<<"Type in 'help' for command list."<<endl;
    while (Menu());
#endif

    return 0;
}
