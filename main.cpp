#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

void genlist(int *list, int quantity, int minmax);

int minLocalMax(int *list, int quantity);

int maxLocalMin(int *list, int quantity);

void printresult(int maxLocalMin1, int minLocalMax1);
int main() {
    char answer;

    do{
        srand(time(nullptr));
        int quantity;
        int minmax;
        cout << "Enter the number of elements: ";
        cin >> quantity;
        if (quantity < 3) {
            cout << "The number of elements must be at least 3" << endl;
            continue;
        }
        cout << "Enter the minimum and maximum values: ";
        cin >> minmax;
        if (minmax < 1) {
            cout << "The minimum and maximum values must be at least 1" << endl;
            continue;
        }
        int *list = new int[quantity];
        genlist(list, quantity, minmax);
        int maxLocalMin1 = maxLocalMin(list, quantity);
        int minLocalMax1 = minLocalMax(list, quantity);
        printresult(maxLocalMin1, minLocalMax1);
        delete[] list;
        cout << "Do you want to try again? (y/n): ";
        cin >> answer;
    } while (answer != 'n');
    return 0;
}

void genlist(int *list, int quantity, int minmax) {
    for (int i = 0; i < quantity; i++) {
        list[i] = rand() % (2 * minmax + 1) - minmax;
        cout << list[i] << " ";
    }
    cout << endl;
}

int minLocalMax(int *list, int quantity) {
    int minLocalMax = 1000000;
    for (int i = 0; i < quantity - 1; i++) {
        if ((i == 0 && list[i] > list[i + 1]) ||
            (i > 0 && i < quantity - 1 && list[i] > list[i - 1] && list[i] > list[i + 1]) ||
            (i == quantity - 1 && list[i] > list[i - 1])) {
            if (list[i] < minLocalMax) {
                minLocalMax = list[i];
            }
        }
    }
    return minLocalMax;
}

int maxLocalMin(int *list, int quantity) {
    int maxLocalMin = -1000000;
    for (int i = 0; i < quantity - 1; i++) {
        if (i == 0 && list[i] < list[i + 1] ||
            (i > 0 && i < quantity - 1 && list[i] < list[i - 1] && list[i] < list[i + 1]) ||
            (i == quantity - 1 && list[i] < list[i - 1])) {
            if (list[i] > maxLocalMin) {
                maxLocalMin = list[i];
            }
        }
    }
    return maxLocalMin;
}
void printresult(int maxLocalMin1, int minLocalMax1) {
    if (maxLocalMin1 == -1000000) {
        cout << "There is no local minimum in the list" << endl;
    } else {
        cout << "The maximum local minimum is: " << maxLocalMin1 << endl;
    }
    if (minLocalMax1 == 1000000) {
        cout << "There is no local maximum in the list" << endl;
    } else {
        cout << "The minimum local maximum is: " << minLocalMax1 << endl;
    }
}

