#include <iostream>
#include <string>

using std::cout, std::cerr, std::endl, std::string, std::move;

template <typename T> struct d_arr {
  public:
    T *data;
    int size;

    d_arr() : data(0), size(0) {}
    d_arr(const d_arr &other);

    ~d_arr() { delete[] data; }

    void append(const T &element);
};

class item {
  public:
    string producer, name;
    int count;
    float value;
};

class inventory {
    d_arr<item *> items;

  public:
    inventory() : items() {}

    inventory(const inventory &copy) = delete;

    inventory(inventory &&move);

    // not neccessary since d_arr is allocated as an automtic variable
    // which will be deleted when the object goes out of context
    ~inventory() {}

    void add_item(item *i) { items.append(i); }

    void add_item(const string &producer, const string &name, float price = 0);
};

inventory::inventory(inventory &&temp) {
    for (int i = 0; i < items.size; i++) {
        items.data[i] = move(temp.items.data[i]);
    }
}

void inventory::add_item(const string &producer, const string &name,
                         float price) {}

int main(int argc, char **argv) { cout << "test" << endl; }
