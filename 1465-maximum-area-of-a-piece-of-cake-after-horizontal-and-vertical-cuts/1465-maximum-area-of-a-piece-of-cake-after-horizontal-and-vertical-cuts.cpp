class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& verti) {
        const long long int mod = 1000000007;
        int n = hori.size() , m = verti.size();
        
        sort(hori.begin(),hori.end());
        sort(verti.begin(),verti.end());
        
        vector<int> horiHeights = {max(hori[0],h-hori[n-1])};
        vector<int> vertiHeights = {max(verti[0],w-verti[m-1])};
        
        for(int i=1;i<n;i++){
            horiHeights.push_back(hori[i] - hori[i-1]);
        }

        for(int i=1;i<m;i++){
            vertiHeights.push_back(verti[i] - verti[i-1]);
        }
  
        long long int a = *max_element(horiHeights.begin(),horiHeights.end());
        long long int b = *max_element(vertiHeights.begin(),vertiHeights.end());
        return (int)(a%mod * b%mod);
       

        
    }
};