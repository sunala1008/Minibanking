#ifndef _HANDLR_H_
#define _HANDLR_H_

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "AccArr.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"
#include "ScreenOut.h"
#include "Exception.h"

class AccountHandler
{
private:
	ACCOUNT_PTR accArr[MAXACCOUNT]; // ���¸� ������ �迭
	int accNum;				 // ������ ���� ��

public:
	AccountHandler(); // ������
	
	~AccountHandler(); // �Ҹ���

	void AccMenu(void);								 // ���� ���� �޴�
	void NormalMakeAccount(void);					 // �Ϲ� ���� ���� 
	void CreditMakeAccount(void);					 // �ſ� ���� ����
	
	void DepositMoney(void) const;					 // �Ա�
	void WithdrawMoney(void) const;					 // ���

	void ShowAccInfo() const;						 // ���� ���� ���

	// ���� �Է����� ������ �������
	void FMNormalAcc(int indx, int ID, int balance, String Name, int rate, char tru);

	// ���� �Է����� ������ �ſ����
	void FMHighCreditAcc(int indx, int ID, int balance, String Name, int rate, char tru);
};

class IO_File				// ���� �Է�
{
private:
	int indx;				// �Ϲ�-�ſ� ����
	int id;					// ���� ��ȣ
	String name;			// �� ��
	int balance;			// �ݾ�
	int roi;				// ����
	char trust;				// �ŷڵ��

public:
	void input(AccountHandler &hand, ifstream &fin); // ���� ���ε� - �Է�
};

#endif // !_HANDLR_H_
