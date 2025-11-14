#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> c) {
    int answer = 0;
    
    sort(c.begin(), c.end(), greater<>());
    for(int i=0;i<c.size();i++){
        if(c[i] >= i+1){
            answer = i+1;
        }
    }
    
    return answer;
}