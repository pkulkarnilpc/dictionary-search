#ifndef ARRAY_LIST_DICTIONARY_HPP
#define ARRAY_LIST_DICTIONARY_HPP

#include "Dictionary.hpp"
#include "ArrayList.hpp"

template <typename Key, typename Val>
class ArrayListDictionary : public Dictionary<Key, Val> {
    private:
        // an element in a dictionary, contains a key and a value
        struct Record {
            Key k;
            Val v;

            Record() : k(Key()), v(Val()) { }
            Record(Key x, Val y) : k(x), v(y) { }
        };

        // the underlying array-based list
        ArrayList<Record>* list;

        // sequential search algorithm (iterative)
        Val seqSearchIter(const Key&) const;

        // sequential search algorithm (recursive)
        Val seqSearchRec(const Key&, int = 0) const;

        // binary search algorithm (iterative)
        Val binSearchIter(const Key&, int, int) const;

        // binary search algorithm (recursive)
        Val binSearchRec(const Key&, int, int) const;

        // copy the state of the argument dictionary to `this`
        void copy(const ArrayListDictionary<Key, Val>&);

        // counter to keep track of the number of key comparisons
        static unsigned numComps;

    public:
        // constructor with the maximum size as the argument
        ArrayListDictionary(int = 100);

        // copy constructor
        ArrayListDictionary(const ArrayListDictionary<Key, Val>&);

        // overloaded assignment operator
        ArrayListDictionary<Key, Val>& operator=(const ArrayListDictionary<Key, Val>&);

        // destructor
        virtual ~ArrayListDictionary();

        // remove all records in the dictionary, resetting to the initial state
        virtual void clear() override;

        // retrieve the record that matches the argument key
        // if multiple records match, return an arbitrary one
        virtual Val find(const Key&) const override;

        // return the number of key comparisons made by the search algorithm
        static unsigned getNumComps();

        // add the record as a key-value pair to the dictionary
        virtual void insert(const Key&, const Val&) override;

        // remove the record that matches the argument key from the dictionary
        // if multiple records match, remove an arbitrary one
        virtual void remove(const Key&) override;

        // return the number of records in the dictionary
        virtual int size() const override;
};

#include "ArrayListDictionary.tpp"
#endif
