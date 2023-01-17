/**
 * Starting from React.StrictMode
 * -> Will help to find issues in your code, giving some warnings when needed.
 * There's a double invocation that StrictMode generates
 * 
 * In development mode, the functions and components will be invoked twice to avoid side effects
 * Will help u to doesn't have side effects in places that u shouldn't have them
 * 
 * We can also use Profiler from React
 * import { Profiler } from 'react', and we can wrap some components there
 * 
 * Another thing is React Dev Tools
 * 
 * We can see on browser, components and Profiler tabs
 * 
 * Components Tab
 * -> Similar to the elements Tab but showing React Components, we can click on components and see infos like: props, hooks, rendered by, source etc
 * -> We can also see the code
 * 
 * Profiler Tab
 * -> we can click on record button and check the graph to check how much time take each component etc
 * 
 * React.StrictMode
 * -> Provide warnings when using deprecated functions or lifecycle mthods
 * -> Double invocation some functions to help to find potential bugs related to side-effects
 * 
 * React.Profiler
 * -> Track how often component renders
 * 
 * React DevToolts
 * -> Extension for browser
 */

import { useState, Profiler, useDebugValue } from 'react'

let renderCount = 0;

export default function App() {
  renderCount++; // We can see that this gonna be twice, if we using StrictMode

  console.log('Rendering')

  // We can wrap the elements using Profiler
  /**
   * Lets u keep track of when a component is rendering, only works in development mode
   * In production mode, Profiler will be ignored
   * 
   * If we run the code, we can see the console log being:
   * Rendering
   * Commit
   */
  return (
    <Profiler id="App" onRender={() => console.log('commit')}>
      <Counter initialValue={5}/>
      <Counter />
    </Profiler>
  )
}

function Counter({initialValue = 0}) {
  // const [count, setCount] = useState(initialValue)
  const [count, setCount] = useMyState(initialValue)

  // Make this component being slower to test Profiler from React Dev Tools, check how much time take to render it there
  const startTime = Date.now();
  while(new Date() - startTime < 500) {}

  return (
    <>
      <button onClick={() => setCount(count + 1)}>
        Increment
      </button>
      <p>Count: {count}</p>
    </>
  )
}

function useMyState(initialValue = 0) {
  // useDebugValue('hello world') we can use that with react dev tools to add some value there
  return useState(initialValue);
}