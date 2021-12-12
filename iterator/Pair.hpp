#ifndef PAIR_HPP
# define PAIR_HPP


/*

ВНЕСТИ НЕМНОЖКО ЯСНОСТИ ПО ПОВОДУ ЭТОЙ ЕРУНДЫ

*/







namespace ft{

template <class T1, class T2>
struct pair
{
public:
    typedef T1 first_type;
    typedef T2 second_type;
private:
    first_type      first;
    second_type     second;
    
public:
    //-----------------------------Constructor-------------------------------//
    pair(): first(), second() {}

    template<class U, class V>
    pair(const pair< U, V >& p) : first(p.first), second(p.second) {}

    pair(first_type const& t1, second_type const& t2): first(t1), second(t2) {}

    pair& operator=(pair const& p) {
        this->first = p.first;
        this->second = p.second;
        return (*this);
    }

    ~pair(){}
};
    //-------------------------Relational operators--------------------------//
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
        return !(lhs == rhs);
    }
    template <class T1, class T2>
    bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) &&
                                            lhs.second < rhs.second);
    }
    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
        return !(rhs < lhs);
    }
    template <class T1, class T2>
    bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
        return rhs < lhs;
    }
    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
        return !(lhs < rhs);
    }


    //-------------------------------Make Pair-------------------------------//
    template <class T1, class T2>
    pair<T1, T2> make_pair (T1 x, T2 y){
        return (pair<T1, T2>(x, y));
    }
}

#endif