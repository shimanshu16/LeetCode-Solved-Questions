class Solution {
public:
    int n, m;
    int rand10() {
        
		n = rand7(), m = 7;
    
		while (n > 5) {
            m = n - 5;
            n = rand7();
        }
    
		while (m == 7) m = rand7();
        return (m % 2 ? 5 : 0) + n;
    }
};