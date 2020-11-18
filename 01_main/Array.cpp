#include <iostream>

#include "Array.h"



/*
 * �� �� �� : CreateArray
 * ��    �� : 2���� ���� �޸� �Ҵ� (nRow x nCol)
 */
void CreateArray(char ***pData, char nRow, char nCol)
{
        int i = 0;
        char **p = NULL;


        p = new char *[nRow];
        for (i = 0; i < nRow; i++)
        {
                p[i] = new char[nCol];
        }

        *pData = p;
}

/*
 * �� �� �� : DeleteArray
 * ��    �� : ���� �޸� ����
 */
void DeleteArray(char ***pData, int nRow)
{
        int i = 0;

        char **p = 0;



        p = *pData;

        for (i = 0; i < nRow; i++)
        {
                delete [] p[i];
                p[i] = NULL;
        }

        delete [] p;
        p = NULL;

        *pData = p;
}
