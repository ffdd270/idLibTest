/*
===========================================================================

Doom 3 BFG Edition GPL Source Code
Copyright (C) 1993-2012 id Software LLC, a ZeniMax Media company. 

This file is part of the Doom 3 BFG Edition GPL Source Code ("Doom 3 BFG Edition Source Code").  

Doom 3 BFG Edition Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 BFG Edition Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 BFG Edition Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 BFG Edition Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 BFG Edition Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/
#ifndef __ARRAY_H__
#define __ARRAY_H__

/*
================================================
idArray is a replacement for a normal C array.
idArray는 평범한 C 배열을 대채합니다. 

int		myArray[ARRAY_SIZE];

becomes:

idArray<int,ARRAY_SIZE>	myArray;

int myArray[ARRAY_SIZE];는 idArray<int, ARRAY_SIZE> myArray;에 대응합니다. 

Has no performance overhead in release builds, but
does index range checking in debug builds.

Release 빌드에서 성능상의 오버해드는 없지만, 디버그 빌드에서는 index 범위 체크로 인한 오버헤드가 발생합니다. 

Unlike idTempArray, the memory is allocated inline with the
object, rather than on the heap.

idTempArray와는 다르게 메모리는 힙에 할당되지 않고, 스택에 할당됩니다. 

Unlike idStaticList, there are no fields other than the
actual raw data, and the size is fixed.

idStaticList와는 다르게 Raw Data이며, 크기는 고정되어있습니다. 
================================================
*/
template<class T_, int numElements > class idArray {
public:
	// returns number of elements in list
	// 리스트에 있는 객체 수를 반환합니다. 
	int				Num() const { return numElements; }

	 T_ * begin()
	{
		return &ptr[0];
	}

	 T_ * end(){
		return &ptr[numElements];
	}

	// returns the number of bytes the array takes up
	// 배열이 차지하는 바이트수를 반환합니다. 
	int				ByteSize() const { return sizeof( ptr ); }

	// memset the entire array to zero
	// 배열을 0으로 채웁니다.
	void			Zero() { memset( ptr, 0, sizeof( ptr ) ); }

	// memset the entire array to a specific value
	// 배열을 지정된 값으로 채웁니다. 
	void			Memset( const char fill ) { memset( ptr, fill, numElements * sizeof( *ptr ) ); }

	// array operators
	// 배열 연산자들. 
	const T_ &		operator[]( int index ) const { assert( (unsigned)index < (unsigned)numElements ); return ptr[index]; }
	T_ &			operator[]( int index ) { assert( (unsigned)index < (unsigned)numElements ); return ptr[index]; }

	// returns a pointer to the list
	// 리스트(배열)의 보인터를 반환합니다. 
	const T_ *		Ptr() const { return ptr; }
	T_ *			Ptr() { return ptr; }

private:
	T_				ptr[numElements];
};

#define ARRAY_COUNT( arrayName ) ( sizeof( arrayName )/sizeof( arrayName[0] ) )
#define ARRAY_DEF( arrayName ) arrayName, ARRAY_COUNT( arrayName )


/*
================================================
id2DArray is essentially a typedef (as close as we can
get for templates before C++11 anyway) to make
declaring two-dimensional idArrays easier.

Usage:
	id2DArray< int, 5, 10 >::type someArray;

================================================
*/
template<class _type_, int _dim1_, int _dim2_ >
struct id2DArray {
	typedef idArray< idArray< _type_, _dim2_ >, _dim1_ > type;
};


/*
================================================
idTupleSize
Generic way to get the size of a tuple-like type.
Add specializations as needed.
This is modeled after std::tuple_size from C++11,
which works for std::arrays also.
================================================
*/
template< class _type_ >
struct idTupleSize;

template< class _type_, int _num_ >
struct idTupleSize< idArray< _type_, _num_ > > {
	enum { value = _num_ };
};

#endif // !__ARRAY_H__
