import { BrowserRouter, Routes, Route } from 'react-router-dom'
import MyForm from './component/MyForm'
import Studentmarks from './component/Studentmarks'
import Error from './component/Error'

const App = () => {
  return (
     <BrowserRouter>
      <Routes>
        <Route path="/" element={<MyForm />} />
        <Route path="/Studentmarks" element={<Studentmarks />} />
        <Route path="/Error" element={<Error />} />
      </Routes>
    </BrowserRouter>
  )
}

export default App