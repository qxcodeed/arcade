// @DROP
#include <iostream>
#include <vector>

using namespace std;

// Função recursiva para verificar se existe um subconjunto com soma igual a k
bool subsetSum(size_t idx, int currentSum, int target, const vector<int>& nums) {
    if (currentSum == target) return true;      // encontramos a soma desejada
    if (idx == nums.size() || currentSum > target) return false;  // ultrapassou ou acabou

    // Tenta incluir ou não incluir o número atual
    return subsetSum(idx + 1, currentSum + nums[idx], target, nums) ||
           subsetSum(idx + 1, currentSum, target, nums);
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    bool result = subsetSum(0, 0, k, nums);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
