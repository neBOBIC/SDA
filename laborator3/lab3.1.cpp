#include <iostream>
using namespace std;

int numberOfSteps(int num) {
    int steps = 0;

    while (num > 0) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = num - 1;
        }

        steps++;
    }

    return steps;
}

int main() {
    int num = 14;

    cout << numberOfSteps(num);

    return 0;
}