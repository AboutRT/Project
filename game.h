#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
#include <stdio.h>
#include <time.h>
#include <stdlib.h> //rand头文件
//初始化棋盘声明
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘声明
void DisplayBoard_0(char board[ROW][COL], int row, int col);
void DisplayBoard_1(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//判别输赢
char IsWin(char board[ROW][COL], int row, int col);

int Isfull(char board[ROW][COL], int row, int col);