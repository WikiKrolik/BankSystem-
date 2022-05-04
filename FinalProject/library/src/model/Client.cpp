//
// Created by student on 1/16/22.
//

#include "model/Client.h"
#include <algorithm>
#include <iostream>


std::shared_ptr<Address> Client::getAddress() const {
    return std::shared_ptr<Address>();
}

void Client::setAddress(const std::shared_ptr<Address> &address) {
    C_address = std::move(address);
}

int Client::setPassword(std::string password) {
   Password=password;
}

int Client::getID() {
    return ClientID;
}

std::string Client::setName(std::string fname) {
    Name=fname;
}

std::string Client::setSurname(std::string sn) {
    return Surname=sn;
}



std::string Client::setPhone(std::string p) {
    Phone=p;
}

const std::string &Client::getName() {
    return Name;
}

const std::string &Client::getSurname() {
    return Surname;
}


const std::string &Client::getPhone() {
    return Phone;
}

const std::string &Client::getPassword() const {
    return Password;
}



    void Client::addAccount( std::shared_ptr<Account> account) {
        {
            accounts.push_back(account);
        }
    }
    void Client::removeAccount(std::shared_ptr<Account> account) {
        {
            accounts.erase(std::remove(accounts.begin(), accounts.end(), account), accounts.end());
        }
    }

Client::Client(int clientId, const std::string &name, const std::string &surname, const std::string &phone) : ClientID(
        clientId), Name(name), Surname(surname), Phone(phone) {}
