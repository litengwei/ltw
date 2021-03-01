#include "cunit.h"
#include <iostream>
using namespace std;
void cunit::erase()
{
	gotoxy(m_x,m_y);
	cout << ' ' << endl;
}
cunit::cunit(int x, int y, char pic)
{

	m_x = x;
	m_y = y;
	m_pic = pic;
}
cunit::~cunit()
{

}
void cunit::gotoxy(int x,int y)
{
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	HANDLE hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void cunit::show()
{
	gotoxy(m_x, m_y);
	cout << m_pic << endl;
}