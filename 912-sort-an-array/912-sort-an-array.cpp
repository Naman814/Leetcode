class Solution {
public:

void merge(vector<int>&nums,int l,int mid,int h){
    int i=l,j=mid+1,k=l,b[h+1];
    while(i<=mid and j<=h){
        b[k++] = nums[i]<nums[j]? nums[i++] : nums[j++];
    }
    while(i<=mid){
        b[k++] = nums[i++];
    }
    while(j<=h){
        b[k++] = nums[j++];
    }
    for(int i=l;i<=h;++i){
        nums[i] = b[i];
    }
}
void mergeSort(vector<int>&nums,int l,int h){
    if(l<h){
        int mid = (l+h)>>1;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,h);
        merge(nums,l,mid,h);
    }
}
    vector<int> sortArray(vector<int>& nums) {
        int l=0,h=nums.size();
        mergeSort(nums,l,h-1);
        return nums;
    }
};