#include <iostream>
#include <time.h>

using namespace std;

enum MAP_TYPE
{
    MT_NONE,
    MT_EASY,
    MT_NORMAL,
    MT_HARD,
    MT_BACK
};


enum JOB
{
    JOB_NONE,
    JOB_KNIGHT,
    JOB_ARCHER,
    JOB_WIZARD,
    JOB_END
};

enum BATTLE
{
    BATTLE_NONE,
    BATTLE_ATTACK,
    BATTLE_BACK
};

enum ITEM_TYPE
{
    IT_NONE,
    IT_WEAPON,
    IT_ARMOR,
    IT_BACK
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



#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3
#define LEVEL_MAX 10

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

enum MAIN_MENU
{
    MM_NONE,
    MM_MAP,
    MM_STORE,
    MM_INVENTORY,
    MM_EXIT
};


// ���� �Է��� �޴´�. �Է� �������� ó�����ְ� INT_MAX�� �����ϸ�
// �Է� �����̴�. 
int InputInt()
{
	
	int iInput;
	cin >> iInput;
	
	if (cin.fail()) {

        cin.clear();
        cin.ignore(1024, '\n');
        return INT_MAX; // INT_MAX�� ���ϵǸ� �Է��� �߸��ƴٴ� �ǹ��̴�. 
    }
    
    return iInput;
}


// ���� �޴��� ȭ�鿡 �����ְ� �Է¹��� �޴��� ��ȯ�Ѵ�.
// �Է� ������ ��� Ȥ�� �߸��� ��ȣ�� �Է��� ��� MM_NONE��
// ��ȯ���ش�. 
int OutputMainMenu()
{	
	system("cls");
    cout << "************************** �κ� **************************" << endl;
    cout << "1. ��" << endl;
    cout << "2. ����" << endl;
    cout << "3. ����" << endl;
    cout << "4. ����" << endl;
    cout << "�޴��� �����ϼ��� : ";
    int iMenu = InputInt();
	
	if(iMenu == INT_MAX || iMenu <= MM_NONE || iMenu > MM_EXIT){
		return MM_NONE;	
	}
    
    return iMenu;
}

int OutputMapMenu()
{
	system("cls");
    cout << "************************** �� **************************" << endl;
    cout << "1. ����" << endl;
    cout << "2. ����" << endl;
    cout << "3. ����� " << endl;
    cout << "4. �ڷΰ���" << endl;
	cout << "���� �����ϼ���: ";
    int iMenu = InputInt();
	
	if(iMenu == INT_MAX || iMenu <= MT_NONE || iMenu > MT_BACK){
		return MT_NONE;	
	}
    
    return iMenu;
}


void RunMap()
{
	bool bLoop = true;
	while(bLoop){
		
		switch(OutputMapMenu())
		{
			
			
		}
		
		
	}
	
}


int main() 
{

    srand((unsigned int)time(0));

    // �������� �ʿ��� ����ġ ����� �����.
    const int iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };

    // JOB_END�� 4�̴�. �׷��� ������ 3���̹Ƿ� -1�� ���־ �迭�� �� ��������
    // �����ϵ��� �Ѵ�.
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



    // ������ �����Ҷ� �÷��̾� ������ �����ϰ� �Ѵ�.
    _tagPlayer tPlayer = {};

    // �÷��̾� �̸��� �Է� �޴´�.
    cout << "�̸� : ";
    cin.getline(tPlayer.strName, NAME_SIZE - 1);

    int iJob = JOB_NONE;
    while (iJob == JOB_NONE)
    {
        system("cls");
        cout << "1. ���" << endl;
        cout << "2. �ü�" << endl;
        cout << "3. ������" << endl;
        cout << "������ �����ϼ��� : ";
        cin >> iJob;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if (iJob <= JOB_NONE || iJob >= JOB_END)
            iJob = JOB_NONE;

    }


    tPlayer.iLevel = 1;
    tPlayer.iExp = 0;
    tPlayer.eJob = (JOB)iJob;
    tPlayer.tInventory.iGold = 10000;


