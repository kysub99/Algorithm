#include <iostream>
#include <stack>

using namespace std;

int n, h; 
stack<pair<int, int>> st; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    st.push({ 100000001,0 });
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> h;
        while (!st.empty()) {
            if (h < st.top().first) {
                cout << st.top().second << " ";
                break;
            }
            st.pop();
        }
        st.push({ h,i });
    }
    cout << "\n";
}