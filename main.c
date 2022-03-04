#include "common.h"
#include "sokoban.h"
#include "cursor.h"

enum { ESC = 27, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80 };

#define putchxy(x, y, c) {gotoxy(x, y);putch(c);}
#define putsxy(x, y, s) {gotoxy(x, y);puts(s);}

int main(int argc, char *argv[]) {
	int ch;
	int x, y;

	int dx=0, dy=0;
	
	BOOL bEnd;
	
	show(); //����ȭ��
	putsxy(45, 2, "SOKOBAN");
	putsxy(45, 4, "ESC:����"); 
	delay(3000);
	clrscr();
	initial(); //�ʱ�ȭ 
	charactersetting(); //���ΰ� ������ġ
	
	while(1){
		showstage();//ȭ����� 
		ch = getch();
		if(ch == 0xE0 || ch == 0){
			ch = getch();
			switch (ch) {
			case LEFT:
				dx = -1;
				break;
			case RIGHT:
				dx = 1;
				break;
			case UP:
				dy = -1;
				break;
			case DOWN:
				dy = 1;
				break;
			}
			charactermove(dx,dy);
			dx = dy = 0;
		}
		else {
			if(ch == ESC){
				clrscr();
				showgamestop();
				break;
			}
		}
		bEnd = TRUE;
		for(y=0;y<18;y++){
			for(x=0;x<20;x++) {
				if(playstage[y][x]=='.'){
					bEnd = FALSE;
				}
			}
		}
		if(bEnd) {
			clrscr();
			putsxy(10, 10, "�� ���߾���");
			delay(2000);
			break; 
		}	
	} 
	
	return 0;
}


