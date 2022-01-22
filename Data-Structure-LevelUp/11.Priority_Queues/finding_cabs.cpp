#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Car {
   public:
    string id;
    int x;
    int y;
    Car(string id, int x, int y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int euclidDistance() const { return (x * x + y * y); }
};

class CarCompare {
   public:
    bool operator()(const Car A, const Car B) {
        return A.euclidDistance() < B.euclidDistance();
    }
};

void printNearestCars(vector<Car> cars, int k) {
    priority_queue<Car, vector<Car>, CarCompare> heap(cars.begin(),
                                                      cars.begin() + k);

    for (int i = k; i < cars.size(); i++) {
        auto car = cars[i];

        if (car.euclidDistance() < heap.top().euclidDistance()) {
            heap.pop();
            heap.push(car);
        }
    }
    vector<Car> output;
    while (!heap.empty()) {
        output.push_back(heap.top());
        heap.pop();
    }

    reverse(output.begin(), output.end());

    for (auto x : output) {
        cout << x.id << endl;
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    string id;
    int x, y;

    vector<Car> cars;

    while (N--) {
        cin >> id >> x >> y;
        Car car(id, x, y);
        cars.push_back(car);
    }

    printNearestCars(cars, K);
}