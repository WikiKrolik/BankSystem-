//
// Created by student on 1/21/22.
//

#ifndef FINALPROJECT_ADDRESS_H
#define FINALPROJECT_ADDRESS_H

#include <string>

class Address {
private:
    std::string Street{""};
    std::string StreetNumber{""};
    std::string ApartmentNumber{""};
    std::string City{""};

public:

    Address(const std::string &street, const std::string &streetNumber, const std::string &apartmentNumber,
            const std::string &city);

    void setStreet(const std::string &street);

    void setStreetNumber(const std::string &streetNumber);

    void setApartmentNumber(const std::string &apartmentNumber);

    void setCity(const std::string &city);

    const std::string &getStreet() const;

    const std::string &getStreetNumber() const;

    const std::string &getApartmentNumber() const;

    const std::string &getCity() const;
};


#endif //FINALPROJECT_ADDRESS_H
