class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;

        while(r>0 and arr[r]>=arr[r-1])
            r--;

        int shortest=r;
        while(l<r){
            while(r<n and arr[l]>arr[r])
                r++;

            shortest = min(shortest,r-l-1);
            l++;
            if(arr[l]<arr[l-1])
                break;
        }
        return shortest;
        
    }
};