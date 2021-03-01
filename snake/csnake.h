#pragma once
#include "food.h"
#include<vector>
#include"cunit.h"
#include<iostream>
using namespace std;
typedef enum 
{
	UP,DOWN,LEFT,RIGHT
}directions;
class csnake
{
public:
	csnake(int x = 20, int y = 10, int lenth = 4, directions direction = RIGHT, int speed =300, char pic = '*');
	virtual ~csnake();	
	void changedirection(int vkvalue);
	void move();
	bool eatfood(cfood *pfood);
	void showsnake();
	void erasesnake();
	void growup();
public:
	int m_ilength;
	int m_iheadx;
	int m_iheady;
	int m_ispeed;
	int m_cpic;
	int lx;
	int ly;
	directions m_direction;
	vector<cunit>m_vecbody;
};

