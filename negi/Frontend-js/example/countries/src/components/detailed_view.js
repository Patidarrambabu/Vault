import axios from "axios"
import { useState, useEffect } from "react"

const Details = ({ data }) => {


    const [weather, setWeather] = useState({})
    const fetchWeather = () => {
        axios.get('http://api.weatherstack.com/current?access_key=' + process.env.REACT_APP_API_KEY + '&query=' + data["name"]).then((Response) => {
            setWeather(Response.data["current"])
            console.log(Response.data["current"])
        })
    }
    // eslint-disable-next-line
    useEffect(fetchWeather, [])

    return (
        <div>
            <div>
                <h1>{data["name"]}</h1>
                <div>capital {data["capital"]}</div>
                <div>population {data["population"]}</div>
            </div>

            <div>
                <h3>languages</h3>
                <ul>
                    {data["languages"].map((e) => <li key={e["iso639_1"]}>{e["name"]}</li>)}
                </ul>
            </div>
            <div>
                <img src={data["flag"]} alt="flag" width="100px" />
            </div>
            <div>
                <h3>Weather in {data["name"]}</h3>
                <div>
                    <p><b>temperature: </b>{weather["temperature"]} Celcius</p>
                    <img src={weather["weather_icons"]} alt="weather-icon" />
                    <p><b>wind: </b>{weather["wind_speed"]} mph directions {weather["wind_dir"]}</p>
                </div>
            </div>
        </div>
    )
}

export default Details