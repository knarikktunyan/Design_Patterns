#include <iostream>
#include <memory>
#include <string>

class Chair {
public:
    virtual ~Chair() = default;
    virtual std::string description() const = 0;
};

class Sofa {
public:
    virtual ~Sofa() = default;
    virtual std::string description() const = 0;
};

class CoffeeTable {
public:
    virtual ~CoffeeTable() = default;
    virtual std::string description() const = 0;
};

class ModernChair : public Chair {
public:
    std::string description() const override { return "Modern chair"; }
};
class ModernSofa : public Sofa {
public:
    std::string description() const override { return "Modern sofa"; }
};
class ModernCoffeeTable : public CoffeeTable {
public:
    std::string description() const override { return "Modern coffee table"; }
};

class VictorianChair : public Chair {
public:
    std::string description() const override { return "Victorian chair"; }
};
class VictorianSofa : public Sofa {
public:
    std::string description() const override { return "Victorian sofa"; }
};
class VictorianCoffeeTable : public CoffeeTable {
public:
    std::string description() const override { return "Victorian coffee table"; }
};

class ArtDecoChair : public Chair {
public:
    std::string description() const override { return "Art Deco chair"; }
};
class ArtDecoSofa : public Sofa {
public:
    std::string description() const override { return "Art Deco sofa"; }
};
class ArtDecoCoffeeTable : public CoffeeTable {
public:
    std::string description() const override { return "Art Deco coffee table"; }
};

class FurnitureFactory {
public:
    virtual ~FurnitureFactory() = default;
    virtual std::unique_ptr<Chair> createChair() const = 0;
    virtual std::unique_ptr<Sofa> createSofa() const = 0;
    virtual std::unique_ptr<CoffeeTable> createCoffeeTable() const = 0;
};

class ModernFactory : public FurnitureFactory {
public:
    std::unique_ptr<Chair> createChair() const override {
        return std::make_unique<ModernChair>();
    }
    std::unique_ptr<Sofa> createSofa() const override {
        return std::make_unique<ModernSofa>();
    }
    std::unique_ptr<CoffeeTable> createCoffeeTable() const override {
        return std::make_unique<ModernCoffeeTable>();
    }
};

class VictorianFactory : public FurnitureFactory {
public:
    std::unique_ptr<Chair> createChair() const override {
        return std::make_unique<VictorianChair>();
    }
    std::unique_ptr<Sofa> createSofa() const override {
        return std::make_unique<VictorianSofa>();
    }
    std::unique_ptr<CoffeeTable> createCoffeeTable() const override {
        return std::make_unique<VictorianCoffeeTable>();
    }
};

class ArtDecoFactory : public FurnitureFactory {
public:
    std::unique_ptr<Chair> createChair() const override {
        return std::make_unique<ArtDecoChair>();
    }
    std::unique_ptr<Sofa> createSofa() const override {
        return std::make_unique<ArtDecoSofa>();
    }
    std::unique_ptr<CoffeeTable> createCoffeeTable() const override {
        return std::make_unique<ArtDecoCoffeeTable>();
    }
};

void showFurniture(const FurnitureFactory& factory) {
    auto chair = factory.createChair();
    auto sofa = factory.createSofa();
    auto table = factory.createCoffeeTable();

    std::cout << chair->description() << "\n"
              << sofa->description() << "\n"
              << table->description() << "\n";
}

int main() {
    std::cout << "Modern collection:\n";
    ModernFactory modern;
    showFurniture(modern);

    std::cout << "\nVictorian collection:\n";
    VictorianFactory victorian;
    showFurniture(victorian);

    std::cout << "\nArt Deco collection:\n";
    ArtDecoFactory artDeco;
    showFurniture(artDeco);

    return 0;
}
