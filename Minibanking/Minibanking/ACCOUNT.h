#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "Exception.h"
#include "String.h"

enum {NOR = 1, CRE = 2};

class ACCOUNT
{
private:
	int accID;		// ���¹�ȣ
	int balance;	// �ܾ�
	String cusName; // �� �̸�

	int indx;		// �Ϲ�-�ſ� ����

public:
	ACCOUNT(const int indx, const int ID, const int money, const String myname) // ������
		: accID(ID), balance(money), cusName(myname)
	{
		this->indx = indx;
	}

	ACCOUNT(const ACCOUNT &copy); // default ���� ������
	
	int getindx();
	virtual int getaccID();
	virtual int getbalance();
	virtual char* getcusName() const;
	virtual int getroi() = 0;
	virtual char gettrust() = 0;
	virtual void setplusbalance(int money);
	void setminusbalance(int money);

	//~ACCOUNT();
};

#endif // !_ACCOUNT_H_
