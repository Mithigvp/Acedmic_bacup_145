const subjects = [
  { key: 'programming', label: 'Programming in C', maxMarks: 100 },
  { key: 'dbms', label: 'Database Management System', maxMarks: 100 },
  { key: 'webTechnology', label: 'Web Technology', maxMarks: 100 },
  { key: 'computerNetwork', label: 'Computer Networks', maxMarks: 100 },
  { key: 'operatingSystem', label: 'Operating System', maxMarks: 100 },
  { key: 'softwareEngineering', label: 'Software Engineering', maxMarks: 100 },
]

const Marksheet = ({ report }) => {
  const student = report.student
  const marks = report.marks

  const totalMarks = subjects.reduce((sum, subject) => {
    return sum + (Number(marks[subject.key]) || 0)
  }, 0)

  const percentage = Math.round((totalMarks / 600) * 100)
  const cgpa = (percentage / 100) * 10
  const finalResult =
    totalMarks >= 240 && subjects.every((subject) => (Number(marks[subject.key]) || 0) >= 35)
      ? 'Pass'
      : 'Fail'

  return (
    <div id="marksheet" className="marksheet">
      <h2>Student Marksheet</h2>
      <div className="student-info">
        <p>
          <b>Student Name:</b> <span>{student.name || 'N/A'}</span>
        </p>
        <p>
          <b>Email:</b> <span>{student.email || 'N/A'}</span>
        </p>
        <p>
          <b>Age:</b> <span>{student.age || 'N/A'}</span>
        </p>
        <p>
          <b>Course:</b> <span>{student.course || 'N/A'}</span>
        </p>
      </div>

      <table>
        <thead>
          <tr>
            <th>Subject</th>
            <th>Max Marks</th>
            <th>Obtained</th>
            <th>Status</th>
          </tr>
        </thead>

        <tbody>
          {subjects.map((subject) => {
            const obtained = Number(marks[subject.key]) || 0
            const status = obtained >= 35 ? 'Pass' : 'Fail'

            return (
              <tr key={subject.key}>
                <td>{subject.label}</td>
                <td>{subject.maxMarks}</td>
                <td>{obtained}</td>
                <td className={status === 'Pass' ? 'status-pass' : 'status-fail'}>{status}</td>
              </tr>
            )
          })}
        </tbody>

        <tfoot>
          <tr>
            <th colSpan="2">Total Marks</th>
            <th>{totalMarks}</th>
            <th>/ 600</th>
          </tr>
          <tr>
            <th colSpan="2">Percentage</th>
            <th colSpan="2">{percentage}%</th>
          </tr>
          <tr>
            <th colSpan="2">CGPA</th>
            <th colSpan="2">{cgpa.toFixed(2)}</th>
          </tr>
          <tr>
            <th colSpan="2">Final Result</th>
            <th colSpan="2" className={finalResult === 'Pass' ? 'status-pass' : 'status-fail'}>
              {finalResult}
            </th>
          </tr>
        </tfoot>
      </table>
    </div>
  )
}

export default Marksheet