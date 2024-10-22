#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    set<int> st;
    for(int num : nums){
        st.insert(num);
    }
    
    answer = min(nums.size()/2, st.size());
    
    return answer;
}