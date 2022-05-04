//
// Created by student on 1/21/22.
//

#include "model/Address.h"

Address::Address(const std::string &street, const std::string &streetNumber, const std::string &apartmentNumber,
                 const std::string &city) : Street(street), StreetNumber(streetNumber),
                                            ApartmentNumber(apartmentNumber), City(city) {}

void Address::setStreet(const std::string &street) {
    Street = street;
}

void Address::setStreetNumber(const std::string &streetNumber) {
    StreetNumber = streetNumber;
}

void Address::setApartmentNumber(const std::string &apartmentNumber) {
    ApartmentNumber = apartmentNumber;
}

void Address::setCity(const std::string &city) {
    City = city;
}

const std::string &Address::getStreet() const {
    return Street;
}

const std::string &Address::getStreetNumber() const {
    return StreetNumber;
}

const std::string &Address::getApartmentNumber() const {
    return ApartmentNumber;
}

const std::string &Address::getCity() const {
    return City;
}

