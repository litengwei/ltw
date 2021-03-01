// snake.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "cunit.h"
#include "food.h"
#include"map.h"
#include"csnake.h"
#include "cgame.h"
#include <iostream>
using namespace std;
#include<stdlib.h>


int main()
{ 
	
	//cunit unit(0,0);
	//unit.show();
	//Sleep(10);
	//unit.erase();
	/*cfood food;
	food.createpos();
	map map;
	map.drawgamearea();
	csnake snake;*/
	//GetAsyncKeyState;
	/*while (1)
	{
		snake.move();
		if (_kbhit())
		{
			int vk = _getch();
			snake.changedirection(vk);
		}
		if (snake.eatfood(&food))
		{
			snake.growup();
			food.createpos();
		}*/
	cgame cgame;
	cgame.run();

	getchar();
	//return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
