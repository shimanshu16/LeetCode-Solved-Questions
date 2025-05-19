#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // If total cards are not divisible by groupSize, it's not possible
        if (hand.size() % groupSize != 0) return false;

        // Count frequency of each card using hashmap
        unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        // Use a min-heap (priority queue) to always pick the smallest card
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& entry : count) {
            minHeap.push(entry.first);
        }

        // Try to make groups starting from the smallest card
        while (!minHeap.empty()) {
            int first = minHeap.top();  // Smallest available card

            // Try to build a group starting from 'first'
            for (int i = 0; i < groupSize; i++) {
                int currentCard = first + i;

                // If current card doesn't exist, we can't form a valid group
                if (count[currentCard] == 0) return false;

                // Use one copy of this card
                count[currentCard]--;

                // If count becomes 0, remove from heap to avoid reuse
                if (count[currentCard] == 0 && currentCard == minHeap.top()) {
                    minHeap.pop();
                }
            }
        }

        // All cards used successfully in valid groups
        return true;
    }
};
