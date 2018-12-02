
namespace ece309{
class arrayList{
        public:
        int n;
        int num;
        char** theList;
        // constructor
        arrayList(){
            n = 10; // size of array
            num = 0; // number of items on list
            theList = new char*[10];
        };
        void push_back(char* a);
        char* get(int n);
        int length();
        char* remove_front();
        ~arrayList();
};

// removes the front of the list and returns what was removed
char* arrayList::remove_front(){
    char* temporary;
    temporary = theList[0];
    for(int j = 0; j < (num-1); j++){
        theList[j] = theList[j+1];
    }
    num--;
    theList[num] = 0;
    return temporary;
}
// adds a new item to the list. Makes list larger if not large enough
void arrayList::push_back(char* a){
    if(num == n){
        // we need a bigger array
        n+=n;
        char** temp = new char*[n];
        for(int i = 0; i<num; i++){
            temp[i] = theList[i];
        }

        theList = new char*[n];
        for(int i = 0; i<num; i++){
            theList[i] = temp[i];
        }
        theList[num] = a;
        num++;
    } 
    else{
    theList[num] = a;
    num++;
    }
}
// returns the nth item on the list
char* arrayList::get(int n){
    return theList[n-1];
}
// returns the length of the list
int arrayList::length(){
    return num;
}

//destructor
arrayList::~arrayList(){
    delete theList;
}

int main(){
    return 0;
}
}