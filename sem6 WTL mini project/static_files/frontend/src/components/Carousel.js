import React from 'react'

export default function Carousel() {
  return (
    <>
    <div
      id="header-carousel"
      className="carousel slide carousel-fade"
      data-bs-ride="carousel"
    >
      <div className="carousel-inner">
        <div className="carousel-item active">
          <img className="w-100" src="resizedImage.png" alt="Image" />
          <div
            className="carousel-caption d-flex flex-column align-items-center justify-content-center"
          >
            <div className="p-3" style="max-width: 900px">
              <h5 className="text-white text-uppercase mb-3 animated slideInDown">
                E-Shop
              </h5>
              <h1 className="display-1 text-white mb-md-4 animated zoomIn">
                Sign Up to have a great shopping experience
              </h1>
              
              <a
                href=""
                className="btn btn-outline-light py-md-3 px-md-5 animated slideInUp"
                >Sign Up</a
              >
            </div>
          </div>
        </div>
        
      </div>
      
    </div>
    </>
  )
}
