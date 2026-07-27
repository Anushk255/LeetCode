#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;
        
        for (int num : nums) {
            if (num > max1) {
                max2 = max1; // पुराना सबसे बड़ा अब दूसरा सबसे बड़ा बन गया
                max1 = num;  // नया सबसे बड़ा मिला
            } else if (num > max2) {
                max2 = num;  // केवल दूसरा सबसे बड़ा अपडेट करें
            }
        }
        
        return (max1 - 1) * (max2 - 1);
    }
};
