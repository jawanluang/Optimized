//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "Mem.h"

//--------------------------------
//    DO NOT MODIFY this File
//--------------------------------

#define PTR_FIX(x)  (unsigned int)(x == 0) ? 0: ((unsigned int)x - (unsigned int)h) 

TEST(Mem14_combo_1, TestConfig::Flag::ALL)
{
#if Mem14_combo_1

	{
		FileIO::Open("Student_", "Test_14");

		fprintf(FileIO::GetHandle(), "Test14: \n\n");

		fprintf(FileIO::GetHandle(), "      Mem mem1(Mem::Guard::Type_A);                           \n");
		fprintf(FileIO::GetHandle(), "      mem1.initialize();                  \n");
		fprintf(FileIO::GetHandle(), "      mem1.Print(1);                        \n");
		fprintf(FileIO::GetHandle(), "                                          \n");
		fprintf(FileIO::GetHandle(), "      void *a1 = mem1.malloc( 0x200 );    \n");
		fprintf(FileIO::GetHandle(), "      void *b1 = mem1.malloc( 0x200 );    \n");
		fprintf(FileIO::GetHandle(), "      void *c1 = mem1.malloc( 0x300 );    \n");
		fprintf(FileIO::GetHandle(), "      void *d1 = mem1.malloc( 0x300 );    \n");
		fprintf(FileIO::GetHandle(), "      void *e1 = mem1.malloc( 0x300 );    \n");
		fprintf(FileIO::GetHandle(), "      void *f1 = mem1.malloc( 0x400 );    \n");
		fprintf(FileIO::GetHandle(), "      void *g1 = mem1.malloc( 0x300 );    \n");
		fprintf(FileIO::GetHandle(), "                                          \n");
		fprintf(FileIO::GetHandle(), "      mem1.Print(2);                        \n");
		fprintf(FileIO::GetHandle(), "                                          \n");
		fprintf(FileIO::GetHandle(), "      // Part B:                          \n");
		fprintf(FileIO::GetHandle(), "      mem1.free( a1 );                    \n");
		fprintf(FileIO::GetHandle(), "      mem1.free( c1 );                    \n");
		fprintf(FileIO::GetHandle(), "      mem1.free( f1 );                    \n");
		fprintf(FileIO::GetHandle(), "      mem1.Print(3);                        \n");
		fprintf(FileIO::GetHandle(), "                                          \n");
		fprintf(FileIO::GetHandle(), "      // Part C:                          \n");
		fprintf(FileIO::GetHandle(), "      void *r1 = mem1.malloc( 0x180 );    \n");
		fprintf(FileIO::GetHandle(), "      mem1.Print(4);                        \n");
		fprintf(FileIO::GetHandle(), "                                          \n");
		fprintf(FileIO::GetHandle(), "      void *s1 = mem1.malloc(0xb100);     \n");
		fprintf(FileIO::GetHandle(), "      mem1.Print(5);                        \n");
		fprintf(FileIO::GetHandle(), "                                          \n");
		fprintf(FileIO::GetHandle(), "      void *t1 = mem1.malloc(0x220);      \n");
		fprintf(FileIO::GetHandle(), "      mem1.Print(6);                        \n");
		fprintf(FileIO::GetHandle(), "                                          \n");
		fprintf(FileIO::GetHandle(), "      mem1.free(s1);                      \n");
		fprintf(FileIO::GetHandle(), "      mem1.Print(7);                        \n");

		// Part A:
		Mem mem1(Mem::Guard::Type_A);
		mem1.initialize();
		mem1.Print(1);

		void *a1 = mem1.malloc(0x200);
		void *b1 = mem1.malloc(0x200);
		void *c1 = mem1.malloc(0x300);
		void *d1 = mem1.malloc(0x300);
		void *e1 = mem1.malloc(0x300);
		void *f1 = mem1.malloc(0x400);
		void *g1 = mem1.malloc(0x300);

		mem1.Print(2);

		// Part B:
		mem1.free(a1);
		mem1.free(c1);
		mem1.free(f1);
		mem1.Print(3);

		// Part C:
		void *r1 = mem1.malloc(0x180);
		mem1.Print(4);

		// Part D:
		void *s1 = mem1.malloc(0xb100);
		mem1.Print(5);

		// Part E:
		void *t1 = mem1.malloc(0x220);
		mem1.Print(6);

		// Part F:
		mem1.free(s1);
		mem1.Print(7);

		// to shut up warnings
		r1 = 0;
		t1 = 0;
		g1 = 0;
		e1 = 0;
		d1 = 0;
		b1 = 0;

		FileIO::Close();
	}

	// ----  GENERAL CHECK ------------------------------------------------------
	{
		// ---- Part A: -------------------------------------------------------------

		Mem mem(Mem::Guard::Type_A);
		mem.initialize();

		void *a = mem.malloc(0x200);
		void *b = mem.malloc(0x200);
		void *c = mem.malloc(0x300);
		void *d = mem.malloc(0x300);
		void *e = mem.malloc(0x300);
		void *f = mem.malloc(0x400);
		void *g = mem.malloc(0x300);

		// ---- Verify A: -----------------------------------------------------------

		Heap *h = mem.GetHeap();

		CHECK_EQUAL(PTR_FIX(a), 0x28);
		CHECK_EQUAL(PTR_FIX(b), 0x234);
		CHECK_EQUAL(PTR_FIX(c), 0x440);
		CHECK_EQUAL(PTR_FIX(d), 0x74c);
		CHECK_EQUAL(PTR_FIX(e), 0xa58);
		CHECK_EQUAL(PTR_FIX(f), 0xd64);
		CHECK_EQUAL(PTR_FIX(g), 0x1170);


		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x1470);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x1164);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->currNumUsedBlocks, 7);
		CHECK_EQUAL(h->currUsedMem, 0x1400);

		CHECK_EQUAL(h->currNumFreeBlocks, 1);
		CHECK_EQUAL(h->currFreeMem, 0xb384);

		// ----  Type walk ------------------------------------------------------

		uint32_t hdrStart;
		uint32_t hdrEnd;
		uint32_t blkStart;
		uint32_t blkEnd;
		uint32_t secret;

		// ---- USED HDR 1 -------------------------------------------

			// Check type
		Used *used = (Used *)(h + 1);
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x28);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x228);
		// Next
		CHECK_EQUAL(used->pNext, nullptr);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x228);
		CHECK_EQUAL(used->mDataSize, 0x200);

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
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x228);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x234);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x434);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x1c);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Used));

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x434);
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
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x434);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x440);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x740);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x228);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x740);
		CHECK_EQUAL(used->mDataSize, 0x300);

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
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x740);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x74c);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0xa4c);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x434);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xa4c);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- HDR 5 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xa4c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xa58);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0xd58);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x740);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xd58);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- HDR 6 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xd58);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xd64);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x1164);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0xa4c);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x1164);
		CHECK_EQUAL(used->mDataSize, 0x400);

		// ---- HDR 7 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1164);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x1170);
		// Prev
		CHECK_EQUAL(used->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0xd58);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x1470);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- HDR 8 -------------------------------------------

			// Check type
		Free *free = (Free *)blkEnd;
		// Should be USED
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1470);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x147c);
		// Prev
		CHECK_EQUAL(free->pPrev, nullptr);
		// Next
		CHECK_EQUAL(free->pNext, nullptr);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mDataSize, 0xb384);

		secret = *((uint32_t *)(blkEnd - 4));

		CHECK_EQUAL(PTR_FIX(secret), PTR_FIX(hdrStart));

		CHECK_EQUAL(PTR_FIX(h->pNextFit), PTR_FIX(hdrStart));

		// ---- Part B: -------------------------------------------------------------

		mem.free(a);
		mem.free(c);
		mem.free(f);

		// ---- Verify B: -----------------------------------------------------------

		h = mem.GetHeap();

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x1c);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x1164);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->currNumUsedBlocks, 4);
		CHECK_EQUAL(h->currUsedMem, 0xb00);

		CHECK_EQUAL(h->currNumFreeBlocks, 4);
		CHECK_EQUAL(h->currFreeMem, 0xbc84);

		// ---- HDR 1 -------------------------------------------

			// Check type
		free = (Free *)(h + 1);
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x28);
		// Prev
		CHECK_EQUAL(free->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0x434);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Free));

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x228);
		CHECK_EQUAL(free->mDataSize, 0x200);

		// ---- HDR 2 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x228);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x234);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x740);
		// Next
		CHECK_EQUAL(used->pNext, nullptr);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Used));

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x434);
		CHECK_EQUAL(used->mDataSize, 0x200);

		// ---- Hdr 3 -------------------------------------------

			// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x434);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x440);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0x1c);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0xd58);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x740);
		CHECK_EQUAL(free->mDataSize, 0x300);

		// ---- HDR 4 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x740);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x74c);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0xa4c);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x228);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xa4c);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- HDR 5 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xa4c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xa58);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x1164);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x740);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xd58);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- Hdr 6 -------------------------------------------

			// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xd58);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xd64);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0x434);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0x1470);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x1164);
		CHECK_EQUAL(free->mDataSize, 0x400);

		// ---- HDR 7 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1164);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x1170);
		// Prev
		CHECK_EQUAL(used->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0xa4c);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x1470);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- Hdr 8 -------------------------------------------

			// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1470);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x147c);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0xd58);
		// Next
		CHECK_EQUAL(free->pNext, nullptr);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mDataSize, 0xb384);

		secret = *((uint32_t *)(blkEnd - 4));
		CHECK_EQUAL(PTR_FIX(secret), PTR_FIX(hdrStart));

		CHECK_EQUAL(PTR_FIX(h->pNextFit), PTR_FIX(hdrStart));

		// ---- Part C: -------------------------------------------------------------

		void *r = mem.malloc(0x180);

		// ---- Verify C: -----------------------------------------------------------

		h = mem.GetHeap();

		CHECK_EQUAL(PTR_FIX(r), 0x147c);

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x1c);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x1470);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->currNumUsedBlocks, 5);
		CHECK_EQUAL(h->currUsedMem, 0xc80);

		CHECK_EQUAL(h->currNumFreeBlocks, 4);
		CHECK_EQUAL(h->currFreeMem, 0xbaf8);

		// ---- HDR 1 -------------------------------------------

			// Check type
		free = (Free *)(h + 1);
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x28);
		// Prev
		CHECK_EQUAL(free->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0x434);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Free));

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x228);
		CHECK_EQUAL(free->mDataSize, 0x200);

		// ---- HDR 2 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x228);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x234);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x740);
		// Next
		CHECK_EQUAL(used->pNext, nullptr);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Used));

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x434);
		CHECK_EQUAL(used->mDataSize, 0x200);

		// ---- Hdr 3 -------------------------------------------

			// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x434);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x440);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0x1c);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0xd58);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x740);
		CHECK_EQUAL(free->mDataSize, 0x300);

		// ---- HDR 4 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x740);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x74c);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0xa4c);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x228);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xa4c);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- HDR 5 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xa4c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xa58);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x1164);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x740);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xd58);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- Hdr 6 -------------------------------------------

			// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xd58);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xd64);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0x434);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0x15fc);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x1164);
		CHECK_EQUAL(free->mDataSize, 0x400);

		// ---- HDR 7 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1164);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x1170);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x1470);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0xa4c);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x1470);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- HDR 8 -------------------------------------------

			// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1470);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x147c);
		// Prev
		CHECK_EQUAL(used->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x1164);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x15fc);
		CHECK_EQUAL(used->mDataSize, 0x180);

		// ---- Hdr 9 -------------------------------------------

			// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x15fc);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x1608);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0xd58);
		// Next
		CHECK_EQUAL(free->pNext, nullptr);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mDataSize, 0xb1f8);

		// ---- Part D: -------------------------------------------------------------

		void *s = mem.malloc(0xb100);

		// ---- Verify D: -----------------------------------------------------------

		h = mem.GetHeap();

		CHECK_EQUAL(PTR_FIX(s), 0x1608);

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x1c);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x15fc);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->currNumUsedBlocks, 6);
		CHECK_EQUAL(h->currUsedMem, 0xbd80);

		CHECK_EQUAL(h->currNumFreeBlocks, 4);
		CHECK_EQUAL(h->currFreeMem, 0x9ec);

		// ---- HDR 1 -------------------------------------------

		// Check type
		free = (Free *)(h + 1);
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x28);
		// Prev
		CHECK_EQUAL(free->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0x434);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Free));

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x228);
		CHECK_EQUAL(free->mDataSize, 0x200);

		// ---- HDR 2 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x228);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x234);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x740);
		// Next
		CHECK_EQUAL(used->pNext, nullptr);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Used));

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x434);
		CHECK_EQUAL(used->mDataSize, 0x200);

		// ---- Hdr 3 -------------------------------------------

		// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x434);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x440);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0x1c);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0xd58);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x740);
		CHECK_EQUAL(free->mDataSize, 0x300);

		// ---- HDR 4 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x740);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x74c);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0xa4c);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x228);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xa4c);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- HDR 5 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xa4c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xa58);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x1164);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x740);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xd58);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- Hdr 6 -------------------------------------------

		// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xd58);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xd64);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0x434);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0xc708);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x1164);
		CHECK_EQUAL(free->mDataSize, 0x400);

		// ---- HDR 7 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1164);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x1170);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x1470);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0xa4c);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x1470);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- HDR 8 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1470);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x147c);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x15fc);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x1164);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x15fc);
		CHECK_EQUAL(used->mDataSize, 0x180);

		// ---- HDR 9 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x15fc);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x1608);
		// Prev
		CHECK_EQUAL(used->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x1470);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc708);
		CHECK_EQUAL(used->mDataSize, 0xb100);

		// ---- Hdr 10 -------------------------------------------

		// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xc708);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xc714);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0xd58);
		// Next
		CHECK_EQUAL(free->pNext, nullptr);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mDataSize, 0xec);

		// ---- Part E: -------------------------------------------------------------

		void *t = mem.malloc(0x220);

		// ---- Verify E: -----------------------------------------------------------

		h = mem.GetHeap();

		CHECK_EQUAL(PTR_FIX(t), 0x440);

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x1c);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x434);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->currNumUsedBlocks, 7);
		CHECK_EQUAL(h->currUsedMem, 0xbfa0);

		CHECK_EQUAL(h->currNumFreeBlocks, 4);
		CHECK_EQUAL(h->currFreeMem, 0x7c0);

		// ---- HDR 1 -------------------------------------------

		// Check type
		free = (Free *)(h + 1);
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x28);
		// Prev
		CHECK_EQUAL(free->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0x660);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Free));

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x228);
		CHECK_EQUAL(free->mDataSize, 0x200);

		// ---- HDR 2 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x228);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x234);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x740);
		// Next
		CHECK_EQUAL(used->pNext, nullptr);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Used));

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x434);
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
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x434);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x440);
		// Prev
		CHECK_EQUAL(used->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x15fc);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Used));

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x660);
		CHECK_EQUAL(used->mDataSize, 0x220);

		// ---- Hdr 4 -------------------------------------------

		// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x660);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x66c);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0x1c);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0xd58);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x740);
		CHECK_EQUAL(free->mDataSize, 0xd4);

		// ---- HDR 5 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x740);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x74c);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0xa4c);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x228);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xa4c);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- HDR 6 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xa4c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xa58);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x1164);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x740);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xd58);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- Hdr 7 -------------------------------------------

		// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xd58);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xd64);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0x660);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0xc708);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x1164);
		CHECK_EQUAL(free->mDataSize, 0x400);

		// ---- HDR 8 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1164);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x1170);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x1470);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0xa4c);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x1470);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- HDR 9 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1470);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x147c);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x15fc);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x1164);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x15fc);
		CHECK_EQUAL(used->mDataSize, 0x180);

		// ---- HDR 10 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x15fc);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x1608);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x434);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x1470);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc708);
		CHECK_EQUAL(used->mDataSize, 0xb100);

		// ---- Hdr 11 -------------------------------------------

		// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xc708);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xc714);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0xd58);
		// Next
		CHECK_EQUAL(free->pNext, nullptr);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mDataSize, 0xec);

		// ---- Part F: -------------------------------------------------------------

		mem.free(s);

		// ---- Verify F: -----------------------------------------------------------

		h = mem.GetHeap();

		// Sanit check, make sure everything is heap relative for testing
		CHECK_EQUAL(PTR_FIX(h), 0);

		// Used / free
		CHECK_EQUAL(PTR_FIX(h->pFreeHead), 0x1c);
		CHECK_EQUAL(PTR_FIX(h->pUsedHead), 0x434);

		// ---- Heap Stats ------------------------------------------------------

		CHECK_EQUAL(h->currNumUsedBlocks, 6);
		CHECK_EQUAL(h->currUsedMem, 0xea0);

		CHECK_EQUAL(h->currNumFreeBlocks, 4);
		CHECK_EQUAL(h->currFreeMem, 0xb8cc);

		// ---- HDR 1 -------------------------------------------

		// Check type
		free = (Free *)(h + 1);
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x28);
		// Prev
		CHECK_EQUAL(free->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0x660);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Free));

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x228);
		CHECK_EQUAL(free->mDataSize, 0x200);

		// ---- HDR 2 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x228);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x234);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x740);
		// Next
		CHECK_EQUAL(used->pNext, nullptr);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Used));

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x434);
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
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x434);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x440);
		// Prev
		CHECK_EQUAL(used->pPrev, nullptr);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x1470);
		// Hdr Size
		CHECK_EQUAL(hdrEnd - hdrStart, sizeof(Used));

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x660);
		CHECK_EQUAL(used->mDataSize, 0x220);

		// ---- Hdr 4 -------------------------------------------

		// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x660);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x66c);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0x1c);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0xd58);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x740);
		CHECK_EQUAL(free->mDataSize, 0xd4);

		// ---- HDR 5 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x740);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x74c);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0xa4c);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x228);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xa4c);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- HDR 6 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xa4c);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xa58);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x1164);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x740);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xd58);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- Hdr 7 -------------------------------------------

		// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0xd58);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0xd64);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0x660);
		// Next
		CHECK_EQUAL(PTR_FIX(free->pNext), 0x15fc);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x1164);
		CHECK_EQUAL(free->mDataSize, 0x400);

		// ---- HDR 8 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, true);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1164);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x1170);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x1470);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0xa4c);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x1470);
		CHECK_EQUAL(used->mDataSize, 0x300);

		// ---- HDR 9 -------------------------------------------

		// Check type
		used = (Used *)blkEnd;
		// Should be USED
		CHECK_EQUAL(used->mType, Type::USED);

		// Above free
		CHECK_EQUAL(used->bAboveFree, false);

		hdrStart = (uint32_t)used;
		hdrEnd = (uint32_t)used + sizeof(Used);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x1470);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x147c);
		// Prev
		CHECK_EQUAL(PTR_FIX(used->pPrev), 0x434);
		// Next
		CHECK_EQUAL(PTR_FIX(used->pNext), 0x1164);

		blkStart = hdrEnd;
		blkEnd = blkStart + used->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0x15fc);
		CHECK_EQUAL(used->mDataSize, 0x180);

		// ---- Hdr 10 -------------------------------------------

		// Check type
		free = (Free *)blkEnd;
		// Should be free
		CHECK_EQUAL(free->mType, Type::FREE);

		// Above free
		CHECK_EQUAL(free->bAboveFree, false);

		hdrStart = (uint32_t)free;
		hdrEnd = (uint32_t)free + sizeof(Free);

		// Hdr Start
		CHECK_EQUAL(PTR_FIX(hdrStart), 0x15fc);
		// Hdr End
		CHECK_EQUAL(PTR_FIX(hdrEnd), 0x1608);
		// Prev
		CHECK_EQUAL(PTR_FIX(free->pPrev), 0xd58);
		// Next
		CHECK_EQUAL(free->pNext, nullptr);

		blkStart = hdrEnd;
		blkEnd = blkStart + free->mDataSize;

		CHECK_EQUAL(PTR_FIX(blkStart), PTR_FIX(hdrEnd));
		CHECK_EQUAL(PTR_FIX(blkEnd), 0xc800);
		CHECK_EQUAL(free->mDataSize, 0xb1f8);
	}

	{
	// ----  Checking Guards ----

		Mem mem(Mem::Guard::Type_5);
		CHECK(true);
		mem.initialize();
		CHECK(true);
		void *a;
		a = mem.malloc(0x200);
		CHECK(true);
		void *b;
		b = mem.malloc(0x200);
		CHECK(true);
		void *c;
		c = mem.malloc(0x300);
		CHECK(true);
		void *d;
		d = mem.malloc(0x300);
		CHECK(true);
		void *e;
		e = mem.malloc(0x300);
		CHECK(true);
		void *f;
		f = mem.malloc(0x400);
		CHECK(true);
		void *g;
		g= mem.malloc(0x300);
		CHECK(true);
		mem.free(a);
		CHECK(true);
		mem.free(c);
		CHECK(true);
		mem.free(f);
		CHECK(true);
		void *r;
		r = mem.malloc(0x180);
		CHECK(true);
		void *s;
		s = mem.malloc(0xb100);
		CHECK(true);
		void *t;
		t= mem.malloc(0x220);
		CHECK(true);
		mem.free(s);
		CHECK(true);

	}

#endif
}  TEST_END

// ---  End of File ---
