#pragma once

#include "common.h"
#include <hash_map>


typedef struct
{
	int* elem;
	int count;
}HashTable;

int m = 0;
#define HASHSIZE 12
#define NULLKEY -32768

int InitHashTable(HashTable* H)
{
	int i;
	m = HASHSIZE;
	H->count = m;
	H->elem = (int*)malloc(m * sizeof(int));
	for (i = 0; i < m; i++)
	{
		H->elem[i] = NULLKEY;
	}
	return 0;
}


int Hash(int key)
{
	return key % m;
}

void InsertHash(HashTable* H, int key)
{
	int addr = Hash(key);
	while (H->elem[addr] != NULLKEY)
	{
		addr = (addr + 1) % m;
	}
	H->elem[addr] = key;
}

int SearchHash(HashTable H, int key, int* addr)
{
	*addr = Hash(key);
	while (H.elem[*addr] != key)
	{
		*addr = (*addr + 1) % m;
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key))
		{
			return -1;
		}
	}
	return 0;
}