class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        std::unordered_map<int, int> Loss_game;
        for(const auto &item: matches){
            if(Loss_game.find(item[0]) == Loss_game.end()) Loss_game[item[0]] = 0;
            if(Loss_game.find(item[1]) == Loss_game.end()) Loss_game[item[1]] = 0;
            Loss_game[item[1]] ++;
        }
        std::vector<std::vector<int>> ans(2, std::vector<int>());
        for(const auto &item: Loss_game){
            if(item.second == 0) ans[0].push_back(item.first);
            if(item.second == 1) ans[1].push_back(item.first);
        }
        std::sort(ans[0].begin(), ans[0].end());
        std::sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};