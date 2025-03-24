#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");


    const double TANK = 300.;
    double dist_ab, dist_bc, weight, fuel_per_km;

    cout << "Введите растояние 1, растояние 2 и вес груза через пробел." << endl;

    cin >> dist_ab >> dist_bc >> weight;
       
    if (weight <= 500) {
        fuel_per_km = 1;
    }
    else if (weight <= 1000) {
        fuel_per_km = 4;
    }
    else if (weight <= 1500) {
        fuel_per_km = 7;
    }
    else if (weight <= 2000) {
        fuel_per_km = 9;
    }
    else {
        cout << "Не взлетим";
        return 0; 
    }
    
    double fuel_ab = dist_ab * fuel_per_km;
    double fuel_bc = dist_bc * fuel_per_km;
    
    if (fuel_ab > TANK || fuel_bc > TANK) {
        cout << "Не сможем пролететь. Не хватит топлива.";
        return 0;
    }
   
    double remain = TANK - fuel_ab;
    if (remain >= fuel_bc) {
        
        cout << "Дозаправка не нужна!";
    }
    else {
        cout << "Дозаправка - " << fuel_bc - remain;
    }
    return 0;
}