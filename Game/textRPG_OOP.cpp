#include <iostream>
#include <time.h>

using namespace std;


enum BATTLE
{
    BATTLE_NONE,
    BATTLE_ATTACK,
    BATTLE_BACK
};



enum STORE_MENU
{
    SM_NONE,
    SM_WEAPON,
    SM_ARMOR,
    SM_BACK
};

enum EQUI
{
    EQ_WEAPON,
    EQ_ARMOR,
    EQ_MAX
};




struct _tagLevelUpStatus
{
    int iAttackMin;
    int iAttackMax;
    int iArmorMin;
    int iArmorMax;
    int iHPMin;
    int iHPMax;
    int iMPMin;
    int iMPMax;
};

enum MAIN_MENU
{
    MM_NONE,
    MM_MAP,
    MM_STORE,
    MM_INVENTORY,
    MM_EXIT
};


// 숫자 입력을 받는다. 입력 오류까지 처리해주고 INT_MAX를 리턴하면
// 입력 오류이다. 
int InputInt()
{
	
	int iInput;
	cin >> iInput;
	
	if (cin.fail()) {

        cin.clear();
        cin.ignore(1024, '\n');
        return INT_MAX; // INT_MAX가 리턴되면 입력이 잘못됐다는 의미이다. 
    }
    
    return iInput;
}


// 메인 메뉴를 화면에 보여주고 입력받은 메뉴를 반환한다.
// 입력 오류일 경우 혹은 잘못된 번호를 입력한 경우 MM_NONE을
// 반환해준다. 
int OutputMainMenu()
{	
	system("cls");
    cout << "************************** 로비 **************************" << endl;
    cout << "1. 맵" << endl;
    cout << "2. 상점" << endl;
    cout << "3. 가방" << endl;
    cout << "4. 종료" << endl;
    cout << "메뉴를 선택하세요 : ";
    int iMenu = InputInt();
	
	if(iMenu == INT_MAX || iMenu <= MM_NONE || iMenu > MM_EXIT){
		return MM_NONE;	
	}
    
    return iMenu;
}


enum MAP_TYPE
{
    MT_NONE,
    MT_EASY,
    MT_NORMAL,
    MT_HARD,
    MT_BACK
};

void OutputBattleTag(int iMenu)
{
	switch (iMenu)
    {
        case MT_EASY:
        	cout << "************************** 쉬움 **************************" << endl;
        	break;
        case MT_NORMAL:
        	cout << "************************** 보통 **************************" << endl;
            break;
        case MT_HARD:
            cout << "************************** 어려움 **************************" << endl;
            break;
    }
	
}

void OutputPlayer(_tagPlater* pPlayer)
{
	cout << "************************** Player **************************" << endl;
    cout << "이름 : " << pPlayer->strName << "\t직업 : " << pPlayer->strJobName << endl;
    cout << "레벨 : " << pPlayer->iLevel << "\t경험치 : " << pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << endl;
    cout << "공격력 : " << iAttackMin << " - " << iAttackMax << "\t방어력 : " << iArmorMin << " - " << iArmorMax << endl;
    cout << "체력 : " << pPlayer->iHP << " / " << pPlayer->iHPMax << "\t마나 : " << pPlayer->iMP << " / " << pPlayer->iMPMax << endl;
    cout << "보유골드 : " << pPlayer->tInventory->iGold << " Gold" << endl;


	// 무기를 장착하고 있을 경우 무기의 Min, Max를 더해준다.
    if (pPlayer->bEquip[EQ_WEAPON])
    {
        iAttackMin += pPlayer->tEquip[EQ_WEAPON].iMin;
        iAttackMax += pPlayer->tEquip[EQ_WEAPON].iMax;
    }

    int iArmorMin = pPlayer->iArmorMin;
    int iArmorMax = pPlayer->iArmorMax;

    // 방어구를 장착하고 있을 경우 방어의 Min, Max를 더해준다.
    if (pPlayer->bEquip[EQ_ARMOR])
    {
        iArmorMin += pPlayer->tEquip[EQ_ARMOR].iMin;
    	iArmorMax += pPlayer->tEquip[EQ_ARMOR].iMax;
    }
    

}

