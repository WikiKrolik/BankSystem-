#include "ContainerStack.h"
#include <iostream>

int ContainerStack::getCapacity() {
    return MAX_HEIGHT;
}

int ContainerStack::getSize() {
    return  containers.size();
}

const Container &ContainerStack::at(int height) {
        if(height<= getSize())
    return containers.at(height);
        else
            cout << "There aren't that many containers on the stack";
}

void ContainerStack::take(Container aContainer) {
    containers.push_back(aContainer);
}

Container ContainerStack::give() {
    containers.pop_back();
}

