class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> m=new HashMap<>();
        int sum=0,rem=0;
        m.put(0,-1);
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            rem = sum%k;
            if(rem<0){
                rem+=k;
            }
            if(m.containsKey(sum%k)){
                int idx= m.get(rem);
                int len=i-idx;
                if(len>=2){
                return true;
                }
            }
            else{
            m.put(sum%k,i);
            }
        }
        return false;
    }
}