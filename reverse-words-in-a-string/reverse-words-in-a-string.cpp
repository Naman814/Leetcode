class Solution {
public:
    string reverseWords(string str) {
    vector<string> v;
    int n = str.length();
    string temp = "";
    int i;
    for (i = 0; i < n; i++)
    {
        if (str[i] != ' ')
        {
            int start = i;
            while (i < n && str[i] != ' ')
            {
                i++;
            }
            v.push_back(str.substr(start, i - start));
        }
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        temp += v[i];
        temp += " ";
    }
    return temp.substr(0, temp.length() - 1);
        
    }
};