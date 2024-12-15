function run() {
    f=$1
    g++ -g -O2 -std=gnu++20 -static -o $f $f.cpp && ./$f
}