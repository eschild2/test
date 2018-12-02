namespace ece309{

class IntArray{
    public:
    int* ourArray;
    int length;
    IntArray(const char* str);
    IntArray(int size, int val= 0);
    void set(int index, int val) { ourArray[index] = val;}
    int get(int index) {return ourArray[index];}
    int getLength() { return length; }
    int& operator[](int index);
    IntArray& operator +=(const IntArray &rhs);
    IntArray operator+(const IntArray &rhs) const;
    IntArray operator-(const IntArray &rhs) const;
    IntArray operator*(int x) const;
    IntArray operator/(int x) const;
    IntArray operator<<(int count) const;
    operator char*() const;
    operator int() const;
};
}