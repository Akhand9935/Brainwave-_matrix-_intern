#include <iostream>
#include <map>
#include <string>
using namespace std;


struct Account {
    string name;
    int accountNumber;
    double balance;
};


void createAccount(map<int, Account>& accounts, int& nextAccountNumber, string name, double initialDeposit) {
    if (initialDeposit < 0) {
        cout << "Initial deposit cannot be negative!" << endl;
        return;
    }

    Account newAccount;
    newAccount.name = name;
    newAccount.accountNumber = nextAccountNumber;
    newAccount.balance = initialDeposit;

    accounts[nextAccountNumber] = newAccount;
    cout << "Account created successfully! Account Number: " << nextAccountNumber << endl;

    nextAccountNumber++;
}


Account* findAccount(map<int, Account>& accounts, int accountNumber) {
    if (accounts.find(accountNumber) != accounts.end()) {
        return &accounts[accountNumber];
    } else {
        cout << "Account not found!" << endl;
        return nullptr;
    }
}


void deposit(Account* account, double amount) {
    if (amount > 0) {
        account->balance += amount;
        cout << "Current Balance: Rs." << account->balance << endl;
    } else {
        cout << "Deposit amount should be positive!" << endl;
    }
}


void withdraw(Account* account, double amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        cout << "Current Balance: Rs." << account->balance << endl;
    } else {
        cout << "Insufficient funds or invalid amount!" << endl;
    }
}


void transfer(Account* fromAccount, Account* toAccount, double amount) {
    if (amount > 0 && amount <= fromAccount->balance) {
        fromAccount->balance -= amount;
        toAccount->balance += amount;
        cout << "Successfully transferred: Rs. " << amount << " to Account " << toAccount->accountNumber << endl;
    } else {
        cout << "Transfer failed. Insufficient funds or invalid amount!" << endl;
    }
}


void displayAccountInfo(const Account& account) {
    cout << "Account Holder: " << account.name << endl;
    cout << "Account Number: " << account.accountNumber << endl;
    cout << "Balance: Rs." << account.balance << endl;
}


int main() {
    map<int, Account> accounts;  
    int nextAccountNumber = 1001; 
    int choice, accountNumber, toAccountNumber;
    string name;
    double amount;

    do {
        cout << "\n===== Online Banking System Menu =====" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Transfer" << endl;
        cout << "5. Display Account" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account holder name: ";
                cin.ignore(); 
                getline(cin, name);
                cout << "Enter initial deposit amount: ";
                cin >> amount;
                createAccount(accounts, nextAccountNumber, name, amount);
                break;

            case 2:
                cout << "Enter account number: ";
                cin >> accountNumber;
                {
                    Account* account = findAccount(accounts, accountNumber);
                    if (account != nullptr) {
                        cout << "Enter deposit amount: ";
                        cin >> amount;
                        deposit(account, amount);
                    }
                }
                break;

            case 3:
                cout << "Enter account number: ";
                cin >> accountNumber;
                {
                    Account* account = findAccount(accounts, accountNumber);
                    if (account != nullptr) {
                        cout << "Enter withdraw amount: ";
                        cin >> amount;
                        withdraw(account, amount);
                    }
                }
                break;

            case 4:
                cout << "Enter your account number: ";
                cin >> accountNumber;
                cout << "Enter recipient account number: ";
                cin >> toAccountNumber;
                {
                    Account* fromAccount = findAccount(accounts, accountNumber);
                    Account* toAccount = findAccount(accounts, toAccountNumber);
                    if (fromAccount != nullptr && toAccount != nullptr) {
                        cout << "Enter transfer amount: ";
                        cin >> amount;
                        transfer(fromAccount, toAccount, amount);
                    }
                }
                break;

            case 5:
                cout << "Enter account number: ";
                cin >> accountNumber;
                {
                    Account* account = findAccount(accounts, accountNumber);
                    if (account != nullptr) {
                        displayAccountInfo(*account);
                    }
                }
                break;

            case 6:
                cout << "Exiting system..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
