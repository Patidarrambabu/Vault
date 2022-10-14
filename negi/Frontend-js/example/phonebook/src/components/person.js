import service from "../service/persons"

const Persons = ({ persons, setPersons, setError }) => {


    const onClick = (event) => {
        const p = persons.filter(e => {
            return e.id.toString() === event.target.id
        })
        if (window.confirm(`Delete ${p[0].name} ?`)) {
            service.removeContact(event.target.id)
                .then(response => {
                    console.log(response)
                    setError({ message: `Deleted ${p[0].name}`, color: 'green' })
                    setTimeout(() => {
                        setError({ message: null, color: 'red' })
                    }, 2000)
                })
                .catch(error => {
                    console.log('error', error)
                    setError({ message: `Information of ${p[0].name} has already been removed from server`, color: 'red' })
                    setTimeout(() => {
                        setError({ message: null, color: 'green' })
                    }, 2000)
                })
            const newList = persons.filter(e => e.id.toString() !== event.target.id)
            setPersons(newList)
        }
    }

    return (
        <div>
            {
                persons.map(
                    (e, i) =>
                        <div key={e.name + i}>
                            {e.name} {e.number}
                            <button id={e.id} onClick={onClick} > delete</button>
                        </div >
                )
            }
        </div >
    )
}

export default Persons