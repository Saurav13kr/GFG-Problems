class Solution {
public:
    int maxMinHeight(vector<int>& arr, int k, int w) {
        int n = arr.size();
        int low = INT_MAX;
        int high = INT_MIN;
        for (int a : arr) {
            low = min(low, a);
            high = max(high, a);
        }
        high += k; // maximum possible increase

        int result = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canReach(arr, k, w, mid)) {
                result = mid;
                low = mid + 1; // try for higher minimum
            } else {
                high = mid - 1;
            }
        }
        return result;
    }

private:
    bool canReach(vector<int>& arr, int k, int w, int target) {
        int n = arr.size();
        vector<long long> diff(n + 2, 0);
        long long used = 0;
        long long curr = 0;

        for (int i = 0; i < n; ++i) {
            curr += diff[i]; // accumulated increment at i
            long long height = arr[i] + curr;
            if (height < target) {
                long long need = target - height;
                used += need;
                if (used > k) return false;
                curr += need;
                diff[i] += need;
                if (i + w < diff.size()) diff[i + w] -= need;
            }
        }
        return true;
    }
};