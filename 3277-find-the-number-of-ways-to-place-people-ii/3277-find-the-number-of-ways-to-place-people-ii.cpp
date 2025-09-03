class Solution {
public:
    static bool cmp(const vector<int>& p, const vector<int>& q){
        return (p[0]==q[0])?p[1]<q[1]:p[0]>q[0];// order by (x, >)
    }
    int numberOfPairs(vector<vector<int>>& points) {
        ranges::sort(points, cmp);
        int n = points.size(), ans = 0;
        for(int i=0; i<n-1; i++){
            int y=INT_MAX, yi=points[i][1];
            for(int j = i+1; j<n; j++){
                const int yj=points[j][1];
                if (yj>=yi && y>yj){//P[j] cannot be in between
                    ans++;
                    y=yj;
                    if (yi==yj) break;
                }
            }
        }
        return ans;
    }
};