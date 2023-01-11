/**
 * @param {string} s
 * @return {string}
 */

 var globalString 
 var memo = new Array(1011)
 let l = 0, r = 0
 // Solution using memo
 
 function solve(i, j) {
     if(i > j || i < 0 || j >= globalString.length) return memo[i][j] = 0
     if(i === j) return memo[i][j] = 1
     if(memo[i][j] !== -1) return memo[i][j]
     
     let c = solve(i + 1, j)
     let b = solve(i, j - 1)
     let a = solve(i + 1, j - 1)
     
     if(globalString[i] === globalString[j] && a === 1 || globalString[i] === globalString[j] && j - i <= 1) {
         if((j - i) > (r - l)) l = i, r = j
         return memo[i][j] = 1
     }
     
     return memo[i][j] = 0
 }
 
 var longestPalindrome = function(s) {
     globalString = s
     l = 0, r = 0
     for(let i = 0; i < 1010; i++) memo[i] = new Array(1001).fill(-1)
     
     solve(0, s.length - 1)
     return s.slice(l, r + 1)
 };