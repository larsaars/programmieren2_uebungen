#include "fur.h"

void Fur::grow(int time)  {
    len += time;
}

void Fur::print() {
    cout << "fur color: "  << color
        << "fur len: " << len;
}
