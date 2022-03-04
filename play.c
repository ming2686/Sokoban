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

void initial(){ //�޸𸮰� ���� 
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

void charactersetting(){ // ���ΰ��� ��ġ ã�Ƴֱ� 
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
		// ���� �̴� ���
		if (playstage[ny + dy][nx + dx] == 'O') {
			// �� ���� ĭ�� ��� �ְų� â���� �Ѵ�. 
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
		// �� ��ġ�� �̵�
		nx += dx;
		ny += dy;
	}

}

