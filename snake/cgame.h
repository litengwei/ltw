#pragma once

#include "csnake.h"
class cgame
{
public:
	cgame();
	virtual ~cgame();

	void run();
	bool checkfailed();
	bool checklevel();
	void changeinfo();
	void Drawgamearea();
	void Drawgameinfo();
	void MouseOff();
	void menu();
	void list();
	void con();
	void ilist();
public:
	static const int kleft=5;
	static const int kup=0;
	static const int kwidth=110;
	static const int kheight=30;
	/*static const*/ int kscore_offset;
	/*static const */int klevel_offset;
public:
	cfood *m_pfood;
	csnake *m_psnake;
	int m_iscore;
	int m_ilevel;
	int score[3];
	char name;
};

