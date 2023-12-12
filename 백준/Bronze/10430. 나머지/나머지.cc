#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int result1 = (A + B) % C;
    int result2 = ((A % C) + (B % C)) % C;
    int result3 = (A * B) % C;
    int result4 = ((A % C) * (B % C)) % C;

    cout << result1 << endl << result2 << endl << result3 << endl << result4 << endl;

    return 0;
}
