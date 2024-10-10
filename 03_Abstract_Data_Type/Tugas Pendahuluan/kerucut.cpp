#include <iostream>
#include <cmath>

using namespace std;

struct Kerucut {
    double radius;
    double tinggi;
};
void inputKerucut(Kerucut &k);
float volumeKerucut(Kerucut k);
float luaspermukaanKerucut(Kerucut k);

int main(){
    Kerucut k;

    inputKerucut(k);

    cout << "Volume kerucut = " << volumeKerucut(k) <<endl;
    cout << "Luas Permukaan Kerucut = " << luaspermukaanKerucut(k) <<endl;

    return 0;
}
void inputKerucut(Kerucut &k){
    cout << "masukan jari-jari kerucut = ";
    cin >> k.radius;
    cout << "Masukan tinggi kerucut = ";
    cin >> k.tinggi;
}
float volumeKerucut(Kerucut k){
    return (1.0 / 3) * M_PI * k.radius * k.radius * k.tinggi;
}
float luaspermukaanKerucut(Kerucut k){
    double s = sqrt((k.radius * k.radius) + (k.tinggi * k.tinggi));
    return M_PI * k.radius * (k.radius + s);
}