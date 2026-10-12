#include <iostream>
using namespace std;

class Car {
public:
    virtual void drive() {
        cout << "Car is driving" << endl;
    }

    virtual ~Car() = default;
};

class Tesla : public Car {
public:
    void drive() override {
        cout << "Tesla is driving" << endl;
    }
};

void startDriving(Car& car) {
    car.drive();
}

int main() {
    Car car;
    Tesla tesla;

    startDriving(car);
    startDriving(tesla);

    return 0;
}

