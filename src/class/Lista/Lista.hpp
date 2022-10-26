//template class T
//template class E

namespace Listas
{
  template <class TL>
  class Lista 
  {  
    public:
      template <class E>
      class Elemento
      {
        private:
          Elemento<E>* next;
          E* info;

        public:
          Elemento() 
          {
            next = NULL;
            info = NULL;
          }
          ~Elemento() {}

          Elemento<E>* getNext() { return this->next; }
          void setNext(Elemento<E>* p) { this->next = p}
          E* getInfo() { }
      };

    private:
      Elemento<TL>* first;
      Elemento<TL>* last;

    public:
      Lista() 
      {
        this->first = NULL;
        this->last = NULL;
      }
      ~Lista() {}

      Elemento<TL>* getFirst()
      {
        return this->first;
      }
      Elemento<TL>* getLast()
      {
        return this->last;
      }

      void setFirst(Elemento<TL>* p)
      {
        this->first = p;
      }
      void setLast(Elemento<TL>* p)
      {
        this->last = p;
      }
  };
  
}