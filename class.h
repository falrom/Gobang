//===============================================
//class.h头文件
//包含所有定义的类和头文件
//===============================================

#ifndef _CLASSS_H_
#define _CLASSS_H_

/******************包含头文件********************/
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

/*******************类：棋盘*********************/
class Player;//声明玩家类
class Board
{
public:
	int point[15][15];//棋盘各节点。标准15*15路五子棋棋盘
public:
	void display(Player *pt=NULL,int duixiang=1);//当duixiang=1时，说明两个玩家对战；=2时，人与电脑对战
	Board();
};

/*******************类：玩家*********************/
class Player
{
public:
	int num;//参与游戏的玩家编号。1或2
	int x,y;//记录玩家落子的节点坐标
public:
	Player(int n=1);//n将用于初始化该玩家的游戏编号。默认为1
	int judge(const Board & bd);//取胜判断
	void play(Board & bd);//下棋函数
};

/*****************类：电脑玩家*******************/
class Computer:public Player//继承于玩家类。默认编号num将初始化为2
{
public:
	float flag;//用于存储各点落子重要性
public:
	Computer();
	void jingong(Board & bd);//进攻重要性判断函数
	void fangshou(Board & bd);//防守重要性判断
	void play(Board & bd);//下棋函数
};

#endif