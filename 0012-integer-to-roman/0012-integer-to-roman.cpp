class Solution {
public:
    string intToRoman(int num) {
        vector nums = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string str[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string res = "";
        int div;

        int i = 12;
        while(num > 0){
            div = num/nums[i];
            num = num%nums[i];
            while(div--){
                res += str[i];
            }
            i--;
        }
    return res;
    }
};