#include "Exception.h"

void D_Exception::ShowExceptionReason()
{
	cout << "��������������������������������������������������" << endl;
	cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
	cout << "��\t   " << depositMoney << "���� �Ա��� �Ұ��մϴ�.\t\t��" << endl;
	cout << "��������������������������������������������������" << endl;
	getchar();
	getchar();
}

void W_Exception::ShowExceptionReason()
{
	cout << "��������������������������������������������������" << endl;
	cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
	cout << "�� �ܾ��� �����Ͽ� " << balance << "���� ����� �� �����ϴ�. ��" << endl;
	cout << "��������������������������������������������������" << endl;
	getchar();
	getchar();
}

void FULL_ACCOUNT::ShowAccFull()
{
	cout << "��������������������������������������������������" << endl;
	cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
	cout << "��\t���� ������ ���¼��� �ʰ��Ͽ����ϴ�.   \t��" << endl;
	cout << "��������������������������������������������������" << endl;
	
	getchar();
	getchar();
}

void AlreadyRegiAcc::ShowAlreadyRegi()
{
	cout << "��������������������������������������������������" << endl;
	cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
	cout << "��\t   �̹� ��ϵ� ���� ��ȣ�Դϴ�.     \t��" << endl;
	cout << "��������������������������������������������������" << endl;
	getchar();
	getchar();
}

void IntoMoney::ShowIntoMoney() 
{
	cout << "��������������������������������������������������" << endl;
	cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
	cout << "��    ���� ���� �ݾ��� 0�� �̻��̾���մϴ�.\t��" << endl;
	cout << "��������������������������������������������������" << endl;
	getchar();
	getchar();
}

void GradeErr::ShowGradeErr()
{
	cout << "��������������������������������������������������" << endl;
	cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
	cout << "��\t  �ſ� ����� �ٽ� �Է����ּ���.      \t��" << endl;
	cout << "��������������������������������������������������" << endl;
	getchar();
	getchar();
}

void NoMinusMoney::ShowNoMinusMoney()
{
	cout << "��������������������������������������������������" << endl;
	cout << "��\t\t   �� �� �� ��     \t\t��" << endl;
	cout << "��\t  " << money << "���� ��� �Ұ� �ݾ��Դϴ�. \t��" << endl;
	cout << "��������������������������������������������������" << endl;
	getchar();
	getchar();
}