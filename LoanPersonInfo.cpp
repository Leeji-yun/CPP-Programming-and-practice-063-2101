#include "LoanPersonInfo.h"
#include <cstring>
#include <iostream>
//LoanPersonInfo::checkPassWord(int pw)�Լ� �ڵ� �ۼ�

using namespace std;

int i = 0;

LoanPersonInfo::LoanPersonInfo(int myaccID,  int mydesired_amount, int myloanNum, int mypassword)
: accID(myaccID),  desired_amount(mydesired_amount), loanNum(myloanNum),PassWord(mypassword), payback(0){}

void LoanPersonInfo::setPay(int pay) {
	this->payback = pay;
}

int LoanPersonInfo::getAccID() {
	return this->accID;
}

int LoanPersonInfo::getLoanNum() {
	return this->loanNum;
}


int LoanPersonInfo::getLoanDesiredAmount() {
	return this->desired_amount;
}

int LoanPersonInfo::getLoanPayback() {
	return this->payback;
}

int LoanPersonInfo::checkPassWord(int pw) {
	if (this->PassWord != pw)
	{
		cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		return 1;
		system("PAUSE");
	}
}


