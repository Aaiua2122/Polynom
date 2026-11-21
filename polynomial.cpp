#include <iostream>
#include "polynomial.h"

//------------------------- Methods ---------------------------//

void Polynomial::Print_polynomial() const {
  for (int i = 0; i < count_coeff_; ++i) {
    if (!i) {
      std::cout << coeff_[i];
      continue;
    }
    if (coeff_[i] < 0) {
      std::cout << " - " << coeff_[i] << "x**" << i;
    } else {
      std::cout << " + " << coeff_[i] << "x**" << i;
    }
  }
  std::cout << "\n";
}

int Polynomial::Polynomail_value(int arg) const {
  if (cache_[0] == arg) {return cache_[1];}
  else {
    int final_value = 0;
    for (int i = count_coeff_ - 1; i >= 0; --i) {
      final_value = final_value * arg + coeff_[i];
    }
    cache_[0] = arg;
    cache_[1] = final_value;
    return final_value;
  }
}


//------------------------- Constructors ---------------------------//

Polynomial::Polynomial(int* coeff, int count) {
  count_coeff_ = count;

  coeff_ = new int[count_coeff_];
  for (int i = 0; i < count_coeff_; ++i) {
    coeff_[i] = coeff[i];
  }
  cache_[0] = 0;
  cache_[1] = coeff_[0];
}

Polynomial::~Polynomial() {
  delete[] coeff_;
}

Polynomial::Polynomial(const Polynomial& other) {
  count_coeff_ = other.count_coeff_;
  coeff_ = new int[count_coeff_];
  for (int i = 0; i < count_coeff_; ++i) {
    coeff_[i] = other.coeff_[i];
  }
  cache_[0] = other.cache_[0];
  cache_[1] = other.cache_[1];
}
Polynomial& Polynomial::operator=(const Polynomial& other) {
  if (this == &other) {return *this;}
  delete[] coeff_;

  count_coeff_ = other.count_coeff_;
  coeff_ = new int[count_coeff_];
  for (int i = 0; i < count_coeff_; ++i) {
    coeff_[i] = other.coeff_[i];
  }
  cache_[0] = other.cache_[0];
  cache_[1] = other.cache_[1];
  return *this;
}



//------------------------- Operators ---------------------------//

Polynomial Polynomial::operator+(const Polynomial& other) {
  int max;
  int min;
  if (count_coeff_ < other.count_coeff_) {
    max = other.count_coeff_;
    min = count_coeff_;
    
  } else {
    max = count_coeff_;
    min = other.count_coeff_;
  }

  int* new_coeff = new int[max];

  for (int i = 0; i < max; ++i) {
    if (i < min) {
      new_coeff[i] = coeff_[i] + other.coeff_[i];
    } else {
      if (min == count_coeff_) {
        new_coeff[i] = other.coeff_[i];
      } else {
        new_coeff[i] = coeff_[i];

      }
    }
  }

  Polynomial result(new_coeff, max);
  delete[] new_coeff;
  return result;
}