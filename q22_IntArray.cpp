#include<iostream>
using namespace std;

class IntArray {
private:
    int n;
    int* arr;

public:
    IntArray(int temp[], int size) : n(size) {
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }

    IntArray(const IntArray& other) : n(other.n) {
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~IntArray() {
        delete[] arr;
    }

    int* additionArray(int arr1[]) {
        int* sum = new int[n];
        for (int i = 0; i < n; i++) {
            sum[i] = arr[i] + arr1[i];
        }
        return sum;
    }

    void reverseArray() {
        for (int i = 0; i < n / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[n - 1 - i];
            arr[n - 1 - i] = temp;
        }
    }

    void sortArray() {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void printArray() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    int temp[n];
    cout << "Enter all elements in array: ";
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
    IntArray a1(temp, n);
    IntArray a2(a1);

    a1.printArray();
    a2.reverseArray();
    a1.printArray();
    a2.printArray();

    int arr1[n];
    cout << "Enter elements for the second array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int* sumArray = a1.additionArray(arr1);
    cout << "Sum of arrays: ";
    for (int i = 0; i < n; i++) {
        cout << sumArray[i] << " ";
    }
    cout << "\n";

    delete[] sumArray;

    return 0;
}
