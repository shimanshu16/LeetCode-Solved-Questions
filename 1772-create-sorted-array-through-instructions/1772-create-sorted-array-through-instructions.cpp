class Solution {
public:
    int mod = 1e9 + 7;
    vector<pair<int,int>> index; 
    vector<int> lesser, greater; 
    
    void merge(int left, int mid, int right) {
        
        for(int i = mid + 1, j = left, k = left; i <= right; i++) {
            while(j <= mid and index[j].first < index[i].first) j++;
            while(k <= mid and index[k].first <= index[i].first) k++;
            lesser[index[i].second] += j - left;
            greater[index[i].second] += mid - k + 1;
        }

        vector<pair<int,int>> temp(right - left + 1);
        int p = left, q = mid + 1, r = 0;
        while (p <= mid and q <= right) 
            if(index[p].first <= index[q].first)
                temp[r++] = index[p++];
            else
                temp[r++] = index[q++];
        while (p <= mid) 
            temp[r++] = index[p++];
        while (q <= right)
            temp[r++] = index[q++];
        
        move(temp.begin(), temp.end(), index.begin() + left);
    }

    void mergeSort(int left, int right) {
        if(left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }

    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        index.resize(n);
        lesser.resize(n);
        greater.resize(n);

        for (int i = 0; i < n; i++)
            index[i] = {instructions[i], i};
        
        mergeSort(0, n - 1);
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
          
            ans += min(lesser[i], greater[i]);
            ans %= mod;
        }
        return ans;
    }
};