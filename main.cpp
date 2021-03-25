//===============================================
//main.cpp源文件
//主函数，游戏过程函数
//===============================================

#include"class.h"

/***************人机对战过程函数*****************/
void ptc()
{
	Board gobang;//键盘：gobang
	gobang.display();
	Player player1(1);//玩家1：player1
	Computer comp;//玩家电脑：comp
	while (1)//死循环，当有一方胜出时，退出本局
	{
		player1.play(gobang);
		gobang.display(&player1,2);
		if(player1.judge(gobang)==1)
		{
			cout<<"玩家1获得胜利！（按回车键继续）"<<endl;
			while(cin.get()!='\n');
			while(cin.get()!='\n');
			return;
		}
		comp.play(gobang);
		gobang.display(&comp,2);
		if(comp.judge(gobang)==1)
		{
			cout<<"电脑获得胜利！（按回车键继续）"<<endl;
			while(cin.get()!='\n');
			while(cin.get()!='\n');
			return;
		}
	}
}

/***************双人对战过程函数*****************/
void ptp()
{
	Board gobang;//键盘：gobang
	gobang.display();
	Player player1(1),player2(2);//玩家1：player1，玩家2：player2
	while (1)//死循环，当有一方胜出时，退出本局
	{
		player1.play(gobang);
		gobang.display(&player1,1);
		if(player1.judge(gobang)==1)
		{
			cout<<"玩家1获得胜利！（按回车键继续）"<<endl;
			while(cin.get()!='\n');
			while(cin.get()!='\n');
			return;
		}
		player2.play(gobang);
		gobang.display(&player2,1);
		if(player2.judge(gobang)==1)
		{
			cout<<"玩家2获得胜利！（按回车键继续）"<<endl;
			while(cin.get()!='\n');
			while(cin.get()!='\n');
			return;
		}
	}
}

/****************游戏过程主函数******************/
int main()
{
	int m=0;//用以判断游戏模式。
loop:
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
	cout<<"==========================================="<<endl;
	cout<<"||           欢迎来玩五子棋！            ||"<<endl;
	cout<<"==========================================="<<'\n'<<endl;
	cout<<"请选择游戏模式："<<'\n'<<"双人对战，请输入“1”并回车。"<<'\n'<<"人机对战，请输入“2”并回车。"<<endl;
	cin>>m;
	if(m==1)//双人对战模式
		ptp();
	else if(m==2)//人机对战模式
		ptc();
	else
		goto loop;
	goto loop;
	return 0;
}