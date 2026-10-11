#include <iostream>
#include <map>
#include <string>

class ConfigurationManager {
private:
    std::map<std::string, std::string> settings;

    ConfigurationManager() {
        settings["theme"] = "light";
        settings["language"] = "English";
    }

public:
    ConfigurationManager(const ConfigurationManager&) = delete;
    ConfigurationManager& operator=(const ConfigurationManager&) = delete;

    static ConfigurationManager& instance() {
        static ConfigurationManager manager;
        return manager;
    }

    void set(const std::string& key, const std::string& value) {
        settings[key] = value;
    }

    std::string get(const std::string& key) const {
        auto it = settings.find(key);
        if (it == settings.end())
            return "(not set)";
        return it->second;
    }

    void showAll() const {
        for (const auto& setting : settings)
            std::cout << setting.first << " = " << setting.second << "\n";
    }
};

int main() {
    ConfigurationManager& firstModule = ConfigurationManager::instance();
    ConfigurationManager& secondModule = ConfigurationManager::instance();

    firstModule.set("theme", "dark");
    firstModule.set("language", "Armenian");

    std::cout << "Settings read by the second module:\n";
    std::cout << "Theme: " << secondModule.get("theme") << "\n";
    std::cout << "Language: " << secondModule.get("language") << "\n";

    std::cout << "\nAre both references the same instance? "
              << (&firstModule == &secondModule ? "Yes" : "No") << "\n";

    std::cout << "\nAll settings:\n";
    secondModule.showAll();

    return 0;
}
