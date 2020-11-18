#include <iostream>
#include <curses.h>

#include "Game.h"



//
TAYOTYPE g_tayo;
char *g_tayoShape[6] = { "*****", "*@*@*" };



/*
 *
 */
int InitTayoObject(void)
{
    int nRet = 1;



    g_tayo.nX = COLS / 2 - sizeof(g_tayoShape[0]) / 2); 
    g_tayo.nY = LINES / 2;
    g_tayo.nWidth = sizeof(g_tayoShape[0]);
    g_tayo.nHeight = 2;
    g_tayo.pShape = g_tayoShape;

    return nRet;
}



/*
 *
 */
TAYOTYPE *GetTayoObject(void);
{
    int nRet = 1;

    return &g_tayo;
}



/*
 *
 */
int GameStart(void)
{
    int nRet = 1;
    int ch = 0;
    TAYOTYPE *pTayoObj = NULL;



    // 변수 초기화하기
    InitTayoObject();    
    pTayoObj = GetTayoObject();

    // 터미널 초기화하기
    initscr();
    
    // 커서 숨기기
    curs_set(0);

    // 특수키 입력 허용하기
    keypad(stdscr, TRUE);

    // 타임아웃 설정하기
    timeout(30);

    while( (ch != 'q') && (ch != 'Q') )
    {
        // 사용자 키 입력받기
        ch = getch();

        switch(ch)
        {
        case KEY_UP:
            FillObject(' ', pTayoObj->nX, pTayoObj->nY, pTayoObj->nWidth, pTayoObj->nHeight);
            pTayoObj->nY = pTayoObj->nY - 1;
            DrawObject(pTayoObj->pShape, pTayoObj->nX, pTayoObj->nY, pTayoObj->nWidth, pTayoObj->nHeight);
            break;
        case KEY_DOWN:
            FillObject(' ', pTayoObj->nX, pTayoObj->nY, pTayoObj->nWidth, pTayoObj->nHeight);
            pTayoObj->nY = pTayoObj->nY + 1;
            DrawObject(pTayoObj->pShape, pTayoObj->nX, pTayoObj->nY, pTayoObj->nWidth, pTayoObj->nHeight);
            break;
        case KEY_LEFT:
            FillObject(' ', pTayoObj->nX, pTayoObj->nY, pTayoObj->nWidth, pTayoObj->nHeight);
            pTayoObj->nX = pTayoObj->nX - 1;
            DrawObject(pTayoObj->pShape, pTayoObj->nX, pTayoObj->nY, pTayoObj->nWidth, pTayoObj->nHeight);
            break;
        case KEY_RIGHT:
            FillObject(' ', pTayoObj->nX, pTayoObj->nY, pTayoObj->nWidth, pTayoObj->nHeight);
            pTayoObj->nX = pTayoObj->nX + 1;
            DrawObject(pTayoObj->pShape, pTayoObj->nX, pTayoObj->nY, pTayoObj->nWidth, pTayoObj->nHeight);
            break;
        }
    }

    // 터미널 종료하기
    keypad(stdscr, FALSE);
    endwin();

    return nRet;
}