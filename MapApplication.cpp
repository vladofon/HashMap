#include <iostream>
#include <utility>
#include <concepts>

using namespace std;

template <class Type, class BaseClass>
concept CheckType = std::is_base_of<BaseClass, Type>::value;

//class MyClass
//{
//public:
//    inline virtual void Print() const noexcept { cout << "Myclass" << endl; }
//};
//
//
//class Derived : public MyClass
//{
//public:
//    inline virtual void Print() const noexcept override { cout << "Derived" << endl; }
//};
//
//template <class T>
//    requires CheckType<T, MyClass>
//class OnlyMyClass
//{
//private:
//    T Instance;
//
//public:
//    inline void Print() const noexcept { Instance.Print(); }    // Print
//};

template<class T>
class Comparable
{
public:
    inline virtual bool equals(T item) const noexcept { return false; }
};

class Item : public Comparable<Item>
{
public:
    Item(long element)
    {
        this->element = element;
    }

    Item(){}

    inline virtual bool equals(Item item) const noexcept override 
    { 
        if (this->element == item.element)
            return true;

        return false;
    }

    long element;
};

template<class T>
requires CheckType<T, Comparable<T>>
class Container
{
public:
    Container()
    {
        this->elementData = new T[10];
        this->size = 0;
    }

    void add(T item)
    {
        elementData[size] = item;
        size++;
    }

    bool contains(T item)
    {
        for (long i = 0; i < size; i++)
        {
            if (elementData[i].equals(item))
            {
                return true;
            }
        }

        return false;
    }

private:
    T* elementData;
    long size;
};



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
   std::cout << "Hello World!\n";

   Container<Item>* container = new Container<Item>();

   container->add(Item(0));
   container->add(Item(1));
   container->add(Item(2));
   container->add(Item(3));
   container->add(Item(4));

   cout << container->contains(Item(3)) << endl;
   cout << container->contains(Item(79)) << endl;
}

