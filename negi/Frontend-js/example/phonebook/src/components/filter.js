import React, { useState } from 'react';

const Filter = ({ persons }) => {
    const [personToShow, setPersonToShow] = useState([])
    const [searchTerm, setSearchTerm] = useState('')

    const handleChange = (event) => {
        setSearchTerm(event.target.value)
        if (event.target.value !== '') {
          setPersonToShow(persons.filter((e) => e['name'].toLowerCase().startsWith(event.target.value.toLowerCase())))
        } else {
            setPersonToShow([])
        }

        personToShow.map((e) => console.log(e.name))
    }
    return (
        <div>
            <div>
                filter shown with  <input value={searchTerm} onChange={handleChange} />
            </div>
            {
                personToShow.map(
                    (e, i) => <div key={e.name + i}>{e.name} {e.number}</div>
                )
            }
        </div>
    )
}

export default Filter