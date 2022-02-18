// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
     int n = num.length();
        if(n==k) return "0";
        stack<int> s;
        string ans="";
        for(int i=0;i<n;i++){
            int val = num[i]-'0';
                while(!s.empty() and val<s.top() and k>0){
                    s.pop();
                    k--;
                }
                if(s.empty() and val==0) continue;
            s.push(val);
        }
         while(k && !s.empty())
        {
            --k;
            s.pop();
        }
        while(!s.empty()){
            string temp = to_string(s.top());
            ans = temp + ans;
            s.pop();
        }
        return ans = ans==""? "0" : ans;
}