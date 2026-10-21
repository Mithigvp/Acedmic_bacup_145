import { useEffect, useState } from "react";

import StudentInformation from "./StudentInformation";
import StudentAddress from "./StudentAddress";
import AcademicInformation from "./AcademicInformation";

function StudentForm({
  initialForm,
  editingStudent,
  onSubmit,
  onCancel,
}) {
  const [form, setForm] = useState(initialForm);
  const [errors, setErrors] = useState({});

  // When edit button is clicked
  useEffect(() => {
    if (editingStudent) {
      setForm(editingStudent);
    } else {
      setForm(initialForm);
    }

    setErrors({});
  }, [editingStudent, initialForm]);

  // Input change
  const handleChange = (e) => {
    const { name, value } = e.target;

    setForm((prev) => ({
      ...prev,
      [name]: value,
    }));

    setErrors((prev) => ({
      ...prev,
      [name]: "",
    }));
  };

  // Validation
  const validate = () => {
    const newErrors = {};

    if (!form.firstName.trim()) {
      newErrors.firstName = "First name is required";
    }

    if (!form.lastName.trim()) {
      newErrors.lastName = "Last name is required";
    }

    if (!form.gender) {
      newErrors.gender = "Gender is required";
    }

    if (!form.dateOfBirth) {
      newErrors.dateOfBirth = "Date of birth is required";
    }

    if (!form.email.trim()) {
      newErrors.email = "Email is required";
    } else if (
      !/^\S+@\S+\.\S+$/.test(form.email)
    ) {
      newErrors.email = "Invalid email";
    }

    if (!form.phone.trim()) {
      newErrors.phone = "Phone is required";
    } else if (!/^[0-9]{10}$/.test(form.phone)) {
      newErrors.phone =
        "Phone number must contain 10 digits";
    }

    if (!form.address.trim()) {
      newErrors.address = "Address is required";
    }

    if (!form.city.trim()) {
      newErrors.city = "City is required";
    }

    if (!form.state.trim()) {
      newErrors.state = "State is required";
    }

    if (!form.pincode.trim()) {
      newErrors.pincode = "Pincode is required";
    } else if (!/^[0-9]{6}$/.test(form.pincode)) {
      newErrors.pincode =
        "Pincode must contain 6 digits";
    }

    if (!form.admissionNumber.trim()) {
      newErrors.admissionNumber =
        "Admission number is required";
    }

    if (!form.admissionDate) {
      newErrors.admissionDate =
        "Admission date is required";
    }

    if (!form.course) {
      newErrors.course = "Course is required";
    }

    if (!form.department) {
      newErrors.department =
        "Department is required";
    }

    if (!form.semester) {
      newErrors.semester = "Semester is required";
    }

    if (!form.academicYear.trim()) {
      newErrors.academicYear =
        "Academic year is required";
    }

    setErrors(newErrors);

    return Object.keys(newErrors).length === 0;
  };

  // Submit
  const handleSubmit = (e) => {
    e.preventDefault();

    if (!validate()) {
      window.scrollTo({
        top: 0,
        behavior: "smooth",
      });

      return;
    }

    onSubmit(form);

    setForm(initialForm);
    setErrors({});

    window.scrollTo({
      top: 0,
      behavior: "smooth",
    });
  };

  // Cancel
  const handleCancel = () => {
    setForm(initialForm);
    setErrors({});

    onCancel();
  };

  return (
    <form onSubmit={handleSubmit}>

      <StudentInformation
        form={form}
        errors={errors}
        onChange={handleChange}
      />

      <StudentAddress
        form={form}
        errors={errors}
        onChange={handleChange}
      />

      <AcademicInformation
        form={form}
        errors={errors}
        onChange={handleChange}
      />

      <div className="form-actions">

        {editingStudent && (
          <button
            type="button"
            className="btn btn-secondary"
            onClick={handleCancel}
          >
            Cancel
          </button>
        )}

        <button
          type="submit"
          className="btn btn-primary"
        >
          {editingStudent
            ? "Update Student"
            : "Register Student"}
        </button>

      </div>

    </form>
  );
}

export default StudentForm;
