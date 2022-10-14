
const CountryList = ({ filterData, onClick }) => {
    return (
        filterData.map(
            (e, i) => <div key={e.name + i}>
                <div>
                    {e.name}
                    <button onClick={onClick} id={e.name}>show</button>
                </div>
            </div>
        )
    )
}

export default CountryList