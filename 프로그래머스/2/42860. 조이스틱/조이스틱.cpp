#include <bits/stdc++.h>

using namespace std;

#define ALP 26

int solution(string name) {
    int answer = 0;
    
    for(int i=0;i<name.size();i++){
        int dif = name[i] - 'A';
        answer += min(dif, ALP-dif);
    }   
    
    int move = name.size()-1;
    for(int i=0;i<name.size();i++){
        int next = i+1;
        while(next < name.size() && name[next]=='A'){
            next++;
        }
        int a = i*2 + (name.size() - next);
        int b = i + 2*(name.size() - next);
        move = min(move, min(a, b));
    }
    answer += move;
    
    return answer;
}