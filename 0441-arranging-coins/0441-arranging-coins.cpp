class Solution {
    long long sum_upto(long long mid){

        return mid*(mid+1)/2;
    }
public:
    int arrangeCoins(int n) {
        
        int start=1;
        int end=n;

        while(start<=end){
            int mid=start+(end-start)/2;
            long long sum=sum_upto(mid);
            if(n==sum){
                return mid;
            }
            else if(n<sum){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return end;
    }
};