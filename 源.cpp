#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
int KEY();/*�жϼ�������*/
void LOGO();/*����1*/
void LOGO2();/*����2*/
void START();/*��Ϸ��ʼǰ��ʾ*/
void Printing();/*��ӡ�÷���*/
void GAME_OVER();/*��Ϸ������ʾ*/
void PT(struct data *p);/*��Ϸ���ֳ���*/
void goto_xy(int x, int y);/*��λ���λ�õ�ָ������*/
void CHEN_JIU(struct data *p);/*���سɾ��ж�*/
void PD(int y, struct data *p);/*�ж�����Ƿ��겢�÷ֻ�۳�����ֵ*/
void Ball(int x, int y, int sp);/*ˢ��С��*/
void GMAE_Program(struct data *p);/*��Ϸ������*/
struct data
{
	int score, life, chen_jiu; /*�÷�&����&�ɾ�����*/
};
int main(void)
{
	LOGO();
	LOGO2();
	while (1)
	{
		struct data* p, G = { 0, 3, 0 };  /*��ʼ����Ϸ����*/
		p = &G;

		START();
		goto_xy(20, 23);
		printf("����:");
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
		printf("%d", p->score);  /*��ӡ�÷�*/
		goto_xy(25, 24);
		printf("%d", p->life);  /*��ӡʣ������ֵ*/
		PT(p); /*������Ϸ����*/
	}
}
void PT(struct data* p)
{
	int y = 0, speed; /*yΪ��������*/
	srand(time(NULL));
	speed = rand() % 9;  /*ѡȡС�������ٶ�*/

	for (int i = 0; i <= 22; i++, y++) /*ը������22��������,ÿѭ��һ��С������һ������*/
	{
		Printing();
		Ball(34, y, speed);/*ˢ��С��*/
		if (KEY() == 1)    /*�жϿո����벢ת���ʧ�ж�*/
		{
			PD(y, p);
			break;
		}
		if (i == 22) /*�ж�С�򴥵�*/
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
	int i[] = { 150, 80, 100, 70, 120, 50, 130, 180, 95, 75 }; /*���ˢ��С�������ٶ�,��λ����*/
	goto_xy(x, y);
	printf("*\b");
	Sleep(i[sp]);
	printf(" ");
}
void Printing()
{
	goto_xy(25, 20);
	printf("һ�֩�������������������\n");
	goto_xy(25, 21);
	printf("���֩�������������������\n");
}
int KEY()
{
	if (_kbhit())
	{
		if (_getch() == 32)  /*�жϿո�����*/
			return 1;
	}
}
void PD(int y, struct data* p)
{
	if (y == 21) /*�÷��жϣ�2�֣�*/
	{
		p->score += 2;

		if(p->life == 1) /*�ɾ��ж�*/
			p->chen_jiu++;
	}
	else if (y == 20) /*�÷��жϣ�1�֣�*/
	{
		p->score++;

		if (p->life == 1) /*�ɾ��ж�*/
			p->chen_jiu++;
	}
	else
		p->life--; /*��Ѫ*/
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
	if (p->chen_jiu >= 10) /*�ڽ�ʣһ��Ѫʱ���������10�μ���óɾ�*/
	{
		goto_xy(40, 6);
		printf("��ϲ��óɾ�:");
		goto_xy(42, 7);
		printf("������Ѫ������\n");
		Sleep(2000);
		system("cls");
	}
}

void START()
{
	system("color F4");
	goto_xy(30, 3);
	printf("С���䵽һ�ֻ�������ʱ������Ŀո�����ɼ�һ�ֻ�����\n");
	goto_xy(30, 4);
	printf("ע�⣺��������򳬹��������ٲ�������۳�1������,��С�������ٶȲ���!\n");
	goto_xy(30, 5);
	printf("���������ʼ��Ϸ\n");
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
	printf("�����������");
	_getch();
	system("cls");
}
/*����Ϊ��Ϸ�������*/
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
	printf("��Ϸ���������ã�������ڵĿ���������\n");
	goto_xy(36, 7);
	printf("                                     ----��\n");
	Sleep(2200);
	system("cls");
}