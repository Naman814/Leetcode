class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top=0;
        int bottom=n-1;
        int right=n-1;
        int left=0;
        vector<vector<int>> res(n,vector<int>(n,0));
        int dir=0;
        int cnt=1;
        while(top<=bottom && left<=right){
            if(dir==0){
                for(int i=left; i<=right ; i++){
                    res[top][i]=cnt++;
                }
                top++;
            }
            if(dir==1){
                for(int i=top;i<=bottom;i++){
                    res[i][right]=cnt++;
                }
                right--;
            }
            if(dir==2){
                for(int i=right;i>=left;i--){
                    res[bottom][i]=cnt++;
                }
                bottom--; 
            }
            if(dir==3){
                for(int i=bottom;i>=top;i--){
                  res[i][left]=cnt++;
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return res;
    }
};