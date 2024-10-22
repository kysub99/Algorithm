#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq; 
    
    for(int sc : scoville){
        pq.push(sc);
    }
    
    while(pq.top() < K){
        int f = pq.top();
        pq.pop();
        if(pq.empty()){
            return -1;
        }
        int s = pq.top();
        pq.pop();
        
        int ns = f + s*2;
        pq.push(ns);
        
        answer++;
    }
    
    return answer;
}