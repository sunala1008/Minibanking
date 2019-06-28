#ifndef _HANDLR_H_
#define _HANDLR_H_

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

typedef ACCOUNT * ACCOUNT_PTR; // ��

class AccountHandler
{
private:
	ACCOUNT * accArr[100];		// ���¸� ������ �迭
	//ACCOUNT_PTR * accArr;		// �迭 ������? ��
	int accNum;						// ������ ���� �� 


public:
	AccountHandler() : accNum(0) // ������
	{}

	//AccountHandler(int num) : accNum(num) // ��
	//{
	//	accArr = new ACCOUNT_PTR[num];
	//}

	//~AccountHandler()	// �Ҹ��� ��
	//{
	//	delete[]accArr;
	//}

	void NormalMakeAccount(void);			// �Ϲ� ���� ���� 
	void CreditMakeAccount(void);			// �ſ� ���� ����
	void DepositMoney(void) const;			// �Ա�
	void WithdrawMoney(void) const;			// ���
	void AccMenu(void);						// ���� ���� �޴�
	void ShowAllAccInfo(void) const; 		// �ܾ���ȸ
};

#endif // !_HANDLR_H_
