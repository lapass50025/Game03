#include <curses.h>
#include <string>
#include <string.h>



using namespace std;

int main(void)
{
	int nMaxX = 0;
	int nMaxY = 0;

    int i = 0;
    int j = 0;

	string strText;
	int nLen = 0;
	char *strMsg = "Game Start";
	

	// 초기화하기	
	initscr();
	curs_set(0);

	// 터미널 크기 얻기
	nMaxY = LINES;
	nMaxX = COLS;
	
	// 첫 번째 줄 출력하기
    move(0, 0);
    for (i = 0; i < nMaxX; i++)
    {
        addch('*');
    }

    for (i = 0; i < nMaxY; i++)
    {
        for (j = 0; j < nMaxX; j++)
        {
            if(j == 0)
            {
                mvaddch(i, j, '*');
            }
            else if( j == nMaxX - 1)
            {
                mvaddch(i, j, '*');
            }
        }
    }

    // 마지막 줄 출력하기
    move(nMaxY - 1, 0);
    for (i = 0; i < nMaxX; i++)
    {
        addch('*');
    }

    // 문자열 화면 중앙에 출력하기
    nLen = strlen(strMsg);
    mvaddstr(nMaxY / 2, nMaxX / 2 - nLen / 2, strMsg);

	getch();

	endwin();
	
	return 0;
}
