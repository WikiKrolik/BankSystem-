
#include "Container.h"
#include "ContainerStack.h"
#include <iostream>
#ifndef LIBRARY_CRANE_H
#define LIBRARY_CRANE_H

class Crane{
private:
    const unsigned MAX_STACKS = 5;
    ContainerStack CraneStorage[5];
    int position=-1;
    Container container;
public:
     bool IsParked();
    bool IsLoaded();
    bool IsUnloaded();
    bool IsWaitingEmpty();
    bool IsWaitingFull();
    void park();
    void load(Container container);
    Container unload();
    void forward(int NumSteps);
    void backwards(int NumSteps);
    void PickUp();
    void PutDown();
    int GetPosition();
    Container& GetContainer();
    ContainerStack& StackAt( int position);
    bool CanPutDown();


};
#endif //LIBRARY_CRANE_H
