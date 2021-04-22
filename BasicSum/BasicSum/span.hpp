/*
 * span.hpp
 *
 *  Created on: 2021年3月10日
 *      Author: dengkai17334
 */

#ifndef TRUNK_PUBLIC_SOURCES_UST_API_INCLUDE_COMMON_SPAN_HPP_
#define TRUNK_PUBLIC_SOURCES_UST_API_INCLUDE_COMMON_SPAN_HPP_
#include <algorithm>
#include <iterator>
#include <string>
#include <type_traits>
#include <vector>

namespace AMUST
{

/** A range of bytes expressed as a ContiguousContainer

 This class implements a non-owning reference to a storage
 area of a certain size and having an underlying integral
 type with size of 1.

 @tparam T The type pointed to by span iterators
 */
template<class T>
class span
{
	T *data_ = nullptr;
	std::size_t size_ = 0;
public:
	/// The type of value, including cv qualifiers
	using element_type = T;

	/// The type of value of each span element
	using value_type = typename std::remove_const<T>::type;

	/// The type of integer used to index the span
	using index_type = std::ptrdiff_t;

	/// A pointer to a span element
	using pointer = T*;

	/// A reference to a span element
	using reference = T&;

	/// The iterator used by the container
	using iterator = pointer;

	/// The const pointer used by the container
	using const_pointer = T const*;

	/// The const reference used by the container
	using const_reference = T const&;

	/// The const iterator used by the container
	using const_iterator = const_pointer;

	/// Constructor
	span() = default;

	/// Constructor
	span(span const&) = default;

	/// Assignment
	span& operator=(span const&) = default;

	/** Constructor

	 @param data A pointer to the beginning of the range of elements

	 @param size The number of elements pointed to by `data`
	 */
	span(T *data, std::size_t size) :
					data_(data), size_(size)
	{
	}

	/// Returns `true` if the span is empty
	bool empty() const
	{
		return size_ == 0;
	}

	/// Returns a pointer to the beginning of the span
	T*
	data() const
	{
		return data_;
	}

	/// Returns the number of elements in the span
	std::size_t size() const
	{
		return size_;
	}

	/// Returns an iterator to the beginning of the span
	const_iterator begin() const
	{
		return data_;
	}

	/// Returns an iterator to the beginning of the span
	const_iterator cbegin() const
	{
		return data_;
	}

	/// Returns an iterator to one past the end of the span
	const_iterator end() const
	{
		return data_ + size_;
	}

	/// Returns an iterator to one past the end of the span
	const_iterator cend() const
	{
		return data_ + size_;
	}
};

template<class T>
typename span<T>::const_iterator begin(const span<T> &s)
{
	return s.begin();
}

template<class T>
typename span<T>::const_iterator begin(const span<T> *s)
{
	return s->begin();
}

template<class T>
typename span<T>::const_iterator end(const span<T> &s)
{
	return s.end();
}

template<class T>
typename span<T>::const_iterator end(const span<T> *s)
{
	return s->end();
}
/**
 * @brief 对二级指针数组的简单封装
 *
 * @tparam T
 */
template<class T>
class multi_span
{
	std::vector<T*> data_;
	std::size_t size_ { 0 };
public:
	/// The type of value, including cv qualifiers
	using element_type = T;

	using value_type = typename std::vector<T*>::value_type;

	/// The type of integer used to index the span
	using index_type = std::ptrdiff_t;

	/// A pointer to a span element
	using pointer = T*;

	/// A reference to a span element
	using reference = T&;

	/// The iterator used by the container
	using iterator = typename std::vector<T*>::iterator;

	/// The const pointer used by the container
	using const_pointer = T const*;

	/// The const reference used by the container
	using const_reference = T const&;

	/// The const iterator used by the container
	using const_iterator = typename std::vector<T*>::const_iterator;

	/// Constructor
	multi_span() = default;

	/// Constructor
	multi_span(multi_span const&) = default;

	/// Assignment
	multi_span& operator=(multi_span const&) = default;

	/** Constructor

	 @param data A pointer to the beginning of the range of elements

	 @param size The number of elements pointed to by `data`
	 */
	multi_span(std::size_t size) :
					size_(size)
	{
		data_.reserve(size_);
	}

	/// Returns `true` if the span is empty
	bool empty() const
	{
		return size_ == 0;
	}

	/// Returns a pointer to the beginning of the span
	T**
	data()
	{
		return data_.data();
	}
	/**
	 * 访问第Index条记录
	 * @param Index
	 * @return
	 */
	T* operator[](std::size_t Index) const
	{
		return data_[Index];
	}
	/// Returns the number of elements in the span
	std::size_t size() const
	{
		return size_;
	}

	/// Returns an iterator to the beginning of the span
	const_iterator begin() const
	{
		return data_.begin();
	}

	/// Returns an iterator to the beginning of the span
	const_iterator cbegin() const
	{
		return data_.cbegin();
	}

	/// Returns an iterator to one past the end of the span
	const_iterator end() const
	{
		return data_.end();
	}

	/// Returns an iterator to one past the end of the span
	const_iterator cend() const
	{
		return data_.cend();
	}

	void push_back(value_type p)
	{
		data_.push_back(p);
	}
};
template<class T>
typename multi_span<T>::const_iterator begin(const multi_span<T> &s)
{
	return s.begin();
}

template<class T>
typename multi_span<T>::const_iterator begin(const multi_span<T> *s)
{
	return s->begin();
}

template<class T>
typename multi_span<T>::const_iterator end(const multi_span<T> &s)
{
	return s.end();
}

template<class T>
typename multi_span<T>::const_iterator end(const multi_span<T> *s)
{
	return s->end();
}
}

#endif /* TRUNK_PUBLIC_SOURCES_UST_API_INCLUDE_COMMON_SPAN_HPP_ */
