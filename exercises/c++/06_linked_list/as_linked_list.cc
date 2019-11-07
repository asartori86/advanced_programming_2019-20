#include <iostream>
#include <memory>  //unique_ptr

#include "ap_error.h"

enum class method { push_back, push_front };

template <class T>
class List {
  struct node {
    std::unique_ptr<node> next;
    T value;
    node(const T& v, node* p) : next{p}, value{v} {
      std::cout << "copy ctor" << std::endl;
    }
    node(T&& v, node* p) : next{p}, value{std::move(v)} {
      std::cout << "move ctor" << std::endl;
    }
    node(const std::unique_ptr<node>& p) : value{p->value} {
      if (p->next)
        next = std::make_unique<node>(p->next);
    }
  };

  std::unique_ptr<node> head;

  template <class OT>
  void push_back(OT&& v);

  template <class OT>
  void push_front(OT&& v) {
    // auto h = head.release();
    // auto new_node = new node {v,h};
    // head.reset(new_node);

    // head.reset(new node{v, head.release()});

    head = std::make_unique<node>(std::forward<OT>(v), head.release());
  }
  // void push_front(T&& v);

  node* tail();

 public:
  List() noexcept = default;
  List(List&& l) noexcept = default;
  List& operator=(List&& l) noexcept = default;

  List(const List& l);
  List& operator=(const List& l);

  template <class OT>
  void insert(OT&& v, const method m);

  template <class O>
  friend std::ostream& operator<<(std::ostream&, const List<O>&);
};

template <class T>
typename List<T>::node* List<T>::tail() {
  auto tmp = head.get();

  while (tmp->next)
    tmp = tmp->next.get();

  return tmp;
}

template <class T>
template <class OT>
void List<T>::insert(OT&& v, const method m) {
  if (!head) {
    // head.reset(new node{v,nullptr});
    head = std::make_unique<node>(std::forward<OT>(v), nullptr);
    return;
  }
  switch (m) {
    case method::push_back:
      push_back(std::forward<OT>(v));
      break;

    case method::push_front:
      push_front(std::forward<OT>(v));
      break;
    default:
      AP_ERROR(false) << "Unknown insertion method";
      break;
  };
}

template <class T>
template <class OT>
void List<T>::push_back(OT&& v) {
  node* last = tail();
  // last->next.reset(new node{v, nullptr});
  last->next = std::make_unique<node>(std::forward<OT>(v), nullptr);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& l) {
  auto tmp = l.head.get();
  while (tmp) {
    os << tmp->value << " ";
    tmp = tmp->next.get();
  }
  return os;
}

template <class T>
List<T>::List(const List& l) {
  // auto tmp = l.head.get();
  // while(tmp){
  //   insert(tmp->value,method::push_back);
  //   tmp=tmp->next.get();
  // }
  head = std::make_unique<node>(l.head);
}

int main() {
  try {
    List<int> l{};

    l.insert(4, method::push_back);
    l.insert(5, method::push_back);
    l.insert(3, method::push_front);

    std::cout << l << std::endl;

    auto ol = l;
    int a = 9;
    l.insert(14, method::push_front);
    l.insert(a, method::push_front);

    std::cout << l << std::endl;
    std::cout << ol << std::endl;

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception" << std::endl;
  }

  return 0;
}
