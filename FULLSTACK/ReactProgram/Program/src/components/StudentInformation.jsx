function StudentInformation({
  form,
  errors,
  onChange,
}) {
  return (
    <section className="card">

      <div className="section-title">
        <div className="number">1</div>

        <div>
          <h2>Student Information</h2>
          <p>Enter basic student information</p>
        </div>
      </div>

      <div className="form-grid">

        <div className="form-group">
          <label>
            First Name <span>*</span>
          </label>

          <input
            type="text"
            name="firstName"
            value={form.firstName}
            onChange={onChange}
            placeholder="Enter first name"
          />

          {errors.firstName && (
            <small className="error">
              {errors.firstName}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>Middle Name</label>

          <input
            type="text"
            name="middleName"
            value={form.middleName}
            onChange={onChange}
            placeholder="Enter middle name"
          />
        </div>

        <div className="form-group">
          <label>
            Last Name <span>*</span>
          </label>

          <input
            type="text"
            name="lastName"
            value={form.lastName}
            onChange={onChange}
            placeholder="Enter last name"
          />

          {errors.lastName && (
            <small className="error">
              {errors.lastName}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>
            Gender <span>*</span>
          </label>

          <select
            name="gender"
            value={form.gender}
            onChange={onChange}
          >
            <option value="">
              Select Gender
            </option>
            <option value="Male">Male</option>
            <option value="Female">
              Female
            </option>
            <option value="Other">Other</option>
          </select>

          {errors.gender && (
            <small className="error">
              {errors.gender}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>
            Date of Birth <span>*</span>
          </label>

          <input
            type="date"
            name="dateOfBirth"
            value={form.dateOfBirth}
            onChange={onChange}
          />

          {errors.dateOfBirth && (
            <small className="error">
              {errors.dateOfBirth}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>Blood Group</label>

          <select
            name="bloodGroup"
            value={form.bloodGroup}
            onChange={onChange}
          >
            <option value="">
              Select Blood Group
            </option>
            <option value="A+">A+</option>
            <option value="A-">A-</option>
            <option value="B+">B+</option>
            <option value="B-">B-</option>
            <option value="AB+">AB+</option>
            <option value="AB-">AB-</option>
            <option value="O+">O+</option>
            <option value="O-">O-</option>
          </select>
        </div>

        <div className="form-group">
          <label>
            Email <span>*</span>
          </label>

          <input
            type="email"
            name="email"
            value={form.email}
            onChange={onChange}
            placeholder="student@example.com"
          />

          {errors.email && (
            <small className="error">
              {errors.email}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>
            Phone <span>*</span>
          </label>

          <input
            type="tel"
            name="phone"
            value={form.phone}
            onChange={onChange}
            placeholder="10 digit phone"
            maxLength="10"
          />

          {errors.phone && (
            <small className="error">
              {errors.phone}
            </small>
          )}
        </div>

      </div>
    </section>
  );
}

export default StudentInformation;