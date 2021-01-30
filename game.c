#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//初始化棋盘实现
void InitBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

//打印棋盘实现
void DisplayBoard_0(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
			printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
			if(i<row-1) 
				printf("---|---|---\n");
	}
}

void DisplayBoard_1(char board[ROW][COL], int row, int col) {
	//打印数据
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		//打印份隔行
		if (i < row - 1) 
		{
			for (int j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：>\n");
	while(1){
		printf("请输入要下的坐标：>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] ='*';
				break;
			}else {
				printf("该坐标被占用!\n");
			}
		}
		else {
			printf("坐标非法，请重新输入\n");
		}
	}
}



//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("电脑走：>\n");
	while(1){
		x = rand() % row; //生成随机坐标
		y = rand() % col;
		if (board[x - 1][y - 1] == ' ') {
			board[x - 1][y - 1] = '#';
			break;
		}
	}	
}


int Isfull(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
//判别输赢
//玩家赢
//电脑赢
//平局
//继续
char IsWin(char board[ROW][COL], int row, int col) {
	//检查行
	for (int i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return board[i][0];
		}
	}
	//检查列
	for (int j = 0; j < col; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
			return board[0][j];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
		return board[0][2];
	}
	//判断平局
	if (1 == Isfull(board, ROW, COL)) {
		return 'Q';
	}
	else {
		return 'C';
	}
}