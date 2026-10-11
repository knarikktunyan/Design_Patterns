#include <iostream>
#include <string>
#include <vector>
#include <limits>

class Burger {
public:
    std::string bun;
    std::string patty;
    std::string sauce;
    std::vector<std::string> toppings;

    void show() const {
        std::cout << "\nYour burger\n"
                  << "Bun: " << bun << "\n"
                  << "Patty: " << patty << "\n"
                  << "Sauce: " << (sauce.empty() ? "None" : sauce) << "\n"
                  << "Toppings: ";
        if (toppings.empty()) {
            std::cout << "None";
        } else {
            for (std::size_t i = 0; i < toppings.size(); ++i) {
                if (i > 0) std::cout << ", ";
                std::cout << toppings[i];
            }
        }
        std::cout << "\n";
    }
};

class BurgerBuilder {
private:
    Burger burger;
public:
    BurgerBuilder& setBun(const std::string& value) {
        burger.bun = value;
        return *this;
    }
    BurgerBuilder& setPatty(const std::string& value) {
        burger.patty = value;
        return *this;
    }
    BurgerBuilder& setSauce(const std::string& value) {
        burger.sauce = value;
        return *this;
    }
    BurgerBuilder& addTopping(const std::string& value) {
        burger.toppings.push_back(value);
        return *this;
    }
    Burger build() const {
        if (burger.bun.empty() || burger.patty.empty()) {
            throw std::runtime_error("A burger must have both a bun and a patty.");
        }
        return burger;
    }
};

int choose(const std::string& prompt, const std::vector<std::string>& options) {
    int choice;
    while (true) {
        std::cout << prompt << "\n";
        for (std::size_t i = 0; i < options.size(); ++i)
            std::cout << i + 1 << ". " << options[i] << "\n";
        std::cout << "Choose: ";
        if (std::cin >> choice && choice >= 1 &&
            choice <= static_cast<int>(options.size())) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice - 1;
        }
        std::cout << "Invalid choice. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    const std::vector<std::string> buns = {"Sesame", "Brioche", "Whole wheat"};
    const std::vector<std::string> patties = {"Beef", "Chicken", "Veggie"};
    const std::vector<std::string> sauces = {"No sauce", "Ketchup", "Mayonnaise", "BBQ"};
    const std::vector<std::string> toppings = {"Lettuce", "Tomato", "Cheese", "Pickles", "Onion"};

    std::cout << "Burger Builder\n";
    BurgerBuilder builder;
    builder.setBun(buns[choose("Choose a bun:", buns)])
           .setPatty(patties[choose("Choose a patty:", patties)]);

    int sauceChoice = choose("Choose a sauce:", sauces);
    if (sauceChoice != 0) builder.setSauce(sauces[sauceChoice]);

    std::cout << "Choose toppings (enter 1-" << toppings.size()
              << ", or 0 to finish):\n";
    for (std::size_t i = 0; i < toppings.size(); ++i)
        std::cout << i + 1 << ". " << toppings[i] << "\n";

    while (true) {
        int choice;
        std::cout << "Topping: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number.\n";
            continue;
        }
        if (choice == 0) break;
        if (choice >= 1 && choice <= static_cast<int>(toppings.size()))
            builder.addTopping(toppings[choice - 1]);
        else
            std::cout << "Invalid topping number.\n";
    }

    try {
        builder.build().show();
    } catch (const std::exception& error) {
        std::cout << "Could not build burger: " << error.what() << "\n";
        return 1;
    }
    return 0;
}
