import { useState } from 'react'
import { useNavigate } from "react-router-dom";
import '../assets/css/myform.css'

function MyForm() 
{
  const navigate = useNavigate()
  const validUsername = 'Mithilesh'
  const validPassword = '12345'

  const [inputs, setInputs] = useState({
    username: '',
    Password: ''
  })

  const [message, setMessage] = useState('')

  function handlesubmit(e) 
  {
    e.preventDefault()

    if (
      inputs.username === validUsername &&
      inputs.Password === validPassword
    ) 
    {
      setMessage('Login successful!')
      navigate('/Studentmarks')
    }
    else 
    {
      setMessage('Invalid username or password!')
      navigate('/Error')
    }
  }

  const handlechange = (e) => {
    const { name, value } = e.target

    setInputs(values => ({
      ...values,
      [name]: value
    }))
  }

  return (
    <main className="page">
      <form className="student-form" onSubmit={handlesubmit}>
        <h1>Login Form</h1>

        <label htmlFor="username">Username</label>
        <input
          id="username"
          name="username"
          type="text"
          value={inputs.username}
          onChange={handlechange}
          required
        />

        <label htmlFor="Password">Password</label>
        <input
          id="Password"
          name="Password"
          type="password"
          value={inputs.Password}
          onChange={handlechange}
          required
        />

        <button type="submit">Login</button>

        {message && <p>{message}</p>}
      </form>
    </main>
  )
}

export default MyForm