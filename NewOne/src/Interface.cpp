#include "Interface.h"
#include "Bank.h"
#include "Client.h"
#include "Transfer.h"
#include "Loan.h"
#include <iostream>
#include <limits>


using namespace std;

Interface::Interface(const shared_ptr<Bank> &bank) : bank(bank) {}

Interface::~Interface() = default;

void Interface::start() {

    cout << "Welcome in OPP Bank Application" << endl;

    bool exit = false;
    while (!exit) {

        cout
                << "==================================" << endl
                << "1. Login into client account " << endl
                << "2. Register new client " << endl
                << "3. Delete client " << endl
                << "4. List all clients " << endl
                << "0. Exit application " << endl
                << "==================================" << endl;

        char input;
        cin >> input;

        switch (input) {
            // 1. Login
            case '1':
                login();
                break;

                // 2. Register
            case '2':
                registerClient();
                break;

                // 3. Delete
            case '3':
                deleteClient();
                break;

                // 4. List
            case '4':
                listClients();
                break;

                // 0. Exit
            case '0':
                exit = true;
                break;

                // Default
            default:
                cout << "Wrong command. Choose again" << endl;
        }
    }
}

void Interface::login() {

std::string pesel;
std::string password;
cout<<"Pesel number: ";
cin>>pesel;
cout<<"Password: ";
cin>>password;
    for(auto& client : bank->getClients()) {
    if(client->getClientPesel()==pesel)
        if(client->validatePassword(pesel, password)){
            cout<<"Account of "<<client->getClientName()<<" "<<client->getClientSurname()<<endl;
            logged(pesel);
        }
        else{
            cout<<"Login failed."<<endl;
    }
    }
    }

void Interface::registerClient() {

    std::string pesel;
    std::string name;
    std::string surname;
    std::string address;
    long int phone;
    std::string password;

    cout << "Name: ";
    cin >> name;
    cout << "Surname: ";
    cin >> surname;
    cout << "Pesel number: ";
    cin >> pesel;
    cout << "Address:";
    cin.ignore();
    getline(cin, address);
    cout << "Phone: ";
    cin >> phone;
    cout << "Password: ";
    cin >> password;

    if (!(bank->peselInUse(pesel))) {
        bank->addClient(bank->createClient(pesel, name, surname, address, phone, password));
    } else {
        cout << "This pesel number is already in use!" << endl;
    }

}

void Interface::deleteClient() {
std::string pesel;
cout<<"Provide pesel number: ";
cin>>pesel;
bank->removeClient([&](Client c){return c.getClientPesel()==pesel;});
cout<<"Client removed.";
}

void Interface::listClients() {
    bool exit4 = false;
    while (!exit4) {
        cout << "list of all clients: " << endl << endl;
        int i = 1;
        for (const auto &client: bank->getClients()) {
            cout << "Client number " << i << endl;
            cout << "Name: " << client->getClientName() << endl;
            cout << "Surname: " << client->getClientSurname() << endl;
            cout << "Pesel: " << client->getClientPesel() << endl;
            cout << "Address: " << client->getClientAddress() << endl;
            cout << "Phone: " << client->getClientPhone() << endl << endl;
            i++;
        }
        cout << endl << "0. Exit" << endl;
        char input;
        cin >> input;
        switch (input) {
            //0. Exit
            case '0':
                exit4 = true;
                break;
        }
    }
}


void Interface::logged(std::string pesel) {
    if ((bank->getAccounts().empty())) {
        openAccount(pesel);
    } else {
        bool found = false;
        for (auto &account: bank->getAccounts()) {
            if (account->getClientPesel() == pesel) {
                accountPanel(pesel);
                found = true;
                break;
            }
        }
        if(!found) {
            openAccount(pesel);
        }
        }

    }

void Interface::createNormal(std:: string pesel) {
int pin;
double balance = 0;
std::string accountNumber;
cout<<"Choose PIN: ";
cin>>pin;
    accountNumber = bank->generateAccountNumber();
    bank->addAccount(bank->createNormalAccount(pin, balance, pesel, accountNumber));
}

