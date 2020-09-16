class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            ArrayList<Character> list = new ArrayList<>();
            for (int j = i; j < s.length(); j++) {
                char charAt = s.charAt(j);
                if (list.contains(charAt)) {
                    break;
                } else {
                    list.add(charAt);
                }
            }
            if (max < list.size())
                max = list.size();
        }
        return max;
    }
}