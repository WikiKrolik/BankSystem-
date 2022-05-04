#include "Container.h"
#include <iostream>
Container::Container(int number){
    this->number=number;
    this->tareWeight=100;
    this->maxWeight=1000;
    this->strength=5000;
    this->cargo=0;
}

Container::Container() : Container(0) {}

double Container::getTareWeight() const {
    return tareWeight;
}

void Container::setTareWeight(double tareWeight) {
    tareWeight = tareWeight;
}

double Container::getMaxWeight() const {
    return maxWeight;
}

void Container::setMaxWeight(double maxWeight) {
    maxWeight = maxWeight;
}

double Container::getStrength() const {
    return strength;
}

void Container::setStrength(double strength) {
    strength = strength;
}

int Container::getNumber() const {
    return number;
}

void Container::loadCargo(double amount) {
    cargo+=amount;
    if(cargo>maxWeight-tareWeight)
    {
        cargo-=amount;
    }
}

void Container::unloadCargo(double amount) {
    cargo-=amount;
    if(cargo<0){
        cargo=0;
    }
}

double Container::getGrossWeight() {
    int x;
    x= tareWeight+cargo;
    return x;
}

double Container::getNetWeight() {
    return cargo;
}

double Container::getMaxCargo() {
    return maxWeight-tareWeight;
}

Container::~Container() {

}




