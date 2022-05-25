#include <stdio.h>
#include <time.h>//随机种子出现食物
#include <stdlib.h>
#include <conio.h>//监听键盘输入
#include <windows.h>//使用gotoxy()
#define MAP_MOD  "■"
#define SNAKE_HEAD "◎"
#define SNAKE_BODY "●"
#define MAP_WIDTH 80
#define MAP_HEIGHT 30
#define MOVE_CENTER 14
#define INITLEN 3
#define  MAXLEN 30
struct Food 
{
	int x;
	int y;
}food;

struct Snake
{
	int x[MAXLEN];
	int y[MAXLEN];
	int currentLen;
}snake;
void gotoxy(int x, int y);
void createMap();
void createFood();
void initsnake();
void moveSnake();
int statement();
int diretc = 'a';
int flag = 1;

int main()
{
	createMap();
	
	while (1)
	{
		Sleep(250);
		if (flag){
			createFood();
		}
		moveSnake();
		if (statement())
		{
			gotoxy(MAP_WIDTH / 2, MAP_HEIGHT / 2);
			printf("game over!\n");
			gotoxy(96, 0);
			system("pause");
			return 0;
		}
	}
	system("pause");
	return 0;
}



void createMap()
{
		 for (int i=0+ MOVE_CENTER;i<MAP_WIDTH+ MOVE_CENTER;i+=2)
		 {
			 gotoxy(i,0);
			 printf(MAP_MOD);

			 gotoxy(i, MAP_HEIGHT-1);
			 printf(MAP_MOD);
		 }

		 for (int i = 0; i < MAP_HEIGHT; i++)
		 {
			 gotoxy(0+ MOVE_CENTER, i);
			 printf(MAP_MOD);

			 gotoxy(MAP_WIDTH+ MOVE_CENTER, i);
			 printf(MAP_MOD);
		 }
		 initsnake();
}

void createFood()
{
	srand(time(NULL));
	int isCreate = 1;
	food.x = rand() % (MAP_WIDTH - 4+2) + MOVE_CENTER;
	food.y = rand() % (MAP_HEIGHT +1-1);

	if (food.x % 2 == 0) {
		for (int i = 0; i < snake.currentLen; i++)
		{
			if (snake.x[i] == food.x&&snake.y[i] == food.y) {
				isCreate = 0;
			}

			if (isCreate){
				gotoxy(food.x, food.y);
				printf(MAP_MOD);
				flag = 0;
				gotoxy(96, 0);
			}
		}
	}
}
 void initsnake()
 {
	 snake.currentLen = INITLEN;
	 snake.x[0] = MAP_WIDTH / 2+ MOVE_CENTER;
	 snake.y[0] = MAP_HEIGHT / 2;
	 gotoxy(snake.x[0], snake.y[0]);
	 printf(SNAKE_HEAD);
	 for (int i=1;i<snake.currentLen;++i)
	 {
		 snake.x[i] = snake.x[i - 1] + 2;
		 snake.y[i] = snake.y[i - 1] ;
		 gotoxy(snake.x[i], snake.y[i]);
		 printf(SNAKE_BODY);
	 }
 }

 void moveSnake()
 {
	 if (_kbhit())
	 {
		 fflush(stdin);
		 diretc = _getch();
	 }

	 gotoxy(snake.x[snake.currentLen - 1], snake.y[snake.currentLen - 1]);
	 printf("  ");

	 for (int i=snake.currentLen-1;i>0;--i)
	 {
		 snake.x[i] = snake.x[i - 1];
		 snake.y[i] = snake.y[i - 1];
		 gotoxy(snake.x[i], snake.y[i]);
		 printf(SNAKE_BODY);
	 }
	 switch (diretc) {

	 case 'w':
	 case 'W':
		 snake.y[0]--;
		 break;
	 case 's':
	 case 'S':
		 snake.y[0]++;
		 break;
	 case 'a':
	 case 'A':
		 snake.x[0] -= 2;
		 break;
	 case 'd':
	 case 'D':
		 snake.x[0] += 2;
		 break;
	 }
	gotoxy(snake.x[0], snake.y[0]);
	printf(SNAKE_HEAD);	 

	if (snake.x[0] == food.x && snake.y[0] == food.y)
	{
		snake.currentLen+=1;
		flag = 1;
	}
 }

 int statement()
 {
 	 if (snake.x[0]==0+ MOVE_CENTER ||snake.x[0]==MAP_WIDTH+ MOVE_CENTER ||snake.y[0] == 0 || snake.y[0] == MAP_HEIGHT-1)
 	 {
		 return 1;
 	 }

	 for (int i = 1; i < snake.currentLen;i++) {
		 if (snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i])
		 {
			 return 1;
		 }
	 }
	 return 0;
 }
void gotoxy(int x, int y)
{
	COORD pos = { x , y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}