#include <iostream>
#include <conio.h>

using namespace std;


/*
0:  벽
1: 길
2: 시작점
3: 도착점
*/


struct _tagPoint()
{
	int x;
	int y;
}


// typedef: 타입을 재정의하는 기능이다. 
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;



void SetMaze(char Maze[21][21])
{
	strcpy_s(Maze[0], "21100000000000000000");
	strcpy_s(Maze[1], "00111111111100000000");
	strcpy_s(Maze[2], "00100010100111111100");
	strcpy_s(Maze[3], "01100000100000000100");
	strcpy_s(Maze[4], "01000000100000000100");
	strcpy_s(Maze[5], "01000000111100111100");
	strcpy_s(Maze[6], "01000000000000010000");
	strcpy_s(Maze[7], "01100000000000010000");
	strcpy_s(Maze[8], "01111111111111111111");
	strcpy_s(Maze[9], "01100000000000000000");
	strcpy_s(Maze[10], "01100000000000000000");
	strcpy_s(Maze[11], "01100000000000000000");
	strcpy_s(Maze[12], "01100000000000000000");
	strcpy_s(Maze[13], "01100000000000000000");
	strcpy_s(Maze[14], "01100000000000000000");
	strcpy_s(Maze[15], "01100000000000000000");
	strcpy_s(Maze[16], "01100000000000000000");
	strcpy_s(Maze[17], "01100000000000000000");
	strcpy_s(Maze[18], "00100000000000000000");
	strcpy_s(Maze[19], "01111111111111111113");

}

void Output(char Maze[21][21])
{
	for (int i = 0 i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (Maze[i][j] == '0')
				cout << " ";

			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "★";

			else if (Mazr[i][j] == '3')
				cout << "◎";

		}
		cout < endl;
	}
}

int main()
{
	// 20 * 20 미로를 만든다.
	char strMaze[21][21];

	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;


	// 미로를 설정한다. 
//	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

	SetMaze(strMaze);

	while (true)
	{
		system("cls");

		// 미로를 출력한다. 
		Output(strMaze);
		cout << "w: 위, s: 아래, a: 왼쪽, d: 오른쪽, q: 종료:  ";
		char cinput = _getch();

		if (cinput == 'q' || cinput == 'Q')
			break;

	}


	return 0;
}