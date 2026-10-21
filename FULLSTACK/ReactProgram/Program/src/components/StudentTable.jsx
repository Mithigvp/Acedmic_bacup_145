import { useState } from "react";

function StudentTable({
  students,
  onEdit,
  onDelete,
}) {
  const [search, setSearch] = useState("");

  const filteredStudents = students.filter(
    (student) => {
      const keyword = search.toLowerCase();

      return (
        student.firstName
          .toLowerCase()
          .includes(keyword) ||
        student.lastName
          .toLowerCase()
          .includes(keyword) ||
        student.admissionNumber
          .toLowerCase()
          .includes(keyword) ||
        student.email
          .toLowerCase()
          .includes(keyword) ||
        student.phone.includes(keyword) ||
        student.course
          .toLowerCase()
          .includes(keyword)
      );
    }
  );

  return (
    <section className="card">

      <div className="list-header">

        <div>
          <h2>Registered Students</h2>

          <p>
            Total Records: {filteredStudents.length}
          </p>
        </div>

        <input
          className="search"
          type="text"
          value={search}
          onChange={(e) =>
            setSearch(e.target.value)
          }
          placeholder="Search student..."
        />

      </div>

      {filteredStudents.length === 0 ? (
        <div className="empty">
          <div className="empty-icon">
            🎓
          </div>

          <h3>No Students Found</h3>

          <p>
            Register a student using the form
            above.
          </p>
        </div>
      ) : (
        <div className="table-wrapper">

          <table>

            <thead>
              <tr>
                <th>#</th>
                <th>Admission No.</th>
                <th>Student Name</th>
                <th>Gender</th>
                <th>Phone</th>
                <th>Email</th>
                <th>Course</th>
                <th>Department</th>
                <th>Semester</th>
                <th>Address</th>
                <th>Actions</th>
              </tr>
            </thead>

            <tbody>

              {filteredStudents.map(
                (student, index) => (
                  <tr key={student.id}>

                    <td>{index + 1}</td>

                    <td>
                      <strong>
                        {student.admissionNumber}
                      </strong>
                    </td>

                    <td>
                      <strong>
                        {student.firstName}{" "}
                        {student.middleName}{" "}
                        {student.lastName}
                      </strong>
                    </td>

                    <td>
                      {student.gender}
                    </td>

                    <td>
                      {student.phone}
                    </td>

                    <td>
                      {student.email}
                    </td>

                    <td>
                      <span className="badge">
                        {student.course}
                      </span>
                    </td>

                    <td>
                      {student.department}
                    </td>

                    <td>
                      {student.semester}
                    </td>

                    <td>
                      {student.address},
                      <br />
                      {student.city},{" "}
                      {student.state}
                      <br />
                      {student.country} -{" "}
                      {student.pincode}
                    </td>

                    <td>

                      <div className="actions">

                        <button
                          type="button"
                          className="edit-btn"
                          onClick={() =>
                            onEdit(student)
                          }
                        >
                          Edit
                        </button>

                        <button
                          type="button"
                          className="delete-btn"
                          onClick={() =>
                            onDelete(student.id)
                          }
                        >
                          Delete
                        </button>

                      </div>

                    </td>

                  </tr>
                )
              )}

            </tbody>

          </table>

        </div>
      )}

    </section>
  );
}

export default StudentTable;
