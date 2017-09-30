//
//  main.cpp
//  ExampleProgram
//
//  Created by nMaD on 9/27/17.
//  Copyright © 2017 nMaD. All rights reserved.
//

#include <iostream>
#include <string>
#include "main.h"

using namespace std;

struct superStruct {
    int name;
};

// entry point of this app
int main()
{
    MyCustomClass::PrintIntro();
    
    superStruct myStruct;
    superStruct *ptr; ptr = &myStruct;
    
    myStruct.name = 5;
    ptr->name = 10;
    
    cout << myStruct.name << "\n\n";
    
    constexpr int TOTAL_RETRY = 5;
    string MyString = "";
    int index = 0;
    while(index < TOTAL_RETRY)
    {
        cout << "Two and two are? ";
        MyString = MyCustomClass::GetValueFromLine();
        cout << "You entered: " << MyString << endl;
        index++;
    }
    
    return 0;
}

void MyCustomClass::PrintIntro()
{
    constexpr int MY_CONSTANT = 10;
    cout << "Welcome to my app" << endl;
    cout << "Today's value is: " << MY_CONSTANT << "\n";
}

string MyCustomClass::GetValueFromLine()
{
    string ToReturn;
    getline(cin,ToReturn);
    return  ToReturn;
}


