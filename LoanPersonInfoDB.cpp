#include"LoanPersonInfoDB.h"
//LoanPersonInfoDB::getpw(int idx, int pw)�Լ� �ڵ� �ۼ�

using namespace std;

int idx = 0;

void LoanPersonInfoDB::addLoanPersonInfo() {
	int loanNum;
	int accid;
	int desired_amount;
	int pw;
	char a[10];
	int i = 0;

	cout << "���� ��ǰ ��ȣ : ";
	cin >> loanNum;
	cout << "���¹�ȣ : ";
	cin >> accid;
	cout << "��й�ȣ : ";
	while (i != 6)
	{
		if (_kbhit())
		{
			a[i] = _getch();
			if (a[i] == 13)
			{
				break;
			}
			i++;
			cout << "*";
		}
	}
	cout << endl;
	int result = 0;
	for (int i = 5; i >= 0; i--)
	{
		result += (static_cast<int>(a[5 - i]) - 48) * pow(10, i);
	}
	pw = result;
	cout << "��� ���� �ݾ�  : ";
	cin >> desired_amount;


	Info.push_back(LoanPersonInfo(accid, desired_amount, loanNum, pw));	

	cout << "\n------------------------------------------------" << endl;
	cout << "������ �Ϸ�Ǿ����ϴ�. �Ʒ��� ������ Ȯ���� �ּ���.\n" << endl;
	cout << "���¹�ȣ : " << accid << endl;
	cout << "���� �ݾ� : " << desired_amount << endl;

}

void LoanPersonInfoDB::setPayBack(int idx,int anspayback) {
	Info[idx].setPay(anspayback);
}

int LoanPersonInfoDB::getLoanNumber(int idx) {
	return Info[idx].getLoanNum();
}


int LoanPersonInfoDB::getLoanAccID(int idx) {
	return Info[idx].getAccID();
}
int LoanPersonInfoDB::getLoanAmount(int idx) {
	return Info[idx].getLoanDesiredAmount();
}

int LoanPersonInfoDB::getSize() {
	return Info.size();
}


int LoanPersonInfoDB::getLoanPayback(int idx) {
	return Info[idx].getLoanPayback();
}

int LoanPersonInfoDB::getpw(int idx, int pw) {
	return Info[idx].checkPassWord(pw);
}