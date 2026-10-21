function AcademicInformation({
  form,
  errors,
  onChange,
}) {
  return (
    <section className="card">

      <div className="section-title">
        <div className="number">3</div>

        <div>
          <h2>Academic Information</h2>
          <p>Enter academic and admission details</p>
        </div>
      </div>

      <div className="form-grid">

        <div className="form-group">
          <label>
            Admission Number <span>*</span>
          </label>

          <input
            type="text"
            name="admissionNumber"
            value={form.admissionNumber}
            onChange={onChange}
            placeholder="ADM2026001"
          />

          {errors.admissionNumber && (
            <small className="error">
              {errors.admissionNumber}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>
            Admission Date <span>*</span>
          </label>

          <input
            type="date"
            name="admissionDate"
            value={form.admissionDate}
            onChange={onChange}
          />

          {errors.admissionDate && (
            <small className="error">
              {errors.admissionDate}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>
            Course <span>*</span>
          </label>

          <select
            name="course"
            value={form.course}
            onChange={onChange}
          >
            <option value="">
              Select Course
            </option>

            <option value="BCA">BCA</option>
            <option value="BBA">BBA</option>
            <option value="B.Tech">B.Tech</option>
            <option value="MCA">MCA</option>
            <option value="MBA">MBA</option>
            <option value="M.Tech">M.Tech</option>
            <option value="B.Sc">B.Sc</option>
            <option value="M.Sc">M.Sc</option>
            <option value="B.Com">B.Com</option>
            <option value="M.Com">M.Com</option>
          </select>

          {errors.course && (
            <small className="error">
              {errors.course}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>
            Department <span>*</span>
          </label>

          <select
            name="department"
            value={form.department}
            onChange={onChange}
          >
            <option value="">
              Select Department
            </option>

            <option value="Computer Science">
              Computer Science
            </option>

            <option value="Information Technology">
              Information Technology
            </option>

            <option value="Commerce">
              Commerce
            </option>

            <option value="Management">
              Management
            </option>

            <option value="Mechanical Engineering">
              Mechanical Engineering
            </option>

            <option value="Civil Engineering">
              Civil Engineering
            </option>

            <option value="Electrical Engineering">
              Electrical Engineering
            </option>
          </select>

          {errors.department && (
            <small className="error">
              {errors.department}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>
            Semester <span>*</span>
          </label>

          <select
            name="semester"
            value={form.semester}
            onChange={onChange}
          >
            <option value="">
              Select Semester
            </option>

            <option value="1st Semester">
              1st Semester
            </option>

            <option value="2nd Semester">
              2nd Semester
            </option>

            <option value="3rd Semester">
              3rd Semester
            </option>

            <option value="4th Semester">
              4th Semester
            </option>

            <option value="5th Semester">
              5th Semester
            </option>

            <option value="6th Semester">
              6th Semester
            </option>

            <option value="7th Semester">
              7th Semester
            </option>

            <option value="8th Semester">
              8th Semester
            </option>
          </select>

          {errors.semester && (
            <small className="error">
              {errors.semester}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>
            Academic Year <span>*</span>
          </label>

          <input
            type="text"
            name="academicYear"
            value={form.academicYear}
            onChange={onChange}
            placeholder="2026-2027"
          />

          {errors.academicYear && (
            <small className="error">
              {errors.academicYear}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>Previous School / College</label>

          <input
            type="text"
            name="previousSchool"
            value={form.previousSchool}
            onChange={onChange}
            placeholder="Previous school/college"
          />
        </div>

        <div className="form-group">
          <label>Previous Percentage</label>

          <input
            type="number"
            name="previousPercentage"
            value={form.previousPercentage}
            onChange={onChange}
            placeholder="85"
            min="0"
            max="100"
          />
        </div>

      </div>
    </section>
  );
}

export default AcademicInformation;
