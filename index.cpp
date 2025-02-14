#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account
{
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(string accNum, string accHolder, double bal) : accountNumber(accNum), accountHolder(accHolder), balance(bal) {}

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: $" << amount << "\n";
    }

    bool withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew: $" << amount << "\n";
            return true;
        }
        else
        {
            cout << "Insufficient funds!\n";
            return false;
        }
    }

    void display() const
    {
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Account Holder: " << accountHolder << "\n";
        cout << "Balance: $" << balance << "\n";
    }

    string getAccountNumber() const { return accountNumber; }
};

class Bank
{
private:
    vector<Account> accounts;

public:
    void createAccount(const string &accNum, const string &accHolder, double initialBalance)
    {
        accounts.push_back(Account(accNum, accHolder, initialBalance));
        cout << "Account created successfully!\n";
    }

    Account *findAccount(const string &accNum)
    {
        for (auto &acc : accounts)
        {
            if (acc.getAccountNumber() == accNum)
                return &acc;
        }
        return nullptr;
    }

    void displayAllAccounts() const
    {
        for (const auto &acc : accounts)
        {
            acc.display();
            cout << "-----------------------\n";
        }
    }
};

int main()
{
    Bank bank;
    int choice;

    while (true)
    {
        cout << "\nBanking System Menu:\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Display All Accounts\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5)
            break;

        string accNum, accHolder;
        double amount;

        switch (choice)
        {
        case 1:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, accHolder);
            cout << "Enter Initial Balance: $";
            cin >> amount;
            bank.createAccount(accNum, accHolder, amount);
            break;
        case 2:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Amount to Deposit: $";
            cin >> amount;
            if (Account *acc = bank.findAccount(accNum))
                acc->deposit(amount);
            else
                cout << "Account not found!\n";
            break;
        case 3:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Amount to Withdraw: $";
            cin >> amount;
            if (Account *acc = bank.findAccount(accNum))
                acc->withdraw(amount);
            else
                cout << "Account not found!\n";
            break;
        case 4:
            bank.displayAllAccounts();
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }

    cout << "Thank you for using the Banking System!\n";
    return 0;
}
