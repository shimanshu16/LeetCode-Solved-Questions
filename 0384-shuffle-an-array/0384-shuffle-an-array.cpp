class Solution {
private:
    std::vector<int> nums;
    std::vector<int> original;
    
public:
    Solution(std::vector<int>& nums) : nums(nums), original(nums) {}
    
    std::vector<int> reset() {
        nums = original;
        return nums;
    }
    
    std::vector<int> shuffle() {
        std::vector<int> shuffled = nums;
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(shuffled.begin(), shuffled.end(), g);
        return shuffled;
    }
};