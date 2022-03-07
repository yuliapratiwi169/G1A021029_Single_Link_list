// C++ program to remove a given element from an array
#include<iostream>
using namespace std;

// fungsi ini untuk menghapus sebuah elemen x dari arr[] dan
// mengembalikan ukuran baru setelah penghapusan.
// ukuran yang dikembalikan adalah n-1 saat elemen ditampilkan.
// jika tidak 0 dikembalikan untuk menunjukkan kegagalan.
int deleteElement(int arr[], int n, int x)
{
// jika x adalah elemen terakhir, tidak ada hubungannya
if (arr[n-1] == x)
	return (n-1);

// mulai dari elemen paling kanan dan terus bergerak
// elemen berada satu posisi di depan.
int prev = arr[n-1], i;
for (i=n-2; i>=0 && arr[i]!=x; i--)
{
	int curr = arr[i];
	arr[i] = prev;
	prev = curr;
}

// jika elemen tidak ditemukan
if (i < 0)
	return 0;

// pilihan lain pindahkan elemen berikutnya di tempat x
arr[i] = prev;

return (n-1);
}

/* menjalankan program */
int main()
{
	int arr[] = {6, 2, 11, 1, 9, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 9;

	// Delete x from arr[]
	n = deleteElement(arr, n, x);

	cout << "Modified array is \n";
	for (int i=0; i<n; i++)
	cout << arr[i] << " ";

	return 0;
}