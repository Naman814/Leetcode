class Solution {
public:
    string addBinary(string s1, string s2) {
         vector<int> v;
    int n1 = s1.length();
    int n2 = s2.length();
    int carry = 0;
    string ans = "";
    int i = n1 - 1, j = n2 - 1, sum = 0;
    while (i >= 0 || j >= 0)
    {
        sum = carry;
        if (i >= 0)
            sum += (s1[i] - '0');
        if (j >= 0)
            sum += (s2[j] - '0');
        ans=(char)((sum % 2)+'0')+ans;
        carry = sum / 2;
        i--;
        j--;
    }
    if (carry) ans=(char)(carry+'0')+ans;
   
    return ans;
        
    }
};