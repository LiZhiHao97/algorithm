
const initial2DArray = (n, m, val) => Array(n).fill().map(() => Array(m).fill(val))

var longestPalindrome = function(s) {
    const n = s.length
    const dp = initial2DArray(n, n, false)
    let ans = ''

    for (let l = 0; l < n; l++) {
        for (let i = 0; i + l < n; i++) {
            let j = i + l
            if (l == 0) {
                dp[i][j] = true
            } else if (l == 1) {
                dp[i][j] = (s[i] == s[j])
            } else {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1])
            }
            if (dp[i][j] && l + 1 > ans.length) {
                ans = s.substr(i, l + 1)
            }
        }
    }

    return ans
};