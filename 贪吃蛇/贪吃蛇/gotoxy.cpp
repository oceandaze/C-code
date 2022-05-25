	/*
#include <stdio.h>
#include <conio.h>//º‡Ã˝º¸≈Ã ‰»Î
#include <windows.h>
void gotoxy(int x, int y);
void moveCircle();
int direct = '0';
struct Circle 
{
	int x;
	int y;
}circle;

int main1()
{
	circle.x = 20;
	circle.y = 10;
	gotoxy(circle.x, circle.y);
	printf("o");
	gotoxy(100, 0);
	system("pause");


	while (1)
	{
		moveCircle();
	}
	
	return 0;
}
void moveCircle()
{
		  if (_kbhit())
		  {
			  fflush(stdin);
			  direct = _getch();

			  switch(direct) {
			  
			  case 'w':
			  case 'W':
				  circle.y--;
				  break;
			  case 's':
			  case 'S':
				  circle.y++;
				  break;
			  case 'a':
			  case 'A':
				  circle.x-=2;
				  break;
			  case 'd':
			  case 'D':
				  circle.x+=2;
				  break;
			  }
			  system("cls");
			  gotoxy(circle.x, circle.y);
			  printf("o");
		  }
}

void gotoxy(int x, int y)
{
	COORD pos = { x , y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);

}
*/