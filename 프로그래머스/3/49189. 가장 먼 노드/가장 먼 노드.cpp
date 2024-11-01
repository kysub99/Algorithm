#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 20001

using namespace std;

vector<bool> visit(MAX, false);
vector<int> depth(MAX, 0);
vector<vector<int>> graph(MAX);

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=0;i<edge.size();i++){
        int fn = edge[i][0];
        int sn = edge[i][1];
        
        graph[fn].push_back(sn);
        graph[sn].push_back(fn);
    }
    
    queue<int> q;
    q.push(1);
    visit[1]=true;
    int maxDepth = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            if(!visit[next]){
                visit[next] = true;
                depth[next] = depth[cur] + 1;
                maxDepth = max(maxDepth, depth[next]);
                q.push(next);
            }
        }
    }
    
    for(int d : depth){
        if(d==maxDepth)
            answer++;
    }
    
    
    return answer;
}