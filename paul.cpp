#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class K, class D>
class AVL;

template <class K, class D>
class Node{
private:
  K key;
  D dato;
  int height;
  Node<K,D>* p_child[2];
public:
  Node(const K & _key, const D & _dato):key(_key),dato(_dato){
    height=0;
    p_child[0] = NULL; 
    p_child[1] = NULL;
  }
  friend class AVL<K,D>;
};

template <class K, class D>
class AVL{
private:
  Node<K,D>* root;
public:
  AVL();
  ~AVL();
  bool insert(const K & key, const D & dato);
  bool find(Node<K,D>**&tmp,const K & k);
  void print();
};

template <class K, class D>
AVL<K,D>::AVL(){
  root=NULL;
}

template <class   K, class D>
AVL<K,D>::~AVL(){
  //librerar memoria delete  
}


template <class K,class D>
bool AVL<K,D>::find(Node<K,D>**& tmp,const K & key){
    tmp=&root;
    while(*tmp){
      if((*tmp)->key==key) return true;
      tmp=&(*tmp)->p_child[(*tmp)->key<key];
    }
    return false;

}

template <class K, class D>
bool AVL<K,D>::insert(K & key,D & dato){
  return insert(& root,key,dato);
  }
template <class K, class D>
bool AVL<K,D>::insert(Node<K,D>** n,const K & key,const D & dato){
      if(!*n){
        *n=new Node<K,D>(key,dato);
        return true;
      }
      if((*n)->key==key) return false;
      int d=key->(*n)->key;
      if (insert(&(*n)->p_child[d],key,dato)) return false;
      (*n)->h=max((*n)->p_child[0]->h,(*n)->p_child[1]->h)+1;
      int f = (*n)->p_child[0]->h - (*n)->p_child[1]->h;
      
    }









int main(){
  AVL<int,int> avl;
  avl.insert(1,4);
  avl.insert(2,5);
  
}