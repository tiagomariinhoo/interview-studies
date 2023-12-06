// https://youtu.be/9cQsv91zBsc?list=LL

/**
 * JS Questions
 * 
 * --------------------  WHAT IS HOISTING?
 * 
 * Basically when javascript compiles the code, all the declarations using 'var' are hoisted
 * Taking to the top of the function/scopes
 * 
 * According the following code:
 */
console.log(myName)
var myName = 'Tiago'

/**
 * Which command the console.log will show?
 * 
 * 1 - Uncaught ReferenceError: myName is not defined
 * 2 - Bob
 * 3 - Undefined
 * 
 * 3 is the correct answer, the variable is moved to the top but just the declaration and
 * not the real value. It will just recognize that myName exists
 */

// -------------------- WHAT'S THE DIFFERENCE BETWEEN LET AND VAR?
/**
 * Let are only available inside the block where they're defined
 * Var are available throughout the function in which they're declared
 */

function varScoping() {
  var x = 1;

  if (true) {
    var x = 2;
    console.log(x); // will print 2
  }

  console.log(x); // will print 2
}

function letScoping() {
  let x = 1;

  if (true) {
    let x = 2;
    console.log(x); // will print 2
  }

  console.log(x); // will print 1
}

// -------------------- WHAT IS EVENT LOOP
/**
 * JavaScript has a runtime model based on an event loop
 * Which is responsible for executing the code
 * Collecting and processing events, and executing queued sub-tasks
 * 
 * Javascript is a single threaded language
 * That means first in first out
 * In event loop it means like moving our events from the task queue to the
 * caller stack
 * 
 * But what is the precedence in Event Loop?
 */

//--------------------  WHAT'S THE DIFFERENCE BETWEEN setTimeout and setInterval
//setTimeout will just execute once after a specific time in ms
//setInterval will executee in a loop 
setInterval(() => console.log('setInterval'), 10000) // Will execute each 10s
setTimeout(() => console.log('setTimeout'), 5000) // Will execute once after 5s

//--------------------  WHEN USE REST OPERATOR

function sum(...args) {
  let total = 0
  for (const arg of args) {
    total += arg
  }
  return total
}

console.log(sum(1, 2, 3)) // 6
console.log(sum(1, 2, 'teste')) // 3teste

// -------------------- WHAT'S IS ARRAY REVERSE
//Just reverse an array
const reversed = array1.reverse()

// DIFFERENCE BETWEEN SHALLOW COPY AND DEEP COPY
// Shallow copy will just copy the first level of the object. Deeper levels are references
// Deep copy means that all levels of the object are copied

// Shallow copy:
const obj = { name: 'Version 1', additionalInfo: { version: 1 } };

// {...obj} or Object.assign({}, obj)
const shallowCopy1 = {...obj}

shallowCopy1.name = 'New Name'
shallowCopy1.additionalInfo.version = 2

console.log(shallowCopy1) // { name: 'New Name', additionalInfo: { version: 2 } }
console.log(obj) // { name: 'Version 1', additionalInfo: { version: 2 } }

// Deep copy
const obj = { name: 'Version 1', additionalInfo: { version: 1 } };

const deepCopy = JSON.parse(JSON.stringify(obj))

// The only note here is the performance, because shallow copies are a lot faster than deep copies

// --------------------  WHAT ARE CLOSURES
// Let's suppose that we have a function inside a function and we have a variable in a parent function. The child function
// will have access to it, it will just allow inner functions to access the outer scope of a functions

// --------------------  HAVE U USED REDUCE FUNCTIONS? DIFFERENCE MAP x REDUCE
/**
 * Map we can change every element of the array and return a new array
 * const newArray = array1.map((element) => element * 2)
 * 
 * Reduce executes a reducer function for each element and the result will be just an element
 * const value = array1.reduce((accumulator, element) => accumulator + element, initialValue)
 */

// --------------------  PARAMETERS FOR A MAP
/**
 * Will have a value and index
 * array1.map((element, index) => console.log(element, index))
 */

// --------------------  DIFFERENCE BETWEEN PROMISES AND CALLBACKS
/**
 * Callbacks are functions that are passed inside the arguments of other functions
 * This is allowed in javascript because functions are objects and objects can be passed
 * as arguments to functions
 */
function test(callback) {
  callback()
}

const myFunction = () => {
  console.log('test')
}

test(myFunction)

/**
 * Promise represents an eventual conclusion of an async operation
 * 
 * We need to use async await
 * then and catch
 * That's how the Promise syntax is
 */

var myPromise = new Promise(function(resolve, reject) {
  if (true) {
    resolve()
  } else {
    reject()
  }
  // code
})

myPromise.then(() => console.log('success'))
.catch(() => console.log('Error'))

// We can define a promise like this
var promise = new Promise(function(resolve, reject) {
  setTimeout(() => {
      resolve('resolved')
  }, 2000)
})


/*
For this code below, there are some important points
The order will be:
Opa
resolved
Eae

Since what is out from an async function, will run normally
but for what is inside an asyn function, will run after the await
*/
const test = async () => {
  await promise.then((res) => {
      console.log(res)
  })
  console.log('Eae')
}

test()

console.log('Opa')

// --------------------  WHAT POSITION ATTRIBUTES IN CSS HAVE YOU USED
/** https://www.freecodecamp.org/news/learn-the-basics-the-css-position-property/
 * static
 * - Default value
 * relative
 * - positioned according the flow of the document, left/right/top/bottom can affect it
 * absolute
 * - positioned relative to their parent elements, the element is removed from the normal document
 * - is positioned to its closest positioned ancestor, the parent has to have a position different from static
 * fixed
 * - similar to absolute but are relative to the <html> element
 * - so it will always show even scrolling the page
 * sticky
 * - it's a mix of relative and fixed, relatively positioned element until a certain scroll
 * - and it will be fixed 
 */

// --------------------  WHAT IS FLEXBOX?
/**
 * It's a one-dimensional layout method for arranging items in rows or columns
 * 
 * display: flex
 * flex-direction etc
 */

// --------------------  DIFFERENCE BETWEEN DISPLAY NONE AND HIDDEN
/**
 * None will literally remove the element
 * Hidden will make it not visible, it will just hide
 */

// --------------------  useState / useEffect / useMemo / useContext / useRef / useReducer
/**
 * useCallback when to use it?
 * - when a component is passing a callback to its child component to prevent the rendering of the child component
 * - it only changes the callback when one of its dependencies gets changed
 */

// --------------------  WHAT ARE CLASS BASED LIFECYCLE METHODS
/**
 * u can simulate componentWillMount componentDidMount etc
 * Using useEFfect
 */

// --------------------  WHAT ARE PURE COMPONENTS?
/**
 * The component is considered pure if it renders the same output for the same
 * state and props.
 * 
 * In class component based, we need to use PureComponent extending in a Class
 * To skip re-rendering a class component for same props and state, extend PureComponent instead of Component
 */

// --------------------  WHAT ARE HIGH ORDER COMPONENTS?
/**
 * https://youtu.be/2zqWG2--0pc
 * 
 * They allow to reuse component logic across multiple components
 * Is a function that takes a component as an argument and returns a new component that wraps the original component
 * When u want to reuse the logic between some components
 * 
 * They're commonly used to implement authentication, error handling and data loading
 * 
 */

// --------------------  REACT MIDDLEWARES