void Interface::createCredit(std::string pesel) {
int pin;
double balance = 0;
std::string accountNumber;
double limit = 1000;
float creditCost = 0.1;

cout<<"Choose PIN: ";
cin>>pin;
    accountNumber = bank->generateAccountNumber();
    bank->addAccount(bank->createCreditAccount(pin, balance, pesel, accountNumber, limit, creditCost));
}

void Interface::createSavings(std::string pesel) {
    int pin;
    double balance = 0;
    std::string accountNumber;
    float interestRate = 0.03;

    cout<<"Choose PIN: ";
    cin>>pin;
    accountNumber = bank->generateAccountNumber();
    bank->addAccount(bank->createSavingsAccount(pin, balance, pesel, accountNumber, interestRate));
}

void Interface::openAccount(std::string pesel) {
    bool exit2 = false;
    while (!exit2) {
        cout << "You dont have an account." << endl;
        cout << "=========================" << endl;
        cout << "1. Open normal account." << endl;
        cout << "2. Open credit account." << endl;
        cout << "3. Open savings account." << endl;
        cout << "0. Exit." << endl;

        char input;
        cin >> input;

        switch (input) {
            //1. Normal Account
            case '1':
                createNormal(pesel);
                exit2=true;
                break;
                //2. Credit Account
            case '2':
                createCredit(pesel);
                exit2=true;
                break;
                //3. Savings Account
            case '3':
                createSavings(pesel);
                exit2=true;
                break;
                // 0. Exit
            case '0':
                exit2 = true;
                break;
                // Default
            default:
                cout << "Wrong command. Choose again" << endl;
        }
    }
}

void Interface::accountPanel(std::string pesel) {
    cout<<"Account Panel"<<endl;
    for (auto &account: bank->getAccounts()) {
        if (account->getClientPesel() == pesel) {
            if((dynamic_cast<NormalAccount*>(account.get()))){
                cout<<"====================================="<<endl;
                cout<<"Balance: "<<account->getBalance()<<"PLN"<<endl<<endl;
                cout<<"Your account number: "<<account->getAccountNumber()<<endl;
                cout<<"Your pesel number: "<<account->getClientPesel()<<endl;
                cout<<"====================================="<<endl;
                accountOptions(pesel);
            }
            if((dynamic_cast<CreditAccount*>(account.get()))){
                cout<<"====================================="<<endl;
                cout<<"Balance: "<<account->getBalance()<<"PLN"<<endl<<endl;
                cout<<"Your account number: "<<account->getAccountNumber()<<endl;
                cout<<"Your pesel number: "<<account->getClientPesel()<<endl;
                cout<<"Your available limit: "<<((dynamic_cast<CreditAccount*>(account.get())))->getLimit()<<"PLN"<<endl;
                cout<<"====================================="<<endl;
                accountOptions(pesel);
            }
            if((dynamic_cast<SavingsAccount*>(account.get()))){
                cout<<"====================================="<<endl;
                double x = account->getBalance();
                x = x + (x * ((dynamic_cast<SavingsAccount*>(account.get())))->getInterestRate());
                account->setBalance(x);
                cout<<"Balance: "<<account->getBalance()<<"PLN"<<endl<<endl;
                cout<<"Your account number: "<<account->getAccountNumber()<<endl;
                cout<<"Your pesel number: "<<account->getClientPesel()<<endl;
                cout<<"Your interest rate: "<<((dynamic_cast<SavingsAccount*>(account.get())))->getInterestRate() * 100<<"%"<<endl;
                cout<<"====================================="<<endl;
                accountOptions(pesel);
            }
        }


        }
}

void Interface::accountOptions(std::string pesel) {

    bool exit3 = false;
    while (!exit3) {
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Transfer" << endl;
        cout << "4. Loan" << endl;
        cout << "0. Exit" << endl;
        cout << "=====================================" << endl;

        char input;
        cin >> input;

        switch (input) {
            //1. Deposit
            case '1':
                depositInterface(pesel);
                accountPanel(pesel);
                exit3 = true;
                break;

            //2. Withdraw
            case '2':
                withdrawInterface(pesel);
                accountPanel(pesel);
                exit3 = true;
                break;

            //3. Transfer
            case '3':
                transferInterface(pesel);
                accountPanel(pesel);
                exit3 = true;
                break;

            //4. Loan
            case '4':
                loanInterface(pesel);
                accountPanel(pesel);
                exit3 = true;
                break;

            //0. Exit
            case '0':
                exit3 = true;
                break;

            //Default
            default:
                cout << "Wrong command. Choose again" << endl;
                break;
        }
    }
}

