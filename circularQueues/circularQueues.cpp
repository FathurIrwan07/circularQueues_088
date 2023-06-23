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
		cout << "Enter a Number :";
		cin >> num;
		cout << endl;

		//cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueues overflow\n";
			return;
		}

		//cek apakah antrian kosong
		if (FRONT == -1) {
			FRONT == 0;
			REAR == 0;
		}
		else {
			//jika REAR berada di posisi terakhir array, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_array[REAR] = num;
	}

	void remove() {
		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queues underflow\n";
			return;
		}
		cout << "\nThe element deleted from the queues is : " << queue_array[FRONT] << "\n";

		//cek jika antrian hanya memiliki satu element
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			//jika element yang di hapus berada diposisi terakhir array, kembali ke awal array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}

	void display() {
		int FRONT_position = FRONT;
		int REAR_position = REAR;

		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queues is empty\n";
			return;
		}

		cout << "\nElement in the queues are....\n";

		//jika FRONT_position <= REAR_position interasi dari FRONT hingga REAR
		if (FRONT_position <= REAR_position) {
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << " ";
				FRONT_position++;
			}
			FRONT_position = 0;

			//iterasi dari awal array hingga REAR
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << " ";
				FRONT_position++;
			}
			cout << endl;
		}
	}
};

int main() {
	Queues q;
	char ch;

	while (true) {
		try {
			cout << "Menu" << endl;
			cout << "1. Implement insert operation" << endl;
			cout << "2. Implement delate operation" << endl;
			cout << "3. Display value" << endl;
			cout << "4. Exit" << endl;
			cout << "Enter your choise (1-4) : ";
			cin >> ch;
			cout << endl;

			switch (ch) {
			case '1': {

				q.insert();
				break;
			}
			case '2': {

				q.remove();
				break;
			}
			case '3': {

				q.display();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option!!" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << "Check for the value entered." << endl;
		}
	}

	return 0;

}


		
		
