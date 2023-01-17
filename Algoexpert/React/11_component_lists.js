// Welcome to our Playground!

function App() {
  const [items, setItems] = useState([]);
  const [newItem, setNewItem] = useState('');

  /**
   * The only important thing here is to put a key for each element of the list
   * to help React keep track of those elements
   * if the list changes, React can easily know which elements need to be mounted, updated and unmounted
   * 
   */
  return (
    <>
      <ul>
        {items.map(item => { 
          return <li key={item}>{item}</li>;
        })}
      </ul>

      <input type="text" value={newItem} onChange={event => setNewItem(event.target.value)} />

      <button
        onClick={() => {
          setItems([...items, newItem]);
          setNewItem('');
        }}>
        Add List Item
      </button>
    </>
  );
}