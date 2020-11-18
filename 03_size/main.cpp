#include <curses.h>
#include <string>
#include <string.h>



using namespace std;

int main(void)
{
	int nMaxX = 0;
	int nMaxY = 0;
	string strText;
	int nLen = 0;
	char *strMsg = "Middle Hello ncurses!!!";
	

	// 초기화하기	
	initscr();
	curs_set(0);

	// 터미널 크기 얻기
	nMaxY = LINES - 1;
	nMaxX = COLS - 1;
	
	// 출력하기
	printw("Start Hello ncurses!!!");
	
	// 커서 이동 후 출력하기 (x : 4, y : 3)
	move(3, 4);
	addch('3');

	// 한 번에 이동 후 출력하기
	// (x : 4, y : 5)
	mvaddch(5, 4, '5');

	// 문자열 출력하기
	strText = "LINES : " + to_string(nMaxX) + ", " + "COLS : " + to_string(nMaxY);
	// (x : 4, y : 6)
	mvaddstr(6, 4, strText.c_str());
	
	// 문자열 중앙 출력하기
	nLen = strlen(strMsg);
	mvprintw(nMaxY / 2, nMaxX / 2 - nLen / 2, strMsg);
	getch();

	endwin();
	
	return 0;
}
