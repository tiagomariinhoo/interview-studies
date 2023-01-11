/**
 * @param {string} s
 * @return {number}
 */
 var lengthOfLongestSubstring = function(s) {
   // Solution using set
  let aux = new Set()
  let substring = ""
  let ans = 0
  let i = 0, j = 0
  
  while(i < s.length) {
      while(j < s.length) {
          if(!aux.has(s[j])) {
              aux.add(s[j])
              if(aux.size > ans) ans = aux.size
          } else break
          j++
      }
      aux.delete(s[i])
      i++
  }
  
  
  return ans
};