#include <vector>
#include "Container.h"
#ifndef OOPPROJECT_CONTAINERSTACK_H
#define OOPPROJECT_CONTAINERSTACK_H

using namespace std;

class ContainerStack{
private:
    vector<Container> containers;
    const unsigned MAX_HEIGHT = 10;
public:
    int getCapacity();
    int getSize();
    const Container& at(int height);
    void take(Container aContainer);
    Container give();
};
#endif //OOP