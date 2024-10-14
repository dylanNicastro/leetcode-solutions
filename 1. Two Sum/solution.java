import java.util.HashMap;
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int num = 0; num < nums.length; num++) {
            Integer returnValue = map.get(target - nums[num]);
            if (returnValue == null) {
                map.put(nums[num], num);
            }
            else {
                return new int[]{num, (int)(returnValue)};
            }
        }
        return null;
    }
}