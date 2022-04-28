class Solution {
public:
    struct Node {
        int8_t row = 0;
        int8_t col = 0;
        int effort = 0;
    };
    static constexpr auto byEffort = [](const Node& a, const Node& b) noexcept {
        return a.effort > b.effort;
    };
    static constexpr array<array<int8_t, 2>, 4> dirs = {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
    
    int minimumEffortPath(const vector<vector<int>>& heights) const noexcept {
        ios_base::sync_with_stdio(false);
        const auto rows = heights.size();
        const auto cols = heights.front().size();    
        vector<vector<int>> efforts(rows, vector<int>(cols, numeric_limits<int>::max()));
        efforts[0][0] = 0;
        priority_queue<Node, vector<Node>, decltype(byEffort)> backlog(byEffort);
        backlog.emplace(Node{});
        
        while(!backlog.empty()) {
            const auto node = backlog.top();
            backlog.pop();
            if(node.row == rows - 1 && node.col == cols - 1)
                return node.effort;
         
            for(const auto& dir : dirs) {
                const int8_t r = node.row + dir[0];
                const int8_t c = node.col + dir[1];
                if(r < 0 || r >= rows || c < 0 || c >= cols)
                    continue;
                
                const int newEffort = max(node.effort, abs(heights[node.row][node.col] - heights[r][c]));
                if(auto& effort = efforts[r][c]; effort > newEffort) {
                    effort = newEffort;
                    backlog.emplace(Node{r, c, effort});
                }
            }
        }
        return 0;
    }
};