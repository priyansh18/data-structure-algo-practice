
int Solution::pow(int base, int expo, int m) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for
    // more details
    if (m == 1) return 0;

    long long ans = 1;
    long long y = base % m;
    while (expo > 0) {
        if (expo & 1) ans = ((ans)*y) % m;
        y = (y * y) % m;
        if (y < 0) y += m;
        expo = expo >> 1;
    }
    if (ans < 0) {
        ans = (m - abs(ans) % m);
        return ans;
    }

    return ans;
}