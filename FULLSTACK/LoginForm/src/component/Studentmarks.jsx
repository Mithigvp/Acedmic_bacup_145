import { useState } from "react";
import '../assets/css/studentmatks.css'


const Studentmarks = () => {
  const [name, setName] = useState("");
  const [age, setAge] = useState("");
  const [study, setStudy] = useState("");
  const [rollno, setRollno] = useState("");

  const [m1, setM1] = useState("");
  const [m2, setM2] = useState("");
  const [m3, setM3] = useState("");
  const [m4, setM4] = useState("");

  const [task, setTask] = useState([]);
   const [editIndex, setEditIndex] = useState(null);

  const submitHandler = (e) => {
    e.preventDefault();

    
    const mark1 = Number(m1);
    const mark2 = Number(m2);
    const mark3 = Number(m3);
    const mark4 = Number(m4);

    
    const total = mark1 + mark2 + mark3 + mark4;

    const percentage = (total / 400) * 100;
    const sgpa = (percentage + 7.5) / 10;

    const newStudent = {
      name,
      age,
      study,
      rollno,
      m1: mark1,
      m2: mark2,
      m3: mark3,
      m4: mark4,
      total,
      percentage: percentage.toFixed(2),
      sgpa: sgpa.toFixed(2),
    };

    if (editIndex !== null) {
      const updatedTask = [...task];
      updatedTask[editIndex] = newStudent;

      setTask(updatedTask);
      setEditIndex(null);
    } else {
      setTask([...task, newStudent]);
    }
  
    setName("");
    setAge("");
    setStudy("");
    setRollno("");
    setM1("");
    setM2("");
    setM3("");
    setM4("");
  };

   
  const updateNotes = (idx) => {
    const student = task[idx];

    setName(student.name);
    setAge(student.age);
    setStudy(student.study);
    setRollno(student.rollno);
    setM1(student.m1);
    setM2(student.m2);
    setM3(student.m3);
    setM4(student.m4);

    setEditIndex(idx);
  };

  const deleteNotes = (idx) => {
    const copyTask = [...task];
    copyTask.splice(idx, 1);
    setTask(copyTask);
  };


  return (
    <div className="container">
      <form onSubmit={submitHandler} className="student-form">
        <h1>Student Marksheet</h1>

        <div className="input-group">
          <label>Name</label>
          <input
            type="text"
            placeholder="Enter your name"
            value={name}
            onChange={(e) => setName(e.target.value)}
            required
          />
        </div>

        <div className="input-group">
          <label>Age</label>
          <input
            type="number"
            placeholder="Enter your age"
            value={age}
            onChange={(e) => setAge(e.target.value)}
            required
          />
        </div>

        <div className="input-group">
          <label>Study</label>
          <input
            type="text"
            placeholder="Enter your course"
            value={study}
            onChange={(e) => setStudy(e.target.value)}
            required
          />
        </div>

        <div className="input-group">
          <label>Roll No</label>
          <input
            type="text"
            placeholder="Enter your roll number"
            value={rollno}
            onChange={(e) => setRollno(e.target.value)}
            required
          />
        </div>

        <div className="input-group">
          <label>Full Stack</label>
          <input
            type="number"
            placeholder="Enter Full Stack marks"
            min="0"
            max="100"
            value={m1}
            onChange={(e) => setM1(e.target.value)}
            required
          />
        </div>

        <div className="input-group">
          <label>Java</label>
          <input
            type="number"
            placeholder="Enter Java marks"
            min="0"
            max="100"
            value={m2}
            onChange={(e) => setM2(e.target.value)}
            required
          />
        </div>

        <div className="input-group">
          <label>DSA</label>
          <input
            type="number"
            placeholder="Enter DSA marks"
            min="0"
            max="100"
            value={m3}
            onChange={(e) => setM3(e.target.value)}
            required
          />
        </div>

        <div className="input-group">
          <label>RDBMS</label>
          <input
            type="number"
            placeholder="Enter RDBMS marks"
            min="0"
            max="100"
            value={m4}
            onChange={(e) => setM4(e.target.value)}
            required
          />
        </div>

        <button type="submit" className="add-btn">
          Add Student
        </button>
      </form>

      <div className="students-section">
        <h2>Student Marksheet Details</h2>

        <div className="student-list">
          {task.length === 0 ? (
            <p className="no-student">No student records available.</p>
          ) : (
            task.map((elem, idx) => (
              <div className="student-card" key={idx}>
                <h3>{elem.name}</h3>

                <div className="student-info">
                  <p>
                    <strong>Age:</strong> {elem.age}
                  </p>

                  <p>
                    <strong>Study:</strong> {elem.study}
                  </p>

                  <p>
                    <strong>Roll No:</strong> {elem.rollno}
                  </p>
                </div>

                <hr />

                <div className="marks">
                  <p>
                    <strong>Full Stack:</strong> {elem.m1}
                  </p>

                  <p>
                    <strong>Java:</strong> {elem.m2}
                  </p>

                  <p>
                    <strong>DSA:</strong> {elem.m3}
                  </p>

                  <p>
                    <strong>RDBMS:</strong> {elem.m4}
                  </p>
                </div>

                <hr />

                <div className="result">
                  <p>
                    <strong>Total:</strong> {elem.total} / 400
                  </p>

                  <p>
                    <strong>Percentage:</strong> {elem.percentage}%
                  </p>

                  <p>
                    <strong>SGPA:</strong> {elem.sgpa}
                  </p>
                </div>

                <button
                  className="delete-btn"
                  onClick={() => deleteNotes(idx)}
                >
                  Delete
                </button>

                 <button
                  className="update-btn"
                  onClick={() => updateNotes(idx)}
                >
                  Update
                </button>
              </div>
            ))
          )}
        </div>
      </div>
    </div>
  );
};

export default Studentmarks;
