#include "Huffman_code.h"
#include <iostream>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	Huffman_code example;
	string str = "Huffman Code is awesowe to encode message";
	string encodedString, decodedString;
	example.calcFreq(str, str.length());
	example.HuffmanCodes(str.length());
	cout << "Character With there Frequencies:\n";
	example.printTable();

	for (auto i : str) {
		encodedString += example.codes[i];
	}
	decodedString = example.decode_string(example.minHeap.top(), encodedString);
	encodedString = ' ';
	for (auto i : str) {
		encodedString += example.codes[i] + ' ';
	}
	cout << "\nEncoded Huffman data:\n" << encodedString << endl;

	cout << "\nDecoded Huffman Data:\n" << decodedString << endl;
	system("pause");
	return 0;
}
