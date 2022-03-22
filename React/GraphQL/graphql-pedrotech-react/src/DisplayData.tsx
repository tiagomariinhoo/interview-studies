import React, { useState } from 'react'
import { useQuery, gql, useLazyQuery, useMutation } from "@apollo/client"

const QUERY_ALL_USERS = gql`
  query GetAllUsers {
    users {
      id
      name
      age
      username
    }
  }
`

const GET_MOVIE_BY_NAME = gql`
  query GetMovieByName($name: String!) {
    movie(name: $name) {
      name
      yearOfPublication
    }
  }
`

interface User {
  id: number;
  name: string;
  age: number;
  username: string;
}

const CREATE_USER_MUTATION = gql`
    mutation CreateUser($input: CreateUserInput!) {
      createUser(input: $input) {
        name,
        id
      }
      
    }
  `

/**
 * Check Mutation and Queries
 */

const DisplayData = () => {
  const [movieSearched, setMovieSearched] = useState("")

  //Create User Form
  const [name, setName] = useState("")
  const [age, setAge] = useState(0)
  const [username, setUsername] = useState("")
  const [nationality, setNationality] = useState("")

  const { data, loading, error } = useQuery(QUERY_ALL_USERS);
  const [fetchMovie, { data: movieSearchedData, error: movieError }] = useLazyQuery(GET_MOVIE_BY_NAME)

  const [createUser] = useMutation(CREATE_USER_MUTATION)

  if (loading) {
    return <h1>DATA IS LOADING....</h1>
  }

  if (data) {
    console.log('Data', data)
  }

  if (error) {
    console.log(error)
  }

  if (movieError) {
    console.log('Movie error', movieError)
  }

  return (
    <div style={{ display: "flex", alignItems: 'center', justifyContent: 'center', flexDirection: 'column' }}>
      <div>
        <input onChange={(evt) => { setName(evt.target.value) }} type="text" placeholder="Name..." />
        <input onChange={(evt) => { setUsername(evt.target.value) }} type="text" placeholder="Username..." />
        <input onChange={(evt) => { setAge(Number(evt.target.value)) }} type="number" placeholder="Age..." />
        <input onChange={(evt) => { setNationality(evt.target.value.toUpperCase()) }} type="text" placeholder="Nationality..." />
        <button onClick={() => {createUser({variables: {
          input: {
            name,
            username,
            age,
            nationality
          }
        }})}}>Create User</button>
      </div>
      {data && data.users.map((user: User) => {
        return (
          <div key={user.id}>
            <h1>Name: {user.name}</h1>
          </div>
        )
      })}
      <div>
        <input
          type="text"
          placeholder="Interstellar..."
          onChange={(evt) => { setMovieSearched(evt.target.value) }}
        />
        <button onClick={() => fetchMovie({
          variables: {
            name: movieSearched
          }
        })}>Fetch Data</button>
        <div>
          {movieSearchedData && <div>{`MovieName: ${movieSearchedData.movie.name}`}</div>}
        </div>
      </div>
    </div>

  )
}

export default DisplayData