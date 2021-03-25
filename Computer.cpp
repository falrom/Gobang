//===============================================
//Computer.cpp源文件
//定义类Computer的成员函数
//===============================================

#include"class.h"

/*******************构造函数*********************/
Computer::Computer()
{
	num=2;
	flag=0;
}

/*******************下棋函数*********************/
void Computer::play(Board & bd)
{
	jingong(bd);
	fangshou(bd);
	bd.point[x][y]=num;
}

/**************进攻重要性判断函数****************/
void Computer::jingong(Board & bd)
{
	x=y=8;//初始化
	flag=0;
	int i,j;
	int d,n;//记录连子两段截堵棋子的个数和连子数目
	float f=0;//临时记录【i】【j】点的重要性
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			f=0;
			if((bd.point[i][j]==1)||(bd.point[i][j]==2))//如果改点已经存在棋子，跳过
			{
				continue;
			}
			//判断列重要性
			n=1;
			d=0;
			if((i!=0)&&(bd.point[i-1][j]==num))
			{
				n++;
				if(((i-1)!=0)&&(bd.point[i-2][j]==num))
				{
					n++;
					if(((i-2)!=0)&&(bd.point[i-3][j]==num))
					{
						n++;
						if(((i-3)!=0)&&(bd.point[i-4][j]==num))
						{
							n++;
						}
						else if(((i-3)==0)||(bd.point[i-4][j]==1))
						{
							d++;
						}
					}
					else if(((i-2)==0)||(bd.point[i-3][j]==1))
					{
						d++;
					}
				}
				else if(((i-1)==0)||(bd.point[i-2][j]==1))
				{
					d++;
				}
			}
			else if((i==0)||(bd.point[i-1][j]==1))
			{
				d++;
			}
			if((i!=14)&&(bd.point[i+1][j]==num))
			{
				n++;
				if(((i+1)!=14)&&(bd.point[i+2][j]==num))
				{
					n++;
					if(((i+2)!=14)&&(bd.point[i+3][j]==num))
					{
						n++;
						if(((i+3)!=14)&&(bd.point[i+4][j]==num))
						{
							n++;
						}
						else if(((i+3)==14)||(bd.point[i+4][j]==1))
						{
							d++;
						}
					}
					else if(((i+2)==14)||(bd.point[i+3][j]==1))
					{
						d++;
					}
				}
				else if(((i+1)==14)||(bd.point[i+2][j]==1))
				{
					d++;
				}
			}
			else if((i==14)||(bd.point[i+1][j]==1))
			{
				d++;
			}
			if(n>=5)//可连接成5子，不再需要之后的判断
			{
				x=i;
				y=j;
				flag=100;
				return;
			}
			if(d==0)
			{
				switch(n)
				{
					case 4:f+=25;break;
					case 3:f+=7;break;
					case 2:f+=3;break;
					default:;
				}
			}
			if(d==1)
			{
				switch(n)
				{
					case 4:f+=14;break;
					case 3:f+=2;break;
					case 2:f+=1;break;
					default:;
				}
			}
			//判断行重要性
			n=1;
			d=0;
			if((j!=0)&&(bd.point[i][j-1]==num))
			{
				n++;
				if(((j-1)!=0)&&(bd.point[i][j-2]==num))
				{
					n++;
					if(((j-2)!=0)&&(bd.point[i][j-3]==num))
					{
						n++;
						if(((j-3)!=0)&&(bd.point[i][j-4]==num))
						{
							n++;
						}
						else if(((j-3)==0)||(bd.point[i][j-4]==1))
						{
							d++;
						}
					}
					else if(((j-2)==0)||(bd.point[i][j-3]==1))
					{
						d++;
					}
				}
				else if(((j-1)==0)||(bd.point[i][j-2]==1))
				{
					d++;
				}
			}
			else if((j==0)||(bd.point[i][j-1]==1))
			{
				d++;
			}
			if((j!=14)&&(bd.point[i][j+1]==num))
			{
				n++;
				if(((j+1)!=14)&&(bd.point[i][j+2]==num))
				{
					n++;
					if(((j+2)!=14)&&(bd.point[i][j+3]==num))
					{
						n++;
						if(((j+3)!=14)&&(bd.point[i][j+4]==num))
						{
							n++;
						}
						else if(((j+3)==14)||(bd.point[i][j+4]==1))
						{
							d++;
						}
					}
					else if(((j+2)==14)||(bd.point[i][j+3]==1))
					{
						d++;
					}
				}
				else if(((j+1)==14)||(bd.point[i][j+2]==1))
				{
					d++;
				}
			}
			else if((j==14)||(bd.point[i][j+1]==1))
			{
				d++;
			}
			if(n>=5)
			{
				x=i;
				y=j;
				flag=100;
				return;
			}
			if(d==0)
			{
				switch(n)
				{
					case 4:f+=25;break;
					case 3:f+=7;break;
					case 2:f+=3;break;
					default:;
				}
			}
			if(d==1)
			{
				switch(n)
				{
					case 4:f+=14;break;
					case 3:f+=2;break;
					case 2:f+=1;break;
					default:;
				}
			}
			//判断左上右下重要性
			n=1;
			d=0;
			if((i!=0)&&(j!=0)&&(bd.point[i-1][j-1]==num))
			{
				n++;
				if(((i-1)!=0)&&((j-1)!=0)&&(bd.point[i-2][j-2]==num))
				{
					n++;
					if(((i-2)!=0)&&((j-2)!=0)&&(bd.point[i-3][j-3]==num))
					{
						n++;
						if(((i-3)!=0)&&((j-3)!=0)&&(bd.point[i-4][j-4]==num))
						{
							n++;
						}
						else if(((i-3)==0)||((j-3)==0)||(bd.point[i-4][j-4]==1))
						{
							d++;
						}
					}
					else if(((i-2)==0)||((j-2)==0)||(bd.point[i-3][j-3]==1))
					{
						d++;
					}
				}
				else if(((i-1)==0)||((j-1)==0)||(bd.point[i-2][j-2]==1))
				{
					d++;
				}
			}
			else if((i==0)||(j==0)||(bd.point[i-1][j-1]==1))
			{
				d++;
			}
			if((i!=14)&&(j!=14)&&(bd.point[i+1][j+1]==num))
			{
				n++;
				if(((i+1)!=14)&&((j+1)!=14)&&(bd.point[i+2][j+2]==num))
				{
					n++;
					if(((i+2)!=14)&&((j+2)!=14)&&(bd.point[i+3][j+3]==num))
					{
						n++;
						if(((i+3)!=14)&&((j+3)!=14)&&(bd.point[i+4][j+4]==num))
						{
							n++;
						}
						else if(((i+3)==14)||((j+3)==14)||(bd.point[i+4][j+4]==1))
						{
							d++;
						}
					}
					else if(((i+2)==14)||((j+2)==14)||(bd.point[i+3][j+3]==1))
					{
						d++;
					}
				}
				else if(((i+1)==14)||((j+1)==14)||(bd.point[i+2][j+2]==1))
				{
					d++;
				}
			}
			else if((i==14)||(j==14)||(bd.point[i+1][j+1]==1))
			{
				d++;
			}
			if(n>=5)
			{
				x=i;
				y=j;
				flag=100;
				return;
			}
			if(d==0)
			{
				switch(n)
				{
					case 4:f+=25;break;
					case 3:f+=7;break;
					case 2:f+=3;break;
					default:;
				}
			}
			if(d==1)
			{
				switch(n)
				{
					case 4:f+=14;break;
					case 3:f+=2;break;
					case 2:f+=1;break;
					default:;
				}
			}
			//判断右上左下重要性
			n=1;
			d=0;
			if((i!=14)&&(j!=0)&&(bd.point[i+1][j-1]==num))
			{
				n++;
				if(((i+1)!=14)&&((j-1)!=0)&&(bd.point[i+2][j-2]==num))
				{
					n++;
					if(((i+2)!=14)&&((j-2)!=0)&&(bd.point[i+3][j-3]==num))
					{
						n++;
						if(((i+3)!=14)&&((j-3)!=0)&&(bd.point[i+4][j-4]==num))
						{
							n++;
						}
						else if(((i+3)==14)||((j-3)==0)||(bd.point[i+4][j-4]==1))
						{
							d++;
						}
					}
					else if(((i+2)==14)||((j-2)==0)||(bd.point[i+3][j-3]==1))
					{
						d++;
					}
				}
				else if(((i+1)==14)||((j-1)==0)||(bd.point[i+2][j-2]==1))
				{
					d++;
				}
			}
			else if((i==14)||(j==0)||(bd.point[i+1][j-1]==1))
			{
				d++;
			}
			if((i!=0)&&(j!=14)&&(bd.point[i-1][j+1]==num))
			{
				n++;
				if(((i-1)!=0)&&((j+1)!=14)&&(bd.point[i-2][j+2]==num))
				{
					n++;
					if(((i-2)!=0)&&((j+2)!=14)&&(bd.point[i-3][j+3]==num))
					{
						n++;
						if(((i-3)!=0)&&((j+3)!=14)&&(bd.point[i-4][j+4]==num))
						{
							n++;
						}
						else if(((i-3)==0)||((j+3)==14)||(bd.point[i-4][j+4]==1))
						{
							d++;
						}
					}
					else if(((i-2)==0)||((j+2)==14)||(bd.point[i-3][j+3]==1))
					{
						d++;
					}
				}
				else if(((i-1)==0)||((j+1)==14)||(bd.point[i-2][j+2]==1))
				{
					d++;
				}
			}
			else if((i==0)||(j==14)||(bd.point[i-1][j+1]==1))
			{
				d++;
			}
			if(n>=5)
			{
				x=i;
				y=j;
				flag=100;
				return;
			}
			if(d==0)
			{
				switch(n)
				{
					case 4:f+=25;break;
					case 3:f+=7;break;
					case 2:f+=3;break;
					default:;
				}
			}
			if(d==1)
			{
				switch(n)
				{
					case 4:f+=14;break;
					case 3:f+=2;break;
					case 2:f+=1;break;
					default:;
				}
			}
			if(f>flag)
			{
				flag=f;
				x=i;
				y=j;
			}
		}
	}
}

