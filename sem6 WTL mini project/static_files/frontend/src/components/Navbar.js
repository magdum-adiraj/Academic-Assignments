import React from 'react'

export default function Navbar() {
  return (
    <>
    <div>
      <nav className="navbar navbar-expand-lg  bg-body-tertiary">
  <div className="container-fluid">
    <a className="navbar-brand" href="#">E-Shop</a>
    <button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
      <span className="navbar-toggler-icon"></span>
    </button>
    <div className="collapse navbar-collapse" id="navbarSupportedContent">
      <ul className="navbar-nav me-auto mb-2 mb-lg-0">
        <li className="nav-item">
          <a className="nav-link active" aria-current="page" href="#">Store</a>
        </li>
        <li className="nav-item">
          <a className="nav-link active" aria-current="page" href="#">Cloth-Men</a>
        </li>
        <li className="nav-item">
          <a className="nav-link active" aria-current="page" href="#">Cloth-Women</a>
        </li>
        <li className="nav-item">
          <a className="nav-link active" aria-current="page" href="#">Vegetables</a>
        </li>
        <li className="nav-item">
          <a className="nav-link active" aria-current="page" href="#">Mobile</a>
        </li>
        
        
        
      </ul>
      <form className="d-flex" role="search">
        
      </form>
    </div>
  </div>
</nav>
    </div>
    </>
  )
}
