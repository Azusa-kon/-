#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
int KEY();/*判断键盘输入*/
void LOGO();/*动画1*/
void LOGO2();/*动画2*/
void START();/*游戏开始前提示*/
void Printing();/*打印得分线*/
void GAME_OVER();/*游戏结束提示*/
void PT(struct data *p);/*游戏呈现程序*/
void goto_xy(int x, int y);/*定位光标位置到指定坐标*/
void CHEN_JIU(struct data *p);/*隐藏成就判定*/
void PD(int y, struct data *p);/*判断玩家是否达标并得分或扣除生命值*/
void Ball(int x, int y, int sp);/*刷出小球*/
void GMAE_Program(struct data *p);/*游戏主程序*/
struct data
{
	int score, life, chen_jiu; /*得分&生命&成就条件*/
};
int main(void)
{
	LOGO();
	LOGO2();
	while (1)
	{
		struct data* p, G = { 0, 3, 0 };  /*初始化游戏数据*/
		p = &G;

		START();
		goto_xy(20, 23);
		printf("分数:");
		goto_xy(20, 24);
		printf("HP:");
		GMAE_Program(p); 
		system("cls");
		GAME_OVER();
		CHEN_JIU(p);
	}
	return 0;
}
void GMAE_Program(struct data* p)
{
	while (p->life != 0)
	{
		goto_xy(25, 23);
		printf("%d", p->score);  /*打印得分*/
		goto_xy(25, 24);
		printf("%d", p->life);  /*打印剩余生命值*/
		PT(p); /*进入游戏程序*/
	}
}
void PT(struct data* p)
{
	int y = 0, speed; /*y为下落坐标*/
	srand(time(NULL));
	speed = rand() % 9;  /*选取小球下落速度*/

	for (int i = 0; i <= 22; i++, y++) /*炸弹下落22个纵坐标,每循环一次小球下落一个坐标*/
	{
		Printing();
		Ball(34, y, speed);/*刷出小球*/
		if (KEY() == 1)    /*判断空格输入并转入得失判断*/
		{
			PD(y, p);
			break;
		}
		if (i == 22) /*判断小球触底*/
		{
			goto_xy(34, y);
			printf("X\b");
			Sleep(150);
			printf(" ");
			p->life--;
		}
	}
}
void Ball(int x, int y, int sp)
{
	int i[] = { 150, 80, 100, 70, 120, 50, 130, 180, 95, 75 }; /*随机刷新小球下落速度,单位毫秒*/
	goto_xy(x, y);
	printf("*\b");
	Sleep(i[sp]);
	printf(" ");
}
void Printing()
{
	goto_xy(25, 20);
	printf("一分━━━━━━━━━━\n");
	goto_xy(25, 21);
	printf("两分━━━━━━━━━━\n");
}
int KEY()
{
	if (_kbhit())
	{
		if (_getch() == 32)  /*判断空格输入*/
			return 1;
	}
}
void PD(int y, struct data* p)
{
	if (y == 21) /*得分判断（2分）*/
	{
		p->score += 2;

		if(p->life == 1) /*成就判断*/
			p->chen_jiu++;
	}
	else if (y == 20) /*得分判断（1分）*/
	{
		p->score++;

		if (p->life == 1) /*成就判断*/
			p->chen_jiu++;
	}
	else
		p->life--; /*扣血*/
}
void goto_xy(int x, int y)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(hOut, pos);
}
void CHEN_JIU(struct data* p)
{
	system("color 05");
	if (p->chen_jiu >= 10) /*在仅剩一条血时，坚持生存10次即获得成就*/
	{
		goto_xy(40, 6);
		printf("恭喜获得成就:");
		goto_xy(42, 7);
		printf("不到残血不会玩\n");
		Sleep(2000);
		system("cls");
	}
}

void START()
{
	system("color F4");
	goto_xy(30, 3);
	printf("小球落到一分或两分线时摁动你的空格键即可加一分或两分\n");
	goto_xy(30, 4);
	printf("注意：过早操作或超过两条线再操作都会扣除1格生命,且小球下落速度不定!\n");
	goto_xy(30, 5);
	printf("按任意键开始游戏\n");
	_getch();
	system("cls");
}
void GAME_OVER()
{
	goto_xy(40, 2);
	printf("************");
	goto_xy(40, 3);
	printf("*GAME OVER!*");
	goto_xy(40, 4);
	printf("************");
	goto_xy(40, 6);
	printf("按任意键继续");
	_getch();
	system("cls");
}
/*以上为游戏主体程序*/
void LOGO()
{
	system("color 3");
	Sleep(150);
	goto_xy(20, 4);
	printf("                ******************          ******\n");
	Sleep(150);
	goto_xy(20, 5);
	printf("               ******************       ****** ******\n");
	Sleep(150);
	goto_xy(20, 6);
	printf("                                       ******   ******\n");
	Sleep(150);
	goto_xy(20, 7);
	printf("             ******************       ******     ******\n");
	Sleep(150);
	goto_xy(20, 8);
	printf("            ******************       ******       ******\n");
	Sleep(100);
	goto_xy(20, 9);
	printf("              ******                ******   ************\n");
	Sleep(100);
	goto_xy(20, 10);
	printf("             ******                ******   **************\n");
	Sleep(100);
	goto_xy(20, 11);
	printf("            ******                ******             ******\n");
	Sleep(100);
	goto_xy(20, 12);
	printf("           ****************************               ******\n");
	Sleep(100);
	goto_xy(20, 13);
	printf("          ****************************                 ******\n");
	Sleep(2000);
	system("cls");
}
void LOGO2()
{
	system("color 60");
	Sleep(400);
	printf("\n\n\n\t                        ***************************************\n\a");
	printf("\t                       ******************************************\n");
	printf("\t                      *********************************************\n");
	printf("\t                     ***********                          **********\n");
	printf("\t                    ***********                           **********\n");
	printf("\t                   ***********                           **********\n");
	printf("\t                  **********************************************\n");
	printf("\t                 ********************************************\n");
	printf("\t                ******************************************\n");
	Sleep(400);
	printf("\t               **********                        **********                  ** \n");
	printf("\t              **********                          **********               ** **\n");
	printf("\t             **********                           **********             **   **\n");
	printf("\t            **********                            **********           **     **\n");
	printf("\t           **********                             **********         **       **\n");
	printf("\t          **********                                **********     **         **\n");
	printf("\t         **********                                  **********  **           **\n");
	printf("\t                                                       ***********              ******************\n");
	printf("\t                                                         **                                   **\n");
	printf("\t                                                           **                              **\n");
	printf("\t                                                             **                         **\n");
	printf("\t                                                            **           **         **\n");
	printf("\t                                                           **        **     **     **\n");
	printf("\t                                                          **      **          **    **\n");
	printf("\t                                                         **    **               **   **\n");
	printf("\t                                                        **  **                    **  **\n");
	printf("\t                                                       **                              **\n");

	Sleep(2300);
	system("cls");
	goto_xy(36, 6);
	printf("游戏可以做得烂，花里胡哨的开场不能少\n");
	goto_xy(36, 7);
	printf("                                     ----我\n");
	Sleep(2200);
	system("cls");
}