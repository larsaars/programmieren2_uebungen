

int main() {
    int a = 0;
    int &b = a;
    int &c = &a;
    int &d = &b;
    int &e = 5;
    int &f = b;
    return 0;
}
