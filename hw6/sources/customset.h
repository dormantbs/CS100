#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <memory>
#include <algorithm>

#ifndef H_customset
#define H_customset

template <typename T>
class CustomSet
{
public:
	// Constructors and destructor:
	CustomSet();
	CustomSet(const CustomSet& other);
	CustomSet(T arr[], int size);
	~CustomSet() {}

// Other member functions:
	int size() const;
	bool add(const T& item);
	T* find(const T& item);
	bool erase(const T& item);
	CustomSet intersection(const CustomSet& other);
	void sortSet();
	void printSet();
	T* begin() const;
	T* end() const;

// Operators:
	CustomSet operator+ (const T& item);
	CustomSet operator+ (const CustomSet& that);
	CustomSet& operator+= (const T& item);
	CustomSet& operator+= (const CustomSet& that);

	CustomSet operator- (const T& item);
	CustomSet operator- (const CustomSet& that);
	CustomSet& operator-= (const T& item);
	CustomSet& operator-= (const CustomSet& that);


	CustomSet<std::pair<T, T>> operator* (const CustomSet& that);

private:
	std::vector<T> data;
};


template<typename T>
T* CustomSet<T>::begin() const{
	return data.begin()._Ptr;
}

template<typename T>
T* CustomSet<T>::end() const {
	return data.end()._Ptr;
}

template<typename T>
CustomSet<T>::CustomSet() {
	data.clear();
}

template<typename T>
CustomSet<T>::CustomSet(const CustomSet<T>& other){
	for (auto v : other.data) data.push_back(v);
}
template<typename T>
CustomSet<T>::CustomSet(T arr[], int size) {
	for (int i = 0; i < size; ++i) data.push_back(arr[i]);
}

template<typename T>
int CustomSet<T>::size() const {
	return data.size();
}

template<typename T>
bool CustomSet<T>::add(const T& item) {
	for (auto v : data) {
		if (v == item) return false;
	}
	data.push_back(item);
	return true;
}

template<typename T>
T* CustomSet<T>::find(const T& item) {
	typename std::vector<T>::iterator it 
		= std::find(data.begin(), data.end(), item);

	if (it != data.end())
		return &(*it);
	return nullptr;
}

template<typename T>
bool CustomSet<T>::erase(const T& item) {
	typename std::vector<T>::iterator it =
		std::find(data.begin(), data.end(), item);
	if (it == data.end()) return false;
	data.erase(it);
	return true;
}

template<typename T>
CustomSet<T> CustomSet<T>::intersection(const CustomSet<T>& other) {
	CustomSet<T> res;
	for (auto v : other.data) {
		if (find(v) != nullptr)
			res += v;
	}
	return res;
}

template<typename T>
void CustomSet<T>::sortSet() {
	std::sort(data.begin(), data.end());
}

template<typename T>
void CustomSet<T>::printSet() {
	putchar('{');
	T end_data = *(data.end() - 1);
	for (auto v : data) {
		std::cout << v;
		if (v != end_data) {
			std::cout << ", ";
		}
	}
	putchar('}');
	putchar('\n');
}

template<typename T>
CustomSet<T> CustomSet<T>::operator+ (const T& item) {
	this->add(item);
	return *this;
}

template<typename T>
CustomSet<T> CustomSet<T>::operator+ (const CustomSet<T>& that) {
	for (auto v : that.data) {
		this->add(v);
	}
	return *this;
}

template<typename T>
CustomSet<T>& CustomSet<T>::operator+= (const T& item) {
	*this = *this + item;
	return *this;
}

template<typename T>
CustomSet<T>& CustomSet<T>::operator+= (const CustomSet<T>& that) {
	*this = *this + that;
	return *this;
}

template<typename T>
CustomSet<T> CustomSet<T>::operator- (const T& item) {
	this->erase(item);
	return *this;
}

template<typename T>
CustomSet<T> CustomSet<T>::operator- (const CustomSet<T>& that) {
	for (auto v : that.data) {
		this->erase(v);
	}
	return *this;
}

template<typename T>
CustomSet<T>& CustomSet<T>::operator-= (const T& item) {
	*this = *this - item;
	return *this;
}

template<typename T>
CustomSet<T>& CustomSet<T>::operator-= (const CustomSet<T>& that) {
	*this = *this - that;
	return *this;
}

template<typename T>
CustomSet<std::pair<T, T>> CustomSet<T>::operator* (const CustomSet<T>& that) {
	CustomSet<std::pair<T, T>> res;
	for (auto u : this->data) {
		for (auto v : that.data)
			res.data.push_back(std::pair<T, T>(u, v));
	}

	return res;
}

#endif
