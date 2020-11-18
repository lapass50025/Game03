#include <curses.h>



/*
 *
 */
int main(void)
{
	// 터미널 초기화하기
	initscr();
	curs_set(0);

	// 출력하기
	printw("Hello, World!!!");
	getch();

	// 터미널 종료하기
	endwin();
}
