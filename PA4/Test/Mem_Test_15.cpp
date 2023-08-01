//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "Mem.h"

//--------------------------------
//    DO NOT MODIFY this File
//--------------------------------

#define PTR_FIX(x)  (unsigned int)(x == 0) ? 0: ((unsigned int)x - (unsigned int)h)  

TEST(Mem15_combo_2, TestConfig::Flag::ALL)
{
#if Mem15_combo_2

	{
		FileIO::Open("Student_", "Test_15");

		fprintf(FileIO::GetHandle(), "Test15: \n\n");

		fprintf(FileIO::GetHandle(), "     Mem mem(Mem::Guard::Type_A);                     \n");
		fprintf(FileIO::GetHandle(), "     mem.initialize();            \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(1);                        \n");

		fprintf(FileIO::GetHandle(), "     void *a = mem.malloc( 0x100 );     \n");
		fprintf(FileIO::GetHandle(), "     void *b = mem.malloc( 0x200 );     \n");
		fprintf(FileIO::GetHandle(), "     void *c = mem.malloc( 0x10 );     \n");
		fprintf(FileIO::GetHandle(), "     void *d = mem.malloc( 0x200 );     \n");


		fprintf(FileIO::GetHandle(), "     mem.Print(2);                        \n");
		fprintf(FileIO::GetHandle(), "     mem.free( d );                     \n");
		fprintf(FileIO::GetHandle(), "     mem.free( b );                     \n");

		fprintf(FileIO::GetHandle(), "     mem.Print(3);                        \n");

		fprintf(FileIO::GetHandle(), "     void *r = mem.malloc( 0x200 );     \n");
		fprintf(FileIO::GetHandle(), "     mem.Print(4);                        \n");

		// Part A:
		Mem mem1(Mem::Guard::Type_A);
		mem1.initialize();
		mem1.Print(1);

		void *a1 = mem1.malloc(0x100);
		void *b1 = mem1.malloc(0x200);
		void *c1 = mem1.malloc(0x10);
		void *d1 = mem1.malloc(0x200);

		mem1.Print(2);

		// Part B:
		mem1.free(d1);
		mem1.free(b1);

		mem1.Print(3);

		// Part C:
		void *r1 = mem1.malloc(0x200);
		mem1.Print(4);

		// to shut up warnings
		r1 = 0;
		a1 = 0;
		c1 = 0;

		FileIO::Close();
	}
	// ----  GENERAL CHECK ------------------------------------------------------
	{
		// ---- Part A: -------------------------------------------------------------

		Mem mem(Mem::Guard::Type_A);
		mem.initialize();

		void *a = mem.malloc(0x100);
		void *b = mem.malloc(0x200);
		void *c = mem.malloc(0x10);
		void *d = mem.malloc(0x200);

		// ---- Verify A: -----------------------------------------------------------

		Heap *h = mem.GetHeap();

		CHECK_EQUAL(PTR_FIX(a), 0x28);
		CHECK_EQUAL(PTR_FIX(b), 0x134);
		CHECK_EQUAL(PTR_FIX(c), 0x340);
		CHECK_EQUAL(PTR_FIX(d), 0x35c);

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x55c);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x350);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->currNumUsedBlocks, 4);
		CHECK_EQUAL(h->currUsedMem, 0x510);

		CHECK_EQUAL(h->currNumFreeBlocks, 1);
		CHECK_EQUAL(h->currFreeMem, 0xc298);

		uint32_t hdrStart;
		uint32_t hdrEnd;
		uint32_t blkStart;
		uint32_t blkEnd;
		uint32_t secret;

		// ---- HDR 1 -------------------------------------------

			// Check type
		Used *used = (Used *)(h + 1);
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x28);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x128);
		// Next
		CHECK_EQUAL(used->pNext, nullptr);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Used));

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x128);
		CHECK_EQUAL(used->mDataSize, 0x100);

		// ---- HDR 2 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x128);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x134);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x334);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x1c);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x334);
		CHECK_EQUAL(used->mDataSize, 0x200);

		// ---- HDR 3 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x334);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x340);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x350);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x128);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x350);
		CHECK_EQUAL(used->mDataSize, 0x10);

		// ---- HDR 4 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x350);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x35c);
		// Prev
		CHECK_EQUAL(used->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x334);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x55c);
		CHECK_EQUAL(used->mDataSize, 0x200);

		// ---- Hdr 5 -------------------------------------------

			// Check type
		Free *free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x55c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x568);
		// Prev
		CHECK_EQUAL(free->pPrev, nullptr);
		// Next
		CHECK_EQUAL(free->pNext, nullptr);

		// ---- Type ----------------------------------------------------

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mDataSize, 0xc298);

		secret = *((uint32_t *)(blkEnd - 4));
		CHECK_EQUAL(PTR_FIX(secret), PTR_FIX(hdrStart));

		CHECK_EQUAL(PTR_FIX(h->pNextFit), PTR_FIX(hdrStart));

		// ---- Part B: -------------------------------------------------------------

		mem.free(d);
		mem.free(b);

		// ---- Verify B: -----------------------------------------------------------

		h = mem.GetHeap();

		CHECK_EQUAL(PTR_FIX(a), 0x28);
		CHECK_EQUAL(PTR_FIX(b), 0x134);
		CHECK_EQUAL(PTR_FIX(c), 0x340);
		CHECK_EQUAL(PTR_FIX(d), 0x35c);

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x128);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x334);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->currNumUsedBlocks, 2);
		CHECK_EQUAL(h->currUsedMem, 0x110);

		CHECK_EQUAL(h->currNumFreeBlocks, 2);
		CHECK_EQUAL(h->currFreeMem, 0xc6a4);

		// ---- HDR 1 -------------------------------------------

			// Check type
		used = (Used *)(h + 1);
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x28);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x334);
		// Next
		CHECK_EQUAL(used->pNext, nullptr);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Used));

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x128);
		CHECK_EQUAL(used->mDataSize, 0x100);

		// ---- HDR 2 -------------------------------------------

			// Check type
		free = (Free *)blkEnd;
		// Should be USED
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x128);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x134);
		// Prev
		CHECK_EQUAL(free->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0x350);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x334);
		CHECK_EQUAL(free->mDataSize, 0x200);

		// ---- HDR 3 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x334);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x340);
		// Prev
		CHECK_EQUAL(used->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x1c);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x350);
		CHECK_EQUAL(used->mDataSize, 0x10);

		// ---- HDR 4 -------------------------------------------

			// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x350);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x35c);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0x128);
		// Next
		CHECK_EQUAL(free->pNext, nullptr);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mDataSize, 0xc4a4);

		secret = *((uint32_t *)(blkEnd - 4));
		CHECK_EQUAL(PTR_FIX(secret), PTR_FIX(hdrStart));

		CHECK_EQUAL(PTR_FIX(h->pNextFit), PTR_FIX(hdrStart));

		// ---- Part C: -------------------------------------------------------------

		void *r = mem.malloc(0x200);

		// ---- Verify C: -----------------------------------------------------------

		h = mem.GetHeap();

		CHECK_EQUAL(PTR_FIX(r), 0x35c);

		// Sanity check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x128);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x350);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->currNumUsedBlocks, 3);
		CHECK_EQUAL(h->currUsedMem, 0x310);

		CHECK_EQUAL(h->currNumFreeBlocks, 2);
		CHECK_EQUAL(h->currFreeMem, 0xc498);

		// ---- HDR 1 -------------------------------------------

			// Check type
		used = (Used *)(h + 1);
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x28);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x334);
		// Next
		CHECK_EQUAL(used->pNext, nullptr);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Used));

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x128);
		CHECK_EQUAL(used->mDataSize, 0x100);

		// ---- HDR 2 -------------------------------------------

			// Check type
		free = (Free *)blkEnd;
		// Should be USED
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x128);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x134);
		// Prev
		CHECK_EQUAL(free->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0x55c);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x334);
		CHECK_EQUAL(free->mDataSize, 0x200);

		// ---- HDR 3 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x334);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x340);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x350);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x1c);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x350);
		CHECK_EQUAL(used->mDataSize, 0x10);

		// ---- HDR 4 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be free
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x350);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x35c);
		// Prev
		CHECK_EQUAL(used->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x334);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));

		CHECK_EQUAL(PTR_FIX(blkEnd), 0x55c);
		CHECK_EQUAL(used->mDataSize, 0x200);

		// ---- HDR 5 -------------------------------------------

			// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x55c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x568);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0x0128);
		// Next
		CHECK_EQUAL(free->pNext, nullptr);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mDataSize, 0xc298);

		secret = *((uint32_t *)(blkEnd - 4));
		CHECK_EQUAL(PTR_FIX(secret), PTR_FIX(hdrStart));

		CHECK_EQUAL(PTR_FIX(h->pNextFit), PTR_FIX(hdrStart));

	}

	{

	// ----  Checking Guards ----

		Mem mem(Mem::Guard::Type_5);
		CHECK(true);
		mem.initialize();
		CHECK(true);
		void *a;
		a = mem.malloc(0x100);
		CHECK(true);
		void *b;
		b = mem.malloc(0x200);
		CHECK(true);
		void *c;
		c = mem.malloc(0x10);
		CHECK(true);
		void *d;
		d = mem.malloc(0x200);
		CHECK(true);
		mem.free(d);
		CHECK(true);
		mem.free(b);
		CHECK(true);
		void *r;
		r = mem.malloc(0x200);
		CHECK(true);
	
	}

#endif
}  TEST_END

// ---  End of File ---
