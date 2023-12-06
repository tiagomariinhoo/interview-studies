// https://www.algoexpert.io/frontend/coding-questions/wordle

// WE CAN CREATE A STATE MATRIX USING THIS
const [matrix, setMatrix] = useState(() => {
  return Array.fill().map(() => Array(5).fill()) // Where it will fill a 6x5 matrix with Nulls
})

// WE CAN USE useRef INSTEAD OF useState WHEN WE DON'T WANT TO RERENDER THE COMPONENT WHEN THE STATE CHANGES
const canType = useRef(true)
canType.current = false || true

// TO FETCH DATA
const fetchData = async () => {
  await fetch(url).then((res) => res.json()).then((res) => console.log(res))
}

useEffect(() => {
  fetchData()
}, [])

// WE CAN CREATE A KEYBOARD LISTENER LIKE THIS
useEffect(() => {
  const keyDownHandler = (evt) => {
    // KeyCode >= 65 and <= 90 is from 'a' to 'z'
    if((evt.keyCode >= 65 && evt.keyCode <= 90) || evt.key == 'Enter' || evt.key == 'Backspace') {
      //...
    }
  }
  document.addEventListener('keydown', keyDownHandler)

  // It will remove the listener when the component is destroyed
  return () => {
    document.removeEventListener('keydown', keyDownHandler)
  }
}, [])

// USE toFixed(2) TO DISPLAY 9.00

// WHEN USING HTML INPUT
<input value={value} type="number" onChange={(evt) => handleChange(evt)} />

// https://www.algoexpert.io/frontend/coding-questions/question-list

// TO FIND A VALUE IN AN ARRAY
const element = list.find((element) => element.id === id)

// LET'S SUPPOSE THAT WE MADE A JAVASCRIPT OBJECT WITH SOME KEYS
// WE CAN ITERATE THROUGH THE OBJECT IN JSX LIKE THIS

return (
  <>
  {
    Object.keys(javascriptObject).map((key) => {
      return <Component name={key} />
    })
  }
  </>
)

/**
 * What to study more
 * 
 * Use setTimeout/setInterval inside useEffect
 * 
 * Javascript Objects/Primitives
 * 
 * Array.prototype, how to add functions and override functions
 * 
 * Update the count each 1 second using useEffect and setInterval
 * Sporty Group
 */

/*
First Question
Counter in React for each 1 second
*/

export function App(props) {
  const [count, setCount] = useState(0)

  useEffect(() => {
    const interval = setInterval(() => {
      setCount(count + 1)
    }, 1000)

    // It was missing during the interview
    return () => {
      clearInterval(interval)
    }
  }, [count])

  return (
    <div className='App'>
    <h1>Count {count}</h1>
    </div>
  );
}

/**
 * Second Question
 * Implement an inverse forEach such as you can call it like this
 * arr.forEachInverse((element) => console.log(element))
 * 
 */

// We need to start putting our function into Array.prototype
/**
 * A note here is that we need to use a regular function instead
 * a arrow function. Because arrow function doesn't have their own
 * 'this' context, they inherit the value from their surrounding lexical scope
 */
Array.prototype.forEachInverse = function(callback) {
  for (let i = this.length - 1; i >= 0; i--) {
      callback(this[i], i)
  }
}

const arr = [1, 2, 3, 4, 5]

arr.forEachInverse((element, index) => {
  console.log(element, index)
})

/**
 * Third Question
 * Types in Javascript
 * 
 * https://morioh.com/a/620129429e84/top-155-javascript-interview-questions-and-answers-for-2021
 * 
 * https://www.interviewbit.com/javascript-interview-questions/
 */