import React, { useState } from 'react'
import service from '../service/persons'

const PersonForm = ({ persons, setPersons, setError }) => {

    const [newName, setNewName] = useState('')
    const [newNumber, setNewNumber] = useState('')

    const handleNameChange = (event) => {
        console.log(event.target.value)
        setNewName(event.target.value)
    }
    const handleNumberChange = (event) => {
        console.log(event.target.value);
        setNewNumber(event.target.value)
    }

    const addNumber = (event) => {
        event.preventDefault()
        var exists = false
        var p
        persons.forEach(function (e) {
            if (e['name'].toLowerCase() === newName.toLowerCase()) {
                exists = true
                p = e
            }
        })
        if (!exists) {
            const newContact = {
                name: newName,
                number: newNumber
            }
            service.addContact(newContact)
                .then(response => {
                    console.log(response)
                    setPersons(persons.concat(response))
                    setError({ message: `Added ${newName}`, color: 'green' })
                    setTimeout(() => {
                        setError({ message: null, color: 'green' })
                    }, 2000)
                }
                ).catch(error => {
                    setError({ message: error.response.data.error, color: 'red' })
                    setTimeout(() => {
                        setError({ message: null, color: 'green' })
                    }, 2000)
                })
        } else {
            if (window.confirm(newName + ' is already added to phonebook , replace the old number with a new one?')) {
                const newContact = {
                    name: p['name'],
                    number: newNumber
                }
                // console.log(newContact)
                service.update(p.id, newContact)
                    .then(response => {
                        setPersons(persons.map(e => e.id !== response.id ? e : response))
                        setError({ message: `Updated ${newName}`, color: 'green' })
                        setTimeout(() => {
                            setError({ message: null, color: 'green' })
                        }, 2000)
                    })
                    .catch(error => {
                        console.log('error', error)
                        setError({ message: `Information of ${newName} has already been removed from server`, color: 'red' })
                        setTimeout(() => {
                            setError({ message: null, color: 'green' })
                        }, 2000)
                    })
            }
        }
        setNewName('')
        setNewNumber('')
    }

    return (
        <div>
            <form onSubmit={addNumber}>
                <div>
                    name: <input value={newName} onChange={handleNameChange} />
                </div>
                <div>
                    number: <input value={newNumber} onChange={handleNumberChange} />
                </div>
                <div>
                    <button type="submit">add</button>
                </div>
            </form>
        </div>
    )
}

export default PersonForm