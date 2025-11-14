#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> pr, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for(int i=0;i<pr.size();i++){
        q.push({pr[i], i});
        pq.push(pr[i]);
    }
    
    int cnt=0;
    while(!q.empty() || !pq.empty()){
        int prVal = q.front().first;
        int prLoc = q.front().second;
        q.pop();
        if(prVal == pq.top()){
            cnt++;
            if(prLoc == location){
                break;
            }
            pq.pop();   
        }
        else{
            q.push({prVal, prLoc});
        }
    }
    answer = cnt;
    return answer;
}