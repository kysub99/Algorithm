#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

int t, f;

unordered_map<string, string> root;
unordered_map<string, int> cnt;

string Find(string name) {
    if (name == root[name]) {
        return name;
    }
    return root[name] = Find(root[name]);
}

void Union(string name1, string name2) {
    string root1 = Find(name1);
    string root2 = Find(name2);

    if (root1 != root2) {
        root[root2] = root1;
        cnt[root1] += cnt[root2];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> f;
        root.clear();
        cnt.clear();

        for (int i = 0; i < f; i++) {
            string name1, name2;
            cin >> name1 >> name2;

            if (root.find(name1) == root.end()) {
                root[name1] = name1;
                cnt[name1] = 1;
            }
            if (root.find(name2) == root.end()) {
                root[name2] = name2;
                cnt[name2] = 1;
            }

            Union(name1, name2);
            cout << cnt[Find(name1)] << "\n";
        }
    }
    return 0;
}
