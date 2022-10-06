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

// console.log("Start")

// const promise1 = new Promise((resolve, reject) => {
//     console.log(1);
//     resolve("Success")
// })

// console.log("Middle")

// promise1.then(res => {
//   console.log(res) // ASYNC CODE
// })

// console.log("End");

// Challenge 6 - The one with a fulfilling promise
/**
 * Output: Start, End, 1, 2, since the code inside
 * the then are async and will be exectued after all sync code
 */
// console.log('start')

// Promise.resolve(1).then((res) => {
//   console.log(res)
// })

// Promise.resolve(2).then((res) => {
//   console.log(res)
// })

// console.log('end')

// Challenge 7 - setTimeout vs Promise
/**
 * Usually the difficulty of Promise is that it appears with setTimeout
 * 
 * For this code, setTimeout is 0 second and Promise.resolve
 * will also return a fulfilled Promise object immediately after
 * execution
 * 
 * Both of them are completed at the same time, so whose callback function
 * will be executed first?
 * 
 * In JavaScript EventLoop there's also the conepct of priority
 * 
 * Tasks with higher priority are called microtasks: Promise, ObjectObserver, MutationObserver, process.nextTick, async/await
 * Tasks with lower priority are called macrotasks: setTimeout, setInterval and XHR
 * 
 * Then here, the output should be:
 * Start, end, resolve, setTimeout
 * 
 * Execut Sync code first -> microtask (Promise.resolve()) -> macrotask (setTimeout)
 */

//  console.log('start')

//  setTimeout(() => {
//    console.log('setTimeout')
//  })
 
//  Promise.resolve().then(() => {
//    console.log('resolve')
//  })
 
//  console.log('end')

// Challenge 8 - Microtasks mix Macrotasks
/**
 * Output:
 * 1, 2, 4, timerStart, timerEnd, Success
 */
 
// const promise = new Promise((resolve, reject) => { // Sync code
//   console.log(1); // 1
//   setTimeout(() => { // Macrotask
//     console.log("timerStart"); // 4
//     resolve("success"); // 6
//     console.log("timerEnd"); // 5
//   }, 0);
//   console.log(2); // 2
// });

// promise.then((res) => { // Microtask async, but since the current promise is still in the PENDING state, the code won't be executed now
//   console.log(res);
// });

// console.log(4); // 3 - Sync Code

// Challenge 9 - Prioritise between Microtasks and Macrotasks
/**
 * One important thing is, that's wrong:
 * 1 - Execute Microtasks
 * 2 - Macrotasks
 * 3 - Microtasks again
 * 4 - Cycle through
 * 
 * The correct understanding is:
 * 1 - All microtasks first
 * 2 - One macrotask
 * 3 - All (newly added) microtasks again
 * 4 - Next macrotask
 * 5 - Cycle through
 * 
 * Then the output should be: timer1, Promise1, timer2
 */

// const timer1 = setTimeout(() => {
//   console.log('timer1');
  
//   const promise1 = Promise.resolve().then(() => { // Newly added microtask
//     console.log('promise1')
//   })
// }, 0)

// const timer2 = setTimeout(() => {
//   console.log('timer2')
// }, 0)

// Challenge 10 - Typical Interview Question
// Talk about the output order

/**
 * Start, end, promise1, timer1, promise2, timer2
 * 
 * Execute all sync code:
 * start, end
 * 
 * Execute microtask
 * start, end, promise1,
 * 
 * Execute first macrotask
 * start, end, promise1, timer1, 
 * 
 * The macrotask put a new microtask to the task queue:
 * start, end, promise1, timer1, promise2, 
 * 
 * Execute the next macro task:
 * start, end, promise1, timer1, promise2, timer2
 */

console.log('start');

const promise1 = Promise.resolve().then(() => {
  console.log('promise1');
  const timer2 = setTimeout(() => {
    console.log('timer2')
  }, 0)
});

const timer1 = setTimeout(() => {
  console.log('timer1')
  const promise2 = Promise.resolve().then(() => {
    console.log('promise2')
  })
}, 0)

console.log('end');