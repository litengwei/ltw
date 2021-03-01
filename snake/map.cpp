#include "map.h"
#include"cunit.h"
void map::drawgamearea()
{
	int i, j;
	for (i = kup; i <= kheight; i++)
	{
		for (j = kleft; j <= kwidth; j++)
		{
			if (i == kup || i == kup + 3 || i == kheight)
			{
				cunit::gotoxy(j, i);
				cout << "-" << endl;
			}
			if (j == kleft || j == kwidth)
			{
				cunit::gotoxy(j, i);
				cout << "|" << endl;
			}
		}
	}
}
void map::drawgameinfo()
{
	cunit::gotoxy(6, 2);
	cout << " Ì°³ÔÉß";
	cunit::gotoxy(15, 2);
	cout << "±à¼­Õß£ºÀèÌÚÎµ";
	cunit::gotoxy(40, 2);
	cout << "µÃ·Ö£º"/*<< kscode_offset*/;
	cunit::gotoxy(60, 2);
	cout << "¹Ø¿¨£º"/*<<klevel_offset*/;
}