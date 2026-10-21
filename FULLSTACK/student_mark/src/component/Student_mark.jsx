const Student_mark = ({ student, setStudent, marks, setMarks }) => {
  const handleStudentChange = (event) => {
    const { name, value } = event.target
    setStudent((prev) => ({ ...prev, [name]: value }))
  }

  const handleMarkChange = (event) => {
    const { name, value } = event.target
    setMarks((prev) => ({ ...prev, [name]: value }))
  }

  return (
    <div className="container">
      <h1>Student Marksheet</h1>

      <div className="section">
        <h2>Student Information</h2>
        <div className="form-grid">
          <div className="field-group">
            <label htmlFor="name">Student Name</label>
            <input
              id="name"
              name="name"
              type="text"
              value={student.name}
              onChange={handleStudentChange}
              placeholder="Enter student name"
            />
          </div>

          <div className="field-group">
            <label htmlFor="email">Email</label>
            <input
              id="email"
              name="email"
              type="email"
              value={student.email}
              onChange={handleStudentChange}
              placeholder="Enter email"
            />
          </div>

          <div className="field-group">
            <label htmlFor="age">Age</label>
            <input
              id="age"
              name="age"
              type="number"
              value={student.age}
              onChange={handleStudentChange}
              placeholder="Enter age"
            />
          </div>

          <div className="field-group">
            <label htmlFor="course">Study</label>
            <select
              id="course"
              name="course"
              value={student.course}
              onChange={handleStudentChange}
            >
              <option value="">Select Course</option>
              <option value="BCA">BCA</option>
              <option value="MCA">MCA</option>
            </select>
          </div>
        </div>
      </div>

      <div className="section">
        <h2>Subject Marks</h2>
        <div className="marks-table">
          <div className="table-header">
            <div>Subject</div>
            <div>Max Marks</div>
            <div>Student Marks</div>
          </div>

          <div className="table-row">
            <label htmlFor="programming">Programming in C</label>
            <span>100</span>
            <input
              id="programming"
              name="programming"
              type="number"
              min="0"
              max="100"
              value={marks.programming}
              onChange={handleMarkChange}
              placeholder="0"
            />
          </div>

          <div className="table-row">
            <label htmlFor="dbms">Database Management System</label>
            <span>100</span>
            <input
              id="dbms"
              name="dbms"
              type="number"
              min="0"
              max="100"
              value={marks.dbms}
              onChange={handleMarkChange}
              placeholder="0"
            />
          </div>

          <div className="table-row">
            <label htmlFor="webTechnology">Web Technology</label>
            <span>100</span>
            <input
              id="webTechnology"
              name="webTechnology"
              type="number"
              min="0"
              max="100"
              value={marks.webTechnology}
              onChange={handleMarkChange}
              placeholder="0"
            />
          </div>

          <div className="table-row">
            <label htmlFor="computerNetwork">Computer Networks</label>
            <span>100</span>
            <input
              id="computerNetwork"
              name="computerNetwork"
              type="number"
              min="0"
              max="100"
              value={marks.computerNetwork}
              onChange={handleMarkChange}
              placeholder="0"
            />
          </div>

          <div className="table-row">
            <label htmlFor="operatingSystem">Operating System</label>
            <span>100</span>
            <input
              id="operatingSystem"
              name="operatingSystem"
              type="number"
              min="0"
              max="100"
              value={marks.operatingSystem}
              onChange={handleMarkChange}
              placeholder="0"
            />
          </div>

          <div className="table-row">
            <label htmlFor="softwareEngineering">Software Engineering</label>
            <span>100</span>
            <input
              id="softwareEngineering"
              name="softwareEngineering"
              type="number"
              min="0"
              max="100"
              value={marks.softwareEngineering}
              onChange={handleMarkChange}
              placeholder="0"
            />
          </div>
        </div>
      </div>
    </div>
  )
}

export default Student_mark