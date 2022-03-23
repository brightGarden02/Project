#include <iostream>
#include <conio.h>

using namespace std;


/*
0:  벽
1: 길
2: 시작점
3: 도착점
4: 폭탄 
5: 폭탄 이펙트 
*/


struct _tagPoint
{
	int x;
	int y;
};


// typedef: 타입을 재정의하는 기능이다. 
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;



void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos)
{
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	*pPlayerPos = *pStartPos;


	strcpy_s(Maze[0], "21100000000000000000");
	strcpy_s(Maze[1], "00111111111100000000");
	strcpy_s(Maze[2], "00100010100111111100");
	strcpy_s(Maze[3], "01100000100000000100");
	strcpy_s(Maze[4], "01000000100000000100");
	strcpy_s(Maze[5], "01000000111100111100");
	strcpy_s(Maze[6], "01000000000000010000");
	strcpy_s(Maze[7], "01100000000000010000");
	strcpy_s(Maze[8], "01111111111111111110");
	strcpy_s(Maze[9], "00100000001000000000");
	strcpy_s(Maze[10], "00100000001000000000");
	strcpy_s(Maze[11], "00100000111000011110");
	strcpy_s(Maze[12], "01101000100000010000");
	strcpy_s(Maze[13], "01001000100000010000");
	strcpy_s(Maze[14], "01001001100011110000");
	strcpy_s(Maze[15], "01101111000010010000");
	strcpy_s(Maze[16], "00100001111110010000");
	strcpy_s(Maze[17], "01101000000001111100");
	strcpy_s(Maze[18], "00101001100000000000");
	strcpy_s(Maze[19], "01111111111111111113");

}

void Output(char Maze[21][21], PPOINT pPlayerPos)
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if(Maze[i][j] == '4')
				cout << "♨";			

			else if (pPlayerPos->x == j && pPlayerPos->y == i)
				cout << "☆";

			else if (Maze[i][j] == '0')
				cout << "ㅁ";

			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "★";

			else if (Maze[i][j] == '3')
				cout << "◎";

		}
		cout << endl;
	}
}


void MoveUp(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y - 1 >= 0)
	{
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0' &&
			Maze[pPlayerPos->y - 1][pPlayerPos->x] != '4')
		{
			--pPlayerPos->y;
		}
	}

}

void MoveDown(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y + 1 < 20)
	{
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0'&&
			Maze[pPlayerPos->y + 1][pPlayerPos->x] != '4')
		{
			++pPlayerPos->y;
		}
	}

}

void MoveLeft(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x - 1 >= 0)
	{
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0'&&
			Maze[pPlayerPos->y][pPlayerPos->x - 1] != '4')
		{
			--pPlayerPos->x;
		}
	}

}


void MoveRight(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x + 1 < 20)
	{
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0'&&
			Maze[pPlayerPos->y][pPlayerPos->x + 1] != '4')
		{
			++pPlayerPos->x;
		}
	}

}


void MovePlayer(char Maze[21][21], PPOINT pPlayerPos, char cinput)
{

	switch (cinput)
	{
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayerPos);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;

	}

}


// 포인터 변수를 const로 생성하면 가리키는 대상의 값을 변경할 수 없다. 
void CreateBomb(char Maze[21][21] , const PPOINT pPlayer,
PPOINT pBombArr, int* pBombCount)
{
	if(*pBombCount == 5)
		return;
	
	
	for(int i = 0; i < *pBombCount; ++i)
	{
		if(pPlayer->x == pBombArr[i].x &&
		pPlayer->y == pBombArr[i].y)
			return;
	}
	
	pBombArr[*pBombCount] = *pPlayer;
	++(*pBombCount);
	
	
	Maze[pPlayer->y][pPlayer->x] = '4';
			
	
}


void Fire(char Maze[21][21], PPOINT pPlayer, PPOINT pBombArr,
int* pBombCount)
{
	
	for(int i = 0; i < *pBombCount; ++i)
	{
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';
		
		// 플레이어가 폭탄에 맞았을 때 시작점으로 보낸다.
		if(pPlayer->x == pBombArr[i].x &&
			pPlayer->y == pBombArr[i].y)
		{
			pPlayer->x = 0;
			pPlayer->y = 0;
		 } 
		 
		if(pBombArr[i].y - 1 >= 0)
		{
			if(Maze[pBombArr[i].y - 1][pBombArr[i].x] == '0')
				Maze[pBombArr[i].y - 1][pBombArr[i].x] = '1';
		
			if(pPlayer->x == pBombArr[i].x &&
				pPlayer->y == pBombArr[i].y - 1)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
		 	} 	
		}
		if(pBombArr[i].x - 1 >= 0)
		{
			if(Maze[pBombArr[i].y][pBombArr[i].x - 1] == '0')
				Maze[pBombArr[i].y][pBombArr[i].x - 1] = '1';
			
			if(pPlayer->x == pBombArr[i].x - 1 &&
				pPlayer->y == pBombArr[i].y)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
		 	} 	
		}
		if(pBombArr[i].y + 1 < 20 )
		{
			if(Maze[pBombArr[i].y + 1][pBombArr[i].x] == '0')
				Maze[pBombArr[i].y + 1][pBombArr[i].x] = '1';
	
			if(pPlayer->x == pBombArr[i].x &&
				pPlayer->y == pBombArr[i].y + 1)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			 } 		
		}	
		if(pBombArr[i].x + 1 < 20)
		{
			if(Maze[pBombArr[i].y][pBombArr[i].x + 1] == '0')
				Maze[pBombArr[i].y][pBombArr[i].x + 1] = '1';
	
			if(pPlayer->x == pBombArr[i].x + 1 &&
			pPlayer->y == pBombArr[i].y)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			 } 		
		}	
		
	}
	 
	*pBombCount = 0;
	
}

int main()
{
	// 20 * 20 미로를 만든다.
	char strMaze[21][21];

	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;

	int iBombCount = 0;
	int iAddBomb = 0;
	
	POINT tBombPos[5];

	// 미로를 설정한다. 
	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);


	while (true)
	{
		system("cls");

		// 미로를 출력한다. 
		Output(strMaze, &tPlayerPos);
		
		if(tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y)
		{
			cout << "도착했습니다." << endl;
			break; 
		}
		
		
		
		cout << "t: 폭탄설치, u: 폭탄 터트리기" << endl;
		cout << "w: 위, s: 아래, a: 왼쪽, d: 오른쪽, q: 종료:  ";
		char cinput = _getch();

		if (cinput == 'q' || cinput == 'Q')
			break;

		else if(cinput == 't' || cinput == 'T')
			CreateBomb(Maze, &pPlayerPos, tBombPos, &tBombCount);
		
		else if(cinput == 'u' || cinput == 'U')
		{
			Fire(Maze, &pPlayerPos, pBombPos, &pBombCount)
		}
		
		else
			MovePlayer(strMaze, &tPlayerPos, cinput);

	}


	return 0;
}
