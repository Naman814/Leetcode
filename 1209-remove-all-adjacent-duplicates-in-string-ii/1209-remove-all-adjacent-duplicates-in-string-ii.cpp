class Solution {
public:
  string removeDuplicates(string s, int k) {
  vector<pair<char, int>> stk;
  string res;
  for (auto ch : s) {
    if (stk.empty() || stk.back().first != ch) stk.push_back({ ch, 0 });
    if (++stk.back().second == k) stk.pop_back();
  }
  for (auto& p : stk) res += string(p.second, p.first);
  return res;
}
};