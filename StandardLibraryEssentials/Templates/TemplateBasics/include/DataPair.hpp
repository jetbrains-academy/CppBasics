#ifndef CPPBASICS_DATAPAIR_HPP
#define CPPBASICS_DATAPAIR_HPP

template <typename T1, typename T2>
class DataPair {
private:
    T1 first;
    T2 second;

public:
    DataPair() : first(T1()), second(T2()) {}
    DataPair(T1 first, T2 second) : first(first), second(second) {}

    T1 getFirst() const {
        return first;
    }

    T2 getSecond() const {
        return second;
    }

    void setFirst(T1 value) {
        first = value;
    }

    void setSecond(T2 value) {
        second = value;
    }
};

template <typename T1, typename T2>
DataPair<T1, T2> makePair(T1 first, T2 second) {
    return DataPair<T1, T2>(first, second);
}

#endif //CPPBASICS_DATAPAIR_HPP
