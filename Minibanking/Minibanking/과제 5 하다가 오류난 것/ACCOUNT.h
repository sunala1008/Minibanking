#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "MiniBankingCommonDecl.h"

class String //��
{
private:
	int strLen;
	char * str;

public:
	String() // �⺻ ������
	{
		strLen = 0;
		str = NULL;
	}

	String(const char * str, int len) // �Ű������� �ִ� ������
	{
		strLen = strlen(str) + 1;
		this->str = new char[strLen]; // new �� char �迭 ����
		strcpy(this->str, str);

		strLen = len;
	}

	// ���� ������
	String(const String &copy) : str(copy.str)
	{}

	// �Ҹ���
	~String()
	{
		delete[]str;
	}
};

class ACCOUNT
{
private:
	int accID;		// ���¹�ȣ
	int balance;	// �ܾ�
	char * cusName; // �� �̸�
	//myString * cusName;

public:
	ACCOUNT(const int ID, const int money, const char * myname) // ������
		: accID(ID), balance(money)
	{
		int len = strlen(myname) + 1;
		cusName = new char[len];
		strcpy(cusName, myname);
	}
	
	int getaccID();
	int getbalance();
	virtual void setplusbalance(int money);
	void setminusbalance(int money);
	char * getcusName();
	~ACCOUNT();
};




#endif // !_ACCOUNT_H_
