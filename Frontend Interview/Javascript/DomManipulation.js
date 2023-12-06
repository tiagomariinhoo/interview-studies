// Sometimes you might need to access to the DOM elements managed by React, to focus a node, scroll etc
// There's no built-in way to do those things in React, so you will need a ref to the DOM node

/**
 * Important things:
 * How to access a DOM node, managed by React with the ref attribute
 * How the ref JSX attribute relates to the useRef hook
 * How to access another component's DOM node
 * In which cases it's safe to modify the DOM managed by React
 */

// To access a DOM node managed by React, we need to use an useRef hook

import { forwardRef, useRef } from 'react'

const myRef = useRef(null)

return (
  <div ref={myRef}>

  </div>
)

/**
 * The useRef hook returns an object with a single property called current
 * Initially, myRef.current will be null
 * When React creates a DOM node for this <div>, React will put a reference to this node into
 * myRef.current
 * And we can use any browser APIs:
 * myRef.current.scrollIntoView()
 */

// ACCESSING ANOTHER COMPONENT's DOM NODES
/**
 * Just a note, if you try to put a ref into a created component
 * if you have <MyComponent ref={myRef} />
 * myRef will be null
 * 
 * This happens because by default React doesn't let a component access the DOM nodes of other components
 * Components that want to expose their DOM ndoes have to opt in to that behavior
 * We need to use forwardRef
 */

const MyInput = forwardRef((props, ref) => {
  return <input {...props} ref={ref} />
})