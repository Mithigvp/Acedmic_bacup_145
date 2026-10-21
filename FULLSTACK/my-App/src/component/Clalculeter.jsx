import { useState } from 'react'


const Clalculeter = () => {
    const [Num1, setNum1] = useState('')
    const [Num2, setNum2] = useState('')
    const [Result, setResult] = useState('')

    const calculate = (operator) => {
        if (Num1 === '' || Num2 === '') {
            setResult('Please enter both numbers')
            return
        }

        const a = Number(Num1)
        const b = Number(Num2)

        if (operator === '+') {
            setResult(a + b)
        } 
        else if (operator === '-') {
            setResult(a - b)
        } 
        else if (operator === '*') {
            setResult(a * b)
        } 
        else if (operator === '/') {
            if (b === 0) {
                setResult('Cannot divide by 0')
                return
            }

            setResult(a / b)
        }
    }

    return (
        <div className="calculator">
            <h2>Simple Calculator</h2>

            <label htmlFor="Num1">Number 1</label>
            <input
                id="Num1"
                type="number"
                value={Num1}
                onChange={(e) => setNum1(e.target.value)}
                placeholder="Enter first number"
            />

            <label htmlFor="Num2">Number 2</label>
            <input
                id="Num2"
                type="number"
                value={Num2}
                onChange={(e) => setNum2(e.target.value)}
                placeholder="Enter second number"
            />

            <div className="buttons">
                <button onClick={() => calculate('+')}>+</button>
                <button onClick={() => calculate('-')}>-</button>
                <button onClick={() => calculate('*')}>×</button>
                <button onClick={() => calculate('/')}>÷</button>
            </div>

            <h3>Result: {Result}</h3>
        </div>
    )
}

export default Clalculeter
