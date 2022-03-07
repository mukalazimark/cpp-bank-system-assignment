#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Account
{
public:
    int accountPin;
    string accountType;
    string accountName;
    int pin1;
    int pin2;
    double minBalance;
    int serviceCharge;
    void newUser()
    {
        int reply;
        cout << "Enter your full name\n";
        // getline(cin, accountName);
        cin >> accountName;
        cout << "Enter your preffered pin\n";
        cin >> pin1;
        cout << "Renter your preffered pin\n";
        cin >> pin2;
        if (pin1 == pin2)
        {
            pin2 = accountPin;
            cout << "Enter your account type\n1.Savings Account\n2.Current Account\n";
            cin >> reply;
            if (reply == 1)
            {
                accountType = "Savings";
                cout << "Account created successfully\t Keep Your pin safe\n";
                cout << "User Name: " << accountName << "\tAccount Type: " << accountType << "\tPin: " << accountPin << "\n";
            }
            else if (reply == 2)
            {
                accountType = "Current";
                cout << "Account created successfully\t Keep Your pin safe\n";
                cout << "User Name: " << accountName << "\tAccount Type: " << accountType << "\tPin: " << accountPin << "\n";
            }
            else
            {
                cout << "Unknown account type\n";
            }
        }
        else
        {
            cout << "First pin is different from the second pin\n";
            newUser();
        }
    }
    void save()
    {
        string line = "\n";
        fstream record;
        record.open("users.txt", std::ios_base::app | std::ios_base::in);
        record << line;
        record << accountName;
        record << accountPin;
        record << accountType;
        record.close();
    }
};

class Curr_Account
{
public:
};
class Sav_Account
{
public:
    double interest;
};
class Manage
{
public:
    double balance = 0;
    double withdraw;
    double deposit;
    string depositer;
    void withdrawal()
    {
        cout << "withdrawing\n";
        cout << "Enter amount to withdraw\n";
        cin >> withdraw;
        if (withdraw > balance)
        {
            cout << "Insufficient balance\n";
            withdrawal();
        }
        else
        {
            balance -= withdraw;
            cout << "Withdrawn: " << withdraw << "\tAccount balance: " << balance << "\n";
        }
    }
    void check()
    {
        cout << "Balance is " << balance << "\n";
    }
    void depositing()
    {
        int choice;
        cout << "Depositing\n";
        cout << "Select account type\n1.Savings Account\n2.Current Account\n";
        cin >> choice;
        if (choice == 1)
        {
        }
        cout << "Enter amount to deposit\n";
        cin >> deposit;
        balance += deposit;
        cout << "Name of depositer\n";
        cin >> depositer;
        cout << "Deposited: " << deposit << " by " << depositer << "\tAccount balance: " << balance << "\n";
    }
};

void login()
{
    //     string user;
    //     ofstream records;
    //     records.open("users.txt");
    //     if (records.is_open())
    //     {
    //         cout << "no user records found\n";
    //     }
    //     else
    //     {
    //         cout << "User exists\n";
    //     }
    //     records.close();
    // first authenticate user and if successful, display this below
    int choice;
    cout << "1.Deposit Funds\n2.Withdraw funds\n3.Check Balance\n";
    cin >> choice;
    Manage account;
    if (choice == 1)
    {
        account.depositing();
    }
    else if (choice == 2)
    {
        account.withdrawal();
    }
    else if (choice == 3)
    {
        account.check();
    }
    else
    {
        cout << "Invalid operation\n";
    }
}
int main()
{
    int choice;
    string greeting = "welcome to thunder bank\n";
    cout << "Press 1 to login\n press 2 to create an account\n";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Logging in\n";
        login();
    }
    else if (choice == 2)
    {
        cout << "creating \n";
        Account createUser;
        createUser.newUser();
        createUser.save();
    }
}