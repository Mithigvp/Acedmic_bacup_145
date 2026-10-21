function StudentAddress({
  form,
  errors,
  onChange,
}) {
  return (
    <section className="card">

      <div className="section-title">
        <div className="number">2</div>

        <div>
          <h2>Student Address</h2>
          <p>Enter student's address</p>
        </div>
      </div>

      <div className="form-grid">

        <div className="form-group full">
          <label>
            Full Address <span>*</span>
          </label>

          <textarea
            name="address"
            value={form.address}
            onChange={onChange}
            placeholder="House number, street, area..."
            rows="3"
          />

          {errors.address && (
            <small className="error">
              {errors.address}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>
            City <span>*</span>
          </label>

          <input
            type="text"
            name="city"
            value={form.city}
            onChange={onChange}
            placeholder="Enter city"
          />

          {errors.city && (
            <small className="error">
              {errors.city}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>
            State <span>*</span>
          </label>

          <input
            type="text"
            name="state"
            value={form.state}
            onChange={onChange}
            placeholder="Enter state"
          />

          {errors.state && (
            <small className="error">
              {errors.state}
            </small>
          )}
        </div>

        <div className="form-group">
          <label>Country</label>

          <select
            name="country"
            value={form.country}
            onChange={onChange}
          >
            <option value="India">India</option>
            <option value="USA">USA</option>
            <option value="UK">UK</option>
            <option value="Canada">Canada</option>
            <option value="Australia">
              Australia
            </option>
          </select>
        </div>

        <div className="form-group">
          <label>
            Pincode <span>*</span>
          </label>

          <input
            type="text"
            name="pincode"
            value={form.pincode}
            onChange={onChange}
            placeholder="6 digit pincode"
            maxLength="6"
          />

          {errors.pincode && (
            <small className="error">
              {errors.pincode}
            </small>
          )}
        </div>

      </div>
    </section>
  );
}

export default StudentAddress;
