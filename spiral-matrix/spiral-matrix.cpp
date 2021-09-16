class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0;
        int bottom=matrix.size()-1;
        int right=matrix[0].size()-1;
        int left=0;
        vector<int> res;
        int dir=0;
        while(top<=bottom && left<=right){
            if(dir==0){
                for(int i=left; i<=right ; i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir==1){
                for(int i=top;i<=bottom;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            if(dir==2){
                for(int i=right;i>=left;i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
                
            }
            if(dir==3){
                for(int i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            
            dir=(dir+1)%4;
        }
        
        return res;
        
    }
};