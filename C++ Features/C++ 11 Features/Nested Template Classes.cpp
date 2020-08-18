#include <iostream>
#include <vector>
using namespace std;

template<class T>
class ring {
    
    private:
        //int length;
        //vector<T> items;
        int m_size;
        int m_pos;
        T *m_values;
    
    public:
        class iterator;
        //ring(int size) : length(size) {         
        //}
    public:
        ring(int size) : m_size(size), m_pos(0), m_values(NULL) {
            m_values = new T[size];
        }

        ~ring() {
            delete [] m_values;
        }

        int size() {
            return m_size;
        }

        iterator end() {
            return iterator(m_size, *this);
        }

        iterator begin() {
            return iterator(0, *this);
        }

        void add(T value) {
            // postfix so it assigns then increments
            m_values[m_pos++] = value;
            
            if(m_pos == m_size) {
                m_pos = 0;
            }
        }

        T &get(int pos) {
            return m_values[pos];
        }


        
        // void add(T item) {
        //     if (length == 0 ) {
        //         return;
        //     }

        //     if (items.size() < length) {
        //         items.push_back(item);
        //     }

        //     else {
        //         items.erase(items.begin());
        //         items.push_back(item); 
        //     } 
        // } 

        // int size() {
        //     return items.size();
        // }

        // T get(int index) {
        //     return items[index];
        // }
};

template<class T>
class ring<T>::iterator {
private:
    int m_pos;
    ring &m_ring;
public:
    iterator(int pos, ring &aRing) : m_pos(pos), m_ring(aRing) {

    }
    // the int parameter is used for postfix
    iterator &operator++(int) {
        m_pos++;

        return *this;
    }

    iterator &operator++() {
        m_pos++;

        return *this;
    }

    T &operator*() {
        return m_ring.get(m_pos);
    }

    bool operator!=(const iterator& other) const{
        return m_pos != other.m_pos;
    }
};

int main() {

    ring<string> textring(3);
    textring.add("one");
    textring.add("two");
    textring.add("three");
    // textring.add("four");
    // textring.add("five");

    //ring<string>::iterator it;
    // it.print();

    // c++98 style
    for (int i = 0; i < textring.size(); i++) {
        cout << textring.get(i) << endl;
    }
    // need to implement begin(), end(), ++, and * for this to work with a class I create
    for(ring<string>::iterator it=textring.begin(); it != textring.end(); it++) {
         cout << *it << endl;
    }

    // c++ 11 style
    for(auto value: textring) {
        cout << value << endl;
    }

    /* Output shoudl be four, one, two */
    return 0;
}