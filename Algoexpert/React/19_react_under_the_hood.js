/**
 * React create Element,
 * returns a react element object (isn't a DOM node)
 * 
 */
return (
  <h1>Hello World</h1>
)
->
React.createElement(
  "h1",
  null,
  "Hello World"
)
->
{
  $$typeof: Symbol.for("react.element"),
  key: null,
  props: { children: "Hello World"},
  ref: null,
  type: "h1"
}

// That's right if we use it
ReactDOM.render(
  {
      $$typeof: Symbol.for("react.element"),
      key: null,
      props: { children: "Hello World"},
      ref: null,
      type: "h1"
  },
  document.getElementById('root')
)

/**
 * Virtual DOM
 * - The data structure created by nesting React Elements
 * - Faster to update than the real DOM
 *    - Nothing needs to change on screen
 * Is faster because we're updating a JS object
 * 
 * Reconciliation 
 *    - Algorithm that React uses to check what changed
 * 
 * react calculates the diff of the virtual DOM (previous and current) after updates, to check the minimum number of nodes to update
 * - If Root Nodes are different types, delete tree and rebuild
 * - If attributes changed, update existing nodes
 * - Recurse on all children
 * 
 * React FIber - A modern rewrite of the reconciliation algorithm
 *  - Has more performance in things like animations
 * 
 * Keys 
 * - When recursing on children, react assumes elements are in the same order
 *    - Keys allow u to tell react how the order changed
 */