#include <string>
#include <vector>
#define MAX 101

using namespace std;

vector<vector<bool>> dist(MAX, vector<bool>(MAX, false));

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i=0;i<results.size();i++){
        int win = results[i][0];
        int lose = results[i][1];
        dist[win][lose] = true;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k] && dist[k][j]){
                    dist[i][j] = true;
                }            
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(dist[i][j] || dist[j][i])
                cnt++;
        }
        if(cnt == n-1)
            answer++;
    }
    
    return answer;
}