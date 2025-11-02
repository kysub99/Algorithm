import java.util.*;

class Solution {

    public String[] getMenu(String[] orders, int count) {
        Map<String, Integer> mp = new HashMap<>();
        for (int i = 0; i < orders.length; i++) {
            char[] arr = orders[i].toCharArray();
            Arrays.sort(arr);
            String sortedOrder = new String(arr);

            combination(mp, sortedOrder, "", 0, count);
        }

        int mostCount = -1;
        for (String key : mp.keySet()) {
            mostCount = Math.max(mp.get(key), mostCount);
        }

        List<String> candidates = new ArrayList<>();
        for (String key : mp.keySet()) {
            if (mp.get(key) == mostCount && mostCount > 1) {
                candidates.add(key);
            }
        }

        Collections.sort(candidates); 
        return candidates.toArray(new String[0]);
    }

    public void combination(Map<String, Integer> mp, String order, String candidate, int start, int count) {
        if (candidate.length() == count) {
            mp.put(candidate, mp.getOrDefault(candidate, 0) + 1);
            return;
        }

        for (int i = start; i < order.length(); i++) {
            combination(mp, order, candidate + order.charAt(i), i + 1, count);
        }
    }

    public String[] solution(String[] orders, int[] course) {
        List<String> answerList = new ArrayList<>();

        for (int count : course) {
            String[] menus = getMenu(orders, count);
            answerList.addAll(Arrays.asList(menus));
        }

        Collections.sort(answerList); 
        return answerList.toArray(new String[0]);
    }
}
