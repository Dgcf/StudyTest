#include "MemAlloc.h"


void Chunk::Init(std::size_t blocksize, unsigned char blocks)
{
	pData_ = new unsigned char[blocksize * blocks];
	firstAvailableBlock_ = 0;
	blockAvaliable_ = blocks;
	unsigned char i = 0;
	unsigned char* p = pData_;
	for (; i != blocks; p += blocksize)
	{
		*p = ++i;
	}
}

void Chunk::Release()
{
}

void* Chunk::Allocate(std::size_t blocksize)
{
	if (!blockAvaliable_)
	{
		return nullptr;
	}
	unsigned char* pResult = pData_ + (firstAvailableBlock_ * blocksize);
	firstAvailableBlock_ = *pResult;
	--blockAvaliable_;
	return pResult;
}

void Chunk::Deallocate(void* p, std::size_t blockSize)
{
	assert(p >= pData_);
	unsigned char* toRelease = static_cast<unsigned char*>(p);
	assert((toRelease - pData_) % blockSize == 0);
	firstAvailableBlock_ = static_cast<unsigned char>((toRelease - pData_) / blockSize);

	assert(firstAvailableBlock_ == (toRelease - pData_) / blockSize);
	++blockAvaliable_;
}

void* FixedAllocator::Allocate()
{
	if (allocChunk_ == 0 || allocChunk_->blockAvaliable_ == 0)
	{
		Chunks::iterator it = chunks_.begin();
		for (;; ++it)
		{
			if (it == chunks_.end())
			{
				chunks_.push_back(Chunk());
				Chunk& newChunk = chunks_.back();
				newChunk.Init(blockSize_, numBlocks_);
				allocChunk_ = &newChunk;
				deallocChunk_ = &chunks_.front();  // ?
				break;
			}
			if (it->blockAvaliable_ > 0)
			{
				allocChunk_ = &*it;
				break;
			}
		}
	}
	assert(allocChunk_ != 0);
	assert(allocChunk_->blockAvaliable_ > 0);
	return allocChunk_->Allocate(blockSize_);
}

SmallObjAllocator::SmallObjAllocator(std::size_t chunkSize, std::size_t maxObjectSize)
{
}

void* SmallObjAllocator::Allocate(std::size_t numBytes)
{
	return nullptr;
}

void SmallObjAllocator::Deallocate(void* p, std::size_t size)
{
}
