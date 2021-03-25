//===============================================
//Player.cpp源文件
//定义类Player的成员函数
//===============================================

#include"class.h"

/*******************构造函数*********************/
Player::Player(int n)//n将用于初始化该玩家的游戏编号。默认为1
{
	num=n;
	x=y=8;
}

/*******************下棋函数*********************/
void Player::play(Board & bd)
{
	cout<<"下面请玩家"<<num<<"落子。"<<endl;
xia:
	cout<<"请以“行 列”的格式输入您要落子的点并按回车确认："<<endl;
	cin>>x>>y;
	if((x<0)||(x>14)||(y<0)||(y>14))
	{
		cout<<"对不起，请将棋子下在棋盘之内。"<<endl;
		goto xia;
	}
	if((bd.point[x][y]==1)||(bd.point[x][y]==2))
	{
		cout<<"对不起，该处已经存在棋子。"<<endl;
		goto xia;
	}
	bd.point[x][y]=num;//下棋
}

/*****************判断输赢函数*******************/
int Player::judge(const Board & bd)//判断列是否达到5子
{
	//判断列
	int n=1;//初始化n
	if((x!=0)&&(bd.point[x-1][y]==num))//判断前一个位置是否有子
	{
		n++;
		if(((x-1)!=0)&&(bd.point[x-2][y]==num))
		{
			n++;
			if(((x-2)!=0)&&(bd.point[x-3][y]==num))
			{
				n++;
				if(((x-3)!=0)&&(bd.point[x-4][y]==num))
				{
					n++;
				}
			}
		}
	}
	if(n>=5)
		return 1;
	if((x!=14)&&(bd.point[x+1][y]==num))
	{
		n++;
		if(((x+1)!=14)&&(bd.point[x+2][y]==num))
		{
			n++;
			if(((x+2)!=14)&&(bd.point[x+3][y]==num))
			{
				n++;
				if(((x+3)!=14)&&(bd.point[x+4][y]==num))
				{
					n++;
				}
			}
		}
	}
	if(n>=5)
		return 1;

	//判断行
	n=1;//初始化n
	if((y!=0)&&(bd.point[x][y-1]==num))
	{
		n++;
		if(((y-1)!=0)&&(bd.point[x][y-2]==num))
		{
			n++;
			if(((y-2)!=0)&&(bd.point[x][y-3]==num))
			{
				n++;
				if(((y-3)!=0)&&(bd.point[x][y-4]==num))
				{
					n++;
				}
			}
		}
	}
	if(n>=5)
		return 1;//达到5个，立即响应
	if((y!=14)&&(bd.point[x][y+1]==num))
	{
		n++;
		if(((y+1)!=14)&&(bd.point[x][y+2]==num))
		{
			n++;
			if(((y+2)!=14)&&(bd.point[x][y+3]==num))
			{
				n++;
				if(((y+3)!=14)&&(bd.point[x][y+4]==num))
				{
					n++;
				}
			}
		}
	}
	if(n>=5)//达到5个，立即响应
		return 1;

	//判断左上右下
	n=1;//初始化n
	if((x!=0)&&(y!=0)&&(bd.point[x-1][y-1]==num))
	{
		n++;
		if(((x-1)!=0)&&((y-1)!=0)&&(bd.point[x-2][y-2]==num))
		{
			n++;
			if(((x-2)!=0)&&((y-2)!=0)&&(bd.point[x-3][y-3]==num))
			{
				n++;
				if(((x-3)!=0)&&((y-3)!=0)&&(bd.point[x-4][y-4]==num))
				{
					n++;
				}
			}
		}
	}
	if(n>=5)
		return 1;
	if((x!=14)&&(y!=14)&&(bd.point[x+1][y+1]==num))
	{
		n++;
		if(((x+1)!=0)&&((y+1)!=0)&&(bd.point[x+2][y+2]==num))
		{
			n++;
			if(((x+2)!=0)&&((y+2)!=0)&&(bd.point[x+3][y+3]==num))
			{
				n++;
				if(((x+3)!=0)&&((y+3)!=0)&&(bd.point[x+4][y+4]==num))
				{
					n++;
				}
			}
		}
	}
	if(n>=5)
		return 1;

	//判断右上左下
	n=1;//初始化n
	if((x!=0)&&(y!=0)&&(bd.point[x+1][y-1]==num))
	{
		n++;
		if(((x+1)!=0)&&((y-1)!=0)&&(bd.point[x+2][y-2]==num))
		{
			n++;
			if(((x+2)!=0)&&((y-2)!=0)&&(bd.point[x+3][y-3]==num))
			{
				n++;
				if(((x+3)!=0)&&((y-3)!=0)&&(bd.point[x+4][y-4]==num))
				{
					n++;
				}
			}
		}
	}
	if(n>=5)
		return 1;
	if((x!=14)&&(y!=14)&&(bd.point[x-1][y+1]==num))
	{
		n++;
		if(((x-1)!=0)&&((y+1)!=0)&&(bd.point[x-2][y+2]==num))
		{
			n++;
			if(((x-2)!=0)&&((y+2)!=0)&&(bd.point[x-3][y+3]==num))
			{
				n++;
				if(((x-3)!=0)&&((y+3)!=0)&&(bd.point[x-4][y+4]==num))
				{
					n++;
				}
			}
		}
	}
	if(n>=5)
		return 1;

	//不满足胜利条件
	return 0;
}