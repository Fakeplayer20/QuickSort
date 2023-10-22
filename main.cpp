#include <iostream>
#include <list>
#include <string.h>
#include <chrono>
#include <fstream>
#include <vector>

using namespace std;

void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "Hitro uredi -> izbira:" << endl;
    cout << "1 ... Generiraj nakljucno zaporedje" << endl;
    cout << "2 ... Generiraj narascujoce zaporedje " << endl;
    cout << "3 ... Generiraj padajoce zaporedje" << endl;
    cout << "4 ... Izpis zaporedja" << endl;
    cout << "5 ... Preveri ali je zaporedje urejeno" << endl;
    cout << "6 ... Uredi s hitrim urejanjem brez mediane" << endl;
    cout << "7 ... Uredi s hitrim urejanjem z mediano" << endl;
    cout << "8 ... Uredi z drugim algoritmom za urejanje" << endl; /* Te točke v prihodnje ne bom uporabljal*/
    cout << "0 ... KONEC" << endl;
    cout << "============================" << endl;
    cout << "IZBIRA: ";
}

string chekIfOrdered(vector<int> arrayOne) {
    for (int i = 0; i < arrayOne.size() - 1; i++) {
        if (arrayOne[i] > arrayOne[i + 1])
            return "ni urejeno";
    }
    return "je urejeno";
}

int split(vector<int>& arrayOne, int bottom, int top) {
    int first = arrayOne[bottom];
    int leftIndex = bottom;
    int rightIndex = top;

    while (leftIndex < rightIndex) {
        while (arrayOne[leftIndex] <= first && top > leftIndex)
            leftIndex++;
        while (arrayOne[rightIndex] >= first && bottom < rightIndex)
            rightIndex--;

        if (rightIndex > leftIndex)
            swap(arrayOne[leftIndex], arrayOne[rightIndex]);
    }

    swap(arrayOne[bottom], arrayOne[rightIndex]);
    return rightIndex;
}


void quickSort(vector<int>& arrayOne, int bottom, int top) {
    if (bottom < top) {
        int pivot = split(arrayOne, bottom, top);
        quickSort(arrayOne, bottom, pivot - 1);
        quickSort(arrayOne, pivot + 1, top);
    }
}
void quickSortMedian(vector<int>& arrayOne, int bottom, int top) {
    if (bottom < top) {

        int middle = bottom + (top -bottom) / 2;
        swap(arrayOne[bottom], arrayOne[middle]);

        int pivot = split(arrayOne, bottom, top);
        quickSort(arrayOne, bottom, pivot - 1);
        quickSort(arrayOne, pivot + 1, top);
    }
}



int main() {


    vector<int> arrayOne;
    int value;
    bool running = true;
    int selection;
    string ordered;

    do {
        menu();
        cin >> selection;

        switch (selection) {
            case 1:
                cout << "Vpisite zeljeno dolzino:" << endl;
                cin >> value;
                arrayOne.clear();
                for (int i = 0; i < value; i++)
                    arrayOne.push_back(rand() % 1000000 + 1);

                break;
            case 2:
                cout << "Vpisite zeljeno dolzino za narascajoce zaporedje:" << endl;
                cin >> value;
                arrayOne.clear();
                for (int i = 0; i < value; i++) {
                    arrayOne.push_back(i + 1);
    cout <<  arrayOne.push_back(i + 1) << endl;
                }
                break;
            case 3:
                cout << "Vpisite zeljeno dolzino za narascajoce zaporedje:" << endl;
                cin >> value;
                arrayOne.clear();
                for (int i = 0; i < value; i++){
                    arrayOne.push_back(value - i);
cout <<  arrayOne.push_back(i - 1) << endl;
                }
                break;
            case 4:
                for (int i = 0; i < arrayOne.size(); i++)
                    cout << arrayOne[i] << " ";
                cout << endl;
                break;

            case 5:
                if (arrayOne.empty()) {
                    cout << " Polje je prazno" << endl;
                } else {
                    ordered = chekIfOrdered(arrayOne);
                    cout << "Zaporedje " << ordered << endl;
                }
                break;
            case 6:{
                auto start = std::chrono::steady_clock::now();
                if (arrayOne.empty()) {
                    cout << " Polje je prazno" << endl;
                } else {
                    quickSort(arrayOne, 0, arrayOne.size() - 1);
                }
                auto end = std::chrono::steady_clock::now();
                std::cout << "Cas urejanja quick sorta brez mediane ->"
                          << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
                          << " nanosekund."
                          << std::endl;
        }
                break;
            case 7: {
                auto start = std::chrono::steady_clock::now();
                if (arrayOne.empty()) {
                    cout << " Polje je prazno" << endl;
                } else {
                    quickSortMedian(arrayOne, 0, arrayOne.size() - 1);
                }

                auto end = std::chrono::steady_clock::now();
               std::cout << "Cas urejanja quick sorta z mediano ->"
                         << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
                         << " nanosekund."
                         << std::endl;
            }
                     break;
            case 8:{
                auto start = std::chrono::steady_clock::now();
                if (arrayOne.empty()) {
                    cout << " Polje je prazno" << endl;
                } else {
                    selectionSort(arrayOne);
                }
                auto end = std::chrono::steady_clock::now();
                std::cout << "Cas urejanja selection sorta ->"
                          << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
                          << " nanosekund."
                          << std::endl;
        }
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Napacna izbira!" << endl;
                break;
        }
        cout << endl;
    } while (running);


    return 0;
}
