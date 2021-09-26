class Solution {
public:
    bool searchMatrix(vector<vector<int>>& M, int target) {
      bool flag=false;
    
    int n=M.size(), m=M[0].size();
    int i=0,j=m-1;
    
    while(i<n && j>=0)
    {
        if(M[i][j]==target)
        {
            flag=true;
            break;
        }
        
        else if(M[i][j]<target)
            i++;
        else
            j--;
    }
    
    return flag;
    }
};

  // int low=0, high=matrix[0].size()-1;
  //       for(int i=0;i<matrix.size();i++){
  //           if(target>=matrix[i][low] && target<=matrix[i][high]){
  //               for(auto x:matrix[i]){
  //                   if(x==target){
  //                       return true;
  //                   }
  //               }
  //           }
  //       }
  //       return false; 