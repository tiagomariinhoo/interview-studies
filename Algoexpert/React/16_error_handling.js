// Welcome to our Playground!

/**
 * React Component that catches errors in child components, preventing crashs from a single error
 * 
 * Error boundaries must be class-based components in order to take advantage of two lifecycle methods:
 * static getDerivedStateFromError(error) - called during the render phase and updates the current state of the component 
 * componentDidCatch(error, errorInfo) - called during the commit phase for the purpose of side-effects related to the caught error
 * 
 */

// Will only get the errors in components below it
function App() {
  return (
    <>
      <h1>Hello World</h1>
      <ErrorBoundary fallback={<h1>There was an error</h1>}>
        <Buggy />
      </ErrorBoundary>
    </>
  );
}

function Buggy() {
  // Throw new error here, will be get by getDerivedStateFromError
  throw new Error('error');
  return <h1>Buggy</h1>;
}


class ErrorBoundary extends Component {
  state = {hasError: false};

  /**
    We can't thrown an error here because the ErrorBoundary
    just can get the errors from the children, not itself
  */
  
  // Is going to take in some error
  static getDerivedStateFromError(error) {
    return {hasError: true};
  }

  // When we render this component, there are two options
  /**
    Either is an error or not
*/

  componentDidCatch(error, errorInfo) {
    logErrorToServer(error, erorrInfo)
  }
  
  render() {
    if (this.state.hasError) {
      return this.props.fallback;
    }
    return this.props.children;
  }
}