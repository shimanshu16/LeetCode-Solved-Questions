class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int today = 0;

        sort(meetings.begin(), meetings.end());

        for (const auto& meeting : meetings) {
            int i = meeting[0], j = meeting[1];

            if (j <= today) continue;
            else if (i > today) days -= j - i + 1;
            else days -= j - today;

            today = j;
        }

        return days;
    }
};