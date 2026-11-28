class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size(),cheapest_price=INT_MAX;
        vector<int>freq(n+1,0);
        for(auto&vec:items){
            int f=vec[0];
            int p=vec[1];
            freq[f]++;
            cheapest_price=min(cheapest_price,p);
        }
        vector<int>freq_sum(n+1,0);
        for(int f=1;f<=n;f++){
            for(int k=f;k<=n;k+=f){
                freq_sum[f]+=freq[k];
            }
        }
        vector<pair<int,int>>units;
        for(auto&vec:items){
            int f=vec[0],p=vec[1];
            int cnt=freq_sum[f]-1;
            if(cnt>0&&p<2LL*cheapest_price){
                units.push_back({p,cnt});
            }
        }
        sort(units.begin(),units.end());
        int res=0;
        for(int i=0;i<units.size();i++){
            int p=units[i].first;
            int freq_cnt=units[i].second;
            int k=min(budget/p,freq_cnt);
            budget-=k*p;
            res+=(2*k);
        }
        res+=(budget/cheapest_price);
        return res;

    }
};