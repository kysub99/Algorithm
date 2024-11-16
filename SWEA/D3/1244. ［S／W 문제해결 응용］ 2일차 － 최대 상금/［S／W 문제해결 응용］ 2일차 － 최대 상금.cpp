#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int t;
string num;
int ch;
string res;
unordered_set<string> visited;

void bt(int d) {
    if (d == ch) { 
        res = max(res, num);
        return;
    }

    string state = num + to_string(d);
    if (visited.find(state) != visited.end()) {
        return;
    }
    visited.insert(state);


    for (int i = 0; i < num.size() - 1; i++) {
        for (int j = i + 1; j < num.size(); j++) {
            swap(num[i], num[j]); 
            bt(d + 1);         
            swap(num[i], num[j]); 
        }
    }
}

int main() {
    cin >> t; 
    for (int c = 1; c <= t; c++) {
        cin >> num >> ch; 
        res = "";         
        visited.clear();
        bt(0);           
        cout << "#" << c << " " << res << "\n";
    }
    return 0;
}
