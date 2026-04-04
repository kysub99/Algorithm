import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        
        for(String op : operations){
            String[] s = op.split(" ");
            String cmd = s[0];
            int num = Integer.parseInt(s[1]);
            
            if(cmd.equals("I")){
                mp.put(num, mp.getOrDefault(num, 0) + 1);
            }
            else{
                if(mp.isEmpty()){
                    continue;
                }
                int target = (num == 1) ? mp.lastKey() : mp.firstKey();
                
                if(mp.get(target)==1){
                    mp.remove(target);
                }
                else{
                    mp.put(target, mp.get(target) - 1);
                }
            }
        }
        if(mp.isEmpty()){
            return new int[]{0,0};
        }
        return new int[]{mp.lastKey(), mp.firstKey()};
    }
}