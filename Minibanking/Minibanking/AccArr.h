#ifndef _ACC_ARR_H_
#define _ACC_ARR_H_

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"

#define MAXACCOUNT 100

typedef ACCOUNT * ACCOUNT_PTR;

template <typename T>

class ACC_ARR
{
private:
	T *accArr;
	int arrLen;

	ACC_ARR(const ACC_ARR &arr) {}
	ACC_ARR& operator=(const ACC_ARR &arr) {}

public:
	ACC_ARR(int len = MAXACCOUNT);

	T& operator[](int idx);	   // �迭 �ε��� �����ε� 
	// ��� �迭Ŭ������ ��������� �� �̻� ������ ���� ���� �� �� ���� ���� ��Ȳ.
	T operator[](int idx) const; // �迭 �ε��� �����ε� -> constȭ ��Ų ��

	int getarrLen() const;

	~ACC_ARR();
};

#endif // !_ACC_ARR_H_
