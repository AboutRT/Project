#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
#include <stdio.h>
#include <time.h>
#include <stdlib.h> //randͷ�ļ�
//��ʼ����������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ��������
void DisplayBoard_0(char board[ROW][COL], int row, int col);
void DisplayBoard_1(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//�б���Ӯ
char IsWin(char board[ROW][COL], int row, int col);

int Isfull(char board[ROW][COL], int row, int col);