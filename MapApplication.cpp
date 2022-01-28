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

    map->put(Long(68), Long(45));
    
    cout << "______________________" << endl;
    cout << map->containsValue(firstNumber) << endl;
    cout << map->containsValue(secondNumber) << endl;
    cout << map->containsValue(thirdNumber) << endl;
    cout << map->containsValue(new Long(45)) << endl;
}

