/* +---------------------------------------------------------------------------+
   | File:arrayList.h                                                          |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/22                                                           |
   | Describe:  array implementation of a linear list.                         |
   |            derives from abstract class linearList just to  make sure      |
   |            all methods of the ADT are implemented                         |
   |            USES STL ALGORIHMS TO SIMPLIFY CODE                            |
   +---------------------------------------------------------------------------+ */
#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>

#include "./linearList.h" 
#include "./myExceptions.h"  
#include "./changeLength1D.h"

using namespace std;

template<class T>
class arrayList : public linearList<T>
{
	public:
		//constructor,copy constructor and destructor
		arrayList(int initialCapacity = 10);
		arrayList(const arrayList<T>&);
		~arrayList(){delete [] element;}

		// ADT methods
		bool empty() const {return listSize == 0;}
		int size() const {return listSize;}
		T& get(int theIndex) const;
		int indexOf(const T& theElement) const;
		void erase(int theIndex);
		void insert(int theIndex,const T& theElement);
		void output(ostream& out) const;
  
		//additional method
		int capacity() const {return arrayLength;}

		//iterator to start and end of list
		class iterator;
		iterator begin(){return iterator(element);}
		iterator end(){return iterator(element + listSize);}

		//iterator for arrayList.
		class iterator
		{
			public:
				// typedefs required by C++ for a bidirectional iterator
				typedef bidirectional_iterator_tag iterator_category;
				typedef T value_type;
				typedef ptrdiff_t difference_type;
				typedef T* pointer;
				typedef T& reference;

				//constructor
				iterator(T* thePosition = 0){position = thePosition;}

				//dereferencing operators
				T& operator*() const{return *position;}
				T* operator->() const{return &*position;}

				//increment
				iterator& operator++()//preincrement
					{++position;return *this;}
				iterator operator++(int) //postincrement
					{iterator old = *this;
					 ++position;
					 return old;
					}
				//decrement
				iterator& operator--() //predecrement
					{--position;return *this;}
				iterator operator--(int) //postdecrement
					{iterator old = *this;
					 --position;
					 return old;				 
					}

				//equality testing
				bool operator!=(const iterator right) const
					{return position != right.position;}
				bool operator==(const iterator right) const
					{return position == right.position;}
			protected:
				T* position;
		};
	protected:
		void checkIndex(int theIndex) const;

		T* element;
		int arrayLength;
		int listSize;
};

template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
	if(initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << "Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	copy(theList.element,theList.element + listSize,element);
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{//Verify that theIndex is between 0 and listSize - 1.
	if(theIndex < 0 || theIndex >= listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << "size = " << listSize;
		throw illegalIndex(s.str()); 
	}
}

template<class T>
T& arrayList<T>::get(int theIndex) const
{//return element whose index is theIndex.
 //Throw illegalIndex exception if no such element.
	checkIndex(theIndex);
	return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{//return index of first occurrence of theElement.
 // return -1 if theElement not in list.
 
 //search for theElement.
	int theIndex = (int) (find(element,element + listSize,theElement)
 	                   - element);
 //check if theElement was found
	if(theIndex == listSize)
		return - 1;//not found.
	else return theIndex;
}

template<class T>
void arrayList<T>::erase(int theIndex)
{//Delete the element whose index is theIndex
 //throw illegalIndex exception if no such element.
	checkIndex(theIndex);
	copy(element + theIndex + 1,element + listSize,
		                         element + theIndex);
	element[--listSize].~T();//invoke destructor.`
}

template<class T>
void arrayList<T>::insert(int theIndex,const T& theElement)
{//insert theElement so that its index is theElement.
	if(theIndex < 0 || theIndex > listSize)
	{//invalid index
		ostringstream s;
		s << "index = " << theIndex << "size = " << listSize;
		throw illegalIndex(s.str());
	}

	//valid index,make sure we have space
	if(listSize == arrayLength)
	{//no space,double capacity
		changeLength1D(element,arrayLength,2 * arrayLength);
		arrayLength *= 2;
	}

	//shift elements right one position
	copy_backward(element + theIndex,element + listSize,
				  element + listSize + 1);

	element[theIndex] = theElement;

	++listSize;
}

template<class T>
void arrayList<T>::output(ostream& out) const
{// put the list into the stream out.
	copy(element, element + listSize, ostream_iterator<T>(cout, "  "));
}

//overload <<
template<class T>
ostream& operator<<(ostream& out,const arrayList<T>& x)
	{x.output(out); return out;}

#endif