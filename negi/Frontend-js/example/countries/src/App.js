import { useState, useEffect } from "react"
import axios from 'axios'
import Search from "./components/search"

function App() {

  const [data, setData] = useState([])


  const fetchData = () => {
    // console.log('api call')
    axios.get('https://restcountries.eu/rest/v2/all').then((response) => {
      // console.log(response.data)
      setData(response.data)
    })
  }
  useEffect(fetchData, [])

  return (
    <div>
      <Search data={data} />
    </div>
  );
}

export default App;
