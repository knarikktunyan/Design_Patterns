#include <iostream>
#include <memory>
#include <string>

class Transport {
public:
    virtual ~Transport() = default;
    virtual void deliver() const = 0;
};

class Truck : public Transport {
public:
    void deliver() const override {
        std::cout << "Delivering cargo by road using a truck.\n";
    }
};

class Ship : public Transport {
public:
    void deliver() const override {
        std::cout << "Delivering cargo by sea using a ship.\n";
    }
};

class Airplane : public Transport {
public:
    void deliver() const override {
        std::cout << "Delivering cargo by air using an airplane.\n";
    }
};

class Logistics {
public:
    virtual ~Logistics() = default;

    void planDelivery() const {
        std::unique_ptr<Transport> transport = createTransport();
        std::cout << "Preparing delivery...\n";
        transport->deliver();
    }

protected:
    virtual std::unique_ptr<Transport> createTransport() const = 0;
};

class RoadLogistics : public Logistics {
protected:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Truck>();
    }
};

class SeaLogistics : public Logistics {
protected:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Ship>();
    }
};

class AirLogistics : public Logistics {
protected:
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Airplane>();
    }
};

int main() {
    RoadLogistics road;
    SeaLogistics sea;
    AirLogistics air;

    std::cout << "Road delivery:\n";
    road.planDelivery();

    std::cout << "\nSea delivery:\n";
    sea.planDelivery();

    std::cout << "\nAir delivery (new delivery method):\n";
    air.planDelivery();

    return 0;
}
