#include <iostream>  // std::cout
#include <memory>    // std::unique_ptr
#include <utility>   // std::move
#include <vector>

template <typename T>
// requires:
// T has default ctor (called in the array of T)
// T has copy and move assignment
class Vector {
  std::size_t _size{};
  std::unique_ptr<T[]> elem{};
  std::size_t _capacity{};

  void check_and_increase_capacity() {
    if (_capacity == 0)
      reserve(8);
    if (_size == _capacity)
      reserve(2 * _size);
  }

 public:
  auto size() const noexcept { return _size; }
  auto capacity() const noexcept { return _capacity; }

  T& operator[](const std::size_t i) noexcept {
    // preconditions: elem != nullptr and i < _size
    return elem[i];
  }

  const T& operator[](const std::size_t i) const noexcept {
    // preconditions: elem != nullptr and i < _size
    return elem[i];
  }

  Vector() = default;

  // custom ctor
  explicit Vector(const std::size_t& lenght)
      : _size(lenght), elem{new T[lenght]{}}, _capacity{lenght} {}

  void reserve(const std::size_t new_size) {
    if (_capacity < new_size) {
      T* new_array = new T[new_size];

      for (std::size_t i = 0; i < _size; ++i)
        new_array[i] = std::move(elem[i]);

      elem.reset(new_array);
      _capacity = new_size;
    }
  }

  // template <typename OT>
  // void push_back(OT&& x){
  //   check_and_increase_capacity();
  //   elem[_size] = std::forward<OT>(x);
  //   ++_size;
  // }

  void push_back(const T& x) {
    check_and_increase_capacity();
    elem[_size] = x;
    ++_size;
  }

  void push_back(T&& x) {
    check_and_increase_capacity();
    elem[_size] = std::move(x);
    ++_size;
  }

  // variadic templates
  template <typename... Types>  // parameter pack
  void emplace_back(Types&&... args) {
    check_and_increase_capacity();
    elem[_size] = T{std::forward<Types>(args)...};
    ++_size;
  }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& x) {
  os << "size " << x.size() << "\n"
     << "capacity " << x.capacity() << "\n";
  for (std::size_t i = 0; i < x.size(); ++i)
    os << x[i] << " ";

  os << std::endl;

  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& x) {
  os << "size " << x.size() << "\n"
     << "capacity " << x.capacity() << "\n";
  for (std::size_t i = 0; i < x.size(); ++i)
    os << x[i] << " ";

  os << std::endl;

  return os;
}

struct Date {
  int d, m, y;
  Date() { std::cout << "default ctor" << std::endl; }
  Date(int d, int m, int y) : d{d}, m{m}, y{y} {}
};

std::ostream& operator<<(std::ostream& os, const Date& x) {
  os << x.d << "/" << x.m << "/" << x.y << std::endl;
  return os;
}

int main() {
  // Vector<Date> v;
  std::vector<Date> v;
  std::cout << v << std::endl;
  Date x{1, 2, 3};
  v.push_back(x);  // const T&

  // v.push_back(Date{4,5,6});

  v.emplace_back(4, 5, 6);
  v.emplace_back();

  std::cout << v << std::endl;

  return 0;
}
