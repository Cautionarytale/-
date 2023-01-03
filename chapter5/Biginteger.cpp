#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;

struct BigInteger {
  static const int BASE = 100000000;
  static const int WIDTH = 8;
  vector<int> s;

  BigInteger(long long num = 0) { *this = num; } // 构造函数
  BigInteger operator = (long long num) { // 赋值运算符
    s.clear();
    do {
      s.push_back(num % BASE);
      num /= BASE;
    } while(num > 0);
    return *this;
  }
  BigInteger operator = (const string& str) { // 赋值运算符
    s.clear();
    int x, len = (str.length() - 1) / WIDTH + 1;
    for(int i = 0; i < len; i++) {
      int end = str.length() - i*WIDTH;
      int start = max(0, end - WIDTH);
      sscanf(str.substr(start, end-start).c_str(), "%d", &x);
      s.push_back(x);
    }
    return *this;
  }
  bool operator < (const BigInteger& b) const
{
    if (s.size() != b.s.size())  return s.size() < b.s.size();
    for (int i = s.size() - 1; i >= 0; --i)
        if (s[i] != b.s[i])  return s[i] < b.s[i];
    return false;
}

bool operator > (const BigInteger& b) const
{
    return b < *this;
}

bool operator <= (const BigInteger& b) const
{
    return !(b < *this);
}

bool operator >= (const BigInteger& b) const
{
    return !(*this < b);
}

bool operator != (const BigInteger& b) const
{
    return b < *this || *this < b;
}

bool operator == (const BigInteger& b) const
{
    return !(b < *this) && !(*this < b);
}

  BigInteger operator + (const BigInteger& b) const {
    BigInteger c;
    c.s.clear();
    for(int i = 0, g = 0; ; i++) {
      if(g == 0 && i >= s.size() && i >= b.s.size()) break;
      int x = g;
      if(i < s.size()) x += s[i];
      if(i < b.s.size()) x += b.s[i];
      c.s.push_back(x % BASE);
      g = x / BASE;
    }
    return c;
  }
  BigInteger operator - (const BigInteger& b) const
{
    BigInteger c;
    c.s.clear();
    int MAX = max(s.size(), b.s.size());
    if (*this > b)
    {
        for (int i = 0, g = 0; ; ++i)
        {
            bool borrow = 0;
            if (g == 0 && i >= MAX)  break;
            int x = g;
            if (i < s.size())  x += s[i];
            if (i < b.s.size())  x -= b.s[i];
            if (x < 0)  borrow = 1;
            c.s.push_back((x + BASE) % BASE);
            g = x / BASE;
            if (borrow)  --g;
        }
        return c;
    }
    else if (*this == b)
    {
        return c;
    }
    else
    {
        for (int i = 0, g = 0; ; ++i)
        {
            bool borrow = 0;
            if (g == 0 && i >= MAX)  break;
            int x = g;
            if (i < b.s.size())  x += b.s[i];
            if (i < s.size())  x -= s[i];
            if (x < 0)  borrow = 1;
            if (i == MAX - 1)
                c.s.push_back(-x % BASE);
            else
                c.s.push_back((x + BASE) % BASE);
            g = x / BASE;
            if (borrow)  --g;
        }
        return c;
    }
}
BigInteger operator * (const BigInteger& b) const
{
    BigInteger c;
    c.s.clear();
    if (s.size() == 1 && s[0] == 0)
    {
        c.s.clear();
        c.s.push_back(0);
        return c;
    }
    if (b.s.size() == 1 && b.s[0] == 0)
    {
        c.s.clear();
        c.s.push_back(0);
        return c;
    }
    int MAX = max(s.size(), b.s.size());
    for (int i = 0; i < (MAX * 2 + 2); ++i)
        c.s.push_back(0);
    for (int i = 0; i < s.size(); ++i)
        for (int j = 0; j < b.s.size(); ++j)
        {
            c.s[i + j + 1] += c.s[i + j] / BASE;
            c.s[i + j] %= BASE;
            c.s[i + j] += s[i] * b.s[j];
        }
    for (int i = 0; i < (MAX * 2 + 1); ++i)
    {
        c.s[i + 1] += c.s[i] / BASE;
        c.s[i] %= BASE;
    }
    while (!*(c.s.end() - 1))
        c.s.erase(c.s.end() - 1);
    return c;
}
BigInteger operator / (const BigInteger& b) const
{
    if (b.s.size() == 1 && b.s[0] == 0)
    {
        cerr << "Exception has occured." << endl;
        cerr << "Arithmetic exception: Divided by Zero." << endl;
        exit(1);
    }
    BigInteger c;
    c.s.clear();
    BigInteger substraction = *this;
    BigInteger tmp;
    tmp.s.clear();
    tmp.s.push_back(1);
    if (substraction > b)
    {
        while (substraction >= b)
        {
            substraction -= b;
            if (substraction.s.size() > 1)
                while (!*(substraction.s.end() - 1))
                    substraction.s.erase(substraction.s.end() - 1);
            c += tmp;
        }
    }
    else if (substraction == b)
        c.s.push_back(1);
    else
        c.s.push_back(0);
    return c;
}

BigInteger operator % (const BigInteger& b) const
{
    BigInteger c;
    c = *this - (*this / b) * b;
    return c;
}

BigInteger operator += (const BigInteger& b)
{
    *this = *this + b;
    return *this;
}

BigInteger operator -= (const BigInteger& b)
{
    *this = *this - b;
    return *this;
}

BigInteger operator *= (const BigInteger& b)
{
    *this = *this * b;
    return *this;
}

BigInteger operator /= (const BigInteger& b)
{
    *this = *this / b;
    return *this;
}

BigInteger operator %= (const BigInteger& b)
{
    *this = *this % b;
    return *this;
}

};

ostream& operator << (ostream &out, const BigInteger& x) {
  out << x.s.back();
  for(int i = x.s.size()-2; i >= 0; i--) {
    char buf[20];
    sprintf(buf, "%08d", x.s[i]);
    for(int j = 0; j < strlen(buf); j++) out << buf[j];
  }
  return out;
}

istream& operator >> (istream &in, BigInteger& x) {
  string s;
  if(!(in >> s)) return in;
  x = s;
  return in;
}
int main()
{
	BigInteger a(1234567890);
	cout<<a<<endl;
	return 0;
}

