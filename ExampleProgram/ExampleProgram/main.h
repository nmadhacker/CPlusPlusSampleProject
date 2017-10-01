//
//  main.h
//  ExampleProgram
//
//  Created by nMaD on 9/27/17.
//  Copyright © 2017 nMaD. All rights reserved.
//

#include <string>

class MyCustomClass
{

public:
	void Reset();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	void PrintIntro() const;
    std::string GetValueFromLine();

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};
