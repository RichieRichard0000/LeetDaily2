class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>alive(n,1);
        int rem=n;
        int i=0,cnt=1;
        while(rem!=1){
            i=i%n;
            if(alive[i] && cnt<k){
                i++;
                cnt++;
            }
            else if(alive[i] && cnt==k){
                cnt=1;
                alive[i]=0;
                rem--;
                i++;
            }
            else if(!alive[i])i++;
        }
        for(int i=0;i<n;i++){
            if(alive[i])return i+1;
        }
        return -1;
    }
};