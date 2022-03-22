import { useState } from 'react'
import { ApolloClient, InMemoryCache, ApolloProvider, useQuery } from '@apollo/client'
import './App.css'
import DisplayData from './DisplayData'

function App() {
  const client = new ApolloClient({
    cache: new InMemoryCache(),
    uri: `http://localhost:4000/graphql` //I can test use a public api as well
  })

  return (
    <ApolloProvider client={client}>
      <DisplayData />
    </ApolloProvider>
  )
}

export default App
