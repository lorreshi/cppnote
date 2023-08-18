#include <iostream>
#include <vector>

// 回溯函数
void backtrack(std::vector<std::vector<int> >& result, std::vector<int>& candidates, int target, int start, std::vector<int>& current) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); ++i) {
        if (target - candidates[i] >= 0) {
            current.push_back(candidates[i]);
            backtrack(result, candidates, target - candidates[i], i, current);
            current.pop_back();
        }
    }
}

int combinationSum2(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int> > result;
    std::vector<int> current;
    backtrack(result, candidates, target, 0, current);
    return result.size();
}

int main() {
    int target, n;
    std::cin >> target >> n;

    std::vector<int> candidates(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> candidates[i];
    }

    int count = combinationSum2(candidates, target);
    std::cout << "不同组合个数: " << count << std::endl;

    return 0;
}