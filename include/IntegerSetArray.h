
namespace ece309{

class IntegerSet {
   protected:
       int size;
   public:
       IntegerSet(int htsize):size(htsize) {}
       virtual bool insert(int) = 0;
       virtual bool search(int) const = 0;
       virtual void remove(int) = 0;
}; 

class IntegerSetArray: public IntegerSet {
    public:
        int size;
        int* a;
        int currentIndex;
        IntegerSetArray(int s);
        bool insert(int x);
        bool search(int x) const;
        void remove(int x);
};
}