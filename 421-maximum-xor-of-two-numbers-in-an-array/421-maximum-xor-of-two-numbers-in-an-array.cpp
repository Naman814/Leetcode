class Solution {
public:

    class trieNode{
        public:
        trieNode *left;
        trieNode *right;
        
    };
    
    void insert(trieNode *head, int val){
        trieNode* currNode = head;
        for(int i=31;i>=0;i--){
            int bit=(val>>i) & 1;
            if(bit==0){
                if(!currNode->left){
                    currNode->left=new trieNode();
                }
                currNode=currNode->left;
            }
            else{
                if(!currNode->right){
                    currNode->right=new trieNode();
                }
                currNode=currNode->right;
            }
        }
    }
    
    int max_xor(trieNode *head, vector<int> nums){
        int maxi_xor=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            int curr_xor=0;
        trieNode *curr=head;
            int val=nums[i];
            for(int j=31;j>=0;j--){
                int bit=(val>>j)&1;
                if(bit==0){
                    if(curr->right){
                        curr_xor+=pow(2,j);
                        curr=curr->right;
                    }
                    else{
                        curr=curr->left;
                    }
                }
                else{
                    if(curr->left){
                         curr_xor+=pow(2,j);
                        curr=curr->left;
                    }
                    else{
                        curr=curr->right;
                    }
                    
                }
            }
            if(curr_xor>maxi_xor){
                maxi_xor=curr_xor;
            }
        }
        return maxi_xor;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        trieNode *head=new trieNode();
        for(int i=0;i<n;i++){
            insert(head,nums[i]);
        }
        return max_xor(head,nums);
    }
};