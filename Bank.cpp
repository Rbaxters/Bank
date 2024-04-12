#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Function prototypes
void get_input(double& input, const string& prompt);
void get_input(int& input, const string& prompt);

int main() {
    double initialBalance, annualInterest, monthlyDeposit, monthlyWithdrawal;
    int monthsActive;
    bool goodInput = false;

    // Get initial balance
    get_input(initialBalance, "Please input the initial balance: ");

    // Get annual interest rate
    get_input(annualInterest, "Please input the annual interest: ");

    // Get months active
    get_input(monthsActive, "Please input the number of months: ");

    double balance = initialBalance;
    double totalWithdrawals = 0;
    double totalDeposits = 0;
    double totalMonthlyInterest = 0;
    double monthlyInterest = annualInterest / 12;

    fstream myFile("savingsdata.txt", ios::out);

    for (int month = 1; month <= monthsActive; ++month) {
        // Get monthly deposit
        get_input(monthlyDeposit, "How much have you deposited this month?: ");
        balance += monthlyDeposit;
        totalDeposits += monthlyDeposit;

        // Get monthly withdrawal
        get_input(monthlyWithdrawal, "How much have you withdrawn this month?: ");
        balance -= monthlyWithdrawal;
        totalWithdrawals += monthlyWithdrawal;

        // Calculate monthly interest
        double monthlyInterestAmount = balance * monthlyInterest;
        balance += monthlyInterestAmount;
        totalMonthlyInterest += monthlyInterestAmount;

        cout << "Balance after month " << month << ": " << balance << endl;
    }

    // Write final values to file
    myFile << "FINAL VALUES\n"
           << "Balance: " << balance << "\n"
           << "Total amount of Withdrawals: " << totalWithdrawals << "\n"
           << "Total amount of Deposits: " << totalDeposits << "\n"
           << "Total Monthly Interest: " << totalMonthlyInterest << "\n";

    myFile.close();
    cout << "Final data has been written in savingsdata.txt\n";

    // Read and output data from the file
    ifstream inputFile("savingsdata.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    return 0;
}

void get_input(double& input, const string& prompt) {
    cout << prompt;
    while (!(cin >> input)) {
        string str;
        cin.clear();
        getline(cin, str);  // Clear input buffer
        cout << str << " is not a valid input. Please try again: ";
    }
    cout << "Input is valid." << endl;
}

void get_input(int& input, const string& prompt) {
    cout << prompt;
    while (!(cin >> input)) {
        string str;
        cin.clear();
        getline(cin, str);  // Clear input buffer
        cout << str << " is not a valid input. Please try again: ";
    }
    cout << "Input is valid." << endl;
}
