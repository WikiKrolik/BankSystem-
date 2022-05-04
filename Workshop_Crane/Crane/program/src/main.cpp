#include "Container.h"
#include <iostream>

using namespace std;

void display(Container c){
    cout<<c.getNumber()<<"\n";
    cout<<c.getMaxWeight()<<"\n";
    cout<<c.getStrength()<<"\n";
    cout<<c.getTareWeight()<<"\n";
    cout<<c.getMaxCargo()<<"\n";
    cout<<c.getNetWeight()<<"\n";
    cout<<c.getGrossWeight()<<"\n";
}

void testLocalObject(){
    auto x=Container(20);
    x.setMaxWeight(2000);
    x.setStrength(6000);
    x.setTareWeight(200);
    cout<<x.getTareWeight()<<"\n";
    cout<<x.getStrength()<<"\n";
    cout<<x.getMaxWeight()<<"\n";
    cout<<x.getNumber()<<"\n";
    cout<<x.getGrossWeight()<<"\n";
    cout<<x.getMaxCargo()<<"\n";
    cout<<x.getNetWeight()<<"\n";
}

void displayCargo(Container& c){
    cout<<c.getNetWeight()<<"\n";
}

void loadAndSend(Container& c, double goods) {
    double x;
    displayCargo(c);
    cout<<"Insert weight of cargo that you want to load: ";
    cin>>x;
    cout<<"\n";
    c.loadCargo(x);
    displayCargo(c);
}

Container* prepare(int number, double goods){
    Container* k = new Container(number);
    k->loadCargo(goods);
    return k;
}

void display(Container* k){
    cout<<k->getNumber();
    cout<<k->getNetWeight();
    cout<<k->getGrossWeight();
    cout<<k->getMaxCargo();
    cout<<k->getMaxWeight();
    cout<<k->getStrength();
    cout<<k->getTareWeight();
}

void testDynamicObject(){
    Container* k=prepare(21, 600);
    display(k);
    delete k;
}

int main(){
    Container k0 = Container();
    display(k0);

    Container k1 = Container(1);
    display(k1);
    cout<<"\n";
    display(&k1);

    Container *k2 = prepare(2, 600);
    display(k2);
    delete k2;

    loadAndSend(k1,700);

    testLocalObject();

    testDynamicObject();



}



