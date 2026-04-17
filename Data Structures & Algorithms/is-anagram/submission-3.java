class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length()!=t.length()){
            return false;
        }
        HashMap<Character, Integer> sSet = new HashMap<>();
        HashMap<Character, Integer> tSet = new HashMap<>();
        for (int i = 0; i< s.length(); i++){
            if (sSet.containsKey(s.charAt(i))){
                sSet.put(s.charAt(i), (sSet.get(s.charAt(i)) + 1));
            }
            else{
                sSet.put(s.charAt(i), 1);
            }
            if (tSet.containsKey(t.charAt(i))){
                tSet.put(t.charAt(i), (tSet.get(t.charAt(i)) + 1));
            }
            else{
                tSet.put(t.charAt(i), 1);
            }
        }
        return sSet.equals(tSet);
    }
}
