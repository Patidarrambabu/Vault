import React, { useState, useEffect } from 'react'
import Filter from './components/filter'
import PersonForm from './components/form'
import Persons from './components/person'
import service from './service/persons'
import Message from './components/message'


const App = () => {
  const [persons, setPersons] = useState([])
  const [error, setError] = useState({ message: null, color: 'red' })

  const hooks = () => {
    service.getAll()
      .then((response) => {
        console.log(response)
        setPersons(response)
      })
      .catch(error => {
        console.log('error', error)
        setError({
          message: 'some error happened...', color: 'red'
        })
        setTimeout(() => {
          setError({ message: null, color: 'green' })
        }, 2000)
      })
  }
  useEffect(hooks, [])

  return (
    <div>
      <h2>Phonebook</h2>
      <Message error={error} />
      <Filter persons={persons} />

      <h3>Add a new</h3>

      <PersonForm persons={persons} setPersons={setPersons} setError={setError} />

      <h3>Numbers</h3>

      <Persons persons={persons} setPersons={setPersons} setError={setError} />
    </div>
  )
}

export default App
