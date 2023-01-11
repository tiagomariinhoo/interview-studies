import React, { useState, useRef, forwardRef, useImperativeHandle } from 'react';

// Since is a custom component, when we need to pass a ref here, we need to use forwardRef
const Counter = forwardRef(function Counter(props, ref) {
  const [count, setCount] = useState(0)
  
  useImperativeHandle(ref, () => {
    // The returned object is going to be the current value of the ref
    return {
      reset: () => setCount(0)
    }
  }, []); // Dependency array

  return (
    <>
      <button onClick={() => setCount(count + 1)}>
      Increment
      </button>
      <p>Count: {count}</p>
    </>
  );
});

const CustomInput = forwardRef(function CustomInput(props, ref) {
  const [value, setValue] = useState('')

   useImperativeHandle(ref, () => {
    // The returned object is going to be the current value of the ref
    return {
      reset: () => setValue('')
    }
  }, []); // Dependency array

  return (
    <input {...props} value={value} onChange={(evt) => setValue(evt.target.value)} style={{color: 'red'}} />
  )
})

// Imperative React
// useImperativeHandle
export function App() {
  /**
  Now, let's think how the button reset will be able to reset the state of both components (Counter and CustomInput)

  1 - Lift the state up and pass for the components by props. But this separates the state from the component that's actually related to, so doesn't makes sense
  So we want an imperative way to control those components

  We probably have to use a ref, but remember:
  When we use a ref, the current value is going to be set equal to a DOM node
  and DOM nodes know nothing about React State, they are handled by React

  We want to send the ref value to reset the state into the child components
  We dont want the ref to be equal to a DOM Node, we want to send as the ref current  value,
  to reset the state, and we can do that using another hook, called useImperativeHandle

  It says what the ref current value is actually going to be set to.

  useImperativeHandle is just a hook that allows us to use the components that we have refs to, in an imperative way.
  So we are calling some functions of the components, or really any data that we pass up to the ref. 
   */

  const counterRef = useRef();
  const customInputRef = useRef();

  return (
    <>
      <Counter ref={counterRef}/>
      <CustomInput ref={customInputRef} placeholder="Type Something..." />
      <button onClick={() => {
        counterRef.current.reset();
        customInputRef.current.reset();
      }}>Reset</button>
    </>
  )
}

// Log to console
console.log('Hello console')