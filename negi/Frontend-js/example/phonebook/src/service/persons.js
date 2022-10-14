import axios from 'axios'

const baseUrl = '/api/persons'

const getAll = () => {
    return axios.get(baseUrl).then(response => response.data)
}

const addContact = newContact => {
    return axios.post(baseUrl, newContact).then(response => response.data)
}

const removeContact = id => {
    // console.log(`${baseUrl}/1`)
    return axios.delete(`${baseUrl}/${id}`).then(response => response)

}

const update = (id, newObj) => {
    return axios.put(`${baseUrl}/${id}`, newObj).then(response => response.data)
}

const service = {
    getAll,
    update,
    addContact,
    removeContact
}

export default service