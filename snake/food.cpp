#include "food.h"
#include <iostream>
using namespace std;
void cfood::createpos()
{
		srand((unsigned)time(0));
		m_x = 6 + rand() % 104;
		m_y = 4 + rand() % 26;
		show();

}
void cfood::food(int x,int y,char pic)
{

}
cfood::~cfood()
{

}

