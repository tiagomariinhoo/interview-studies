// https://reactjs.org/docs/portals.html

function App() {
  const [isHidden, setIsHidden] = useState(true);
  return (
    <>
      <div className="container">
        <button onClick={() => setIsHidden(!isHidden)}>
          {isHidden ? 'Show Modal' : 'Hide Modal'}
        </button>
        {isHidden || <Modal />}
      </div>

      <p className="other">Other Content</p>
    </>
  );
}

// Move this to a different location in the tree
// The most common use is when u need to change the modal locations for example and tooltips too
function Modal() {
  return createPortal(<p className="modal">Modal</p>, document.getElementById('portal-root'));
}