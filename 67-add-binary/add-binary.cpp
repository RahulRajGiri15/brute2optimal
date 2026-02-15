class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length()-1;
        int n = b.length()-1;

        string result = "";

        int sum = 0;
        int carry = 0;

        while(m >= 0 || n >= 0) {
            sum = carry;

            if(m >= 0) {
                sum += a[m] - '0';
                m--;
            }

            if(n >= 0) {
                sum += b[n] - '0';
                n--;
            }

            result.push_back((sum%2 == 0) ? '0' : '1');

            carry = (sum > 1) ? 1 : 0; //sum/2
        }

        if(carry) {
            result.push_back('1');
        }

        reverse(begin(result), end(result));
        return result;
    }
};
