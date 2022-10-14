import React, { useState } from 'react'
import Details from './detailed_view'
import CountryList from './country_list'

const Search = ({ data }) => {

    const [term, setTerm] = useState('')
    const [filterData, setFilterData] = useState([])

    const onChange = (event) => {
        setTerm(event.target.value.toLowerCase())
        // console.log(event.target.value.toLowerCase())
        filter(event.target.value)
    }

    const onCLick = (event) => {
        console.log(event.target.id)
        filter(event.target.id)
    }

    function filter(text) {
        const s = text.toLowerCase();
        if (text !== '') {
            var list = []
            data.forEach((e) => {
                if (e["name"].toLowerCase().includes(s)) {
                    list.push(e)
                }
            })
            setFilterData(list)
        } else {
            setFilterData([])
        }
    }

    return (
        <div>
            <div>
                find countries <input onChange={onChange} value={term} />
            </div>
            {
                filterData.length === 1 ?
                    <Details data={filterData[0]} />
                    : filterData.length <= 10 ?
                        <CountryList filterData={filterData} onClick={(event) => onCLick(event)} />
                        :
                        <div>
                            Too many matches, specify another filter
                        </div>
            }
        </div>

    )
}

export default Search;