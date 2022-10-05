// These challenges are made using https://betterprogramming.pub/10-javascript-promise-challenges-before-you-start-an-interview-c9af8d4144ec
// U can type: node index, for execute this file

// Challenge 1 - Promise Construtor
// console.log("Start")

// const promise1 = new Promise((resolve, reject) => {
//     console.log(1);
// })

// console.log("End");

// Challenge 2 - Promise Construtor
/**
For this code, an async code appears
That is the callback function in .then

One important thing - JAVASCRIPT ALWAYS RUNS SYNCHRONOUS CODE FIRST,
THEN ASYNCRHONOUS CODE,
so, when we find this problem, we just need to identify the sync and async code
Output should be: Start, 1, end, 2
 */
// console.log("Start")

// const promise1 = new Promise((resolve, reject) => {
//     console.log(1);
//     resolve(2)
// })

// promise1.then(res => {
//   console.log(res)
// })

// console.log("End");

// Challenge 3 - Resolve()
/**
 * This code wors as the same code before
 * the only difference is that there's a console.log(3)
 * after resolve, but here will follow up the same logic
 * 
 * First find for the sync code and after the async code
 * THen the output should be: Start, 1, 3, End, 2
 * 
 * For Challenge 4, will not have the line with resolve(2)
 * Then the promise.then isn't called cause we're not calling
 * resolve(). Then the output should be: Start, 1, 3, End
 */

// console.log("Start")

// const promise1 = new Promise((resolve, reject) => {
//     console.log(1);
//     resolve(2)
//     console.log(3)
// })

// promise1.then(res => {
//   console.log(res) // ASYNC CODE
// })

// console.log("End");

// Challenge 5 - The one that's there to confuse you
/**
 * This will follow the same logic. First sync code and after async code
 * The output should be: Start, 1, Middle, End, Success
 */

console.log("Start")

const promise1 = new Promise((resolve, reject) => {
    console.log(1);
    resolve("Success")
})

console.log("Middle")

promise1.then(res => {
  console.log(res) // ASYNC CODE
})

console.log("End");