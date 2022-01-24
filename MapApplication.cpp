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

    Map<Long, Long>* map = new HashMap<Long, Long>();

    map->put(*firstNumber, *secondNumber);
    cout<<map->get(firstNumber).data<<endl;
}

