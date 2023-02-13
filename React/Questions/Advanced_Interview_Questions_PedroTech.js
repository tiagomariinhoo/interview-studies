/**
 * https://youtu.be/-UkV6To-7_g
 */

/**
 * 1 - How exactly does the React Reconciliation algorithm work and how it's beneficial for the creation
 * of a react application
 * 
 * - The reason is that if u're able to answer that, u kind understand why u're using
 * react instead pure javascript or another framework.
 * 
 * So reconciliation algorithm is the process by which React updates its components
 * based on its props and states. There's the normal DOM Tree with all the elemnts
 * but react there's another concept which is the Virtual DOM, so React Keep Track of two
 * different versions of the DOM
 * 
 * So whenever there's a change in the component what react does is it kind of
 * compares the virtual DOM tree of the updated component with the
 * virtual DOM tree from the previous render, so if there's any difference
 * between both virtual DOM trees, react will trigger and update
 * the actual DOM, to optmize React calculate the min required amount of changes
 * in the actual DOM in order to make the DOM sync with the virtual DOM
 * 
 * This algorithm reduces the amount of DOM Manipulations which further improves
 * performance
 * Where reconciliation become inneficient?
 * 
 * 2 - How does React handle asynchronous updates and how this could
 * resolve potentioal race conditions?
 * 
 * - Basically it's about how react works internally, how React uses batching to
 * resolve its problems,
 * so, the batching mechanism is basically a way that react groups a bunch of updates
 * that occur within the same render cycle into just a single update,
 * with a lot of States changes and some props changes as well and they all happen
 * in the same render cycle it's importnat that you handle those changes as a 
 * single update, to avoid a lot of rerenders
 * 
 * How it can resolve what is known as race conditions in react,
 * race conditions are a situation where two or more components try to update
 * the same state at the same time, which obviously it can potentially lead
 * to unwanted behavior
 * 
 * 3 - How do you solve optimization problems in react and is it good to always optimize?
 * Yes, its always good 
 * Using React Developer Tools Components/Profiler
 * Using Profiler you can see a recorded action inside of your application
 * and see how your components are working and performing
 * 
 * I can record my actions and see how much time is spent for each action
 */