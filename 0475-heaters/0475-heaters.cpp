class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        vector <int> v(houses.size(),INT_MAX);

        for(int i=0,h=0;i<houses.size() && h<heaters.size();){
            if(houses[i]<=heaters[h]){
                v[i]=heaters[h]-houses[i];
                i++;
            }
            else{
                h++;
            }
        }

        for(int i=houses.size()-1,h=heaters.size()-1;i>=0 && h>=0;){
            if(houses[i]>=heaters[h]){
                v[i]=min(houses[i]-heaters[h],v[i]);
                i--;
            }
            else{
                h--;
            }
        }
        
        return *max_element(v.begin(),v.end());

    }
};