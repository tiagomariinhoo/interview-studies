import React, { useState } from 'react'
import { useQuery, gql, useLazyQuery } from "@apollo/client"

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

const DisplayData = () => {
  const [movieSearched, setMovieSearched] = useState("")
  const { data, loading, error } = useQuery(QUERY_ALL_USERS);
  const [fetchMovie, { data: movieSearchedData, error: movieError }] = useLazyQuery(GET_MOVIE_BY_NAME)

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
    <div>
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
        <button onClick={() => fetchMovie({variables: {
          name: movieSearched
        }})}>Fetch Data</button>
        <div>
          {movieSearchedData && <div>{`MovieName: ${movieSearchedData.movie.name}`}</div>}
        </div>
      </div>
    </div>

  )
}

export default DisplayData