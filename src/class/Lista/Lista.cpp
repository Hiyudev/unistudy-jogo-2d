#include "Lista.hpp"
#include <iostream>

using namespace Listas;

Lista::Elemento::Elemento() {
  this->next = NULL;
  this->info = NULL;
};

Lista::Elemento::~Elemento() {
  this->next = NULL;
  this->info = NULL;
}

Lista::Lista(){
  this->first = NULL;
};

Lista::~Lista(){};