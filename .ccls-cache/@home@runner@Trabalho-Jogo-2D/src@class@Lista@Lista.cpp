#include "Lista.hpp"
#include <iostream>

using namespace Listas;

template <class T> template <class U> Lista<T>::Elemento<U>::Elemento() {
  this->next = NULL;
  this->info = NULL;
}

template <class T> template <class U> Lista<T>::Elemento<U>::Elemento(U *info) {
  this->next = NULL;
  this->info = info;
}

template <class T>
template <class U>
Lista<T>::Elemento<U>::Elemento(Elemento<U> *next, U *info) {
  this->next = next;
  this->info = info;
}

template <class T> template <class U> Lista<T>::Elemento<U>::~Elemento() {
  this->next = NULL;
  this->info = NULL;
}

template <class T>
template <class U>
void Lista<T>::Elemento<U>::setNext(Elemento<U> *next) {
  this->next = next;
}

template <class T>
template <class U>
void Lista<T>::Elemento<U>::setInfo(U *info) {
  this->info = info;
}

template <class T> Lista<T>::Lista() {
  this->first = NULL;
  this->last = NULL;
}
template <class T> Lista<T>::~Lista() {
  this->first = NULL;
  this->last = NULL;
}

template <class T> void Lista<T>::push(T *info) {
  Elemento<T> *el = new Elemento<T>(info);
  if (this->first == NULL) {
    this->first = el;
  }
  this->last->setNext(el);
  this->last = el;
}

template <class T>
T* Lista<T>::operator[](int index)
{
	
}