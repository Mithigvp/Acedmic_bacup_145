import { useState } from 'react'
import Student_mark from './component/Student_mark'
import Marksheet from './component/Marksheet'
import Button from './component/Button'

const initialStudent = {
  name: '',
  email: '',
  age: '',
  course: '',
}

const initialMarks = {
  programming: '',
  dbms: '',
  webTechnology: '',
  computerNetwork: '',
  operatingSystem: '',
  softwareEngineering: '',
}

const App = () => {
  const [student, setStudent] = useState(initialStudent)
  const [marks, setMarks] = useState(initialMarks)
  const [report, setReport] = useState(null)

  const handleGenerate = () => {
    setReport({
      student: { ...student },
      marks: { ...marks },
    })
  }

  return (
    <div className="app-shell">
      <Student_mark
        student={student}
        setStudent={setStudent}
        marks={marks}
        setMarks={setMarks}
      />

      <Button onClick={handleGenerate} />

      {report ? <Marksheet report={report} /> : <div className="empty-sheet">Enter student details and click Generate Marksheet.</div>}
    </div>
  )
}

export default App