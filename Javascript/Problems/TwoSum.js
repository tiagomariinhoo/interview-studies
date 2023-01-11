/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
// Transform the array into tuples pair<int,int> and sort them
 var twoSum = function(nums, target) {
  var ans = []
  // var qt = new Map()
  nums = nums.map((el, idx) => {
      return [el, idx]
  })
  
  nums.sort((a, b) => {
      return a[0] - b[0]
  })
  
  
  console.log(nums)
  
  var i = 0, j = nums.length - 1
  
  while(i < j) {
      if(nums[i][0] + nums[j][0] > target) j--
      else if(nums[i][0] + nums[j][0] < target) i++
      else {
          ans.push(nums[i][1])
          ans.push(nums[j][1])
          break
      }
  }
  
  return ans
};

// Using map

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
 var twoSum = function(nums, target) {
  let qt = {}
  let ans = []
  
  for(let i = 1; i < nums.length; i++) {
      qt[nums[i]] = i
  }
  
  for(let i = 0; i < nums.length; i++) {
      let current = target - nums[i]
      if(qt[current] != null && qt[current] != i) {
          ans.push(i)
          ans.push(qt[current])
          break;
      }
      // if(qt[current] == i) qt[current] = 0
  }
  
  return ans
};