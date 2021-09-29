class Solution {
public:
    int majorityElement(vector<int>& a) {
        
         int count=0,ele=0;
        int n=a.size();
    for(int i=0;i<n;i++){

        if(count==0){
            ele=a[i];
        }
        if(ele==a[i]){
            count++;
        }else{
            count--;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(ele==a[i]){
            count++;
        }
    }

    if(count>n/2){
       return ele;
    }
    else{
       return -1;
    }
        
    }
};