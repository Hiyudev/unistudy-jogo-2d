#include <iostream>

namespace Listas
{
  template <class T>
  class Lista
  {
    private:
      template <class U>
      class Elemento
      {
        private:
          Elemento<U>* next;
          Elemento<U>* previous;
          U* info;

        public:
          Elemento()
					{
					  this->next = NULL;
					  this->previous = NULL;
					  this->info = NULL;
					}
          Elemento(U* info)
					{
  					this->next = NULL;
					  this->previous = NULL;
					  this->info = info;
					}
          Elemento(Elemento<U> *next, Elemento<U>* previous, U *info) {
						this->next = next;
						this->previous = previous;
						this->info = info;
					}
          Elemento(Elemento<U> *next, U *info) {
  					this->next = next;
					  this->info = info;
					}
          ~Elemento() {
						delete this->info;
  					this->next = NULL;
					  this->info = NULL;
					}

					Elemento<U>* getNext() {
						return this->next;
					}
          void setNext(Elemento<U>* next)
					{
					  this->next = next;
					}

					Elemento<U>* getPrevious() {
						return this->previous;
					}
					void setPrevious(Elemento<U>* previous)
					{
						this->previous = previous;
					}

          void setInfo(U* info)
					{
					  this->info = info;
					}
					U* getInfo() {
						return this->info;
					}
					
      };

    private:
      Elemento<T>* first;
      Elemento<T>* last;
			int length;

    public:
      Lista(){
  			this->first = NULL;
			  this->last = NULL;
			}
      ~Lista(){
  			this->first = NULL;
			  this->last = NULL;
			}

      void push(T* info)  {
  			Elemento<T> *el = new Elemento<T>(info);
				
			  if (this->first == NULL) {
			    this->first = el;
			  }

				if(this->last != NULL)
				{
			  	this->last->setNext(el);
				}

				el->setPrevious(this->last);
				
			  this->last = el;
			}

			void pop()
			{
				if(this->last != NULL)
				{
					Elemento<T> prev = this->last->getPrevious();
					if(prev != NULL)
					{
						prev->next = NULL;
					}

					delete this->last;
					this->last = prev;
				}
			}

			T* operator[](int index) {
				Elemento<T>* curr = this->first;

				int i = 0;
				while(first != NULL && i != index)
					{
						curr = curr->getNext();
					}

				return curr->getInfo();
			}

			int getLength()
				{
				return this->length;	
				}
  };
}
