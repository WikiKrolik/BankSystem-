//
// Created by student on 1/16/22.
//

#include "model/Bank.h"
#include "model/Client.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <algorithm>

Bank::Bank(int bankId, double funds) : BankID(bankId), Funds(funds) {}

Bank::~Bank() {

}

std::string Bank::toString() {
    std::stringstream ss;
    ss << "Bank: " << Name << ", Funds- " << Funds <<", Location- " << Location;
    for ( auto client: clients) {
        ss << "\n" << client->getID() << " Name- " << client->getName() <<" Surname- " << client->getSurname();
    }

    ss << ".";

    return ss.str();
}

double Bank::getFunds() const {
    return Funds;
}

bool Bank::addClient( std::shared_ptr<Client> client) {
    {
        clients.push_back(client);
        return true;
    }
}
void Bank::removeClient(std::shared_ptr<Client> client) {
    {
        clients.erase(std::remove(clients.begin(), clients.end(), client), clients.end());
    }
}
/*void Bank::addClientInterface() {
    using namespace std;
    string fname, sn, a, p,password, password1;
    cout << "Enter Name" << endl;
    cin >> fname;
    cout << "Enter Surname" <<endl;
    cin >> sn;
    cout << "Enter Address" << endl;
    //getline(cin, a); dlaczego nie dziala?
    cin >> a;
    cout << "Enter phone Number" << endl;
    cin >> p;

    shared_ptr<ClientInterface> client = make_shared<ClientInterface>(clients.size() + 1, fname, sn, a, p);

    clients.push_back(client);
    //system("clear"); nie dziala
    do {
    cout << "Enter password" << endl;
    cin>>password;
    cout << "Repeat" << endl;
    cin>>password1;
    client->setPassword(password);
    if (password!=password1)
    cout << "Wrong password, try again" << endl;
    //system("clear"); nie dziala

    }while (password!=password1);

}
*/
/*void Bank::LogIn() {
using namespace std;
int ID;
string password;
cout << "Enter ID" << endl;
cin >> ID;
cout << "Enter password" << endl;
cin >> password;
for (int i=0; i<clients.size(); i++){
    if (ID== client.at(i)->getID()){
        cout << "Enter password" << endl;
        cin >> password;
        if (client.getPassword==password){
            cout << "Correct password" << endl;
            //system("clear") nie dziala
            }
    }
    else
        cout << "There is no client with this ID" << endl;
    }
}*/


