#include "AccArr.h"

template <typename T>
ACC_ARR<T>::ACC_ARR(int len) 
{
	accArr = new ACCOUNT_PTR[len];
	arrLen = len;
}

template <typename T>
T& ACC_ARR<T>::operator[](int idx) // �迭 �ε��� �����ε� 
{
	if (idx < 0 || idx >= arrLen)
	{
		// cout << "�� �ùٸ� �ε��� ���� �־��ּ���. ��" << endl;
		cout << "��������������������������������������������������" << endl;
		cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
		cout << "��\t    �迭�� ������ ������ϴ�.    \t��" << endl;
		cout << "��������������������������������������������������" << endl;
		//exit(1);
	}
		
	return accArr[idx]; // �迭 ��Ҹ� �����ڸ� ���� ����
}

template <typename T>
T ACC_ARR<T>::operator[](int idx) const // �迭 �ε��� �����ε� -> constȭ ��Ų ��
{
	if (idx < 0 || idx >= arrLen)
	{
		// cout << "�� �ùٸ� �ε��� ���� �־��ּ���. ��" << endl;
		cout << "��������������������������������������������������" << endl;
		cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
		cout << "��\t    �迭�� ������ ������ϴ�.    \t��" << endl;
		cout << "��������������������������������������������������" << endl;
		//exit(1);
	}

	return accArr[idx]; // �迭 ��Ҹ� �����ڸ� ���� ����
}

template <typename T>
int ACC_ARR<T>::getarrLen() const
{
	return arrLen;
}

template <typename T>
ACC_ARR<T>::~ACC_ARR()
{
	delete[] accArr;
}