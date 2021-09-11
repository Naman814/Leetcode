class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
         if(numerator==0) return "0";
    string ans;
    unordered_map<long int,int> mp;
    if((numerator<0 && denominator>0) || (numerator>0 && denominator<0)) ans=ans+"-";
    long int num=labs(numerator),den=labs(denominator);    
    long int remainder,decimal=num/den;
    int curdigit,index;
    remainder=num%den,
    ans=ans+to_string(decimal);
    if(remainder!=0) ans=ans+".";
    index=ans.size();
    while(remainder!=0)
    {
        if(mp.find(remainder)!=mp.end())
        {
            ans.insert(mp[remainder],"(");
            ans=ans+")";
            break;
        }
        mp[remainder]=index;
        remainder=remainder*10 ;
        curdigit=remainder/den;
        ans=ans+to_string(curdigit);
        remainder=remainder%den;
        index++;
    }
    return ans;
    }
        
};