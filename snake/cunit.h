#pragma once
#include <windows.h>
#include <conio.h>
#include <iostream>
class cunit
{
	public:
		cunit(int x = 0, int y = 0, char pic = '*');
		virtual ~cunit();
		void show();
		void erase();
		static void gotoxy(int x, int y);
	public:
		int m_x;
		int m_y;
		char m_pic;
};

