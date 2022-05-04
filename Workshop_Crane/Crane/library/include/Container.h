#ifndef OOPPROJECT_CONTAINER_H
#define OOPPROJECT_CONTAINER_H
class Container {
private:
    int number;
    double tareWeight;
    double maxWeight;
    double strength;
    double cargo;

public:
    Container();
    ~Container();
    Container(int number);

    int getNumber() const;



    double getTareWeight() const;

    void setTareWeight(double tareWeight);

    double getMaxWeight() const;

    void setMaxWeight(double maxWeight);

    double getStrength() const;

    void setStrength(double strength);

    double getGrossWeight();

    double getNetWeight();

    double getMaxCargo();

    void loadCargo(double amount);

    void unloadCargo(double amount);

};
#endif //OOP