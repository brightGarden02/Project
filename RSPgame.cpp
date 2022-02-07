#include <iostream>
#include <time.h> // 랜덤 테이블을 만들기 위해 time.h 라이브러리 생성
using namespace std;

int main()
{

	srand((unsigned int)time(0)); // 난수 테이블 생성
	
	enum SRP // 가위 바위 보 열거체 생성, 1~4까지 구성
	{
		SRP_S = 1,
		SRP_R,
		SRP_P,
		SRP_END
	};


	int iPlayer, iAI;
	while (true) {

		cout << "1. 가위" << endl;
		cout << "2. 바위" << endl;
		cout << "3. 보" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		cin >> iPlayer;

		if (iPlayer < SRP_S || iPlayer > SRP_END) {
			cout << "잘못된 값을 입력하였습니다." << endl;

			// 일시정지
			system("puase");

			continue;
		}
		else if (iPlayer == SRP_END)
			break;

		// 봇이 선택을 한다
		iAI = rand() % 3 + SRP_S;

		switch (iAI) {

		case SRP_S:
			cout << "AI: 가위" << endl;
			break;
		case SRP_R:
			cout << "AI: 바위" << endl;
			break;
		case SRP_P:
			cout << "AI: 보" << endl;
			break;
		}

		int iWin = iPlayer - iAI;

		if (iWin == 1 || iWin == -2)
			cout << "Player 승리" << endl;
		else if (iWin == 0)
			cout << "비김" << endl;
		else
			cout << "AI 승리" << endl;

		system("pause");
	}
	
	return 0;
}