    switch (tPlayer.eJob)
    {
    case JOB_KNIGHT:
        strcpy_s(tPlayer.strJobName, "���");
        tPlayer.iAttackMin = 5;
        tPlayer.iAttackMax = 10;
        tPlayer.iArmorMin = 15;
        tPlayer.iArmorMax = 20;
        tPlayer.iHPMax = 500;
        tPlayer.iHP = 500;
        tPlayer.iMP = 100;
        tPlayer.iMPMax = 100;
        break;
    case JOB_ARCHER:
        strcpy_s(tPlayer.strJobName, "�ü�");
        tPlayer.iAttackMin = 10;
        tPlayer.iAttackMax = 15;
        tPlayer.iArmorMin = 10;
        tPlayer.iArmorMax = 15;
        tPlayer.iHPMax = 400;
        tPlayer.iHP = 400;
        tPlayer.iMP = 200;
        tPlayer.iMPMax = 200;
        break;
    case JOB_WIZARD:
        strcpy_s(tPlayer.strJobName, "������");
        tPlayer.iAttackMin = 15;
        tPlayer.iAttackMax = 20;
        tPlayer.iArmorMin = 5;
        tPlayer.iArmorMax = 10;
        tPlayer.iHPMax = 300;
        tPlayer.iHP = 300;
        tPlayer.iMP = 300;
        tPlayer.iMPMax = 300;
        break;
    }


    // ���͸� �����Ѵ�
    _tagMonster tMonsterArr[MT_BACK - 1] = {};

    // ��� ����
    strcpy_s(tMonsterArr[0].strName, "���");
    tMonsterArr[0].iAttackMin = 20;
    tMonsterArr[0].iAttackMax = 30;
    tMonsterArr[0].iArmorMin = 2;
    tMonsterArr[0].iArmorMax = 5;
    tMonsterArr[0].iHP = 100;
    tMonsterArr[0].iHPMax = 100;
    tMonsterArr[0].iMP = 10;
    tMonsterArr[0].iMPMax = 10;
    tMonsterArr[0].iLevel = 1;
    tMonsterArr[0].iExp = 1000;
    tMonsterArr[0].iGoldMin = 500;
    tMonsterArr[0].iGoldMax = 1500;

    // Ʈ�� ����
    strcpy_s(tMonsterArr[1].strName, "Ʈ��");
    tMonsterArr[1].iAttackMin = 80;
    tMonsterArr[1].iAttackMax = 130;
    tMonsterArr[1].iArmorMin = 60;
    tMonsterArr[1].iArmorMax = 90;
    tMonsterArr[1].iHP = 2000;
    tMonsterArr[1].iHPMax = 2000;
    tMonsterArr[1].iMP = 100;
    tMonsterArr[1].iMPMax = 100;
    tMonsterArr[1].iLevel = 5;
    tMonsterArr[1].iExp = 7000;
    tMonsterArr[1].iGoldMin = 6000;
    tMonsterArr[1].iGoldMax = 8000;

    // �巡�� ����
    strcpy_s(tMonsterArr[2].strName, "�巡��");
    tMonsterArr[2].iAttackMin = 250;
    tMonsterArr[2].iAttackMax = 500;
    tMonsterArr[2].iArmorMin = 200;
    tMonsterArr[2].iArmorMax = 400;
    tMonsterArr[2].iHP = 30000;
    tMonsterArr[2].iHPMax = 30000;
    tMonsterArr[2].iMP = 20000;
    tMonsterArr[2].iMPMax = 20000;
    tMonsterArr[2].iLevel = 10;
    tMonsterArr[2].iExp = 30000;
    tMonsterArr[2].iGoldMin = 20000;
    tMonsterArr[2].iGoldMax = 50000;

    // �������� �Ǹ��� ������ ����� �����Ѵ�.
    _tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
    _tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

    // �� ������ �������� �������ش�.
    // ���� ����
    strcpy_s(tStoreWeapon[0].strName, "��ö�� ��");
    strcpy_s(tStoreWeapon[0].strTypeName, "��");
    tStoreWeapon[0].eType = IT_WEAPON;
    tStoreWeapon[0].iMin = 200;
    tStoreWeapon[0].iMax = 300;
    tStoreWeapon[0].iPrice = 1500;

    strcpy_s(tStoreWeapon[1].strName, "���̾Ƹ�� Ȱ");
    strcpy_s(tStoreWeapon[1].strTypeName, "Ȱ");
    tStoreWeapon[1].eType = IT_WEAPON;
    tStoreWeapon[1].iMin = 500;
    tStoreWeapon[1].iMax = 800;
    tStoreWeapon[1].iPrice = 2000;

    strcpy_s(tStoreWeapon[2].strName, "�Ҳ� ������");
    strcpy_s(tStoreWeapon[2].strTypeName, "������");
    tStoreWeapon[2].eType = IT_WEAPON;
    tStoreWeapon[2].iMin = 800;
    tStoreWeapon[2].iMax = 1000;
    tStoreWeapon[2].iPrice = 2100;

