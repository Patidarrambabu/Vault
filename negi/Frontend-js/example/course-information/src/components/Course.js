
const Content = ({ parts }) => {
    let count = parts.reduce((s, e) => s + e.exercises, 0);
    return (
        <div>
            {
                parts.map((e) => <p key={e['id']} > {e['name']} {e['exercises']}</p>)
            }
            <h4>total of {count} exercises</h4>
        </div >
    )
}

const Course = ({ course }) => {
    return (
        course.map((e) =>
        (<div>
            <h2>{e['name']}</h2>
            <Content parts={e['parts']} />
        </div >)
        )
    );
}


export default Course;