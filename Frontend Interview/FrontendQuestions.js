/** (https://www.youtube.com/watch?v=qvyvysDV17w must Know FAANG frontend questions)
 * ------ DESCRIBE WHAT HAPPENS WHEN YOU TYPE A URL INTO A BROWSER AND HIT ENTER
 * 
 * 1 - Computer sends a request to the DNS server which serves as an address book for all domain names.
 * This sends beack the exact IP addres (it works like a map)
 * 
 * 2 - Knowing this IP, the computer then establishes a connection with the server through the IP address
 * 
 * 3 - If your computer is behind a firewall, the firewall checks to ensure that the request is allowed
 * 
 * 4 - After establishing the connection, the browser now sends a request for the web page using an encryption protocol, like SSL or TLS
 * in order to encrypt the data that will be shared between you and the server (is the 's' in https), which also implies that the connection is safe.
 * 
 * 5 - Big techs like google with high traffic maintain a host of servers and for that matter, they have a load balancer
 * 
 * 6 - The server that receives the request sends a response back to the load balancer which also forwards the response back to your browser.
 * 
 * 7 - The HTML files returned to tell the browser how to render the content of the page, CSS tells the browser hot to style it, and the JS
 * adds interactivity to the page
 * 
 * 8 - If there is a need for some dynamic content such as Google search results, then the web server will make a request to the application server
 * 
 * 9 - Finally the browser will render the page
 * 
 * --- Resume
 * -> Browser looks up IP address in DNS Cache
 * -> If isn't found, the ISP (internet service provider) initiates a DNS Query to look for address in DNS servers
 * -> Browser sends HTTP request to the server
 * -> Browser establishes TCP connection with the server
 * -> If necessary server reads or writes data to the database
 * -> Server sends back response status code and HTML/JSON
 * -> Browser renders response to the end user
 * -> Browser repeats process for additional resources such as JavasCript bundles and images
 * 
 * 
 * 
 * ------ WHAT IS A JAVASCRIPT CLOSURE?
 * -> A closure remembers the variables and scope of the outer function even after the outer function has finished running
 */

// function urlFormatter(url) {
//   const protocol = 'http'; // Inside the urlFormatter we have access to the Protocol
//   // But if we try to access it outside from urlFormatter, we gonna see a reference error

//   return function() {
//     console.log(protocol);
//     console.log(`${protocol}://${url}`);
//   }
// }
// // console.log(protocol) //Reference error

// const newURL = urlFormatter('reddit.com');
// newURL();

// Normally a closure is a function + the lexical  environment it was declared in
// this environment hold the local identifies and it has a reference to the parent environment
// const globalNum = 5

// // When the function is executed it will use the local scope first
// // Then if it can't find an identifier it's looking for, such as this globalNum
// // Then it's going to look in the parent env, where it finds the const globalNum.
// function logNum() {
//   const localNum = 1
//   console.log(globalNum + localNum)
// }

// logNum()

function example() {
  const num = 5;

  return function logNum() { // it will create a closure at the time it is declared
    console.log(num) // Basically, since we're creating this function inside the lexical scope in example, we've access to NUM
  }

  // logNum(10) if I do it, for example, it will print out 10, since it will firstly try to fine into the local scope 
}

const innerFunction = example()
innerFunction()
//It's going to log five
/**
 * It's interesting because the example function has already run and its execution has completed
 * In many programming languages the num = 5=, would be garbage collected at this time because example is done running
 * But in javascript it creates a Closure
 * 
 * So logNum() creates a closure and it keeps access to its parents scope.
 * So it means that const num = 5 is going to exist as long as this innerFunction exists
 */

// Now you gonna see how useful are closures

function makeFunctions() {
  let privateNum = 0;

  function privateIncrement() {
    privateNum++;
  }

  return {
    logNum: () => console.log(privateNum),
    increment: () => {
      privateIncrement();
      console.log('Incremented!');
    }
  }
}
// It seems like an encapsulation
const { logNum, increment } = makeFunctions()
// if we do like this: const {logNum: logNum2, increment: increment2} = makeFunctions(), it will have a different result since it's a different parent env
logNum()
increment()
logNum()

// Last example that sometimes come up in technical interviews

//https://stackoverflow.com/questions/750486/javascript-closure-inside-loops-simple-practical-example
for (let i = 0; i < 3; i++) {
  setTimeout(() => { // This function is creating a closure, which means that it has access to the i variable (let i = 0)
    // The interesting thing is if we change it to var i = 0, it will log out: 3, 3, 3. 
    // Think about which closure is being created
    // Let is block scoped, let is only scoped inside of these curly braces
    // So in a for loop when using let, it's creating a new version of the variable with each iteration of the loop.

    // Var is function scoped, in this case it's just scoped globally because of the fact that we're not in a function
    // we are using the same Var i in each iteration, there's no way to create a new version of var i, so we get the same variable each time
    console.log(i); // Will run it after 500ms
  }, 500)
}
// Basically a closure remembers the variables and scope of the outer function even after the outer function has finished running

// CSS SPECIFICITY 
/**
 * Is how the browser determines which css property value should be applied to an 
 * HTML element if there are competing selectors
 * Highest --------> Lowest
 * 0              0         1                                         1
 * Inline Styles  IDs       Classes, attributes and pseudo-classes    Elements and pseudo-elements
 * 
 * We can also define it
 * If two selectors share the same specificity the browser will use whichever selector comes later in the document
 */

// What's the difference between .map and .forEach in Javascript?

/**
 * .map will return a brand new array according the callback function for each element
 * numberArray = [1, 2, 3, 4, 5]
 * let newMap = numberArray.map((num) => num*2)
 * newMap = [2, 4, 6, 8, 10]
 */

// Implement a function that is wrapped by a Javascript Promise
/**
 * A promise it's a javascript object that represents state
 * Are commonly used to handle with async functions, like api calls
 */

setTimeout(() => {
  console.log('making api call')
}, 1000)
console.log('Done')

new Promise((res, rej) => {
  setTimeout(() => {
    console.log("making api call")
    res()
  }, 1000)
}).then(() => console.log("Done"))