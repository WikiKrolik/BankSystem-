#include <string>
#include <memory>
#include <Client.h>

Client::Client(const std::__cxx11::basic_string<char> &clientPesel, const std::__cxx11::basic_string<char> &clientName,
               const std::__cxx11::basic_string<char> &clientSurname,
               const std::__cxx11::basic_string<char> &clientAddress, long clientPhone,
               const std::__cxx11::basic_string<char> &clientPassword) : clientPesel(clientPesel),
                                                                         clientName(clientName),
                                                                         clientSurname(clientSurname),
                                                                         clientAddress(clientAddress),
                                                                         clientPhone(clientPhone),
                                                                         clientPassword(clientPassword) {}

Client::~Client() {

}


void Client::addAccount(std::shared_ptr<Account> account) {
    accounts.push_back(std::move(account));
}

unsigned int Client::countAccounts(){
    return accounts.size();
}

const std::string &Client::getClientPesel() const {
    return clientPesel;
}

const std::string &Client::getClientName() const {
    return clientName;
}

const std::string &Client::getClientSurname() const {
    return clientSurname;
}


const std::string &Client::getClientAddress() const {
    return clientAddress;
}

long Client::getClientPhone() const {
    return clientPhone;
}

bool Client::validatePassword(std::string pesel, std::string password) {
    if(clientPesel == pesel){
        if(clientPassword == password)
            return true;
        else{
            return false;
        }
    }
}


