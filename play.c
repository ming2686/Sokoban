#include "common.h"
#include "sokoban.h"
#include "cursor.h"

#define putchxy(x, y, c) {gotoxy(x, y);putch(c);}
#define putsxy(x, y, s) {gotoxy(x, y);puts(s);}

char originstage[18][21] = {
	"####################",
	"####################",
	"####################",
	"#####   ############",
	"#####O  ############",
	"#####  O############",
	"###  O O ###########",
	"### # ## ###########",
	"#   # ## #####  ..##",
	"# O  O   @      ..##",
	"##### ### # ##  ..##",
	"#####     ##########",
	"####################",
	"####################",
	"####################",
	"####################",
	"####################",
	"####################"
};

char playstage[18][21]={0};

int nx, ny;
int dx, dy;

int cursorLocation=19;

void show(){
	clrscr();
	int i, j;
	for(i=0;i<18;i++){
		for(j=0;j<21;j++){
			printf("*");
		}
		printf("\n");
	}
}

void showgamestop(){
	clrscr();
	int i, j;
	for(i=0;i<18;i++){
		for(j=0;j<21;j++){
			printf("&");
		}
		printf("\n");
	}
}

void initial(){ //메모리값 복사 
	memcpy(playstage, originstage, sizeof(playstage));
}

void showstage(){
	clrscr();
	int x, y;
	
	for(y=0;y<18;y++){
		for(x=0;x<21;x++){
			printf("%c",playstage[y][x]);
		}
		printf("\n");
	}
	putchxy(nx, ny, '@');
}

void charactersetting(){ // 주인공의 위치 찾아넣기 
	int x, y;
	
	for(y=0;y<18;y++){
		for(x=0;x<20;x++){
			if (playstage[y][x]=='@'){
				nx = x;
				ny = y;
				playstage[y][x]=' ';
			}
		}
	}
}

void charactermove(int dx, int dy){
	
	if (playstage[ny + dy][nx + dx]!='#') {
		// 짐을 미는 경우
		if (playstage[ny + dy][nx + dx] == 'O') {
			// 그 다음 칸이 비어 있거나 창고여야 한다. 
			if (playstage[ny + dy * 2][nx + dx * 2] == ' ' || playstage[ny + dy * 2][nx + dx * 2] == '.') {
				if (originstage[ny + dy][nx + dx] == '.') {
					playstage[ny + dy][nx + dx] = '.';
				} 
				else {
					playstage[ny + dy][nx + dx] = ' ';
				}
				playstage[ny + dy * 2][nx + dx * 2] = 'O';
			} 
			else {
				dx = dy = 0;
			}
		}
		// 새 위치로 이동
		nx += dx;
		ny += dy;
	}

}

