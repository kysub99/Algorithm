#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	
	while (1) {
		stack<char> st;
		getline(cin , str);
		if (str == ".")
			break;
		bool c = true;
		for (int i = 0;i < str.size();i++) {
			if (str[i] == '(')
				st.push('(');
			else if (str[i] == ')') {
				if (st.empty()||st.top()!='(') {
					c = false;
					break;
				}
				st.pop();
			}
			else if (str[i] == '[')
				st.push('[');
			else if (str[i] == ']') {
				if (st.empty() || st.top() != '[') {
					c = false;
					break;
				}
				st.pop();
			}
		}
		if (!st.empty())
			c = false;
		if (c)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}