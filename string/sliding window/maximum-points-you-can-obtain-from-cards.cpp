class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), rightMostSum = 0, ans = 0;

        //  find right most sum
        for(int  i = n - k; i < n; i++) {
            rightMostSum += cardPoints[i];
        }

        ans = rightMostSum;

        for(int i = 0; i < k; i++) {
            rightMostSum -= cardPoints[n - k + i];
            rightMostSum += cardPoints[i];

            ans = max(rightMostSum, ans);
        }

        return ans;
    }
};
