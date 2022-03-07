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
        // this will be required to be improved
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
    double interest;
    double increase(double x)
    {
        // this will be called when the user deposits funds
        interest = 0;
        x += interest;
        return x;
    }
    void reduce(double a)
    {
        // this will be called when the user withdraws
        cout << "Cheque book created for amount: " << a << "\n";
    }
};
class Sav_Account
{
public:
    double interest = 0.2; // interest of 20%
    double increase(double x)
    {
        // this will be called when the user deposits funds
        interest = interest * x;
        x += interest;
        return x;
    }
};
class Manage
{
public:
    double balance = 0;
    double withdraw;
    double deposit;
    string depositer;
    string withdrawer;
    double minBalance = 10000;
    double serviceCharge = 2000;
    void fine(double y)
    {
        // for checking whether user is below the minimum balance or not
        // if below, a service charge has to be fined
        if (y < minBalance)
        {
            cout << "You have less funds and a service fee of " << serviceCharge << " has been imposed \n";
        }
        else
        {
            cout << "Thank you for choosing Thunder Banking Services";
        }
    }
    void withdrawal()
    {
        int choice;
        string accountName;
        string accountType;
        cout << "Withdrawing\n";
        cout << "Enter account name\n";
        cin >> accountName;
        cout << "Name of withdrawer\n";
        cin >> withdrawer;
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
            cout << "Select account type\n1.Savings Account\n2.Current Account\n";
            cin >> choice;
            if (choice == 1)
            {
                accountType = "Savings Account";
                cout << "Transaction successful\n";
            }
            else if (choice == 2)
            {
                accountType = "Current Account";
                Curr_Account withd;
                withd.reduce(withdraw);
            }
            else
            {
                cout << "Unknown Account Type\n";
            }
            cout << "Account Name: " << accountName << "\tAccount Type: " << accountType << "\nWithdrawn : " << withdraw << " by " << withdrawer << "\tAccount balance: " << balance << "\n";
            fine(balance);
        }
    }
    void check()
    {
        cout << "Balance is " << balance << "\n";
    }
    void depositing()
    {
        int choice;
        string accountName;
        string accountType;
        cout << "Depositing\n";
        cout << "Enter account name\n";
        cin >> accountName;
        cout << "Name of depositer\n";
        cin >> depositer;
        cout << "Enter amount to deposit\n";
        cin >> deposit;
        balance += deposit;
        cout << "Select account type\n1.Savings Account\n2.Current Account\n";
        cin >> choice;
        if (choice == 1)
        {
            accountType = "Savings Account";
            Sav_Account dep;
            balance = dep.increase(balance);
        }
        else if (choice == 2)
        {
            accountType = "Current Account";
            Curr_Account depo;
            balance = depo.increase(balance);
        }
        else
        {
            cout << "Unknown Account Type\n";
        }
        cout << "Account Name: " << accountName << "\tAccount Type: " << accountType << "\nDeposited: " << deposit << " by " << depositer << "\tAccount balance: " << balance << "\n";
        fine(balance);
    }
};
void operations()
{
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

void login()
{
    // first authenticate user and if successful, display this below
    operations();
}

void menu()
{
    // for returning to the main menu after user operations
    int reply;
    cout << "Please select\n1.Continue using our services\n2.To exit\n";
    cin >> reply;
    switch (reply)
    {
    case 1:
        operations();
        break;
    case 2:
        exit(0);
        break;
    default:
        cout << "Unknown reply\n";
        menu();
        break;
    }
}

int main()
{
    int choice;
    string greeting = "welcome to thunder bank\n";
    cout << greeting << "\n"
         << "Press 1 to login\n press 2 to create an account\n";
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
    menu();
}