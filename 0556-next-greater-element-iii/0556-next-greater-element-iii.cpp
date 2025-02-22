class Solution {
public:
    int nextGreaterElement(int n) {
        string temp=to_string(n);
        int p=temp.size();
        bool flag=false;
        for(int i=0;i<temp.size()-1;i++){
            if((int)temp[i]<(int)temp[i+1]){
                flag=true;
                break;
            }
        }
        if(flag==false){
            return -1;
        }
        int lastDigit=temp[temp.size()-1];
        int i=p-2;
        int j;
        for( i=p-2;i>=0;i--){
            if((int)lastDigit>(int)temp[i]){
                break;
            }
            lastDigit=temp[i];
        }
        if(i>=0){
            for( j=p-1;j>i;j--){
                if((int)temp[j]>(int)temp[i]){
                    swap(temp[i],temp[j]);
                    break;

                }
                
            }
        }
        sort(temp.begin()+i+1,temp.end());
        
        long long xx=stol(temp);
        if(xx>INT_MAX){
            return -1;
        }
        
        return xx;
    }
};