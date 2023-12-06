import React, { useState, useEffect, useRef } from 'react'

const App = () => {
  const [text, setText] = useState('')
  const timeoutRef = useRef(null)

  useEffect(() => {
    clearTimeout(timeoutRef.current)
    timeoutRef.current = setTimeout(() => {
      console.log('Saving Text...', text)
    }, 500)
  }, [text])

  const handleChange = (evt) => {
    setText(evt.target.value)
  }

  return (
    <div>
      <input name="input" onChange={handleChange}/>
    </div>
  )
}