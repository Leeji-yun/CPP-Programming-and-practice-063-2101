#include "loan.h"


using namespace std;

loan::loan() {
	Items[0] = new LoanItem(4, 15000000, 3, "원금균등상환");
	Items[1] = new LoanItem(4.5, 5000000, 1, "만기일시상환");
	Items[2] = new LoanItem(10.3, 5000000, 2, "만기일시상환");
	num = 3;
}

int loan::getnum() {
	return num;
}

void loan::addLoanItemMenu() {
	double LoanRate;
	int LoanLimit;
	int Period;
	char PayBackWay[20];

	cout << "< 대출 상품 추가 >" << endl;
	cout << "대출시 연 금리 :  연";
	cin >> LoanRate;
	cout << "최대 한도 :";
	cin >> LoanLimit;
	cout << "대출 기간 : ";
	cin >> Period;
	cout << "상환 방법 :  ";
	cin >> PayBackWay;

	Items[num] = new LoanItem(LoanRate, LoanLimit, Period, PayBackWay);
	num++;

	cout << "대출 상품 추가가 완료되었습니다." << endl;

}

void loan::showLoanItemMenu() {
	cout << "전체 대출 상품 목록" << endl;
	for (int i = 0; i < num; i++) {
		Items[i]->LoanItemInfo(i);
	}
}

void loan::getLoan(){
	string ans;
	
	showLoanItemMenu();

	loanPersonInfoDB.addLoanPersonInfo();
}

void loan::payBackCheck() {
	int accID;
	int  loannum, anspw;
	double interest, desire;
	int j = 0;
	char a[10];
	int i = 0; 
	int check, noaccid = 0;
	
	
	cout << "계좌번호 : ";
	cin >> accID;

	for (int i = 0; i < loanPersonInfoDB.getSize();i++) {
		if (loanPersonInfoDB.getLoanAccID(i) == accID) {
			desire = loanPersonInfoDB.getLoanAmount(i);
			loannum = loanPersonInfoDB.getLoanNumber(i);
			noaccid = 1;
			break;
		}
	}

	if (noaccid == 0) {
		cout << "존재하지 않는 계좌번호입니다.\n" << endl;
		return payBackCheck();
	}

	else {
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
		anspw = result;

		for (int i = 0; i < loanPersonInfoDB.getSize(); i++) {
			if (loanPersonInfoDB.getLoanAccID(i) == accID) {
				check = loanPersonInfoDB.getpw(i, anspw);
				break;
			}
		}

		if (check == 1) {
			cout << "\n";
			return payBackCheck();
		}

		else {

			cout << "< 상환 금액 조회 >" << endl;
			cout << "|" << setw(10) << "개월" << setw(10) << "|" << setw(10) << "이자" << setw(10) << "|" << setw(15) << "원금 상환" << setw(8) << "|" << setw(15) << "대출 잔액" << setw(8) << "|" << setw(15) << "납부금액" << setw(8) << "|" << endl;
			cout << "--------------------------------------------------------------------------------------------------------------" << endl;

			if (Items[loannum - 1]->getPayBackWay() == "만기일시상환") {
				double interest = round((Items[loannum - 1]->getLoanRate() / 100 * desire) / 12);

				int n;

				for (n = 0; n < (Items[loannum - 1]->getPeriod()) * 12 - 1; n++) {
					cout << setw(10) << n + 1 << setw(21) << interest << setw(20) << "-" << setw(25) << desire << setw(23) << interest << endl;
				}

				cout << setw(10) << n + 1 << setw(21) << interest << setw(20) << desire << setw(25) << "-" << setw(23) << interest + desire << endl;
			}

			else if (Items[loannum - 1]->getPayBackWay() == "원금균등상환") {
				int n;
				double interest = round((Items[loannum - 1]->getLoanRate() / 100 * desire) / 12);
				double repay = round(desire / ((double)(Items[loannum - 1]->getPeriod()) * 12));

				for (n = 0; n < (Items[loannum - 1]->getPeriod()) * 12 - 1; n++) {
					cout << setw(10) << n + 1 << setw(21) << interest << setw(20) << repay << setw(25) << desire - repay << setw(23) << interest + repay << endl;
					interest = round((Items[loannum - 1]->getLoanRate() / 100 * (desire - repay)) / 12);
					desire = desire - repay;
				}

				cout << setw(10) << n + 1 << setw(21) << interest << setw(20) << desire << setw(25) << "-" << setw(23) << interest + repay << endl;
			}
		}
	}
}

void loan::payBack() {
	int anspayback;
	int accID, anspw, check, noaccid = 0;
	char a[10];
	int i = 0;
	

	cout << "계좌번호 입력 : ";
	cin >> accID;

	for (int i = 0; i < loanPersonInfoDB.getSize(); i++) {
		if (loanPersonInfoDB.getLoanAccID(i) == accID) {
			noaccid = 1;
			break;
		}
	}

	if (noaccid == 0) {
		cout << "존재하지 않는 계좌번호입니다.\n" << endl;
		return payBack();
	}

	else {
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
		anspw = result;

		for (int i = 0; i < loanPersonInfoDB.getSize(); i++) {
			if (loanPersonInfoDB.getLoanAccID(i) == accID) {
				check = loanPersonInfoDB.getpw(i, anspw);
				break;
			}
		}

		if (check == 1) {
			cout << "\n";
			return payBack();
		}

		else {
			cout << "상환 금액 입력 : ";
			cin >> anspayback;

			for (int i = 0; i < loanPersonInfoDB.getSize(); i++) {
				if (loanPersonInfoDB.getLoanAccID(i) == accID) {
					anspayback += loanPersonInfoDB.getLoanPayback(i);
					loanPersonInfoDB.setPayBack(i, anspayback);
					cout << "현재까지의 상환금액은 총" << loanPersonInfoDB.getLoanPayback(i) << "원 입니다." << endl;;
					break;
				}
			}
		}
	}
}