void OutputMonster(_tagMonster* pMonster)
{
	 // 몬스터 정보 출력
    cout << "************************** Monster **************************" << endl;
    cout << "이름 : " << pMonster->strName << "\t레벨 : " << pMonster->iLevel << endl;
    cout << "공격력 : " << pMonster->iAttackMin << " - " << pMonster->iAttackMax << "\t방어력 : " << pMonster->iArmorMin << " - " << pMonster->iArmorMax << endl;
    cout << "체력 : " << pMonster->iHP << " / " << pMonster->iHPMax << "\t마나 : " << pMonster->iMP << " / " << pMonster->iMPMax << endl;
    cout << "획득 경험치 : " << pMonster->iExp << "\t획득골드 : " << pMonster->iGoldMin << " - " << pMonster->iGoldMax << endl;


	
	
}

int OutputBattleMenu()
{
	cout << "1. 공격" << endl;
    cout << "2. 도망가기" << endl;
    cout << "메뉴를 선택하세요 : ";
	int iMenu = InputInt();
                    
	if (iMenu == INT_MAX || iMenu <= BATTLE_NONE || iMenu > BATTLE_BACK)
    	return BATTLE_NONE;
    	
    return iMenu;
}


void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, int iMenu)
{
	
	_tagMonster tMonster = pMonsterArr[iMenu - 1];
	
	while(true)
	{
		system("cls");
		OutputBattleTag(iMenu);
		
		// 플레이어 출력
		OutputPlayer(pPlayer);
		
		// 몬스터 출력
		OutputMonster(&tMonster);
		 
		switch(OutputBattleMenu())
		{
			case BATTLE_ATTACK;
				break;
			case BATTLE_BACK;
				return;
			
			
		}
		
	}
	
}


int OutputMapMenu()
{
	system("cls");
    cout << "************************** 맵 **************************" << endl;
    cout << "1. 쉬움" << endl;
    cout << "2. 보통" << endl;
    cout << "3. 어려움 " << endl;
    cout << "4. 뒤로가기" << endl;
	cout << "맵을 선택하세요: ";
    int iMenu = InputInt();
	
	if(iMenu == INT_MAX || iMenu <= MT_NONE || iMenu > MT_BACK){
		return MT_NONE;	
	}
    
    return iMenu;
}




// Map에 관련된 동작을 처리한다. 
void RunMap(_tagPlayer* pPlayer, _tagMonster* pMonsterArr)
{
	
	 
	bool bLoop = true;
	while(bLoop){
		
		int iMenu = OutputMapMenu();
		
//		switch(OutputMapMenu())
//		{
//			case MT_EASY:
//				RunMapEasy();         
//				break;
//			case MT_NORMAL:
//				cout << "************************** 보통 **************************" << endl;
//                         
//				break;
//			case MT_HARD:
//				cout << "************************** 어려움 **************************" << endl;
//                         
//				break;
//			case MT_BACK:
//				bLoop = false;
//				break; 
//			
//		}
		if(iMenu == MT_BACK) return;
		
		// 전투를 시작한다.
		RunBattle(pPlayer, pMonsterArr, iMenu); 
		
	}
	
}

enum JOB
{
    JOB_NONE,
    JOB_KNIGHT,
    JOB_ARCHER,
    JOB_WIZARD,
    JOB_END
};

enum ITEM_TYPE
{
    IT_NONE,
    IT_WEAPON,
    IT_ARMOR,
    IT_BACK
};

#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3
#define LEVEL_MAX 10

// 레벨업에 필요한 경험치 목록을 만든다.
const int g_iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };


