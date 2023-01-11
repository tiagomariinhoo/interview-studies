8 - Refs

/**
 * https://www.algoexpert.io/frontend/react-crash-course/refs
 * 
 * Ref -> A react value specific to an instance of a component that persists between renders
 * different from state, update the value doesn't cause a rerender
 * 
 * useRef -> A react hook for creating a ref, will create a simply an object with a current
 * to set the value
 * 
 * React.forwardRef -> An important function used by a custom component (like, u can create
 * a MyInput and use forwardRef to pass a ref by the parent) to forward a ref attribute on 
 * to a child element. Is a higher-order component function, meaning it takes in a component
 * and returns a new one
 * 
 * function Parent() {
 *  const ref = useRef(null)'
 *  return <Child ref={ref}> This child has a ref </Child>
 * }
 * 
 * const child = forwardRef(function (props, ref) {
 *  return <div ref={ref}>{props.children}</div>
 * })
 */
import React, { useState, useRef } from 'react';

export function App(props) {
  // const [seconds, setSeconds] = useState(0)
  // // const [timerID, setTimerID] = useState(null)
  // const timerID = useRef(null) // To don't rerender when change value

  // const startTimer = () => {
  //   timerID.current = (setInterval(() => {
  //     setSeconds(currSeconds => currSeconds + 1);
  //   }, 1000)) //1s delay
  // }

  // const stopTimer = () => {
  //   clearInterval(timerID.current)
  // }

// Be careful that inputRef just won't be null after the render happens
  const inputRef = useRef(null)
  const focusInput = () => {
    // Focus from the DOM, js funct
    inputRef.current.focus();
  }

  return (
    <div className='App'>
      <input ref={inputRef} />
      <button onClick={focusInput}>Focus</button>
    </div>
  );
}

// Log to console
console.log('Hello console')