void Interface::depositInterface(std::string pesel) {
    double x;
    cout<<"Enter amount that you want to deposit: ";
    cin>>x;
    for (auto &account: bank->getAccounts()) {
        if (account->getClientPesel() == pesel) {
            account->deposit(x);
        }
    }
}

void Interface::withdrawInterface(std::string pesel) {
    double x;
    int pin;
    cout << "Enter amount that you want to withdraw: ";
    cin >> x;
    cout<<"Enter your PIN: ";
    cin>>pin;
    if(bank->checkPIN(pesel, pin)) {
        for (auto &account: bank->getAccounts()) {
            if (account->getClientPesel() == pesel) {
                if ((dynamic_cast<NormalAccount *>(account.get()))) {
                    (dynamic_cast<NormalAccount *>(account.get()))->withdraw(x);
                }
                if ((dynamic_cast<CreditAccount *>(account.get()))) {
                    (dynamic_cast<CreditAccount *>(account.get()))->withdraw(x);
                }
                if ((dynamic_cast<SavingsAccount *>(account.get()))) {
                    (dynamic_cast<SavingsAccount *>(account.get()))->withdraw(x);
                }
            }
        }
    }else{
        cout<<"PIN incorrect!";
    }
}
void Interface::transferInterface(std::string pesel) {
    double x;
    int pin;
    std::string s;
    std::string n;
    std::shared_ptr<Account> sourceAccount;
    std::shared_ptr<Account> destinationAccount;

    cout << "Enter amount that you want to transfer: ";
    cin >> x;
    cout << "Enter account number of destination: ";
    cin >> s;
    cout << "Enter your PIN: ";
    cin >> pin;
    if (bank->checkPIN(pesel, pin)) {
        for (auto &account: bank->getAccounts()) {
            if (account->getClientPesel() == pesel) {
                n = account->getAccountNumber();
                sourceAccount = account;
            }
            for (auto &account: bank->getAccounts()) {
                if (account->getAccountNumber() == s) {
                    destinationAccount = account;
                }
            }
        }
        Transfer transfer(n, s, x);
        transfer.makeTransfer(*sourceAccount, *destinationAccount);
    }else{
        cout<<"Wrong PIN!";
    }
}


void Interface::loanInterface(std::string pesel) {
    int day, month, year;
    double x, amount, repayment;
    std::string purpose;
    for (auto &account: bank->getAccounts()) {
        if (account->getClientPesel() == pesel && account->haveLoan()){

            for (auto &loan: bank->getLoans()) {
                if (loan->getClientPesel()==pesel) {
                    loan->penalty();
                    cout << "Infomation about loan: " << endl;
                    cout << "Amount to pay off: " << loan->getAmount() << ", Due to date: " << loan->getDay() << "."
                         << loan->getMonth() << "." << loan->getYear() << endl;
                    cout << "Purpose: " << loan->getPurpose() << endl;
                    cout << "Enter repayment amount" << endl;
                    cin >> repayment;
                    bank->payOffLoan(repayment, loan, account);
                    cout << account->getBalance() << endl;
                }
            }
        }
        else if (account->getClientPesel() == pesel)
        {
            cout << "Enter amount " << endl;
            double a = account->getBalance();
            cin >> x;
            if (a < (0.3 * x))
                cout << " You don't have enough money to take a loan" << endl;
            else {
                cin.exceptions(std::istream::failbit);                
                try
                {
                cout << "Enter purpose" << endl;
                cin.ignore();
                getline(cin, purpose);
                cout << "Enter date to payoff" << endl;
                cout << "day: ";
                cin >> day;
                cout << "month: ";
                cin >> month;
                cout << "year: ";
                cin >> year;
                auto loan = bank->createLoan(pesel, x);
                bank->giveLoan(x, loan, account, day, month, year, purpose);
                cout << "Loan added successful" << endl;
                }
                catch(const std::ios_base::failure &fail)
                {
                    cout<<"Wrong input, please use integers for date"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;
                
  
            }
        }

    }


}