    // ��� ����
    strcpy_s(tStoreArmor[0].strName, "��ö�� ����");
    strcpy_s(tStoreArmor[0].strTypeName, "�Ӹ�");
    tStoreArmor[0].eType = IT_ARMOR;
    tStoreArmor[0].iMin = 20000;
    tStoreArmor[0].iMax = 40000;
    tStoreArmor[0].iPrice = 3000;

    strcpy_s(tStoreArmor[1].strName, "������ ����");
    strcpy_s(tStoreArmor[1].strTypeName, "����");
    tStoreArmor[1].eType = IT_ARMOR;
    tStoreArmor[1].iMin = 200000;
    tStoreArmor[1].iMax = 400000;
    tStoreArmor[1].iPrice = 4000;

    strcpy_s(tStoreArmor[2].strName, "ö�� �Ź�");
    strcpy_s(tStoreArmor[2].strTypeName, "�Ź�");
    tStoreArmor[2].eType = IT_ARMOR;
    tStoreArmor[2].iMin = 3000;
    tStoreArmor[2].iMax = 4000;
    tStoreArmor[2].iPrice = 2000;


	bool bLoop = true;

    while (bLoop) {
        
        switch (OutputMainMenu()) {

        case MM_MAP:
        	
        	RunMap(); // Map ���� ������ ó���Ѵ�. 
        	
            while (true) {
                
                //  9�� 

                // ������ �޴����� 1�� ���ָ� ���� �迭�� �ε����� �ȴ�.
                // �׷��� �ؼ� �ش� ���� ���͸� �������ش�.
                _tagMonster tMonster = tMonsterArr[iMenu - 1];

                while (true) {

                    system("cls");

                    switch (iMenu)
                    {
                    case MT_EASY:
                        cout << "************************** ���� **************************" << endl;
                        break;
                    case MT_NORMAL:
                        cout << "************************** ���� **************************" << endl;
                        break;
                    case MT_HARD:
                        cout << "************************** ����� **************************" << endl;
                        break;
                    }


                    int iAttackMin = tPlayer.iAttackMin;
                    int iAttackMax = tPlayer.iAttackMax;

                    // ���⸦ �����ϰ� ���� ��� ������ Min, Max�� �����ش�.
                    if (tPlayer.bEquip[EQ_WEAPON])
                    {
                        iAttackMin += tPlayer.tEquip[EQ_WEAPON].iMin;
                        iAttackMax += tPlayer.tEquip[EQ_WEAPON].iMax;
                    }

                    int iArmorMin = tPlayer.iArmorMin;
                    int iArmorMax = tPlayer.iArmorMax;

                    // ���� �����ϰ� ���� ��� ����� Min, Max�� �����ش�.
                    if (tPlayer.bEquip[EQ_ARMOR])
                    {
                        iArmorMin += tPlayer.tEquip[EQ_ARMOR].iMin;
                        iArmorMax += tPlayer.tEquip[EQ_ARMOR].iMax;
                    }


                    // �÷��̾� ������ ����Ѵ�.
                    cout << "************************** Player **************************" << endl;
                    cout << "�̸� : " << tPlayer.strName << "\t���� : " << tPlayer.strJobName << endl;
                    cout << "���� : " << tPlayer.iLevel << "\t����ġ : " << tPlayer.iExp << " / " << iLevelUpExp[tPlayer.iLevel - 1] << endl;
                    cout << "���ݷ� : " << iAttackMin << " - " << iAttackMax << "\t���� : " << iArmorMin << " - " << iArmorMax << endl;
                    cout << "ü�� : " << tPlayer.iHP << " / " << tPlayer.iHPMax << "\t���� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
                    cout << "������� : " << tPlayer.tInventory.iGold << " Gold" << endl;


                    // ���� ���� ���
                    cout << "************************** Monster **************************" << endl;
                    cout << "�̸� : " << tMonster.strName << "\t���� : " << tMonster.iLevel << endl;
                    cout << "���ݷ� : " << tMonster.iAttackMin << " - " << tMonster.iAttackMax << "\t���� : " << tMonster.iArmorMin << " - " << tMonster.iArmorMax << endl;
                    cout << "ü�� : " << tMonster.iHP << " / " << tMonster.iHPMax << "\t���� : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
                    cout << "ȹ�� ����ġ : " << tMonster.iExp << "\tȹ���� : " << tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl;


                    cout << "1. ����" << endl;
                    cout << "2. ��������" << endl;
                    cout << "�޴��� �����ϼ��� : ";
                    cin >> iMenu;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1024, '\n');
                        continue;
                    }
                    else if (iMenu == BATTLE_BACK)
                        break;

                    switch (iMenu) {

                    case BATTLE_ATTACK:
                    {

                        int iAttack = rand() % (iAttackMax - iAttackMin + 1) + iAttackMin;
                        int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) + tMonster.iArmorMin;

                        int iDamage = iAttack - iArmor;


                        iDamage = iDamage < 1 ? 1 : iDamage;


                        // ���� HP�� ���ҽ�Ų��.
                        tMonster.iHP -= iDamage;

                        cout << tPlayer.strName << "�� " << tMonster.strName << "����  " << iDamage << " ���ظ� �������ϴ�." << endl;

                        // ���Ͱ� �׾��� ��츦 ó���Ѵ�.
                        if (tMonster.iHP <= 0) {

                            cout << tMonster.strName << " ���Ͱ� ����Ͽ����ϴ�." << endl;

                            tPlayer.iExp += tMonster.iExp;
                            int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin);
                            tPlayer.tInventory.iGold += iGold;

                            cout << tMonster.iExp << " ����ġ�� ȹ���Ͽ����ϴ�." << endl;
                            cout << iGold << " Gold�� ȹ���Ͽ����ϴ�." << endl;

                            tMonster.iHP = tMonster.iHPMax;
                            tMonster.iMP = tMonster.iMPMax;


                            // �������� �ߴ��� üũ�غ���.
                            if (tPlayer.iExp >= iLevelUpExp[tPlayer.iLevel - 1])
                            {
                                // �÷��̾� ����ġ�� �������� �ʿ��� ����ġ��ŭ �����Ѵ�.
                                tPlayer.iExp -= iLevelUpExp[tPlayer.iLevel - 1];

                                // ������ ������Ų��.
                                ++tPlayer.iLevel;

                                cout << " ������ �Ͽ����ϴ�." << endl;

                                // �ɷ�ġ�� ��½�Ų��.
                                // ���� �ε����� ���Ѵ�.
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


                                // ü�°� ������ ȸ����Ų��.
                                tPlayer.iHP = tPlayer.iHPMax;
                                tPlayer.iMP = tPlayer.iMPMax;

                            }


                            system("pause");
                            break;

                        }



                        // ���Ͱ� ����ִٸ� �÷��̾ �����Ѵ�.
                        iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin;


                        iArmor = rand() % (iArmorMax - iArmorMin + 1) + iArmorMin;
                        iDamage = iAttack - iArmor;
                        iDamage = iDamage < 1 ? 1 : iDamage;


                        // �÷��̾��� HP�� ���ҽ�Ų��.
                        tPlayer.iHP -= iDamage;

                        cout << tMonster.strName << "�� " << tPlayer.strName << "����  " << iDamage << " ���ظ� �������ϴ�." << endl;

                        // �÷��̾ �׾��� ��츦 ó���Ѵ�.
                        if (tPlayer.iHP <= 0) {

                            cout << tPlayer.strName << " �÷��̾ ����Ͽ����ϴ�." << endl;

                            int iExp = tPlayer.iExp * 0.1f;
                            int iGold = tPlayer.tInventory.iGold * 0.1f;

                            tPlayer.iExp -= iExp;
                            tPlayer.tInventory.iGold -= iGold;


                            cout << iExp << " ����ġ�� �Ҿ����ϴ�." << endl;
                            cout << iGold << " Gold�� �Ҿ����ϴ�." << endl;


                            // �÷��̾��� HP�� MP�� ȸ���Ѵ�.
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
                cout << "************************** ���� **************************" << endl;
                cout << "1. �������" << endl;
                cout << "2. ������" << endl;
                cout << "3. �ڷΰ���" << endl;
                cout << "������ �����ϼ���: ";
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
                        cout << "************************** ������� **************************" << endl;
                        // �Ǹ� ����� �����ش�.
                        for (int i = 0; i < STORE_WEAPON_MAX; ++i) {
                            cout << i + 1 << ". �̸� : " << tStoreWeapon[i].strName << "\t���� : " << tStoreWeapon[i].strTypeName << endl;
                            cout << "���ݷ� : " << tStoreWeapon[i].iMin << " - " << tStoreWeapon[i].iMax << endl;
                            cout << "�ǸŰ��� : " << tStoreWeapon[i].iPrice << "\t���Ű��� : " << tStoreWeapon[i].iSell << endl;
                            cout << "���� : " << tStoreWeapon[i].strDesc << endl;
                        }

                        cout << STORE_WEAPON_MAX + 1 << ". �ڷΰ���" << endl;
                        cout << "�����ݾ� : " << tPlayer.tInventory.iGold << " Gold" << endl;
                        cout << "�������� : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
                        cout << "������ �������� �����ϼ��� : ";
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
                            cout << "�߸� �����Ͽ����ϴ�." << endl;
                            system("pause");
                            continue;
                        }


                        // �����ǸŸ�� �迭�� �ε����� ���Ѵ�.
                        int iWeaponIndex = iMenu - 1;

                        // �κ��丮�� �� á���� �˻��Ѵ�.
                        if (tPlayer.tInventory.iItemCount == INVENTORY_MAX) {

                            cout << "������ �� á���ϴ�." << endl;
                            system("pause");
                            continue;
                        }
                        // ���� ������ ���
                        else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIndex].iPrice)
                        {
                            cout << "�����ݾ��� �����մϴ�." << endl;
                            system("pause");
                            continue;
                        }

