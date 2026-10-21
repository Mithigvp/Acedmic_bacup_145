import React from 'react'

const App = () => {
  return (
    <div className="calculator">
      <h1>Calculator</h1>
      <p>Welcome to the Calculator!</p>
      <form action="" id="calculator-form">
        <label htmlFor="num1">Number 1:</label>
        <input type="number" id="num1" name="num1" required />
        <br />
        <br />
        <label htmlFor="num2">Number 2:</label>
        <input type="number" id="num2" name="num2" required />
        <br />
        <br />

        <button type="button" onClick={() => {
          const num1 = parseFloat(document.getElementById('num1').value);
          const num2 = parseFloat(document.getElementById('num2').value);
          const result = num1 + num2;
          document.getElementById('result').textContent = `Result: ${result}`;
        }}>
          +
        </button>
        <button type="button" onClick={() => {
          const num1 = parseFloat(document.getElementById('num1').value);
          const num2 = parseFloat(document.getElementById('num2').value);
          const result = num1 - num2;
          document.getElementById('result').textContent = `Result: ${result}`;
        }}>
          -
        </button>
        <button type="button" onClick={() => {
          const num1 = parseFloat(document.getElementById('num1').value);
          const num2 = parseFloat(document.getElementById('num2').value);
          const result = num1 * num2;
          document.getElementById('result').textContent = `Result: ${result}`;
        }}>
          
          *
        </button>
        <button type="button" onClick={() => {
          const num1 = parseFloat(document.getElementById('num1').value);
          const num2 = parseFloat(document.getElementById('num2').value);
          const result = num1 / num2;
          document.getElementById('result').textContent = `Result: ${result}`;
        }}>
          /
        </button>
      <br />
      <br />
          <p id="result">Result</p>
      </form>
    </div>
  )
}

export default App