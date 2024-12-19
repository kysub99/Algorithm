#include <iostream>
#include <string>
using namespace std;

bool contains369(char digit) {
    return digit == '3' || digit == '6' || digit == '9';
}

string processNumber(int number) {
    string str = to_string(number);
    int count = 0;

    for (char digit : str) {
        if (contains369(digit)) {
            count++;
        }
    }

    if (count > 0) {
        return string(count, '-');
    }
    return str;
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cout << processNumber(i) << " ";
    }

    return 0;
}
