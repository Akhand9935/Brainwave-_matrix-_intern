#include <iostream>
using namespace std;

const int ACCOUNT_NUMBER = 12345;
const int PIN_NUMBER = 9935;
int balance = 0;

bool validateAccountNumber(int givenAccountNumber) {
    return givenAccountNumber == ACCOUNT_NUMBER;
}

bool validatePinNumber(int givenPinNumber) {
    return givenPinNumber == PIN_NUMBER;
}

bool login() {
    int givenAccountNumber = -1;
    int givenPinNumber = -1;
    bool isAuthenticated = false;

    cout << "Welcome!" << endl;

    while (!isAuthenticated) {
        cout << "Please enter your account number: ";
        cin >> givenAccountNumber;

        if (validateAccountNumber(givenAccountNumber)) {
            cout << "Enter your PIN: ";
            cin >> givenPinNumber;

            if (validatePinNumber(givenPinNumber)) {
                isAuthenticated = true;
            } else {
                cout << "Invalid PIN! Try again." << endl;
            }
        } else {
            cout << "Invalid account number! Try again." << endl;
        }
    }

    return isAuthenticated;
}

int getUserOption() {
    int selectedOption = -1;
    do {
        cout << "\nMain menu:" << endl;
        cout << "1 - View my balance" << endl;
        cout << "2 - Withdraw cash" << endl;
        cout << "3 - Deposit funds" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter a choice: ";
        cin >> selectedOption;

        if (selectedOption < 1 || selectedOption > 4) {
            cout << "Invalid option! Please choose between 1 and 4." << endl;
        }
    } while (selectedOption < 1 || selectedOption > 4);

    return selectedOption;
}

void viewBalance() {
    cout << "\nYour current balance is: $" << balance << endl;
}

void withdrawCash() {
    const int withdrawalOptions[] = {20, 40, 60, 100, 200};
    int selectedOption = -1;
    bool isTransactionPending = true;

    do {
        cout << "\nWithdrawal options:" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << i + 1 << " - $" << withdrawalOptions[i] << endl;
        }
        cout << "6 - Cancel transaction" << endl;
        cout << "Select a withdrawal option (1-6): ";
        cin >> selectedOption;

        if (selectedOption >= 1 && selectedOption <= 5) {
            int withdrawAmount = withdrawalOptions[selectedOption - 1];
            if (withdrawAmount > balance) {
                cout << "Insufficient funds. Your balance is $" << balance << ". Cannot withdraw $" << withdrawAmount << "." << endl;
            } else {
                balance -= withdrawAmount;
                cout << "You have withdrawn $" << withdrawAmount << ". New balance: $" << balance << endl;
                isTransactionPending = false;
            }
        } else if (selectedOption == 6) {
            cout << "Transaction cancelled." << endl;
            isTransactionPending = false;
        } else {
            cout << "Invalid option! Try again." << endl;
        }
    } while (isTransactionPending);
}

void depositFunds() {
    const int depositOptions[] = {20, 40, 60, 100, 200};
    int selectedOption = -1;
    bool isTransactionPending = true;

    do {
        cout << "\nDeposit options:" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << i + 1 << " - $" << depositOptions[i] << endl;
        }
        cout << "6 - Cancel transaction" << endl;
        cout << "Choose a deposit option (1-6): ";
        cin >> selectedOption;

        if (selectedOption >= 1 && selectedOption <= 5) {
            balance += depositOptions[selectedOption - 1];
            cout << "You have deposited $" << depositOptions[selectedOption - 1] << ". New balance: $" << balance << endl;
            isTransactionPending = false;
        } else if (selectedOption == 6) {
            cout << "Transaction cancelled." << endl;
            isTransactionPending = false;
        } else {
            cout << "Invalid option! Try again." << endl;
        }
    } while (isTransactionPending);
}

int main() {
    if (login()) {
        bool isRunning = true;

        while (isRunning) {
            switch (getUserOption()) {
                case 1:
                    viewBalance();
                    break;
                case 2:
                    withdrawCash();
                    break;
                case 3:
                    depositFunds();
                    break;
                case 4:
                    cout << "Exiting... Thank you for using our ATM!" << endl;
                    isRunning = false;
                    break;
            }
        }
    }

    return 0;
}
