//template class T
//template class E

namespace Listas
{
  template <class T>
  class Lista 
  {  
    public:
      class Elemento
      {
        private:
          Elemento<E> *next;
          E *info;

        public:
          Elemento();
          ~Elemento();

          Elemento<E>* getNext();
          void setNext(Elemento<E>* E);
          E* getInfo();
      };

    private:
      Elemento<T>* first;
      Elemento<T>* last

    public:
      Lista();
      ~Lista();

      Elemento<T>* getFirst()
      {
        return first;
      }
      Elemento<T>* getLast()
      {
        return last;
      }

      void setFirst(Elemento<T>* p)
      {
        first = p;
      }
      void setLast(Elemento<T>* p)
      {
        last = p;
      }
  };

  template<class T>
  Lista<T>::Lista()
  {
    first = NULL;
    last = NULL;
  }

  template<class T>
  Lista<T>::~Lista()
  {
    
  }



  
}