#pragma once
#include "common.h"


struct Chunk
{
	void Init(std::size_t blocksize, unsigned char blocks);
	void Release();
	void* Allocate(std::size_t blocksize);
	void Deallocate(void* p, std::size_t blockSize);
	unsigned char* pData_;
	unsigned char firstAvailableBlock_;
	unsigned char blockAvaliable_;
};


class FixedAllocator
{
private:
	std::size_t blockSize_;
	unsigned char numBlocks_;
	typedef std::vector<Chunk> Chunks;
	Chunks chunks_;
	Chunk* allocChunk_;
	Chunk* deallocChunk_;

public:
	void* Allocate();
};


class SmallObjAllocator
{
public:
	SmallObjAllocator(std::size_t chunkSize, std::size_t maxObjectSize);
	void* Allocate(std::size_t numBytes);
	void Deallocate(void* p, std::size_t size);

private:
	std::vector<FixedAllocator> pool_;
	FixedAllocator* pLastAlloc_;
	FixedAllocator* pL
};