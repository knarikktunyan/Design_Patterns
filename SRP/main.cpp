#include <iostream>
using namespace std;

class ScoreCounter {
private:
    int score;

public:
    ScoreCounter() {
        score = 0;
    }

    void addPoints(int points) {
        score += points;
    }

    int getScore() {
        return score;
    }
};

int main() {
    ScoreCounter counter;

    counter.addPoints(10);
    counter.addPoints(20);

    cout << "Score: " << counter.getScore() << endl;

    return 0;
}

