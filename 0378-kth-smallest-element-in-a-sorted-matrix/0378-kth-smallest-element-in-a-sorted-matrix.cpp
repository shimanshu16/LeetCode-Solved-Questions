class MinHeap {
public:

    bool operator()(const tuple<int, int, int>& a,
                    const tuple<int, int, int>& b) {
        return get<0>(a) > get<0>(b);
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rowCount = matrix.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       MinHeap>
            minHeap;

        for (int i = 0; i < min(rowCount, k); ++i) {
            minHeap.push(make_tuple(matrix[i][0], i, 0));
        }

        int numbersChecked = 0, smallestElement = 0;

        while (!minHeap.empty()) {

            auto [value, rowIndex, colIndex] = minHeap.top();
            minHeap.pop();
            smallestElement = value;
            numbersChecked++;

            if (numbersChecked == k)
                break;

            if (colIndex + 1 < matrix[rowIndex].size()) {
                minHeap.push(make_tuple(matrix[rowIndex][colIndex + 1],
                                        rowIndex, colIndex + 1));
            }
        }

        return smallestElement;
    }
};