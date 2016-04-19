//===============================================
//Board.cpp源文件
//定义类Board的成员函数
//===============================================

#include"class.h"

const string jiaodian[11]={"┼","●","○","┌","┬","┐","┤","┘","┴","└","├"};//定义棋盘显示字符，这些符号不能储存为char

/*******************构造函数*********************/
Board::Board()//初始化棋盘每个节点的字符显示，形成完整键盘图形
{
	int x,y;
	point[0][0]=3;
	point[0][14]=5;
	point[14][0]=9;
	point[14][14]=7;
	for(x=1;x<14;x++)
	{
		for(y=1;y<14;y++)
		{
			point[x][y]=0;
		}
	}
	for(y=1;y<14;y++)
	{
		point[0][y]=4;
	}
	for(x=1;x<14;x++)
	{
		point[x][14]=6;
	}
	for(x=1;x<14;x++)
	{
		point[x][0]=10;
	}
	for(y=1;y<14;y++)
	{
		point[14][y]=8;
	}
}

/*****************棋盘显示函数*******************/
void Board::display(Player *pt,int duixiang)//当duixiang=1时，说明两个玩家对战；=2时，人与电脑对战
{
	system("cls");//清屏
	int x,y;
	cout<<"==========================================="<<endl;
	cout<<"||           欢迎来玩五子棋！            ||"<<endl;
	cout<<"==========================================="<<'\n'<<endl;
	cout<<"        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4"<<endl;
	for(x=0;x<15;x++)
	{
		cout<<"     ";
		cout<<setw(2)<<x;
		for(y=0;y<15;y++)
		{
			cout<<jiaodian[point[x][y]];
		}
		if(pt!=NULL)
		{
			if(x==5)
			{
				if((duixiang==2)&&(pt->num==2))
					cout<<"     您正在与电脑对战。";
				else
					cout<<"     现在是双人对战。";
			}
			if(x==7)
			{
				if((duixiang==2)&&(pt->num==2))
					cout<<"     电脑在"<<pt->x<<"行"<<pt->y<<"列落子。";
				else
					cout<<"     玩家"<<pt->num<<"在"<<pt->x<<"行"<<pt->y<<"列落子。";
			}
		}
		cout<<'\n';
	}
	cout<<endl;
}