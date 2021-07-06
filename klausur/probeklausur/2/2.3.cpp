
struct coord_2d {
    float x, y;
    coord_2d() : x(0), y(0) {}
};

int main() {
    coord_2d pos(); // error: compiler thinks this is a function (this only is a problem with empty constructors)
    // coord_2d pos(2); for example would work if coord_2d had a constructor : coord_2d(int i);
    pos.x = 0;
    return 0;
}