/**************防守重要性判断函数****************/
void Computer::fangshou(Board & bd)
{
	if(flag==100)//如果发现jingong（）已经判定了可以一棋定胜负，则不再需要防守判断。
		return;
	num=1;//判断进攻，临时将num改为1，函数结尾改回
	int i,j;
	int d,n;//记录连子两段截堵棋子的个数和连子数目
	float f=0;//临时记录【i】【j】点的重要性
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			f=0;
			if((bd.point[i][j]==1)||(bd.point[i][j]==2))//如果改点已经存在棋子，跳过
				continue;
			//判断列重要性
			n=1;
			d=0;
			if((i!=0)&&(bd.point[i-1][j]==num))
			{
				n++;
				if(((i-1)!=0)&&(bd.point[i-2][j]==num))
				{
					n++;
					if(((i-2)!=0)&&(bd.point[i-3][j]==num))
					{
						n++;
						if(((i-3)!=0)&&(bd.point[i-4][j]==num))
						{
							n++;
						}
						else if(((i-3)==0)||(bd.point[i-4][j]==2))
						{
							d++;
						}
					}
					else if(((i-2)==0)||(bd.point[i-3][j]==2))
					{
						d++;
					}
				}
				else if(((i-1)==0)||(bd.point[i-2][j]==2))
				{
					d++;
				}
			}
			else if((i==0)||(bd.point[i-1][j]==2))
			{
				d++;
			}
			if((i!=14)&&(bd.point[i+1][j]==num))
			{
				n++;
				if(((i+1)!=14)&&(bd.point[i+2][j]==num))
				{
					n++;
					if(((i+2)!=14)&&(bd.point[i+3][j]==num))
					{
						n++;
						if(((i+3)!=14)&&(bd.point[i+4][j]==num))
						{
							n++;
						}
						else if(((i+3)==14)||(bd.point[i+4][j]==2))
						{
							d++;
						}
					}
					else if(((i+2)==14)||(bd.point[i+3][j]==2))
					{
						d++;
					}
				}
				else if(((i+1)==14)||(bd.point[i+2][j]==2))
				{
					d++;
				}
			}
			else if((i==14)||(bd.point[i+1][j]==2))
			{
				d++;
			}
			if(n>=5)//可连接成5子，必须马上封堵，停止之后的判断
			{
				x=i;
				y=j;
				flag=100;
				num=2;//判断结束，将num改回2
				return;
			}
			if(d==0)
			{
				switch(n)
				{
					case 4:f+=25;break;
					case 3:f+=7;break;
					case 2:f+=3;break;
					default:;
				}
			}
			if(d==1)
			{
				switch(n)
				{
					case 4:f+=14;break;
					case 3:f+=2;break;
					case 2:f+=1;break;
					default:;
				}
			}
			//判断行重要性
			n=1;
			d=0;
			if((j!=0)&&(bd.point[i][j-1]==num))
			{
				n++;
				if(((j-1)!=0)&&(bd.point[i][j-2]==num))
				{
					n++;
					if(((j-2)!=0)&&(bd.point[i][j-3]==num))
					{
						n++;
						if(((j-3)!=0)&&(bd.point[i][j-4]==num))
						{
							n++;
						}
						else if(((j-3)==0)||(bd.point[i][j-4]==2))
						{
							d++;
						}
					}
					else if(((j-2)==0)||(bd.point[i][j-3]==2))
					{
						d++;
					}
				}
				else if(((j-1)==0)||(bd.point[i][j-2]==2))
				{
					d++;
				}
			}
			else if((j==0)||(bd.point[i][j-1]==2))
			{
				d++;
			}
			if((j!=14)&&(bd.point[i][j+1]==num))
			{
				n++;
				if(((j+1)!=14)&&(bd.point[i][j+2]==num))
				{
					n++;
					if(((j+2)!=14)&&(bd.point[i][j+3]==num))
					{
						n++;
						if(((j+3)!=14)&&(bd.point[i][j+4]==num))
						{
							n++;
						}
						else if(((j+3)==14)||(bd.point[i][j+4]==2))
						{
							d++;
						}
					}
					else if(((j+2)==14)||(bd.point[i][j+3]==2))
					{
						d++;
					}
				}
				else if(((j+1)==14)||(bd.point[i][j+2]==2))
				{
					d++;
				}
			}
			else if((j==14)||(bd.point[i][j+1]==2))
			{
				d++;
			}
			if(n>=5)
			{
				x=i;
				y=j;
				flag=100;
				num=2;//判断结束，将num改回2
				return;
			}
			if(d==0)
			{
				switch(n)
				{
					case 4:f+=25;break;
					case 3:f+=7;break;
					case 2:f+=3;break;
					default:;
				}
			}
			if(d==1)
			{
				switch(n)
				{
					case 4:f+=14;break;
					case 3:f+=2;break;
					case 2:f+=1;break;
					default:;
				}
			}
			//判断左上右下重要性
			n=1;
			d=0;
			if((i!=0)&&(j!=0)&&(bd.point[i-1][j-1]==num))
			{
				n++;
				if(((i-1)!=0)&&((j-1)!=0)&&(bd.point[i-2][j-2]==num))
				{
					n++;
					if(((i-2)!=0)&&((j-2)!=0)&&(bd.point[i-3][j-3]==num))
					{
						n++;
						if(((i-3)!=0)&&((j-3)!=0)&&(bd.point[i-4][j-4]==num))
						{
							n++;
						}
						else if(((i-3)==0)||((j-3)==0)||(bd.point[i-4][j-4]==2))
						{
							d++;
						}
					}
					else if(((i-2)==0)||((j-2)==0)||(bd.point[i-3][j-3]==2))
					{
						d++;
					}
				}
				else if(((i-1)==0)||((j-1)==0)||(bd.point[i-2][j-2]==2))
				{
					d++;
				}
			}
			else if((i==0)||(j==0)||(bd.point[i-1][j-1]==2))
			{
				d++;
			}
			if((i!=14)&&(j!=14)&&(bd.point[i+1][j+1]==num))
			{
				n++;
				if(((i+1)!=14)&&((j+1)!=14)&&(bd.point[i+2][j+2]==num))
				{
					n++;
					if(((i+2)!=14)&&((j+2)!=14)&&(bd.point[i+3][j+3]==num))
					{
						n++;
						if(((i+3)!=14)&&((j+3)!=14)&&(bd.point[i+4][j+4]==num))
						{
							n++;
						}
						else if(((i+3)==14)||((j+3)==14)||(bd.point[i+4][j+4]==2))
						{
							d++;
						}
					}
					else if(((i+2)==14)||((j+2)==14)||(bd.point[i+3][j+3]==2))
					{
						d++;
					}
				}
				else if(((i+1)==14)||((j+1)==14)||(bd.point[i+2][j+2]==2))
				{
					d++;
				}
			}
			else if((i==14)||(j==14)||(bd.point[i+1][j+1]==2))
			{
				d++;
			}
			if(n>=5)
			{
				x=i;
				y=j;
				flag=100;
				num=2;//判断结束，将num改回2
				return;
			}
			if(d==0)
			{
				switch(n)
				{
					case 4:f+=25;break;
					case 3:f+=7;break;
					case 2:f+=3;break;
					default:;
				}
			}
			if(d==1)
			{
				switch(n)
				{
					case 4:f+=14;break;
					case 3:f+=2;break;
					case 2:f+=1;break;
					default:;
				}
			}
			//判断右上左下重要性
			n=1;
			d=0;
			if((i!=14)&&(j!=0)&&(bd.point[i+1][j-1]==num))
			{
				n++;
				if(((i+1)!=14)&&((j-1)!=0)&&(bd.point[i+2][j-2]==num))
				{
					n++;
					if(((i+2)!=14)&&((j-2)!=0)&&(bd.point[i+3][j-3]==num))
					{
						n++;
						if(((i+3)!=14)&&((j-3)!=0)&&(bd.point[i+4][j-4]==num))
						{
							n++;
						}
						else if(((i+3)==14)||((j-3)==0)||(bd.point[i+4][j-4]==2))
						{
							d++;
						}
					}
					else if(((i+2)==14)||((j-2)==0)||(bd.point[i+3][j-3]==2))
					{
						d++;
					}
				}
				else if(((i+1)==14)||((j-1)==0)||(bd.point[i+2][j-2]==2))
				{
					d++;
				}
			}
			else if((i==14)||(j==0)||(bd.point[i+1][j-1]==2))
			{
				d++;
			}
			if((i!=0)&&(j!=14)&&(bd.point[i-1][j+1]==num))
			{
				n++;
				if(((i-1)!=0)&&((j+1)!=14)&&(bd.point[i-2][j+2]==num))
				{
					n++;
					if(((i-2)!=0)&&((j+2)!=14)&&(bd.point[i-3][j+3]==num))
					{
						n++;
						if(((i-3)!=0)&&((j+3)!=14)&&(bd.point[i-4][j+4]==num))
						{
							n++;
						}
						else if(((i-3)==0)||((j+3)==14)||(bd.point[i-4][j+4]==2))
						{
							d++;
						}
					}
					else if(((i-2)==0)||((j+2)==14)||(bd.point[i-3][j+3]==2))
					{
						d++;
					}
				}
				else if(((i-1)==0)||((j+1)==14)||(bd.point[i-2][j+2]==2))
				{
					d++;
				}
			}
			else if((i==0)||(j==14)||(bd.point[i-1][j+1]==2))
			{
				d++;
			}
			if(n>=5)
			{
				x=i;
				y=j;
				flag=100;
				num=2;//判断结束，将num改回2
				return;
			}
			if(d==0)
			{
				switch(n)
				{
					case 4:f+=25;break;
					case 3:f+=7;break;
					case 2:f+=3;break;
					default:;
				}
			}
			if(d==1)
			{
				switch(n)
				{
					case 4:f+=14;break;
					case 3:f+=2;break;
					case 2:f+=1;break;
					default:;
				}
			}
			if(f>flag)
			{
				flag=f;
				x=i;
				y=j;
			}
		}
	}
	num=2;//判断结束，将num改回2
}