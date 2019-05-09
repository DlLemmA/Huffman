#pragma once
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX_TREE_HT 256 

struct MinHeapNode
{
	char data;
	int freq;
	MinHeapNode *left, *right;

	MinHeapNode(char data, int freq) {
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};

class Huffman_code
{

public:
	map<char, string> codes;
	map<char, int> freq;
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    MinHeapNode *root;

	Huffman_code();
	~Huffman_code();
	void printTree(struct MinHeapNode* ptr, string str, int level);
	void printTable();
	void storeCodes(struct MinHeapNode* root, string str);
	void HuffmanCodes(int size);
	void calcFreq(string str, int n);
	string decode_string(struct MinHeapNode* root, string s);
};