                        // ó���� iItemCount�� �ϳ��� �߰��Ǿ� ���� �ʱ� ������ 0���� �ʱ�ȭ
                        // �Ǿ� �����Ƿ� 0�� �ε����� ������ �������� �߰��ϰ� �ȴ�. �׸���
                        // ī��Ʈ�� 1�� �ȴ�. �������� �߰��Ҷ��� 1�� �ε����� �߰��ϰ� �ȴ�.
                        tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount]
                            = tStoreWeapon[iWeaponIndex];
                        ++tPlayer.tInventory.iItemCount;

                        // ��带 �����Ѵ�.
                        tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIndex].iPrice;

                        cout << tStoreWeapon[iWeaponIndex].strName << " �������� �����Ͽ����ϴ�." << endl;
                        system("pause");



                    }
                    break;
                case SM_ARMOR:
                    while (true)
                    {
                        system("cls");
                        cout << "************************** �� ���� **************************" << endl;
                        // �Ǹ� ����� �����ش�.
                        for (int i = 0; i < STORE_ARMOR_MAX; ++i) {
                            cout << i + 1 << ". �̸� : " << tStoreArmor[i].strName << "\t���� : " << tStoreArmor[i].strTypeName << endl;
                            cout << "���� : " << tStoreArmor[i].iMin << " - " << tStoreArmor[i].iMax << endl;
                            cout << "�ǸŰ��� : " << tStoreArmor[i].iPrice << "\t���Ű��� : " << tStoreArmor[i].iSell << endl;
                            cout << "���� : " << tStoreArmor[i].strDesc << endl;
                        }

                        cout << STORE_ARMOR_MAX + 1 << ". �ڷΰ���" << endl;
                        cout << "�����ݾ� : " << tPlayer.tInventory.iGold << " Gold" << endl;
                        cout << "�������� : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
                        cout << "������ �������� �����ϼ��� : ";
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
                            cout << "�߸� �����Ͽ����ϴ�." << endl;
                            system("pause");
                            continue;
                        }


                        // �����ǸŸ�� �迭�� �ε����� ���Ѵ�.
                        int iArmorIndex = iMenu - 1;

                        // �κ��丮�� �� á���� �˻��Ѵ�.
                        if (tPlayer.tInventory.iItemCount == INVENTORY_MAX) {

                            cout << "������ �� á���ϴ�." << endl;
                            system("pause");
                            continue;
                        }
                        // ���� ������ ���
                        else if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice)
                        {
                            cout << "�����ݾ��� �����մϴ�." << endl;
                            system("pause");
                            continue;
                        }

                        // ó���� iItemCount�� �ϳ��� �߰��Ǿ� ���� �ʱ� ������ 0���� �ʱ�ȭ
                        // �Ǿ� �����Ƿ� 0�� �ε����� ������ �������� �߰��ϰ� �ȴ�. �׸���
                        // ī��Ʈ�� 1�� �ȴ�. �������� �߰��Ҷ��� 1�� �ε����� �߰��ϰ� �ȴ�.
                        tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount]
                            = tStoreArmor[iArmorIndex];
                        ++tPlayer.tInventory.iItemCount;

                        // ��带 �����Ѵ�.
                        tPlayer.tInventory.iGold -= tStoreArmor[iArmorIndex].iPrice;

                        cout << tStoreArmor[iArmorIndex].strName << " �������� �����Ͽ����ϴ�." << endl;
                        system("pause");


                    }
                    break;
                }

            }
            break;
        case MM_INVENTORY:
            while (true) {
                system("cls");
                cout << "************************** ���� **************************" << endl;
                cout << "************************** Player **************************" << endl;
                cout << "�̸� : " << tPlayer.strName << "\t���� : " << tPlayer.strJobName << endl;
                cout << "���� : " << tPlayer.iLevel << "\t����ġ : " << tPlayer.iExp << endl;

                // ���⸦ �����ϰ� ���� ��� ���ݷ¿� ���� ���ݷ��� �߰��Ͽ� ����Ѵ�.
                if (tPlayer.bEquip[EQ_WEAPON] == true)
                {
                    cout << "���ݷ� : " << tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " - " << tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax;
                }
                else
                {
                    cout << "���ݷ� : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax;
                }

                // ���� �����ϰ� ���� ��� ���¿� �� ������ �߰��Ͽ� ����Ѵ�.

                if (tPlayer.bEquip[EQ_ARMOR] == true)
                {
                    cout << "\t���� : " << tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " - " << tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
                }
                else
                {
                    cout << "\t���� : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
                }


                cout << "ü�� : " << tPlayer.iHP << " / " << tPlayer.iHPMax << "\t���� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
                cout << "������� : " << tPlayer.tInventory.iGold << " Gold" << endl;


                if (tPlayer.bEquip[EQ_WEAPON])
                    cout << "���� ���� : " << tPlayer.tEquip[EQ_WEAPON].strName;
                else
                    cout << "���� ���� : ����";

                if (tPlayer.bEquip[EQ_ARMOR])
                    cout << "\t���� �� : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;
                else
                    cout << "\t���� �� : ����" << endl;


                cout << endl;


                for (int i = 0; i < tPlayer.tInventory.iItemCount; ++i)
                {
                    cout << i + 1 << ". �̸� : " << tPlayer.tInventory.tItem[i].strName << "\t���� : " << tPlayer.tInventory.tItem[i].strTypeName << endl;
                    cout << "���ݷ� : " << tPlayer.tInventory.tItem[i].iMin << " - " << tPlayer.tInventory.tItem[i].iMax << endl;
                    cout << "�ǸŰ��� : " << tPlayer.tInventory.tItem[i].iPrice << "\t���Ű��� : " << tPlayer.tInventory.tItem[i].iSell << endl;
                    cout << "���� : " << tPlayer.tInventory.tItem[i].strDesc << endl;

                }

                cout << tPlayer.tInventory.iItemCount + 1 << ". �ڷΰ���" << endl;
                cout << "������ �������� �����ϼ��� : ";
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
                    cout << "�߸� �����Ͽ����ϴ�." << endl;
                    system("pause");
                    continue;
                }

                // ������ �ε����� �����ش�.
                int idx = iMenu - 1;

                // ����� �������� ��� �ش� �������� ������ ���� ���� ������
                // �����ϰ� �Ѵ�.
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

                // �������� �����Ǿ� ���� ���
                // �����Ǿ� �ִ� �����۰� ������ �������� ��ü�� �־�� �Ѵ�. Swap �˰����� Ȱ���Ѵ�.
                if (tPlayer.bEquip[eq] == true)
                {
                    _tagItem tSwap = tPlayer.tEquip[eq];
                    tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];
                    tPlayer.tInventory.tItem[idx] = tSwap;

                }

                // �����Ǿ� ���� ���� ���
                // �κ��丮 �������� ���������� �ű�� �κ��丮�� 1ĭ ������� �ȴ�.
                else
                {
                    tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];

                    for (int i = idx; i < tPlayer.tInventory.iItemCount - 1; ++i)
                    {
                        tPlayer.tInventory.tItem[i] = tPlayer.tInventory.tItem[i + 1];
                    }
                    --tPlayer.tInventory.iItemCount;

                    // ������ �߱� ������ true�� ������ش�.
                    tPlayer.bEquip[eq] = true;

                }

                cout << tPlayer.tEquip[eq].strName << " �������� �����Ͽ����ϴ�." << endl;


                system("pause");
            }

            break;
        case MM_EXIT:
        	bLoop = false;
        	break;
		default:
            cout << "�߸� �����Ͽ����ϴ�." << endl;
            break;
        }

    }

    return 0;
}

