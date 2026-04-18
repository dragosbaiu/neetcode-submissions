class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap <Integer, Integer> complements = new HashMap <>();
        for (int i = 0; i < nums.length; i++){
            int diff = target - nums[i];
            if (complements.containsKey(diff)){
                return new int [] {complements.get(diff), i};
            }
            complements.put(nums[i], i);
        }
        return new int [] {};
    }
}
