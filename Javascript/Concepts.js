/**
 * https://youtu.be/lkIFF4maKMU?list=LL
 * 
 * Script Language and u can write code on the fly
 */

// High order functions

function add(a, b) { // Function definition
  return a + b;
}

const add = function(a, b) { // function expression

}

function higherOrder(fun) { // high order functions
  fun()

  return function () {

  }
}

function giveMeClosure() { // closure that encapsulates data and logic from the rest of the program
  /**
   * When u call a function that has a variable with a primitive value
   * it's stored on the call stack
   * which is the browser's short-term memory
   * 
   * when u create closure, the inner function can still access
   * variables in the outer function even after the initial function call
   * 
   * This happens because js automatically stores the data in the outer function in the heap memory
   * which will persist between function calls 
   */
  let a = 10;
  return function () {
    a++;
    return a;
  }
}

// This
function wtfIsThis() {
  /**
   * Keyword that references an object and based on how a function is called
   */
  console.log(this)
}

const person = {
  wtfIsThis: () => {
    console.log(this) // "this" here gonna be a reference to that object
  }
}
// You can manually bind a function to some other object using bind method

// const person = {}
const personFun = wtfIsThis.bind(person)

/**
 * Passing arguments a primitive like numbers is passed by
 * value which means a copy is created
 * 
 * But if the argument is an object, that means that will be
 * stored in the heap and it's passed by reference0
 */
someFun(num, obj)

// Recommended way to get the prototype
Object.getPrototypeOf(human)

class Human {
  constructor(name) {
    this.dna = "AACTG"
    this.name = name
  }

  get gender() {
    return this.gender
  }

  set gender(val) {
    this.gender = val
  }

  walk() {
    console.log('walking')
  }

  static isHuman(human) { // Making them global to the class name with the static keyword
    if (human.dna == 'AACTG') {
      return true
    }
  }
}

/**
 * Set, Map etc
 */

// Garbage Collector

// Non-Blocking Event Loop
// Sync part 7:36

setTimeout(() => {
  console.log('5 seconds in the future')
}, 5000)

const promise = new Promise( // Wrapper for a value that's unknown right now but that will resolve to a value in the future
  (resolve, reject) => {
    if(greateSuccess) {
      resolve('success')
    } else {
      reject('rejected')
    }
  }
)
promise.then(success => {})
.catch()

// Async function that automatically return a promise
async function asyncFun() {
  try {
    const result = await promise
  } catch (error) {
    
  }
}

// Export default between files

/**
 * Document allows us to grab an individual html element
 */

const btn = window.document.querySelector('.button') // that has the same class
const AllBtns = window.document.querySelectorAll('.button')

btn.addEventListener('click', () => {
  console.log('clicked')
  document.body.style.backgroundColor = 'red' // we can change the css elements
})

/**
 * For React, we can use Dynamic Imports to optmize
 * and only import that JavaScript when it becomes needed
 */