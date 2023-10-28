constexpr int kMod = 1'000'000'007;

struct Matrix {
  int a[5][5] = {{}, {}, {}, {}, {}};

  static Matrix I() {
    Matrix r;
    for (int i = 0; i < 5; ++i) {
      r.a[i][i] = 1;
    }
    return r;
  }

  Matrix operator*(const Matrix& other) const {
    Matrix r;
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        int64_t e = 0;
        for (int k = 0; k < 5; ++k) {
          e += int64_t(a[i][k]) * other.a[k][j] % kMod;
        }
        r.a[i][j] = e % kMod;
      }
    }
    return r;
  }

  Matrix& operator*=(const Matrix& other) {
    *this = *this * other;
    return *this;
  }

  Matrix& operator+=(const Matrix& other) {
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        a[i][j] = (a[i][j] + other.a[i][j]) % kMod;
      }
    }
    return *this;
  }

  Matrix operator+(const Matrix& other) const {
    Matrix r = *this;
    r += other;
    return r;
  }
};

Matrix ModPow(Matrix a, int x) {
  Matrix r = Matrix::I();
  while (x > 0) {
    if (x % 2 == 1) {
      r *= a;
    }
    a = a * a;
    x /= 2;
  }
  return r;
}

class Solution {
public:
  int countVowelPermutation(int n) {
    Matrix m{
      .a = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0},
      }
    };

    m = ModPow(m, n - 1);
    int64_t sum = 0;
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        sum += m.a[i][j];
      }
    }
    return sum % kMod;
  }
};