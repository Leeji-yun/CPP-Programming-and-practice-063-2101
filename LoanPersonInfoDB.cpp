#include"LoanPersonInfoDB.h"
//LoanPersonInfoDB::getpw(int idx, int pw)함수 코드 작성

using namespace std;

int idx = 0;

void LoanPersonInfoDB::addLoanPersonInfo() {
	int loanNum;
	int accid;
	int desired_amount;
	int pw;
	char a[10];
	int i = 0;

	cout << "대출 상품 번호 : ";
	cin >> loanNum;
	cout << "계좌번호 : ";
	cin >> accid;
	cout << "비밀번호 : ";
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
	cout << "희망 대출 금액  : ";
	cin >> desired_amount;


	Info.push_back(LoanPersonInfo(accid, desired_amount, loanNum, pw));	

	cout << "\n------------------------------------------------" << endl;
	cout << "대출이 완료되었습니다. 아래의 정보를 확인해 주세요.\n" << endl;
	cout << "계좌번호 : " << accid << endl;
	cout << "대출 금액 : " << desired_amount << endl;

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