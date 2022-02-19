class Solution {
public:
    vector<long long> maximumEvenSplit(long long n) {
        if(n%2) 
            return {};

		vector<long long> res;
        long long i = 2;
        long long crSum=0;
		
        while((crSum+i)<= n)
        {
            res.push_back(i);
            crSum+=i;
            i+=2;
        }
		
		int sz = res.size();
        res[sz-1] += (n-crSum);
        return res;
    }
};