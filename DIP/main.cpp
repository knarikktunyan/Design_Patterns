#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sharing {
public:
    virtual void share(const string& message) = 0;
    virtual ~Sharing() = default;
};

class FacebookSharing : public Sharing {
public:
    void share(const string& message) override {
        cout << "Sharing on Facebook: " << message << endl;
    }
};

class TelegramSharing : public Sharing {
public:
    void share(const string& message) override {
        cout << "Sharing on Telegram: " << message << endl;
    }
};

class LinkedInSharing : public Sharing {
public:
    void share(const string& message) override {
        cout << "Sharing on LinkedIn: " << message << endl;
    }
};

class Publisher {
private:
    vector<Sharing*> platforms;

public:
    void addPlatform(Sharing* platform) {
        platforms.push_back(platform);
    }

    void publish(const string& message) {
        for (Sharing* platform : platforms) {
            platform->share(message);
        }
    }
};

int main() {
    FacebookSharing facebook;
    TelegramSharing telegram;
    LinkedInSharing linkedin;

    Publisher publisher;

    publisher.addPlatform(&facebook);
    publisher.addPlatform(&telegram);
    publisher.addPlatform(&linkedin);

    string blogPost = "My new post";

    publisher.publish(blogPost);

    return 0;
}

