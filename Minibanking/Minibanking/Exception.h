#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include "MiniBankingCommonDecl.h"

class A_Exception // ����� ����
{
public:
	virtual void ShowExceptionReason() = 0;
};

class D_Exception : public A_Exception // �Ա� ����
{
private:
	int depositMoney;

public:
	D_Exception(int money) : depositMoney(money) {}

	void ShowExceptionReason();
};

class W_Exception : public A_Exception //��� ����
{
private:
	int balance;

public:
	W_Exception(int money) : balance(money) {}

	void ShowExceptionReason();
};

class FULL_ACCOUNT // ���� ���� ���� �ʰ�
{
private:
	int NUM;

public:
	FULL_ACCOUNT(int num) : NUM(num) {}

	void ShowAccFull();
};

class AlreadyRegiAcc // �̹� ��ϵ� ���� ��ȣ
{
public:
	AlreadyRegiAcc() {}

	void ShowAlreadyRegi();
};

class IntoMoney	// ���� ������ -�ݾ�
{
public:
	IntoMoney() {}

	void ShowIntoMoney();
};

class GradeErr // ��� ����
{
public:
	GradeErr() {}

	void ShowGradeErr();
};

class NoMinusMoney	// - ��� ('1000 - (-5000) = 6000' ����)
{
private:
	int money;

public:
	NoMinusMoney(int cash) : money(cash) {}

	void ShowNoMinusMoney();
};

#endif // !_EXCEPTION_H_
