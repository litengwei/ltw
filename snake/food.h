#pragma once

#include "cunit.h"
#include<vector>
#include<ctime>
#include<stdlib.h>
class cfood :
	public cunit
{
public:
	void food(int x = 0, int y = 0, char pic = '#');
	virtual ~cfood();
	void createpos();
};

