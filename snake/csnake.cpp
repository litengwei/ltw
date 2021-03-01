#include "csnake.h"
#include <conio.h>
using namespace std;
csnake::csnake(int x, int y, int lenth, directions direction , int speed, char pic)
{
	m_iheadx = x;
	m_iheady = y;
	m_ilength = lenth;
	m_ispeed = speed;
	m_cpic = pic;
	m_direction =direction;
	for (int i = 0; i < m_ilength; i++)
	{
		cunit dunit(0, 0, '*');
		m_vecbody.push_back(dunit);
		switch (direction)
		{
		case UP:
			m_vecbody[i].m_x = m_iheadx ;
			m_vecbody[i].m_y = m_iheady+i;
			break;
		case RIGHT:
			m_vecbody[i].m_x = m_iheadx-i;
			m_vecbody[i].m_y = m_iheady;
			break;
		case DOWN:
			m_vecbody[i].m_x = m_iheadx;
			m_vecbody[i].m_y = m_iheady-i;
			break;
		case LEFT:
			m_vecbody[i].m_x = m_iheadx +i;
			m_vecbody[i].m_y = m_iheady;
			break;
		}
	}
}
void csnake::move()
{
	/*showsnake();
	Sleep(m_ispeed);*/
	erasesnake();
	for (int i = m_ilength-1;i>0; i--)
	{
		m_vecbody[i].m_x = m_vecbody[i-1].m_x;
		m_vecbody[i].m_y = m_vecbody[i-1].m_y;
	}
	switch (m_direction)
	{
	case UP:
		m_vecbody[0].m_y--;
		break;
	case DOWN:
		m_vecbody[0].m_y++;
		break;
	case RIGHT:
		m_vecbody[0].m_x++;
		break;
	case LEFT:
		m_vecbody[0].m_x--;
		break;
	}
	showsnake();
	Sleep(m_ispeed);
}
void csnake::changedirection(int vkvalue)
{
	switch (vkvalue)
	{
	case 'W':
	case 'w':
	case 72:
		if (m_direction !=DOWN )
		{
			m_direction = UP;
		}
		break;
	case 'S':
	case 80:
	case 's':
		if (m_direction != UP)
		{
			m_direction = DOWN;
		}
		break;
	case 'A':
	case 'a':
	case 75:
		if (m_direction != RIGHT)
		{
			m_direction = LEFT;
		}
		break;
	case 'D':
	case 'd':
	case 77:
		if (m_direction != LEFT)
		{
			m_direction = RIGHT;
		}
		break;
	default:
		break;
	}
}
bool csnake::eatfood(cfood *pfood)
{
	if (m_vecbody[0].m_x == pfood->m_x&&m_vecbody[0].m_y == pfood->m_y)
		return true;
	else return false;

}
void csnake::showsnake()
{
	for (int i = 0; i < m_ilength; i++)
	{
		m_vecbody[i].show();
	}
}
void csnake::erasesnake()
{
	for (int i = 0; i < m_ilength; i++)
	{
		m_vecbody[i].erase();
	}
}
void csnake::growup()
{
	
	cunit p(0, 0, '*');
	m_vecbody.push_back(p);
	m_ilength++;
}
csnake::~csnake()
{

}
