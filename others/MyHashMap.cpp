#include<iostream>
#include<limits>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include "conio.h"
#include <functional>

using namespace std;


template<typename Key, typename Value>
struct HashKey
{
    HashKey(const Key& k, const Value& v) :key(k), value(v) {}

    Key key;
    Value value;
};


template<typename Key, typename Value, int TABLE_SIZE = 10>
class MyHashMap
{
    public:
        
        MyHashMap() :data(TABLE_SIZE)
        {}

        Value& operator[](const Key& key)
        {
            // If element foudn return the element
            int index = hash<Key>()(key) % TABLE_SIZE;

            for ( auto&& v: data[index])
            {
                if (v.first == key)
                    return v.second;
            }
            
            data[index].push_back(make_pair(key, Value()));
            return data[index].back().second;
        }

        bool find(const Key& key)
        {
            int index = hash<Key>()(key) % TABLE_SIZE;
            for (auto&& v : data[index])
            {
                if (v.first == key)
                    return true;
            }
            return false;
        }

        void insert(const Key& key, const Value& val)
        {
            // Get the HashKey
            int index = hash<Key>()(key) % TABLE_SIZE;

            if (find(key))
            {
                (*this)[key] = val;
                return;
            }

            data[index].push_back(make_pair(key, val));
            if (data[index].size() > 1)
                cout << "The Bucket=" << index <<
                ", has size=" << data[index].size();
        }
        
    private:
    vector<vector<pair<Key, Value>>> data;
};

using namespace std;

int main(int argc, char* argv[])
{
    MyHashMap<string, int> myHashMap;

    myHashMap.insert("One", 1);
    myHashMap.insert("Two", 2);
    myHashMap.insert("Three", 3);
    myHashMap.insert("Four", 4);
    myHashMap.insert("One", 6);

    cout << "Value of One=" << myHashMap["One"];
    cout << "Value of One=" << myHashMap["One"];
    cout << "Value of Four=" << myHashMap["Four"];

    return 0;
}



