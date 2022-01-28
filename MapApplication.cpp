#include <iostream>
#include <utility>
#include <concepts>
#include "Long.h"
#include "HashMap.h"

using namespace std;





//template<class T>
//class Comparable
//{
//public:
//   virtual bool equals(T obj) = 0;
//};
//
//template<class T>
//requires CheckType<T, Comparable>
//class Box
//{
//public:
//   Box(T item)
//   {
//      this->item = item;
//   }
//
//private:
//   T item;
//};

int main()
{
    Long* firstNumber = new Long(10);
    Long* secondNumber = new Long(21);
    Long* thirdNumber = new Long(100000);
    Long* fourthNumber = new Long(4545);

    Map<Long, Long>* map = new HashMap<Long, Long>();

    map->put(Long(6833), Long(45));
    map->put(Long(686), Long(45));
    map->put(Long(658), Long(45));
    map->put(Long(468), Long(45));
    map->put(Long(668), Long(45));
    map->put(Long(6458), Long(45));
    map->put(Long(63438), Long(45));
    map->put(Long(683453), Long(45));
    map->put(Long(62338), Long(45));
    map->put(Long(223468), Long(45));
    map->put(Long(45468), Long(45));
    map->put(Long(6458), Long(45));
    map->put(Long(65668), Long(45));
    map->put(Long(66578), Long(45));
    map->put(Long(68378), Long(45));
    map->put(Long(689898), Long(45));
    map->put(Long(5566), Long(45));
    map->put(Long(567), Long(45));
    map->put(Long(45456), Long(45));
    map->put(Long(7868), Long(45));
    map->put(Long(8989), Long(45));
    map->put(Long(56789), Long(45));

    map->put(*firstNumber, *firstNumber);
    cout<<map->get(firstNumber).data<<endl;
    
    map->put(*secondNumber, *secondNumber);
    cout<<map->get(secondNumber).data<<endl;

    map->put(*thirdNumber, *thirdNumber);
    cout<<map->get(thirdNumber).data<<endl;

    List<Entry<Long, Long>> *entry = map->entrySet();
    List<Long>* keys = map->keyList();
    List<Long>* values = map->values();

    cout << "______________________" << endl;
    for (long i = 0; i < entry->getSize(); i++)
    {
        cout << entry->get(i).getHash() << endl;
    }
    cout << "______________________" << endl;
    cout << "________keys__________" << endl;
    for (long i = 0; i < keys->getSize(); i++)
    {
        cout << keys->get(i).data << endl;
    }    
    cout << "______________________" << endl;
    cout << "________values________" << endl;
    for (long i = 0; i < values->getSize(); i++)
    {
        cout << values->get(i).data << endl;
    }
    cout << "______________________" << endl;
    cout << map->containsKey(firstNumber) << endl;
    cout << map->containsKey(secondNumber) << endl;
    cout << map->containsKey(thirdNumber) << endl;
    cout << map->containsKey(fourthNumber) << endl;    
    
    cout << "______________________" << endl;
    cout << map->containsValue(firstNumber) << endl;
    cout << map->containsValue(secondNumber) << endl;
    cout << map->containsValue(thirdNumber) << endl;
    cout << map->containsValue(new Long(45)) << endl;
}

