namespace ece309{



class IntInf{
    public:
    const char* INF = "+infinity";
    const char* NINF = "-infinity";
    bool pos_inf;
    bool neg_inf;
    bool zero; //boolean to represent if k is actually 0
    int k;
    IntInf(int num = 0, bool positive_inf=0, bool negative_inf=0, bool z = 0){
        pos_inf = positive_inf;
        neg_inf = negative_inf;
        k = num;
        zero = z;
    }
    IntInf& operator=(const IntInf &rhs);
    IntInf& operator=(const int rhs);
    IntInf& operator=(const char* str);
    IntInf operator+(const IntInf &rhs);
    IntInf operator+(const char* str);
    IntInf operator+(const int rhs);
    IntInf operator-(const IntInf &rhs);
    IntInf operator-(const char* str);
    IntInf operator-(const int rhs);
    IntInf operator*(const IntInf &rhs);
    IntInf operator*(const char* str);
    IntInf operator*(const int rhs);
    IntInf operator/(const IntInf &rhs);
    IntInf operator/(const char* str);
    IntInf operator/(const int rhs);
    bool operator==(const IntInf &rhs);
    bool operator==(const char* str);
    bool operator==(const int rhs);
    bool operator>(const IntInf &rhs);
    bool operator>(const char* str);
    bool operator>(const int rhs);
    bool operator<(const IntInf &rhs);
    bool operator<(const char* str);
    bool operator<(const int rhs);
};
}