#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SavingAccount {
private:
    string accountHolderName;
    const int accountNo;
    float balance;
    static float interest;

public:
    SavingAccount(string name, int acNo, float balance)
        : accountNo(acNo), balance(balance) {
        accountHolderName = name;
    }

    void withdraw(int deductedAmt) {
        if (balance > 1000) {
            if ((balance - deductedAmt) > 1000) {
                balance -= deductedAmt;
                cout << deductedAmt << " amount is deducted from your bank account" << endl;
                cout << "Your current balance is " << balance << endl;
            } else {
                cout << "If deducted from your bank account, your balance will go below 1000. So we cannot proceed." << endl;
            }
        } else {
            cout << "Deduction failure, balance is less than 1000" << endl;
        }
    }

    void deposit(int depositedAmt) {
        if ((depositedAmt + balance) > 100000) {
            cout << "Not possible! Bank balance will exceed 1,00,000" << endl;
        } else {
            balance += depositedAmt;
            cout << depositedAmt << " amount is deposited in your bank account. Your current balance is " << balance << endl;
        }
    }

    float calculateInterest(int month) {
        float currInterest = (balance * interest * month) / (100 * 12);
        balance += currInterest;
        return currInterest;
    }

    float currentBalance() {
        return balance;
    }
};

float SavingAccount::interest = 3.8;

int main() {
    int numOfAcc;
    cout << "Enter how many number of accounts there are: ";
    cin >> numOfAcc;

    vector<SavingAccount*> accounts;

    cout << "Enter details of each account: account holder name and initial balance (should be greater than 1000):\n";
    for (int i = 0; i < numOfAcc; i++) {
        cout << "Enter details of user " << i + 1 << " name: ";
        string name;
        cin >> name;
        cout << "Enter initial amount you want to deposit: ";
        float amount;
        cin >> amount;
        accounts.push_back(new SavingAccount(name, i + 1, amount));
    }

    float totalInterest = 0;
    for (int i = 0; i < numOfAcc; i++) {
        cout << "Bank account number: " << i + 1 << " Do you want to deposit amount? (yes/no): ";
        string decision_str;
        cin >> decision_str;
        bool decision = (decision_str == "yes" || decision_str == "Yes");
        if (decision) {
            int depositAmt;
            cout << "Enter deposit amount: ";
            cin >> depositAmt;
            accounts[i]->deposit(depositAmt);
        } else {
            cout << "Ok" << endl;
        }

        cout << "Do you want to withdraw amount? (yes/no): ";
        cin >> decision_str;
        decision = (decision_str == "yes" || decision_str == "Yes");
        if (decision) {
            int withdrawAmt;
            cout << "Enter withdraw amount: ";
            cin >> withdrawAmt;
            accounts[i]->withdraw(withdrawAmt);
        } else {
            cout << "Ok" << endl;
        }

        cout << "Your amount is fixed for 1 year." << endl;
        cout << "After 1 year, your total interest is " << accounts[i]->calculateInterest(12) << endl;
        totalInterest += accounts[i]->calculateInterest(12);
        cout << "Now your current balance is " << accounts[i]->currentBalance() << endl;
    }

    cout << "Total interest to be paid to all accounts in one year is " << totalInterest << endl;

    for (int i = 0; i < numOfAcc; i++) {
        delete accounts[i];
    }

    return 0;
}
