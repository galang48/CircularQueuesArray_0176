#include <iostream>
using namespace std;

class Queues {
    int FRONT, REAR, max = 5;
    int queue_array[5];

public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    void insert() {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        // Cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }
        else {
            // Jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    void remove() {
        // Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        // Cek jika antrian memiliki satu elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            // Jika elemen yang dihapus berada di posisi terakhir array, kembali ke array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    void display() {

        // Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElement in the queue are...\n";

        // Jika FRONT <= REAR, iterasi dari FRONT hingga REAR
        if (FRONT <= REAR) {
            while (FRONT <= REAR) {
                cout << queue_array[FRONT] << "  ";
                FRONT++;
            }
            cout << endl;
        }
        else {
            // jika FRONT > REAR, iterasi dari FRONT hingga akhir array
            while (FRONT <= max - 1) {
                cout << queue_array[FRONT] << "  ";
                FRONT++;
            }

            FRONT = 0;

            // Iterasi dari awal array hingga REAR
            while (FRONT <= REAR) {
                cout << queue_array[FRONT] << "  ";
                FRONT++;
            }
        }
    }
};
int main()
{
    
}


