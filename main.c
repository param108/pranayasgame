#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define BOY_MOVE  1
#define GIRL_MOVE  2

#define BOY 'K'
#define GIRL 'Q'
#define WALL '#'
#define GOAL '$'
int girl_x = 0;
int girl_y = 0;

int boy_x = 0;
int boy_y = 1;

int clue_1_x = 30;
int clue_1_y = 30;

void drawline(int y, int startx, int endx) {
	for (int i = startx; i<= endx; i++) {
		mvaddch(y, i, WALL);
	}
}
void setup_board() {

	int y = 10;
	for (int i = 0; i < 10; i++) {
		int startx = rand()%20 + 10;
		drawline(y, startx, startx + 40);
		y = y + 8;
	}


	clue_1_x = (rand()%50) + 15;
	clue_1_y = (rand()%30) + 15;
	mvaddch(clue_1_y, clue_1_x, GOAL);
	boy_x = clue_1_x + 1;
	boy_y = clue_1_y + 1;
	mvaddch(boy_y, boy_x, BOY);
}

void main(){
	WINDOW * w = initscr();
	srand(time(0)); 
	noecho();
	cbreak();
	keypad(w, TRUE);

	int who_moves = BOY_MOVE;
	mvaddch(girl_y, girl_x, GIRL);

	setup_board();

	while(1) {
		int new_girl_x = girl_x;
		int new_girl_y = girl_y;
		int new_boy_x = boy_x;
		int new_boy_y = boy_y;
		int k = 0;

		k = getch();
		bool exit = false;
		switch(k) {
			case 'q':
				who_moves = GIRL_MOVE;
				break;
			case 'k':
				who_moves = BOY_MOVE;
				break;
			case '=':
				exit = true;
				break;
			case 'd':
				new_boy_x++;
				break;
			case 'a':
				new_boy_x--;
				break;
			case 's':
				new_boy_y++;
				break;
			case 'w':
				new_boy_y--;
				break;

			case KEY_RIGHT:
				new_girl_x++;
				break;
			case KEY_LEFT:
				new_girl_x--;
				break;
			case KEY_DOWN:
				new_girl_y++;
				break;
			case KEY_UP:
				new_girl_y--;
				break;

		}
		if (exit == true) {
			break;
		}

		if (new_girl_x == clue_1_x && new_girl_y == clue_1_y) {
			mvaddstr(0,0,"The Girl Won!");
			break;
		}

		if (new_boy_x == clue_1_x && new_boy_y == clue_1_y) {
			new_boy_x = boy_x;
			new_boy_y = boy_y;
		}
	
		int b = mvinch(new_girl_y, new_girl_x);
		if (b == BOY || b == WALL) {
			new_girl_x = 0;
			new_girl_y = 0;
		}
		b = mvinch(new_boy_y, new_boy_x);
		if (b == GIRL) {
			new_girl_x = 0;
			new_girl_y = 0;
		} else if (b == WALL) {
			new_boy_x = 0;
			new_boy_y = 0;
		}

		if (new_girl_x < 0 || new_girl_y < 0) {
			new_girl_x = girl_x;
			new_girl_y = girl_y;
		}

		if (new_boy_x < 0 || new_boy_y < 0) {
			new_boy_x = boy_x;
			new_boy_y = boy_y;
		}

		mvaddch(boy_y, boy_x, ' ');
		mvaddch(girl_y, girl_x, ' ');
		mvaddch(new_girl_y, new_girl_x, GIRL);
		mvaddch(new_boy_y, new_boy_x, BOY);

		girl_y = new_girl_y;
		girl_x = new_girl_x;
		boy_x = new_boy_x;
		boy_y = new_boy_y;
	}

	while(1) {
		int k = getch();
		if (k == '=') {
			break;
		}
	}
	endwin();
}
