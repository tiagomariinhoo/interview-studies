// IMPORTANT CLASS
import React, {useState,useMemo, memo, useCallback} from 'react';

// export function App(props) {
//   return (
//     <div className='App'>
//       <h1>Hello React.</h1>
//       <h2>Start editing to see some magic happen!</h2>
//     </div>
//   );
// }

export function App(props) {
  const [num, setNum] = useState(10);
  const [logValue, setLogValue] = useState('');

  /**
   * For example, if we don't use the useMemo here and call the function directly there in the component, doing like:
   * Fib {num} is {fib(num)}, everytime that this component is rerendered, this function will be called again
   * So, using useMemo, if the NUM doesn't change, we will just use the previous value from the last render
   */

  /**
   * We're passing a function as a Prop for MyButton
   * in every render of the app component, we create a new function that does the same thing
   * So we can use an useMemo, that will just create a new one, when logValue changes
   * 
   * Instead useMemo like this, we can use an useCallback
   */

  // const onClickLog = useMemo(() => {
  //   return () => {
  //     console.log(logValue)
  //   }
  // }, [logValue])

  /**
   * Another thing is use
   * const MyButton = lazy(() => import('./MyButton'))
   * So MyButton wil only be imported once, and will just be imported when we really use this variable MyButton
   * 
   * And remember to use Suspense for conditional rendering
   * 
   * <Suspense fallback={<div>Loading...</div>}>
   *  <MyButton... />
   * </Suspense>
   * 
   */

  const onClickLog = useCallback(() => {
    console.log(logValue)
  }, [logValue])

  const fibValue = useMemo(() => {
    return fib(num);
  }, [num]);

  return (
    <>
      <h1>
        Fib {num} is {fibValue}
      </h1>
      <input type="number" value={num} onChange={event => setNum(parseInt(event.target.value))} />

      <input 
        type="text"
        value={logValue}
        onChange={(event) => setLogValue(event.target.value)}
      />

      <MyButton onClick={onClickLog}/>
    </>
  );
}

function fib(n) {
  if (n === 2) return 1;
  if (n === 1) return 0;
  return fib(n - 1) + fib(n - 2);
}

// We can see here that if we change the setLogValue, this button will be rerender everytime, then we can use 'memo'
// Memo returns a higher order component, so, when the props hasn't change, just use the previous version of this component
// We can also customize Memo (see the documentation)
export default memo(function MyButton(props) {
   console.log('Render')

   /**
    * We can use those lines of code to test the function passing by useMemo,
    * if we pass without useMemo, we can see that this component is being rerender everytime
    */
  //  const startTime = new Date();
  //  while(new Date() - startTime < 1000) {}

  return (
    <button onClick={() => console.log('Log Value')}>
    LogValue
    </button>
  )
})