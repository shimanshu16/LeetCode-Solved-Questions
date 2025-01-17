class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        
        int n = arr.size();
        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);
        int ans= -1 ;
        while(start<= end){
            
            int mid = start + (end-start)/2;
            int pages = 0, count = 1;
            for(int i=0;i<n;i++){
                pages += arr[i];
                if(pages > mid){
                    count++;
                    pages = arr[i];
                }
            }
            
            if(count <= k){
                ans = mid;
                end = mid-1;
            }
            else 
                start = mid+1;
        }
        return ans;
    }
};