#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> um;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(int i=0;i<clothes.size();i++){
        um[clothes[i][1]]++;
    }
    
    for(auto &it : um){
        answer *= (it.second+1);
    }
    
    return answer-1;
}