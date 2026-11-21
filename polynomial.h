class Polynomial {
  public:
    Polynomial(int* coeff, int count);
    Polynomial(const Polynomial& other);
    Polynomial& operator=(const Polynomial& other);
    ~Polynomial();


    Polynomial operator+(const Polynomial& other);
    Polynomial operator-(const Polynomial& other);
    Polynomial operator*(const Polynomial& other);
    
    bool operator<(const Polynomial& other) const;
    bool operator>(const Polynomial& other) const;
    bool operator<=(const Polynomial& other) const;
    bool operator>=(const Polynomial& other) const;
    bool operator==(const Polynomial& other) const;
    
    int operator[](int index);

    int Polynomail_value(int arg) const;
    void Print_polynomial() const;

  private:
    int* coeff_;
    int count_coeff_;

    mutable int cache_[2];    
};