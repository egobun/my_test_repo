#include<iostream>
using namespace std;
struct root {
	int time_stamp;
	int id;
	int ca;
	int o2_air;
	int co2_air;
	int k;
	int ph;
};
int main() {
	int n;
	cin >> n;
	root* arr = new root[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].time_stamp;
		cin >> arr[i].id;
		cin >> arr[i].ca;
		cin >> arr[i].o2_air;
		cin >> arr[i].co2_air;
		cin >> arr[i].k;
		cin >> arr[i].ph;
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (arr[i].time_stamp > arr[i + 1].time_stamp) {
				root tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
	int help[100];
	for (int i = 0; i < 100; i++) {
		help[i] = 0;
	}
	int k = 0;
	int help_n = 0;
	int counter = 0;
	for (int i = -1; i < n-1; i++) {
		//and arr[i + 1].co2_air < arr[i].co2_airand arr[i + 1].ca >= arr[i].ca
		if (arr[i+1].time_stamp == (arr[i].time_stamp + 1) and arr[i + 1].co2_air < arr[i].co2_air and arr[i + 1].ca >= arr[i].ca) {
			counter += 1;
			//help[i] = counter;
		}
		else {
			k++;
			help[help_n] = counter;
			help_n++;
			counter = 0;
		}
	}

	int max = 0;
	for (int i = 0; i < help_n; i++) {
		if (help[i]>max) {
			max = help[i];
		}
	}
	if(k!=0)
	cout << max;
	else
	cout << counter;
	delete[] arr;
	return 0;
}