#include "Huffman_code.h"
#include <iostream>
#include <string>

using namespace std;

Huffman_code::Huffman_code()
{
}

void Huffman_code::printTree(struct MinHeapNode* ptr, string str, int level)
{
	if (ptr != NULL) {
		printTree(ptr->right, str + "1", level + 1);
		cout << endl;
		if (ptr == root) {
			cout << "Root->:  ";
		}
		else {
			for (int i = 0; i < level; i++) {
				for (int j = 0; j < i; j++) {
					cout << "         ";
				}
			}
		}
		cout << "Code: " << str << ' ';
		if (ptr->data != '$') {
			cout << "Char: " << ptr->data << ' ';
			cout << "Freq: " << ptr->freq << ' ';
		}
		printTree(ptr->left, str + "0", level + 1);
	}
}

void Huffman_code::storeCodes(struct MinHeapNode* root, string str)
{
	if (root == NULL) {
		return;
	}
	if (root->data != '$') {
		codes[root->data] = str;
	}
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}

void Huffman_code::printTable() {
	for (auto v = codes.begin(); v != codes.end(); v++) {
		cout << v->first << ' ' << v->second << endl;
	}
}


void Huffman_code::HuffmanCodes(int size)
{
	struct MinHeapNode *left, *right, *top;
	for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++) {
		minHeap.push(new MinHeapNode(v->first, v->second));
	}
	while (minHeap.size() != 1) {
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");
	printTree(minHeap.top(), "", 0);
	cout << endl << endl;
}


void Huffman_code::calcFreq(string str, int n)
{
	for (int i = 0; i < str.size(); i++) {
		freq[str[i]]++;
	}
}


string Huffman_code::decode_string(struct MinHeapNode *root, string s)
{
	string ans = "";
	struct MinHeapNode* curr = root;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			curr = curr->left;
		} else {
			curr = curr->right;
		} if (curr->left == NULL and curr->right == NULL) {
			ans += curr->data;
			curr = root;
		}
	}
	return ans + '\0';
}

Huffman_code::~Huffman_code()
{
}
