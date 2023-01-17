
/**
 * Just to pass value between components without use props, avoid prop drilling
 */

/**
 * in UserContext.js
 */
import { createContext } from 'react'

export const UserContext = createContext({
  name: null, 
  course: null
})

export function UserContextProvider({children}) {
  const [user, setUser] = useState(conner)

  return (
    <UserContext.Provider value={user}>
      {children}
    </UserContext.Provider>
  )
}

/**
 * in App.js
 */

export default function App() {
  return (
    <>
      <UserContextProvider value={user}>
        {/* ... */}
      </UserContextProvider>
    </>
  )
}

/**
 * in components
 */

function Component() {
  const { user } = useContext(UserContext)
  return(
    <>
    </>
  )
}