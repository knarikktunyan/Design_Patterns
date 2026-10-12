#include <iostream>
using namespace std;

class Car {
public:
    virtual void brake() {
        cout << "Car is braking" << endl;
    }

    virtual ~Car() = default;
};

class CarWithBrakeLights : public Car {
public:
    void brake() override {
        Car::brake();
        cout << "Brake lights are on" << endl;
    }
};

int main() {
    CarWithBrakeLights car;
    car.brake();

    return 0;
}

