class Solution {
    public boolean hasDuplicate(int[] nums) {
        HashMap <Integer, Boolean> appearsOnce = new HashMap <>();
        for (int i = 0; i < nums.length; i++){
            if (appearsOnce.containsKey(nums[i])){
                if (appearsOnce.get(nums[i]) == true){
                    return true;
                }
            }
            else{
                appearsOnce.put(nums[i], true);
            }
        }
        return false;
    }
}