#include <iostream>
#include <time.h>

using namespace std;


#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3
#define LEVEL_MAX 10


enum EQUI
{
    EQ_WEAPON,
    EQ_ARMOR,
    EQ_MAX
};

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


// 레벨업에 필요한 경험치 목록을 만든다.
const int g_iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };

_tagLevelUpStatus g_tLvUpTable[JOB_END - 1] = {};



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


enum MAIN_MENU
{
    MM_NONE,
    MM_MAP,
    MM_STORE,
    MM_INVENTORY,
    MM_EXIT
};


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


// 수정이 필요해보임 
void OutputPlayer(_tagPlayer* pPlayer)
{
	cout << "************************** Player **************************" << endl;
    cout << "이름 : " << pPlayer->strName << "\t직업 : " << pPlayer->strJobName << endl;
    cout << "레벨 : " << pPlayer->iLevel << "\t경험치 : " << pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << endl;
    cout << "공격력 : " << pPlayer->iAttackMin << " - " << pPlayer->iAttackMax << "\t방어력 : " << pPlayer->iArmorMin << " - " << pPlayer->iArmorMax << endl;
    cout << "체력 : " << pPlayer->iHP << " / " << pPlayer->iHPMax << "\t마나 : " << pPlayer->iMP << " / " << pPlayer->iMPMax << endl;
    cout << "보유골드 : " << pPlayer->tInventory.iGold << " Gold" << endl;


	// 무기를 장착하고 있을 경우 무기의 Min, Max를 더해준다.
    if (pPlayer->bEquip[EQ_WEAPON])
    {
        pPlayer->iAttackMin += pPlayer->tEquip[EQ_WEAPON].iMin;
        pPlayer->iAttackMax += pPlayer->tEquip[EQ_WEAPON].iMax;
    }


    // 방어구를 장착하고 있을 경우 방어의 Min, Max를 더해준다.
    if (pPlayer->bEquip[EQ_ARMOR])
    {
        pPlayer->iArmorMin += pPlayer->tEquip[EQ_ARMOR].iMin;
    	pPlayer->iArmorMax += pPlayer->tEquip[EQ_ARMOR].iMax;
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


enum BATTLE
{
    BATTLE_NONE,
    BATTLE_ATTACK,
    BATTLE_BACK
};


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


void Battle(_tagPlayer* pPlayer, _tagMonster* pMonster)
{
	
    int iAttack = rand() % (pPlayer->iAttackMax - pPlayer->iAttackMin + 1) + pPlayer->iAttackMin;
	int iArmor = rand() % (pMonster->iArmorMax - pMonster->iArmorMin + 1) + pMonster->iArmorMin;

    int iDamage = iAttack - iArmor;

    iDamage = iDamage < 1 ? 1 : iDamage;


    // 몬스터 HP를 감소시킨다.
    pMonster->iHP -= iDamage;

    cout << pPlayer->strName << "가 " << pMonster->strName << "에게  " << iDamage << " 피해를 입혔습니다." << endl;

    // 몬스터가 죽었을 경우를 처리한다.
    if (pMonster->iHP <= 0) {

        cout << pMonster->strName << " 몬스터가 사망하였습니다." << endl;

        pPlayer->iExp += pMonster->iExp;
        int iGold = (rand() % (pMonster->iGoldMax - pMonster->iGoldMin + 1) + pMonster->iGoldMin);
        pPlayer->tInventory.iGold += iGold;

        cout << pMonster->iExp << " 경험치를 획득하였습니다." << endl;
        cout << iGold << " Gold를 획득하였습니다." << endl;

        pMonster->iHP = pMonster->iHPMax;
        pMonster->iMP = pMonster->iMPMax;


        // 레벨업을 했는지 체크해본다.
        if (pPlayer->iExp >= g_iLevelUpExp[pPlayer->iLevel - 1])
        {
            // 플레이어 경험치를 레벨업에 필요한 경험치만큼 차감한다.
            pPlayer->iExp -= g_iLevelUpExp[pPlayer->iLevel - 1];

            // 레벨을 증가시킨다.
            ++pPlayer->iLevel;

            cout << " 레벨업 하였습니다." << endl;

            // 능력치를 상승시킨다.
            // 직업 인덱스를 구한다.
            int iJobIndex = pPlayer->eJob - 1;
            int iAttackUp = rand() % (g_tLvUpTable[iJobIndex].iAttackMax - g_tLvUpTable[iJobIndex].iAttackMin + 1) + g_tLvUpTable[iJobIndex].iAttackMin;
            int iArmorUp = rand() % (g_tLvUpTable[iJobIndex].iArmorMax - g_tLvUpTable[iJobIndex].iArmorMin + 1) + g_tLvUpTable[iJobIndex].iArmorMin;

            int iHPUp = rand() % (g_tLvUpTable[iJobIndex].iHPMax - g_tLvUpTable[iJobIndex].iHPMin + 1) + g_tLvUpTable[iJobIndex].iHPMin;
            int iMPUp = rand() % (g_tLvUpTable[iJobIndex].iMPMax - g_tLvUpTable[iJobIndex].iMPMin + 1) + g_tLvUpTable[iJobIndex].iMPMin;

            pPlayer->iAttackMin += g_tLvUpTable[iJobIndex].iAttackMin;
            pPlayer->iAttackMax += g_tLvUpTable[iJobIndex].iAttackMax;
            pPlayer->iArmorMin += g_tLvUpTable[iJobIndex].iArmorMin;
            pPlayer->iArmorMax += g_tLvUpTable[iJobIndex].iArmorMax;

            pPlayer->iHPMax += iHPUp;
            pPlayer->iMPMax += iMPUp;


            // 체력과 마나를 회복시킨다.
            pPlayer->iHP = pPlayer->iHPMax;
            pPlayer->iMP = pPlayer->iMPMax;

        }

        return;

    }



        // 몬스터가 살아있다면 플레이어를 공격한다.
        iAttack = rand() % (pMonster->iAttackMax - pMonster->iAttackMin + 1) + pMonster->iAttackMin;


        iArmor = rand() % (pMonster->iArmorMax - pMonster->iArmorMin + 1) + pMonster->iArmorMin;
        iDamage = iAttack - iArmor;
        iDamage = iDamage < 1 ? 1 : iDamage;


		// 플레이어의 HP를 감소시킨다.
        pPlayer->iHP -= iDamage;

        cout << pMonster->strName << "가 " << pPlayer->strName << "에게  " << iDamage << " 피해를 입혔습니다." << endl;

        // 플레이어가 죽었을 경우를 처리한다.
        if (pPlayer->iHP <= 0) {

            cout << pPlayer->strName << " 플레이어가 사망하였습니다." << endl;

            int iExp = pPlayer->iExp * 0.1f;
            int iGold = pPlayer->tInventory.iGold * 0.1f;

        	pPlayer->iExp -= iExp;
            pPlayer->tInventory.iGold -= iGold;


            cout << iExp << " 경험치를 잃었습니다." << endl;
            cout << iGold << " Gold를 잃었습니다." << endl;


            // 플레이어의 HP와 MP를 회복한다.
            pPlayer->iHP = pPlayer->iHPMax;
            pPlayer->iMP = pPlayer->iMPMax;

        }
        
}


void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, int iMenu)
{
	
	_tagMonster tMonster = pMonsterArr[iMenu - 1];
	
	while(true)
	{
		system("cls");
		
		// 배틀 난이도 조정 
		OutputBattleTag(iMenu);
		
		// 플레이어 출력
		OutputPlayer(pPlayer);
		
		// 몬스터 출력
		OutputMonster(&tMonster);
		 
		switch(OutputBattleMenu())
		{
			case BATTLE_ATTACK:
				Battle(pPlayer, &tMonster);
				system("pause");
				break;
			case BATTLE_BACK:
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
		
		if(iMenu == MT_BACK) return;
		
		// 전투를 시작한다.
		RunBattle(pPlayer, pMonsterArr, iMenu); 
		
	}
	
}



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
    cin.getline(pPlayer->strName, NAME_SIZE - 1);
	
	// eJob이 2개인데?? 
	pPlayer->eJob = (JOB)SelectJob();
	pPlayer->iLevel = 1;
    pPlayer->iExp = 0;
//    pPlayer->eJob = (JOB)iJob;
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


_tagLevelUpStatus CreateLvUpStatus(int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax,
int iHPMin, int iHPMax, int iMPMin, int iMPMax)
{
	_tagLevelUpStatus tStatus = {};

    tStatus.iAttackMin = iAttackMin;
    tStatus.iAttackMax = iAttackMax;
    tStatus.iArmorMin = iArmorMin;
    tStatus.iArmorMax = iArmorMax;
    tStatus.iHP = iHP;
    tStatus.iHPMax = iHPMax;
    tStatus.iMP = iMP;
    tStatus.iMPMax = iMPMax;
    tStatus.iLevel = iLevel;
    tStatus.iExp = iExp;
    tStatus.iGoldMin = iGoldMin;
    tStatus.iGoldMax = iGoldMax;
	
	return tStatus;
}


enum STORE_MENU
{
    SM_NONE,
    SM_WEAPON,
    SM_ARMOR,
    SM_BACK
};

void OutputStoreMenu()
{
	system("cls");
    cout << "************************** 상점 **************************" << endl;
    cout << "1. 무기상점" << endl;
    cout << "2. 방어구상점" << endl;
    cout << "3. 뒤로가기" << endl;
    cout << "상점을 선택하세요: ";
    iMenu = InputInt();
 
    if(iMenu == INT_MAX || iMenu <= SM_NONE || iMenu > SM_BACK){
		iMenu = SM_NONE;	
	}
	
	return iMenu;
}


void RunShop(_tagPlayer* pPlayer, int iMenu)
{
	
	_tagMonster tMonster = pMonsterArr[iMenu - 1];
	
	while(true)
	{
		system("cls");
		
		// 배틀 난이도 조정 
		OutputBattleTag(iMenu);
		
		// 플레이어 출력
		OutputPlayer(pPlayer);
		
		// 몬스터 출력
		OutputMonster(&tMonster);
		 
		switch(OutputBattleMenu())
		{
			case BATTLE_ATTACK;
				Battle(pPlayer, &tMonster);
				system("pause");
				break;
			case BATTLE_BACK;
				return;
		}
		
	}
	
}


int OutputStoreItemList(_tagInventory* pInventory, _tagItem* pStore, int iItemCount)
{
	
	// 판매 목록을 보여준다.
    for (int i = 0; i < iItemCount; ++i) {
        cout << i + 1 << ". 이름 : " << pStore.strName << "\t종류 : " << pStore.strTypeName << endl;
        cout << "공격력 : " << pStore.iMin << " - " << pStore.iMax << endl;
        cout << "판매가격 : " << pStore.iPrice << "\t구매가격 : " << pStore.iSell << endl;
        cout << "설명 : " << pStore.strDesc << endl;
    }

        cout << iItemCount + 1 << ". 뒤로가기" << endl;
        cout << "보유금액 : " << pInventory->iGold << " Gold" << endl;
        cout << "남은공간 : " << INVENTORY_MAX - pInventory->iItemCount << endl;
        cout << "구입할 아이템을 선택하세요 : ";
        int iMenu = InputInt();

        if (iMenu < 1 || iMenu > iItemCount + 1)
        	return INT_MAX;
	
}


void BuyItem(_tagInventory* pInventory, _tagItem* pStore, int iItemCount, int iStoreType)
{
	
	while(true)
	{
		system("cls");
		switch(iStoreType)
		{
			case SM_WEAPON:
				cout << "************************** 무기상점 **************************" << endl;
                break;
			case SM_ARMOR:
				cout << "************************** 방어구상점 **************************" << endl;
                break;
		}
		int iInput = OutputStoreItemList(pInventory, pStore, iItemCount);
		
		if(iInput == INT_MAX)
		{
			cout << "잘못 입력하였습니다." << endl;
			system("pause");
			continue;
		}	
		else if(iInput == iItemCount + 1)
			break;
			
			
        // 상점판매목록 배열의 인덱스를 구한다.
        int iIndex = iInput - 1;

        // 인벤토리가 꽉 찼는지 검사한다.
        if (pInventory->iItemCount == INVENTORY_MAX) {

        	cout << "가방이 꽉 찼습니다." << endl;
            system("pause");
            continue;
        }
                        
		// 돈이 부족할 경우
        else if (pInventory->iGold < pStore[iIndex]->iPrice)
        {
            cout << "보유금액이 부족합니다." << endl;
            system("pause");
            continue;
        }

                        
		// 처음에 iItemCount는 하나도 추가되어 있지 않기 떄문에 0으로 초기화
        // 되어 있으므로 0번 인덱스에 구매한 아이템을 추가하게 된다. 그리고
        // 카운트는 1이 된다. 다음번에 추가할때는 1번 인덱스에 추가하게 된다.
        pInventory->tItem[pInventory->iItemCount] = pStore[iIndex];
        ++pInventory->iItemCount;

        // 골드를 차감한다.
        pInventory->iGold -= pStore[iIndex]->iPrice;

        cout << pStore[iIndex]->strName << " 아이템을 구매하였습니다." << endl;
        system("pause");
	
	}
	
}

void RunStore(_tagPlayer* pPlayer, _tagInventory* pInventory, _tagItem* pWeapon, _tagItem* pArmor)
{
	
	bool bLoop = true;
	while(true){
		
		switch(OutputStoreMenu())
		{
			case SM_WEAPON;
				BuyItem(pInventory, pWeapon, STORE_WEAPON_MAX, SM_WEAPON);
				break;
			case SM_ARMOR;
				BuyItem(pInventory, pArmor, STORE_ARMOR_MAX, SM_ARMOR);
				return;
			case SM_BACK;
				return;	
		} 
		
	}
}

_tagItem CreateItem(char* pName, ITEM_TYPE eType, int iMin, int iMax, int iPrice, int iSell, char* pDesc)
{
	_tagItem tItem = {};
	
	strcpy_s(tItem.strName, pName);
	strcpy_s(tItem.strDesc, pDesc);
	
	tItem.etype = eType;
	switch (eType)
	{
		case IT_WEAPON:
			strcpy_s(tItem.strTypeName, "무기");
			break;
		case IT_ARMOR:
			strcpy_s(tItem.strTypeName, "방어구");
			break;	
		
	}
    
    tItem.iMin = iMin;
    tItem.iMax =  iMax;
    tItem.iPrice = iPrice;
    tItem.iSell = iSell;
	
	return tItem;
}

int OutputInventory(_tagPlayer* pPlayer)
{
	system("cls");
    cout << "************************** 가방 **************************" << endl;
    
	OutputPlayer(pPlayer);
	

    for (int i = 0; i < pPlayer->tInventory.iItemCount; ++i)
    {
        cout << i + 1 << ". 이름 : " << pPlayer->tInventory.tItem[i].strName << "\t종류 : " << pPlayer->tInventory.tItem[i].strTypeName << endl;
        cout << "공격력 : " << pPlayer->tInventory.tItem[i].iMin << " - " << pPlayer->tInventory.tItem[i].iMax << endl;
        cout << "판매가격 : " << pPlayer->tInventory.tItem[i].iPrice << "\t구매가격 : " << pPlayer->tInventory.tItem[i].iSell << endl;
        cout << "설명 : " << pPlayer->tInventory.tItem[i].strDesc << endl;

    }

    cout << pPlayer->tInventory.iItemCount + 1 << ". 뒤로가기" << endl;
    cout << "장착할 아이템을 선택하세요 : ";
    int iMenu = InputInt();
    
	if (iMenu < 1 || iMenu > pPlayer->tInventory.iItemCount + 1)
    	return INT_MAX;
	
	return iMenu;
}


EQUIP ComputeEquipType(ITEM_TYPE eType)
{
	EQUIP eq;
	
	switch (eType)
    {
    	case IT_WEAPON:
        	eq = EQ_WEAPON;
        	break;
    	case IT_ARMOR:
            eq = EQ_ARMOR;
            break;
    }
	return eq;
}

void RunInventory(_tagPlayer* pPlayer)
{
	while(true)
	{
		int iInput = OutputInventory(pPlayer);
		
		if (iInput == INT_MAX)
			continue;
		else if (iInput == pPlayer->tInventory.iItemCount + 1)
			break;
		
	
		// 아이템 인덱스를 구해준다.
    	int idx = iInput - 1;

    	// 제대로 선택했을 경우 해당 아이템의 종류에 따라 장착 부위를
    	// 결정하게 한다.
    	EQUI eq = ComputeEquipType(pPlayer->bEquip[eq]);

    	// 아이템이 장착되어 있을 경우
    	// 장착되어 있는 아이템과 장착할 아이템을 교체해 주어야 한다. Swap 알고리즘을 활용한다.
    	if (pPlayer->bEquip[eq] == true)
    	{
        	_tagItem tSwap = pPlayer->tEquip[eq];
        	pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];
        	pPlayer->tInventory.tItem[idx] = tSwap;

    	}

    	// 장착되어 있지 않은 경우
    	// 인벤토리 아이템을 장착장으로 옮기고 인벤토리는 1칸 비워지게 된다.
    	else
    	{
        	pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];

        	for (int i = idx; i < pPlayer->tInventory.iItemCount - 1; ++i)
        	{
           		pPlayer->tInventory.tItem[i] = pPlayer->tInventory.tItem[i + 1];
        	}
        	--pPlayer->tInventory.iItemCount;

        	// 장착을 했기 때문에 true로 만들어준다.
        	pPlayer->bEquip[eq] = true;

    	}

    	cout << pPlayer->tEquip[eq].strName << " 아이템을 장착하였습니다." << endl;


    	system("pause");
    	
		}
		
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
	
	
    // JOB_END는 4이다. 그런데 직업은 3개이므로 -1을 해주어서 배열을 각 직업별로
    // 생성하도록 한다.
    g_tLvUpTable[JOB_KNIGHT - 1] = CreateLvUpStatus(4, 10, 8, 16, 50, 100, 10, 20);
    g_tLvUpTable[JOB_ARCHER - 1] = CreateLvUpStatus(10, 15, 5, 10, 30, 60, 30, 50);
    g_tLvUpTable[JOB_WIZARD - 1] = CreateLvUpStatus(15, 20, 3, 7, 20, 40, 50, 100);
    
    
    // 상점에서 판매할 아이템 목록을 생성한다.
    _tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
    _tagItem tStoreArmor[STORE_ARMOR_MAX] = {};


	// 각 아이템 정보들을 설정해준다.
	tStoreWeapon[0] = CreateItem("강철의 검", IT_WEAPON, 200, 300, 1500, 1500, "강철의 검이다.");
	tStoreWeapon[1] = CreateItem("다이아몬드 활", IT_WEAPON, 500, 800, 2000, 2000, "다이아몬드 활이다.");
	tStoreWeapon[2] = CreateItem("불꽃 지팡이", IT_WEAPON, 800, 1000, 2100, 2100, "불꽃 지팡이다.");
	
	tStoreArmor[0] = CreateItem("강철의 투구", IT_ARMOR, 20000, 40000, 3000, 3000, "강철의 투구이다.");
	tStoreArmor[1] = CreateItem("무적의 갑옷", IT_ARMOR, 200000, 400000, 4000, 4000, "무적의 갑옷이다.");
	tStoreArmor[2] = CreateItem("철의 신발", IT_ARMOR, 3000, 4000, 2000, 2000, "철의 신발이다.");
	
	
	bool bLoop = true;

    while (bLoop) {
        
        switch (OutputMainMenu()) {

        case MM_MAP:
        	RunMap(&tPlayer, tMonsterArr); // Map 관련 루프를 처리한다. 
        	break;
        case MM_STORE:
        	RunStore(&tPlayer, &tInventory, tStoreWeapon, tStoreArmor);
            break;
        case MM_INVENTORY:
        	RunInventory(&tPlayer);
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
