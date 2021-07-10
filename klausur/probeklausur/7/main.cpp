#include <iostream>
#include <exception>
#include <string>

using std::cout, std::cerr, std::endl, std::string, std::move, std::exception;

template<typename T>
struct d_arr {
public:
    T *data;
    int size;

    d_arr() : data(0), size(0) {}

    d_arr(const d_arr &other);

    ~d_arr() { delete[] data; }

    void append(const T &element);
};

class price_mismatch : public exception {
};

class missing_price : public exception {
};

class item {
public:
    string producer, name;
    int count = 1;
    float price;
};

class inventory {
    d_arr<item *> items;

public:
    inventory() : items() {}

    inventory(const inventory &copy) = delete;

    inventory(inventory &&move);

    // not necessary since d_arr is allocated as an automatic variable
    // which will be deleted when the object goes out of context
    ~inventory() = default;

    void add_item(item *i) { items.append(i); }

    void add_item(const string &producer, const string &name, float price = -1);
};

inventory::inventory(inventory &&temp) {
    items.data = other.items.data;
	items.size = other.items.size;
	temp.items.data = nullptr;
	temp.items.size = 0;
}

void inventory::add_item(const string &producer, const string &name,
                         float price) {
    for (int i = 0; i < items.size; i++) {
        item *current = items.data[i];

        if (current->producer == producer &&
            current->name == name) {

            if (price != -1 && current->price != price)
                throw price_mismatch();

            current->count++;
            return;
        }
    }

    if (price == -1)
        throw missing_price();

    items.append(new item{producer, name, 1, price});
}

int main(int argc, char **argv) {
    inventory i;
    i.add_item("vendor", "kapputtes phone", 100);
	i.add_item("vendor", "kaputtes phone");
}
