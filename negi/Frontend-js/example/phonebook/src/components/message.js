const Message = ({ error }) => {
    if (error.message === null)
        return null
    const footerStyle = {
        color: error.color,
        background: 'lightgrey',
        fontSize: 20,
        borderStyle: 'solid',
        borderRadius: 5,
        padding: 10,
        marginBottom: 10,
    }


    return (
        <div style={footerStyle} >
            {error.message}
        </div >
    )
}

export default Message