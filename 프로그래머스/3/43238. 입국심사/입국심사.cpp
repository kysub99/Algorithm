#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    // 1. minT를 `times` 배열의 첫 번째 요소로 초기화
    int minT = times[0];
    for(int t : times){
        minT = min(minT, t);
    }

    long long l = minT;  // 최소 시간을 minT로 설정
    long long r = (long long)minT * n;
    
    while(l <= r){
        long long mid = (l + r) / 2;
        
        long long sum = 0;
        for(int t : times){
            sum += mid / t;
        }
        
        if(sum < n){
            l = mid + 1;
        } else {
            answer = mid;  // 가능한 시간을 업데이트
            r = mid - 1;        
        }
    }
    
    return answer;
}