struct _tagItem
{
    char strName[NAME_SIZE];
    char strTypeName[NAME_SIZE];
    ITEM_TYPE eType;
    int iMin;
    int iMax;
    int iPrice;
    int iSell;
    char strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory
{
    _tagItem tItem[INVENTORY_MAX];
    int iItemCount;
    int iGold;
};


struct _tagPlayer
{
    char strName[NAME_SIZE];
    char strJobName[NAME_SIZE];
    JOB eJob;
    int iAttackMin;
    int iAttackMax;
    int iArmorMin;
    int iArmorMax;
    int iHP;
    int iHPMax;
    int iMP;
    int iMPMax;
    int iExp;
    int iLevel;
    _tagItem tEquip[EQ_MAX];
    bool bEquip[EQ_MAX];
    _tagInventory tInventory;
};

struct _tagMonster
{
    char strName[NAME_SIZE];
    int iAttackMin;
    int iAttackMax;
    int iArmorMin;
    int iArmorMax;
    int iHP;
    int iHPMax;
    int iMP;
    int iMPMax;
    int iLevel;
    int iExp;
    int iGoldMin;
    int iGoldMax;

};


int SelectJob()
{
	int iJob = JOB_NONE;
	while(iJob == JOB_NONE)
	{
		system("cls");
	    cout << "1. 기사" << endl;
	    cout << "2. 궁수" << endl;
	    cout << "3. 마법사" << endl;
	    cout << "직업을 선택하세요 : ";
	    iJob = InputInt();
	        
	    if(iJob == INT_MAX || iJob <= JOB_NONE || iJob >= JOB_END){
			iJob = JOB_NONE;	
		}
	}
    
    return iJob;
}
	



// 포인터 타입으로 받아야 변경가능 
void SetPlayer(_tagPlayer* pPlayer)
{
	// 플레이어 이름을 입력 받는다.
    cout << "이름 : ";
    cin.getline(tPlayer->strName, NAME_SIZE - 1);
	
	pPlayer->eJob = (JOB)SelectJob();
	pPlayer->iLevel = 1;
    pPlayer->iExp = 0;
    pPlayer->eJob = (JOB)iJob;
    pPlayer->tInventory.iGold = 10000;
	
	switch (pPlayer->eJob)
    {
    case JOB_KNIGHT:
        strcpy_s(pPlayer->strJobName, "기사");
        pPlayer->iAttackMin = 5;
        pPlayer->iAttackMax = 10;
        pPlayer->iArmorMin = 15;
        pPlayer->iArmorMax = 20;
        pPlayer->iHPMax = 500;
        pPlayer->iHP = 500;
        pPlayer->iMP = 100;
        pPlayer->iMPMax = 100;
        break;
    case JOB_ARCHER:
        strcpy_s(pPlayer->strJobName, "궁수");
        pPlayer->iAttackMin = 10;
        pPlayer->iAttackMax = 15;
        pPlayer->iArmorMin = 10;
        pPlayer->iArmorMax = 15;
        pPlayer->iHPMax = 400;
        pPlayer->iHP = 400;
        pPlayer->iMP = 200;
        pPlayer->iMPMax = 200;
        break;
    case JOB_WIZARD:
        strcpy_s(pPlayer->strJobName, "마법사");
        pPlayer->iAttackMin = 15;
        pPlayer->iAttackMax = 20;
        pPlayer->iArmorMin = 5;
        pPlayer->iArmorMax = 10;
        pPlayer->iHPMax = 300;
        pPlayer->iHP = 300;
        pPlayer->iMP = 300;
        pPlayer->iMPMax = 300;
        break;
    }
	
}

_tagMonster CreateMonster(char* pName, int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHP, int iHPMax, int iMP, int iMPMax,
int iLevel, int iExp, int iGoldMin, int iGoldMax)
{
	
	_tagMonster tMonster = {};

    strcpy_s(tMonster.strName, pName);
    tMonster.iAttackMin = iAttackMin;
    tMonster.iAttackMax = iAttackMax;
    tMonster.iArmorMin = iArmorMin;
    tMonster.iArmorMax = iArmorMax;
    tMonster.iHP = iHP;
    tMonster.iHPMax = iHPMax;
    tMonster.iMP = iMP;
    tMonster.iMPMax = iMPMax;
    tMonster.iLevel = iLevel;
    tMonster.iExp = iExp;
    tMonster.iGoldMin = iGoldMin;
    tMonster.iGoldMax = iGoldMax;
	
	return tMonster;
}

void SetMonster(_tagMonster* pMonsterArr)
{
	pMonsterArr[0] = CreateMonster("고불린", 20, 30, 2, 5, 100, 100, 10, 10, 1, 1000, 500, 1500);
	pMonsterArr[1] = CreateMonster("트롤", 80, 130, 60, 90, 2000, 2000, 100, 100, 5, 7000, 6000, 8000);
	pMonsterArr[2] = CreateMonster("드래곤", 250, 500, 200, 400, 30000, 30000, 20000, 20000, 10, 30000, 20000, 50000);
	
}

int main() 
{

    srand((unsigned int)time(0));

	// 게임을 시작할때 플레이어 정보를 설정하게 한다.
    _tagPlayer tPlayer = {};
	
	// 플레이어의 정보를 정의한다. 
	SetPlayer(&tPlayer);


	// 몬스터를 생성한다
    _tagMonster tMonsterArr[MT_BACK - 1] = {};
    
    // 배열명은 포인터주소이다. 
	SetMonster(tMonsterArr);
	
// 전역변수로 
//    // 레벨업에 필요한 경험치 목록을 만든다.
//    const int iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };

    // JOB_END는 4이다. 그런데 직업은 3개이므로 -1을 해주어서 배열을 각 직업별로
    // 생성하도록 한다.
    _tagLevelUpStatus tLvUpTable[JOB_END - 1] = {};

    tLvUpTable[JOB_KNIGHT - 1].iAttackMin = 4;
    tLvUpTable[JOB_KNIGHT - 1].iAttackMax = 10;
    tLvUpTable[JOB_KNIGHT - 1].iArmorMin = 8;
    tLvUpTable[JOB_KNIGHT - 1].iArmorMax = 16;
    tLvUpTable[JOB_KNIGHT - 1].iHPMin = 50;
    tLvUpTable[JOB_KNIGHT - 1].iHPMax = 100;
    tLvUpTable[JOB_KNIGHT - 1].iMPMin = 10;
    tLvUpTable[JOB_KNIGHT - 1].iMPMax = 20;

    tLvUpTable[JOB_WIZARD - 1].iAttackMin = 15;
    tLvUpTable[JOB_WIZARD - 1].iAttackMax = 20;
    tLvUpTable[JOB_WIZARD - 1].iArmorMin = 3;
    tLvUpTable[JOB_WIZARD - 1].iArmorMax = 7;
    tLvUpTable[JOB_WIZARD - 1].iHPMin = 20;
    tLvUpTable[JOB_WIZARD - 1].iHPMax = 40;
    tLvUpTable[JOB_WIZARD - 1].iMPMin = 50;
    tLvUpTable[JOB_WIZARD - 1].iMPMax = 100;



    // 몬스터를 생성한다
    _tagMonster tMonsterArr[MT_BACK - 1] = {};
	
	CreateMonster(tMonsterArr);
	

    // 상점에서 판매할 아이템 목록을 생성한다.
    _tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
    _tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

    // 각 아이템 정보들을 설정해준다.
    // 공격 무기
    strcpy_s(tStoreWeapon[0].strName, "강철의 검");
    strcpy_s(tStoreWeapon[0].strTypeName, "검");
    tStoreWeapon[0].eType = IT_WEAPON;
    tStoreWeapon[0].iMin = 200;
    tStoreWeapon[0].iMax = 300;
    tStoreWeapon[0].iPrice = 1500;

    strcpy_s(tStoreWeapon[1].strName, "다이아몬드 활");
    strcpy_s(tStoreWeapon[1].strTypeName, "활");
    tStoreWeapon[1].eType = IT_WEAPON;
    tStoreWeapon[1].iMin = 500;
    tStoreWeapon[1].iMax = 800;
    tStoreWeapon[1].iPrice = 2000;

    strcpy_s(tStoreWeapon[2].strName, "불꽃 지팡이");
    strcpy_s(tStoreWeapon[2].strTypeName, "지팡이");
    tStoreWeapon[2].eType = IT_WEAPON;
    tStoreWeapon[2].iMin = 800;
    tStoreWeapon[2].iMax = 1000;
    tStoreWeapon[2].iPrice = 2100;

    // 방어 무기
    strcpy_s(tStoreArmor[0].strName, "강철의 투구");
    strcpy_s(tStoreArmor[0].strTypeName, "머리");
    tStoreArmor[0].eType = IT_ARMOR;
    tStoreArmor[0].iMin = 20000;
    tStoreArmor[0].iMax = 40000;
    tStoreArmor[0].iPrice = 3000;

    strcpy_s(tStoreArmor[1].strName, "무적의 갑옷");
    strcpy_s(tStoreArmor[1].strTypeName, "몸통");
    tStoreArmor[1].eType = IT_ARMOR;
    tStoreArmor[1].iMin = 200000;
    tStoreArmor[1].iMax = 400000;
    tStoreArmor[1].iPrice = 4000;

    strcpy_s(tStoreArmor[2].strName, "철의 신발");
    strcpy_s(tStoreArmor[2].strTypeName, "신발");
    tStoreArmor[2].eType = IT_ARMOR;
    tStoreArmor[2].iMin = 3000;
    tStoreArmor[2].iMax = 4000;
    tStoreArmor[2].iPrice = 2000;


	bool bLoop = true;

    while (bLoop) {
        
        switch (OutputMainMenu()) {

        case MM_MAP:
        	
        	RunMap(&tPlayer, tMonsterArr); // Map 관련 루프를 처리한다. 
        	
        	
            while (true) {
                

                // 선택한 메뉴에서 1을 빼주면 몬스터 배열의 인덱스가 된다.
                // 그렇게 해서 해당 맵의 몬스터를 생성해준다.
                _tagMonster tMonster = tMonsterArr[iMenu - 1];

                while (true) {

                    
                    int iAttackMin = tPlayer.iAttackMin;
                    int iAttackMax = tPlayer.iAttackMax;


                    

                    switch (iMenu) {

                    case BATTLE_ATTACK:
                    {

                        int iAttack = rand() % (iAttackMax - iAttackMin + 1) + iAttackMin;
                        int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) + tMonster.iArmorMin;

                        int iDamage = iAttack - iArmor;


                        iDamage = iDamage < 1 ? 1 : iDamage;


                        // 몬스터 HP를 감소시킨다.
                        tMonster.iHP -= iDamage;

                        cout << tPlayer.strName << "가 " << tMonster.strName << "에게  " << iDamage << " 피해를 입혔습니다." << endl;

                        // 몬스터가 죽었을 경우를 처리한다.
                        if (tMonster.iHP <= 0) {

                            cout << tMonster.strName << " 몬스터가 사망하였습니다." << endl;

                            tPlayer.iExp += tMonster.iExp;
                            int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin);
                            tPlayer.tInventory.iGold += iGold;

                            cout << tMonster.iExp << " 경험치를 획득하였습니다." << endl;
                            cout << iGold << " Gold를 획득하였습니다." << endl;

                            tMonster.iHP = tMonster.iHPMax;
                            tMonster.iMP = tMonster.iMPMax;


                            // 레벨업을 했는지 체크해본다.
                            if (tPlayer.iExp >= iLevelUpExp[tPlayer.iLevel - 1])
                            {
                                // 플레이어 경험치를 레벨업에 필요한 경험치만큼 차감한다.
                                tPlayer.iExp -= iLevelUpExp[tPlayer.iLevel - 1];

                                // 레벨을 증가시킨다.
                                ++tPlayer.iLevel;

                                cout << " 레벨업 하였습니다." << endl;

                                // 능력치를 상승시킨다.
                                // 직업 인덱스를 구한다.
                                int iJobIndex = tPlayer.eJob - 1;
                                int iAttackUp = rand() % (tLvUpTable[iJobIndex].iAttackMax - tLvUpTable[iJobIndex].iAttackMin + 1) + tLvUpTable[iJobIndex].iAttackMin;
                                int iArmorUp = rand() % (tLvUpTable[iJobIndex].iArmorMax - tLvUpTable[iJobIndex].iArmorMin + 1) + tLvUpTable[iJobIndex].iArmorMin;

                                int iHPUp = rand() % (tLvUpTable[iJobIndex].iHPMax - tLvUpTable[iJobIndex].iHPMin + 1) + tLvUpTable[iJobIndex].iHPMin;
                                int iMPUp = rand() % (tLvUpTable[iJobIndex].iMPMax - tLvUpTable[iJobIndex].iMPMin + 1) + tLvUpTable[iJobIndex].iMPMin;

                                tPlayer.iAttackMin += tLvUpTable[iJobIndex].iAttackMin;
                                tPlayer.iAttackMax += tLvUpTable[iJobIndex].iAttackMax;
                                tPlayer.iArmorMin += tLvUpTable[iJobIndex].iArmorMin;
                                tPlayer.iArmorMax += tLvUpTable[iJobIndex].iArmorMax;

                                tPlayer.iHPMax += iHPUp;
                                tPlayer.iMPMax += iMPUp;


                                // 체력과 마나를 회복시킨다.
                                tPlayer.iHP = tPlayer.iHPMax;
                                tPlayer.iMP = tPlayer.iMPMax;

                            }


                            system("pause");
                            break;

                        }



                        // 몬스터가 살아있다면 플레이어를 공격한다.
                        iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin;


                        iArmor = rand() % (iArmorMax - iArmorMin + 1) + iArmorMin;
                        iDamage = iAttack - iArmor;
                        iDamage = iDamage < 1 ? 1 : iDamage;


                        // 플레이어의 HP를 감소시킨다.
                        tPlayer.iHP -= iDamage;

                        cout << tMonster.strName << "가 " << tPlayer.strName << "에게  " << iDamage << " 피해를 입혔습니다." << endl;

                        // 플레이어가 죽었을 경우를 처리한다.
                        if (tPlayer.iHP <= 0) {

                            cout << tPlayer.strName << " 플레이어가 사망하였습니다." << endl;

                            int iExp = tPlayer.iExp * 0.1f;
                            int iGold = tPlayer.tInventory.iGold * 0.1f;

                            tPlayer.iExp -= iExp;
                            tPlayer.tInventory.iGold -= iGold;


                            cout << iExp << " 경험치를 잃었습니다." << endl;
                            cout << iGold << " Gold를 잃었습니다." << endl;


                            // 플레이어의 HP와 MP를 회복한다.
                            tPlayer.iHP = tPlayer.iHPMax;
                            tPlayer.iMP = tPlayer.iMPMax;

                        }
                        system("pause");
                    }
                    break;
                    }

                }


            }
            break;
        case MM_STORE:
            while (true)
            {
                system("cls");
                cout << "************************** 상점 **************************" << endl;
                cout << "1. 무기상점" << endl;
                cout << "2. 방어구상점" << endl;
                cout << "3. 뒤로가기" << endl;
                cout << "상점을 선택하세요: ";
                cin >> iMenu;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }
                else if (iMenu == SM_BACK)
                    break;

                switch (iMenu)
                {
                case SM_WEAPON:
                    while (true)
                    {
                        system("cls");
                        cout << "************************** 무기상점 **************************" << endl;
                        // 판매 목록을 보여준다.
                        for (int i = 0; i < STORE_WEAPON_MAX; ++i) {
                            cout << i + 1 << ". 이름 : " << tStoreWeapon[i].strName << "\t종류 : " << tStoreWeapon[i].strTypeName << endl;
                            cout << "공격력 : " << tStoreWeapon[i].iMin << " - " << tStoreWeapon[i].iMax << endl;
                            cout << "판매가격 : " << tStoreWeapon[i].iPrice << "\t구매가격 : " << tStoreWeapon[i].iSell << endl;
                            cout << "설명 : " << tStoreWeapon[i].strDesc << endl;
                        }

                        cout << STORE_WEAPON_MAX + 1 << ". 뒤로가기" << endl;
                        cout << "보유금액 : " << tPlayer.tInventory.iGold << " Gold" << endl;
                        cout << "남은공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
                        cout << "구입할 아이템을 선택하세요 : ";
                        cin >> iMenu;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1024, '\n');
                            continue;
                        }
                        else if (iMenu == STORE_WEAPON_MAX + 1)
                            break;
                        else if (iMenu < 1 || iMenu > STORE_WEAPON_MAX + 1)
                        {
                            cout << "잘못 선택하였습니다." << endl;
                            system("pause");
                            continue;
                        }


                        // 상점판매목록 배열의 인덱스를 구한다.
                        int iWeaponIndex = iMenu - 1;

                        // 인벤토리가 꽉 찼는지 검사한다.
                        if (tPlayer.tInventory.iItemCount == INVENTORY_MAX) {

                            cout << "가방이 꽉 찼습니다." << endl;
                            system("pause");
                            continue;
                        }
                        // 돈이 부족할 경우
                        else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIndex].iPrice)
                        {
                            cout << "보유금액이 부족합니다." << endl;
                            system("pause");
                            continue;
                        }

                        // 처음에 iItemCount는 하나도 추가되어 있지 않기 떄문에 0으로 초기화
                        // 되어 있으므로 0번 인덱스에 구매한 아이템을 추가하게 된다. 그리고
                        // 카운트는 1이 된다. 다음번에 추가할때는 1번 인덱스에 추가하게 된다.
                        tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount]
                            = tStoreWeapon[iWeaponIndex];
                        ++tPlayer.tInventory.iItemCount;

                        // 골드를 차감한다.
                        tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIndex].iPrice;

                        cout << tStoreWeapon[iWeaponIndex].strName << " 아이템을 구매하였습니다." << endl;
                        system("pause");



                    }
                    break;
                case SM_ARMOR:
                    while (true)
                    {
                        system("cls");
                        cout << "************************** 방어구 상점 **************************" << endl;
                        // 판매 목록을 보여준다.
                        for (int i = 0; i < STORE_ARMOR_MAX; ++i) {
                            cout << i + 1 << ". 이름 : " << tStoreArmor[i].strName << "\t종류 : " << tStoreArmor[i].strTypeName << endl;
                            cout << "방어력 : " << tStoreArmor[i].iMin << " - " << tStoreArmor[i].iMax << endl;
                            cout << "판매가격 : " << tStoreArmor[i].iPrice << "\t구매가격 : " << tStoreArmor[i].iSell << endl;
                            cout << "설명 : " << tStoreArmor[i].strDesc << endl;
                        }

                        cout << STORE_ARMOR_MAX + 1 << ". 뒤로가기" << endl;
                        cout << "보유금액 : " << tPlayer.tInventory.iGold << " Gold" << endl;
                        cout << "남은공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
                        cout << "구입할 아이템을 선택하세요 : ";
                        cin >> iMenu;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1024, '\n');
                            continue;
                        }
                        else if (iMenu == STORE_ARMOR_MAX + 1)
                            break;
                        else if (iMenu < 1 || iMenu > STORE_ARMOR_MAX + 1)
                        {
                            cout << "잘못 선택하였습니다." << endl;
                            system("pause");
                            continue;
                        }


                        // 상점판매목록 배열의 인덱스를 구한다.
                        int iArmorIndex = iMenu - 1;

                        // 인벤토리가 꽉 찼는지 검사한다.
                        if (tPlayer.tInventory.iItemCount == INVENTORY_MAX) {

                            cout << "가방이 꽉 찼습니다." << endl;
                            system("pause");
                            continue;
                        }
                        // 돈이 부족할 경우
                        else if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice)
                        {
                            cout << "보유금액이 부족합니다." << endl;
                            system("pause");
                            continue;
                        }

                        // 처음에 iItemCount는 하나도 추가되어 있지 않기 떄문에 0으로 초기화
                        // 되어 있으므로 0번 인덱스에 구매한 아이템을 추가하게 된다. 그리고
                        // 카운트는 1이 된다. 다음번에 추가할때는 1번 인덱스에 추가하게 된다.
                        tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount]
                            = tStoreArmor[iArmorIndex];
                        ++tPlayer.tInventory.iItemCount;

                        // 골드를 차감한다.
                        tPlayer.tInventory.iGold -= tStoreArmor[iArmorIndex].iPrice;

                        cout << tStoreArmor[iArmorIndex].strName << " 아이템을 구매하였습니다." << endl;
                        system("pause");


                    }
                    break;
                }

            }
            break;
        case MM_INVENTORY:
            while (true) {
                system("cls");
                cout << "************************** 가방 **************************" << endl;
                cout << "************************** Player **************************" << endl;
                cout << "이름 : " << tPlayer.strName << "\t직업 : " << tPlayer.strJobName << endl;
                cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << endl;

                // 무기를 장착하고 있을 경우 공격력에 무기 공격력을 추가하여 출력한다.
                if (tPlayer.bEquip[EQ_WEAPON] == true)
                {
                    cout << "공격력 : " << tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " - " << tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax;
                }
                else
                {
                    cout << "공격력 : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax;
                }

                // 방어구를 장착하고 있을 경우 방어력에 방어구 방어력을 추가하여 출력한다.

                if (tPlayer.bEquip[EQ_ARMOR] == true)
                {
                    cout << "\t방어력 : " << tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " - " << tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
                }
                else
                {
                    cout << "\t방어력 : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
                }


                cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax << "\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
                cout << "보유골드 : " << tPlayer.tInventory.iGold << " Gold" << endl;


                if (tPlayer.bEquip[EQ_WEAPON])
                    cout << "장착 무기 : " << tPlayer.tEquip[EQ_WEAPON].strName;
                else
                    cout << "장착 무기 : 없음";

                if (tPlayer.bEquip[EQ_ARMOR])
                    cout << "\t장착 방어구 : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;
                else
                    cout << "\t장착 방어구 : 없음" << endl;


                cout << endl;


                for (int i = 0; i < tPlayer.tInventory.iItemCount; ++i)
                {
                    cout << i + 1 << ". 이름 : " << tPlayer.tInventory.tItem[i].strName << "\t종류 : " << tPlayer.tInventory.tItem[i].strTypeName << endl;
                    cout << "공격력 : " << tPlayer.tInventory.tItem[i].iMin << " - " << tPlayer.tInventory.tItem[i].iMax << endl;
                    cout << "판매가격 : " << tPlayer.tInventory.tItem[i].iPrice << "\t구매가격 : " << tPlayer.tInventory.tItem[i].iSell << endl;
                    cout << "설명 : " << tPlayer.tInventory.tItem[i].strDesc << endl;

                }

                cout << tPlayer.tInventory.iItemCount + 1 << ". 뒤로가기" << endl;
                cout << "장착할 아이템을 선택하세요 : ";
                cin >> iMenu;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    continue;
                }
                else if (iMenu == tPlayer.tInventory.iItemCount + 1)
                    break;
                else if (iMenu < 1 || iMenu > tPlayer.tInventory.iItemCount + 1)
                {
                    cout << "잘못 선택하였습니다." << endl;
                    system("pause");
                    continue;
                }

                // 아이템 인덱스를 구해준다.
                int idx = iMenu - 1;

                // 제대로 선택했을 경우 해당 아이템의 종류에 따라 장착 부위를
                // 결정하게 한다.
                EQUI eq;

                switch (tPlayer.tInventory.tItem[idx].eType)
                {
                case IT_WEAPON:
                    eq = EQ_WEAPON;
                    break;
                case IT_ARMOR:
                    eq = EQ_ARMOR;
                    break;
                }

                // 아이템이 장착되어 있을 경우
                // 장착되어 있는 아이템과 장착할 아이템을 교체해 주어야 한다. Swap 알고리즘을 활용한다.
                if (tPlayer.bEquip[eq] == true)
                {
                    _tagItem tSwap = tPlayer.tEquip[eq];
                    tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];
                    tPlayer.tInventory.tItem[idx] = tSwap;

                }

                // 장착되어 있지 않은 경우
                // 인벤토리 아이템을 장착장으로 옮기고 인벤토리는 1칸 비워지게 된다.
                else
                {
                    tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];

                    for (int i = idx; i < tPlayer.tInventory.iItemCount - 1; ++i)
                    {
                        tPlayer.tInventory.tItem[i] = tPlayer.tInventory.tItem[i + 1];
                    }
                    --tPlayer.tInventory.iItemCount;

                    // 장착을 했기 때문에 true로 만들어준다.
                    tPlayer.bEquip[eq] = true;

                }

                cout << tPlayer.tEquip[eq].strName << " 아이템을 장착하였습니다." << endl;


                system("pause");
            }

            break;
        case MM_EXIT:
        	bLoop = false;
        	break;
		default:
            cout << "잘못 선택하였습니다." << endl;
            break;
        }

    }

    return 0;
}
