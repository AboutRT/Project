#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��ʼ������ʵ��
void InitBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

//��ӡ����ʵ��
void DisplayBoard_0(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
			printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
			if(i<row-1) 
				printf("---|---|---\n");
	}
}

void DisplayBoard_1(char board[ROW][COL], int row, int col) {
	//��ӡ����
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		//��ӡ�ݸ���
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
//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����ߣ�>\n");
	while(1){
		printf("������Ҫ�µ����꣺>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] ='*';
				break;
			}else {
				printf("�����걻ռ��!\n");
			}
		}
		else {
			printf("����Ƿ�������������\n");
		}
	}
}



//��������
void ComputerMove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("�����ߣ�>\n");
	while(1){
		x = rand() % row; //�����������
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
//�б���Ӯ
//���Ӯ
//����Ӯ
//ƽ��
//����
char IsWin(char board[ROW][COL], int row, int col) {
	//�����
	for (int i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return board[i][0];
		}
	}
	//�����
	for (int j = 0; j < col; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
			return board[0][j];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
		return board[0][2];
	}
	//�ж�ƽ��
	if (1 == Isfull(board, ROW, COL)) {
		return 'Q';
	}
	else {
		return 'C';
	}
}