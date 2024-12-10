class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           int m=nums1.size(), n=nums2.size(), total=m+n;
        int left=0, right=0, cnt=-1;
        double median=0;
        bool isEven = (total%2 == 0);
        while(left<m || right<n) {
            int curr;
            if(left<m && right<n && nums1[left] <= nums2[right]) {
                curr = nums1[left];
                left++;
                cnt++;
            }
            else if(left<m && right<n && nums1[left] > nums2[right]) {
                curr = nums2[right];
                right++;
                cnt++;
            }
            else if(left>=m && right<n) {
                curr = nums2[right];
                right++;
                cnt++;
            }
            else if(right>=n && left<m) {
                curr = nums1[left];
                left++;
                cnt++;
            }
            if(isEven && cnt == (total/2)-1) median += curr;
            if(cnt == total/2) median += curr;
        }
        if(isEven) return median/2;
        return median; 
    }
};