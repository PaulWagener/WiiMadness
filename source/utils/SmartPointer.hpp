/*
 * CG Madness - a Marble Madness clone
 * Copyright (C) 2007  Sven Reinck <sreinck@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef SmartPointer_hpp
#define SmartPointer_hpp

template<class T>
class SmartPointer
{
public:
  SmartPointer();
  SmartPointer(T* ptr);
  SmartPointer(const SmartPointer<T>& other);
  virtual ~SmartPointer();

  void operator= (const SmartPointer<T>& other);

  T& operator* ();
  T* operator-> ();
  
  operator T* ();
  operator const T* () const;
  
private:
	T* mPtr;
	unsigned int* mCounter;

	void release();
	void assign(const SmartPointer& other);
	
};

#include <stdlib.h>

template<class T>
SmartPointer<T>::SmartPointer() :
mPtr(NULL)
{
	mCounter = new unsigned int(1);
}

template<class T>
SmartPointer<T>::SmartPointer(T* ptr) :
mPtr(ptr)
{
	mCounter = new unsigned int(1);
}

template<class T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& other)
{
	assign(other);
}

template<class T>
SmartPointer<T>::~SmartPointer()
{
	release();
}

template<class T>
void SmartPointer<T>::operator= (const SmartPointer<T>& other)
{
	if (mPtr != other.mPtr)
	{
		release();
		assign(other);
	}
}

template<class T>
T& SmartPointer<T>::operator* ()
{
	return *mPtr;
}

template<class T>
T* SmartPointer<T>::operator-> ()
{
	return mPtr;
}

template<class T>
SmartPointer<T>::operator T* ()
{
	return mPtr;
}

template<class T>
SmartPointer<T>::operator const T* () const
{
	return mPtr;
}

template<class T>
void SmartPointer<T>::release()
{
	(*mCounter)--;
	if (*mCounter == 0)
	{
		delete mPtr;
		delete mCounter;
	}
}

template<class T>
void SmartPointer<T>::assign(const SmartPointer& other)
{
	mPtr = other.mPtr;
	mCounter = other.mCounter;
	(*mCounter)++;
}


#endif
