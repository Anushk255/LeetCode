class Solution {
    private List<int[]> bitts;
    private int answer(int[] nums, int idx, int k) {
        int left = idx, right = nums.length - 1, ans = Integer.MAX_VALUE;

        while (left <= right) {
            int mid = (left + right) / 2;
            int a = 0;
            for (int i = 0; i < 32; i++) {
                int b = bitts.get(mid + 1)[i] - bitts.get(idx)[i];
                if (b > 0) {
                    a |= (1 << i);
                }
            }
            
            if (a >= k) {
                ans = Math.min(ans, mid - idx + 1);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
    public int minimumSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        int ans = Integer.MAX_VALUE;
        bitts = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            bitts.add(new int[32]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                bitts.get(i + 1)[j] = bitts.get(i)[j] + ((nums[i] >> j) & 1);
            }
        }
        for (int i = 0; i < n; i++) {
            int temp = answer(nums, i, k);
            if (temp != Integer.MAX_VALUE) {
                ans = Math.min(ans, temp);
            } else {
                break;
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
        
    }
}