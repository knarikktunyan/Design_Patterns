#include <iostream>
using namespace std;

class BreadBaker {
public:
    virtual void bakeBread() = 0;
    virtual ~BreadBaker() = default;
};

class CookieMaker {
public:
    virtual void makeCookies() = 0;
    virtual ~CookieMaker() = default;
};

class CakeDecorator {
public:
    virtual void decorateCake() = 0;
    virtual ~CakeDecorator() = default;
};

class Baker : public BreadBaker, public CookieMaker {
public:
    void bakeBread() override {
        cout << "Baking bread" << endl;
    }

    void makeCookies() override {
        cout << "Making cookies" << endl;
    }
};

class CakeSpecialist : public CakeDecorator {
public:
    void decorateCake() override {
        cout << "Decorating a cake" << endl;
    }
};

int main() {
    Baker baker;
    CakeSpecialist specialist;

    baker.bakeBread();
    baker.makeCookies();
    specialist.decorateCake();

    return 0;
}
