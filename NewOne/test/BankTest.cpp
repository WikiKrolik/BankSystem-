#include <boost/test/unit_test.hpp>
#include "Bank.h"
#include "Account.h"
#include "Loan.h"
#include "NormalAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "Transfer.h"

BOOST_AUTO_TEST_SUITE(BankTests)

    BOOST_AUTO_TEST_CASE(BankConstructorTest)
    {
        Bank bank1(1, "MBank", 15000, "Warsaw");
        BOOST_TEST(bank1.getBankId()==1);
        BOOST_TEST(bank1.getBankName()=="MBank");
        BOOST_TEST(bank1.getBankFunds()==15000);
        BOOST_TEST(bank1.getBankLocation()=="Warsaw");
    }

    BOOST_AUTO_TEST_CASE(BankEmptyTest)
    {
        Bank bank1(1, "MBank", 15000, "Warsaw");
        BOOST_TEST(bank1.countClients()==0);
    }

    BOOST_AUTO_TEST_CASE(BankWithClientTest)
    {
        Bank bank1(1, "MBank", 15000, "Warsaw");
        Client client1("01234", "Jan", "Kowalski", "Targowa 25/27", 890690901, "OOP21");
        std::shared_ptr<Client> clients;
        BOOST_TEST(client1.getClientPesel()=="01234");
        bank1.addClient(clients);
        BOOST_TEST(bank1.countClients()==1);
    }

    BOOST_AUTO_TEST_CASE(BankClientRemoveTest)
    {
        Bank bank1(1, "MBank", 15000, "Warsaw");
        std::shared_ptr<Client> client = std::make_shared<Client>("01234054589", "Jan", "Kowalski", "Targowa 25/27", 890690901, "OOP21");
        bank1.addClient(client);
        std::string p = "01234054589";
        bank1.removeClient([&](Client c){return c.getClientPesel() == p;});
        BOOST_TEST(bank1.countClients()==0);
    }

    BOOST_AUTO_TEST_CASE(BankClientRegisterTest)
    {
        Bank bank1(1, "MBank", 15000, "Warsaw");
        std::string pesel = "1234";
        std::string name = "Janek";
        std::string surname = "Kowalczyk";
        std::string address = "Strykow Warszawska 150/12";
        long int phone = 123456789;
        std::string password = "2137";
        bank1.addClient(bank1.createClient(pesel, name, surname, address, phone, password));
        BOOST_TEST(bank1.countClients()==1);
    }
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(AccountsTest)

    BOOST_AUTO_TEST_CASE(BankClientAccount){
        Bank bank1(1, "MBank", 15000, "Warsaw");
        std::string pesel = "1234";
        std::string name = "Janek";
        std::string surname = "Kowalczyk";
        std::string address = "Strykow Warszawska 150/12";
        long int phone = 123456789;
        std::string password = "2137";
        int pin = 1234;
        double balance = 900;
        std::string accountNumber = "33333333";
        auto client = bank1.createClient(pesel, name, surname, address, phone, password);
        auto NormalAccount = bank1.createNormalAccount(pin, balance, pesel, accountNumber );
        client->addAccount(NormalAccount);
        BOOST_CHECK_EQUAL(client->countAccounts(), 1);
        BOOST_CHECK_EQUAL(NormalAccount->getBalance(), 900);
    }

    BOOST_AUTO_TEST_CASE(TransferTest){
        Bank bank1(1, "MBank", 15000, "Warsaw");
        std::shared_ptr<Client> client1 = std::make_shared<Client>("01234", "Jan", "Kowalski", "Targowa 25/27", 890690901, "OOP21");
        bank1.addClient(client1);
        std::shared_ptr<Client> client2 = std::make_shared<Client>("43210", "Jakub", "Kowalczyk", "Warszawska 51/29", 502790851, "21OOP");
        bank1.addClient(client2);
        auto NormalAccount = bank1.createNormalAccount(1111,10000,"01234", "33333");
        auto CreditAccount = bank1.createCreditAccount(1111,10000,"01234", "22222", 1000, 0.05);
        client1->addAccount(NormalAccount);
        client2->addAccount(CreditAccount);
        std::string destination;
        std::string source;
        source = NormalAccount->getAccountNumber();
        destination = CreditAccount->getAccountNumber();
        Transfer transfer(source, destination, 500);
        transfer.makeTransfer(*NormalAccount, *CreditAccount);
        BOOST_CHECK_EQUAL(NormalAccount->getBalance(),9500);
        BOOST_CHECK_EQUAL(CreditAccount->getBalance(), 10500);

}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(LoanTest)

    BOOST_AUTO_TEST_CASE(BankClientLoan){
        Bank bank1(1, "MBank", 15000, "Warsaw");
        std::string pesel = "1234";
        std::string name = "Janek";
        std::string surname = "Kowalczyk";
        std::string address = "Strykow Warszawska 150/12";
        long int phone = 123456789;
        std::string password = "2137";
        int pin = 1234;
        double balance = 900;
        std::string accountNumber = "33333333";
        auto client = bank1.createClient(pesel, name, surname, address, phone, password);
        auto NormalAccount = bank1.createNormalAccount(pin, balance, pesel, accountNumber );
        client->addAccount(NormalAccount);
        auto loan = std::make_shared<Loan>(pesel, 20);
        bank1.giveLoan(20, loan, NormalAccount, 20, 1, 2023, "idk");
        BOOST_CHECK_EQUAL(NormalAccount->getBalance(), 920);
        BOOST_CHECK_EQUAL(bank1.getBankFunds(), 14980);

    }

BOOST_AUTO_TEST_SUITE_END()