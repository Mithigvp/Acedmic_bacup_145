import { useEffect, useState } from "react";
import StudentForm from "./components/StudentForm";
import StudentTable from "./components/StudentTable";
import "./App.css";

const initialForm = {
  firstName: "",
  middleName: "",
  lastName: "",
  gender: "",
  dateOfBirth: "",
  bloodGroup: "",
  email: "",
  phone: "",

  address: "",
  city: "",
  state: "",
  country: "India",
  pincode: "",

  admissionNumber: "",
  admissionDate: "",
  course: "",
  department: "",
  semester: "",
  academicYear: "",
  previousSchool: "",
  previousPercentage: "",

};

function App() {
  const [students, setStudents] = useState([]);
  const [editingStudent, setEditingStudent] = useState(null);

  // Load data
  useEffect(() => {
    const savedStudents = localStorage.getItem("students");

    if (savedStudents) {
      setStudents(JSON.parse(savedStudents));
    }
  }, []);

  // Save data
  useEffect(() => {
    localStorage.setItem("students", JSON.stringify(students));
  }, [students]);

  // Add / Update student
  const handleSubmit = (studentData) => {
    if (editingStudent) {
      setStudents((prevStudents) =>
        prevStudents.map((student) =>
          student.id === editingStudent.id
            ? {
                ...studentData,
                id: editingStudent.id,
              }
            : student
        )
      );

      setEditingStudent(null);
    } else {
      const newStudent = {
        ...studentData,
        id: Date.now(),
      };

      setStudents((prevStudents) => [
        newStudent,
        ...prevStudents,
      ]);
    }
  };

  // Delete student
  const handleDelete = (id) => {
    const confirmDelete = window.confirm(
      "Are you sure you want to delete this student?"
    );

    if (!confirmDelete) return;

    setStudents((prevStudents) =>
      prevStudents.filter((student) => student.id !== id)
    );
  };

  // Edit student
  const handleEdit = (student) => {
    setEditingStudent(student);

    window.scrollTo({
      top: 0,
      behavior: "smooth",
    });
  };

  // Cancel edit
  const handleCancelEdit = () => {
    setEditingStudent(null);
  };

  return (
    <div className="app">

      {/* Header */}
      <header className="header">
        <div>
          <h1>Student Management System</h1>
          <p>
            Student Registration & Academic Records
          </p>
        </div>

        <div className="student-count">
          <strong>{students.length}</strong>
          <span>Total Students</span>
        </div>
      </header>

      <main className="container">

        {/* Student Form */}
        <StudentForm
          initialForm={initialForm}
          editingStudent={editingStudent}
          onSubmit={handleSubmit}
          onCancel={handleCancelEdit}
        />

        {/* Student Table */}
        <StudentTable
          students={students}
          onEdit={handleEdit}
          onDelete={handleDelete}
        />

      </main>
    </div>
  );
}

export default App;