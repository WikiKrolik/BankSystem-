#include "Crane.h"
#include <Container.h>
#include <ContainerStack.h>
#include <iostream>


const unsigned MAX_STACKS = 5;

bool Crane:: IsParked(){
    if(position==-1)
        return true;
    else
        return false;
}

bool Crane::IsLoaded() {
    if (position == -2 && container.getNumber() != 0)
        return true;
    else if (position == -2 && container.getNumber() == 0)
        return false;
}

bool Crane::IsUnloaded() {
    if (position == -2 && container.getNumber() == 0)
        return true;
    else if (position == -2 && container.getNumber() != 0)
        return false;
}

bool Crane::IsWaitingEmpty() {
    if(0<=position<=MAX_STACKS && container.getNumber() == 0)
        return true;
    else
        return false;
}

bool Crane::IsWaitingFull() {
    if(0<=position<=MAX_STACKS && container.getNumber() != 0)
        return true;
    else
        return false;
}

void Crane::park(){
    if ( IsUnloaded()==true || IsWaitingEmpty()==true)
        position=-1;
    else
        std::cout<<"Can't park loaded crane" <<std::endl;
}
void Crane::load(Container container){

    if(IsUnloaded()==1) {
        container = container;
    }
    else
        throw std::out_of_range("Crane not in position to unload");

}

Container Crane::unload() {
    if(IsLoaded()==1) {
        Container a;
        container = a;
        cout << container.getNumber() << endl;
    }
    else
        throw std::out_of_range("Too much cargo");
}

void Crane::forward(int NumSteps) {
    if(NumSteps+position>::MAX_STACKS-1)
        cout << "Can't move";
    else
        position=position+NumSteps;
}

void Crane::backwards(int NumSteps) {
    if(NumSteps-position<-2)
        cout << "Can't move";
    else
        position=position-NumSteps;
}
void Crane::PickUp() {
    if (StackAt(position).getSize()>=1 && IsWaitingEmpty() == true)
    {
        container = StackAt(position).at(StackAt(position).getSize()-1);
        cout<<"Pick up: "<<container.getNumber()<<endl;
        StackAt(position).give();
    }
}

void Crane::PutDown() {
    if(CanPutDown()==1)
    {StackAt(position).take(container);
        Container a;
        container = a;}
    else
        cout <<"Crane not in position to unload";
}

Container &Crane::GetContainer() {
   return container;
}

ContainerStack& Crane::StackAt(int position) {
    return CraneStorage[position];
}

bool Crane::CanPutDown() {
    if (StackAt(position).getSize()< StackAt(position).getCapacity() && 0 <= position <=5 )
        return true;
    else
        return false;
}
