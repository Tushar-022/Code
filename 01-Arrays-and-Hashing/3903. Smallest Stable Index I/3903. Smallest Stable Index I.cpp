 class Solution {
  public int firstStableIndex(int[] nums, int k) {
    int L = nums.length,max=nums[0],res=0;
    int min=nums[L-1];
    int[] max1=new int[L];
    int[] min1=new int[L];
    max1[0]=max;
    min1[L-1] =min;
    for(int i=1;i<L;i++){
        if(nums[i]>=max){
            max1[i]=nums[i];
            max=nums[i];
        }else{
            max1[i]=max;
        }
    }
    for(int i=L-2;i>=0;i--){
        if(nums[i]<=min){
            min1[i]=nums[i];
            min=nums[i];
        }else{
            min1[i]=min;
        }

    }
    for(int i=0;i<L;i++){
        if((max1[i]-min1[i])<=k){
           return i;
        }
    }
    return -1;
 }
}