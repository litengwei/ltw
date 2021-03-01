#include "cgame.h"
#include "map.h"
#include "csnake.h"
#include "food.h"
#include <conio.h>
#include <string.h>
//#include "mmsystem.h"//导入声音文件
//#include "windows.h"
//#pragma comment(lib,"winmm.lib")

cgame::cgame()
{
	m_pfood = new cfood;
	m_psnake = new csnake;
	m_iscore = 0;
	m_ilevel = 1;
	//Drawgamearea();
	//Drawgameinfo();
	
}
cgame::~cgame()
{
	delete m_pfood;
	delete m_psnake;
	m_pfood = NULL;
	m_psnake = NULL;
	/*delete m_pfood;
	m_pfood = NULL;*/
}
void cgame::menu()
{
	cunit::gotoxy(45, 15);
	cout << "1.开始游戏";
	cunit::gotoxy(45, 16);
	cout << "2.排行榜";
}
void cgame::list()
{
	system("cls");//清屏
	Drawgamearea();
	for (int i = 0; i < 3; i++)
	{
		cunit::gotoxy(20, 7+i);
		cout <<score[i];
	}
	cunit::gotoxy(20, 6);
	cout << "分数排行";
	cunit::gotoxy(20, 15);
	cout << "按8退出";
	int w;
	w = _getch();
	if (w=='8')
	  run();
}
void cgame::con()
{
	system("cls");//清屏
	m_iscore = 0;
	m_ilevel = 1;
	Drawgamearea();
	Drawgameinfo();
	changeinfo();
	MouseOff();
	m_psnake->m_ilength = 4;
	m_psnake->m_ispeed == 100;
	for (int i = 0; i < m_psnake->m_ilength; i++)
	{
		m_psnake->m_vecbody[i].m_x = 20 - i;
		m_psnake->m_vecbody[i].m_y = 10;
	}
	m_psnake->showsnake();

	m_pfood->createpos();
	int vk = 0;
	bool sf = true;
	bool pf = true;
	while (vk != VK_ESCAPE && sf)
	{

		if (_kbhit())
		{
			vk = _getch();
			if (vk == VK_SPACE)
			{
				pf = !pf;
			}
			m_psnake->changedirection(vk);
		}
		else
			if (pf)
			{
				continue;
			}
		m_psnake->move();
		if (m_psnake->eatfood(m_pfood))
		{
			m_psnake->growup();
			m_pfood->erase();
			m_pfood->createpos();
			m_iscore++;
			changeinfo();
			/*Drawgameinfo();*/
		}

		if (checkfailed()|| GetAsyncKeyState(VK_ESCAPE) && 0x8000)
		{
			sf = false;
			ilist();
			cunit::gotoxy(50, 10);
			cout << "GAME OVER";
			cunit::gotoxy(50, 11);
			cout << "继续游戏按空格";
			cunit::gotoxy(50, 12);
			cout << "返回主菜单按3";
			int c;
			c = _getch();
			if (c == '3')
				run();
			int b = _getch();
			if (b == VK_SPACE)
				con();
		}
		if (checklevel())
		{
			m_ilevel++;
			changeinfo();
			m_psnake->m_ispeed -= 10;
		}

	}
}

void cgame::run()
{
	system("cls");//清屏
	Drawgamearea();
	menu();
		int a;
			a= _getch();
		if (a == '2')
			list();
		if (a =='1')
		{
			system("cls");//清屏
			m_iscore = 0;
			m_ilevel = 1;
			Drawgamearea();
			Drawgameinfo();
			changeinfo();
			MouseOff();
			m_psnake->m_ilength = 4;
			

			for (int i = 0; i < m_psnake->m_ilength; i++)
			{
				m_psnake->m_vecbody[i].m_x = 20-i;
				m_psnake->m_vecbody[i].m_y = 10;
			}
			m_psnake->showsnake();
			
			m_pfood->createpos();
			int vk = 0;
			bool sf = true;
			bool pf = true;
			while (vk != VK_ESCAPE && sf)
			{

				if (_kbhit())
				{
					vk = _getch();
					if (vk == VK_SPACE)
					{
						pf = !pf;
					}
					m_psnake->changedirection(vk);
				}
				else
					if (pf)
					{
						continue;
					}
				m_psnake->move();
				if (m_psnake->eatfood(m_pfood))
				{
					m_psnake->growup();
					m_pfood->erase();
					m_pfood->createpos();
					m_iscore++;
					changeinfo();
					/*Drawgameinfo();*/
				}
				if (checkfailed())
				{
					sf = false;
					ilist();
					cunit::gotoxy(50, 10);
					cout << "GAME OVER";
					cunit::gotoxy(50, 11);
					cout << "继续游戏按空格";
					cunit::gotoxy(50, 12);
					cout << "返回主菜单按3";
					int c;
					c= _getch();
					if (c == '3')
						run();
					int b = _getch();
					if (b == VK_SPACE)
						con();
				}
				if (checklevel())
				{
					m_ilevel++;
					changeinfo();
					m_psnake->m_ispeed -= 50;
				}

			}
		}
	
}
void cgame::ilist()
{
	if (m_iscore > score[0])
	{
		score[2] = score[1];
		score[1] = score[0];
		score[0] = m_iscore;
	}
	else
		if (m_iscore > score[1] && m_iscore != score[10])
		{
			score[2] = score[1];
			score[1] = m_iscore;
		}
		else
			if (m_iscore > score[2] && m_iscore != score[1])
				score[2] = m_iscore;
}
bool cgame::checkfailed()
{
	for (int i = 1; i < m_psnake->m_ilength; i++)
	{
		if (m_psnake->m_vecbody[0].m_x == m_psnake->m_vecbody[i].m_x&&m_psnake->m_vecbody[0].m_y == m_psnake->m_vecbody[i].m_y)
		{
			return true;
		}
	}
	if (m_psnake->m_vecbody[0].m_x == kleft || m_psnake->m_vecbody[0].m_x == kwidth || m_psnake->m_vecbody[0].m_y == 3 || m_psnake->m_vecbody[0].m_y == kheight)
	{
		return true;
	}
	return false;
}
bool cgame::checklevel()
{
	int t = m_iscore / 10 + 1;
	int t1 = m_ilevel + 1;
	if (t == t1)
	{
		return true;
	}
	return false;
}
void cgame::changeinfo()
{
	cunit::gotoxy(50, 2);
	cout << m_iscore;
	cunit::gotoxy(70, 2);
	cout << m_ilevel;
	cunit::gotoxy(6, 32);
	cout << "上：w  下：s  左：a  右:d   每升一关，速度增加";
	//cunit::gotoxy(70, 32);
	//cin >> name;
	//cunit::gotoxy(70, 32);
	//cout << name;

}
void cgame::Drawgamearea()
{
	map map;
	map.drawgamearea();
}
void cgame::Drawgameinfo()
{
	map map;
	/*map.kscode_offset = m_iscore;
	map.klevel_offset = m_ilevel;*/
	map.drawgameinfo();
}
void cgame::MouseOff()
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;//假不可见   
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}


