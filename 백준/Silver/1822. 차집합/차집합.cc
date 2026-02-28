#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;
    vector<int> aarr(a);
    for (int i = 0; i < a; i++)
    {
        cin >> aarr[i];
    }

    set<int> st;
    for (int i = 0; i < b; i++)
    {
        int num;
        cin >> num;
        st.insert(num);
    }

    vector<int> res;
    for (int i = 0; i < a; i++)
    {
        if (st.find(aarr[i]) == st.end())
        {
            res.push_back(aarr[i]);
        }
    }

    cout << res.size() << "\n";
    sort(res.begin(), res.end());
    for (int num : res)
    {
        cout << num << " ";
    }
}