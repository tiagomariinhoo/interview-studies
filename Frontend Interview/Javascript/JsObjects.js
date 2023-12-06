// Object Equality
// const obj1 = {"a": 1, "b": 2};
// const obj2 = {"a": 1, "b": 2};

// console.log(JSON.stringify(obj1) === JSON.stringify(obj2)); // true

Array.prototype.forEachInverse = (callback) => {
  const resultArray = []
  for (let i = 0; i < this.length; i++) {
      resultArray.push(callback(this[i], i))
  }
  return resultArray
}

const arr = [1, 2, 3, 4, 5]

arr.forEachInverse((element, index) => {
  console.log(element, index)
})