//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "Node.h"
#include "Bloated.h"
#include "HotCold.h"

// ----------------------------------
// ---     DO NOT MODIFY FILE     ---
// ----------------------------------

static HotCold *pHotCold = nullptr;
static Bloated *pBloated = nullptr;

// Previous tests
bool HotColdConvert_Test = false;
bool HotColdLink_Test = false;
bool BloatedFindKey_Test = false;

TEST_WITH_TEARDOWN(Timing_HotCold, TestConfig::ALL)
{

	// Cannot add data to class
	CHECK(sizeof(Node) == 540);
	CHECK(sizeof(Bloated) == 4);
	CHECK(sizeof(HotCold) == 8);
	CHECK(sizeof(HotNode) == 16);
	CHECK(sizeof(ColdNode) == 520);

	//-----------------------------------------------------------------------------
	// Create Bloated
	//-----------------------------------------------------------------------------

	// Create a timer objects
	PerformanceTimer t1;

	// start timer
	t1.Tic();

		//-----------------------------------------------------------------------------
		// It initializes the data if a very bloated way do not modify it!
		//-----------------------------------------------------------------------------
		pBloated = new Bloated(400000);

	// stop timer
	t1.Toc();
	CHECK(pBloated != nullptr);

	//-----------------------------------------------------------------------------
	// Find a specific Key
	//-----------------------------------------------------------------------------

	Node *pFoundNode;
	bool foundFlag;

	// Create a timer objects
	PerformanceTimer t2;

	// start timer
	t2.Tic();

		// find a specific key
		foundFlag = pBloated->FindKey(0x1c663af9, pFoundNode);

	// stop timer
	t2.Toc();
	CHECK(foundFlag == true);

	//-----------------------------------------------------------------------------
	// Verify
	//-----------------------------------------------------------------------------

		CHECK_EQUAL(((unsigned int)&pFoundNode->aa - (unsigned int)pFoundNode), 8);
		CHECK_EQUAL(((unsigned int)&pFoundNode->x - (unsigned int)pFoundNode), 12);
		CHECK_EQUAL(((unsigned int)&pFoundNode->A - (unsigned int)pFoundNode), 16);
		CHECK_EQUAL(((unsigned int)&pFoundNode->y - (unsigned int)pFoundNode), 28);
		CHECK_EQUAL(((unsigned int)&pFoundNode->B - (unsigned int)pFoundNode), 32);
		CHECK_EQUAL(((unsigned int)&pFoundNode->C - (unsigned int)pFoundNode), 44);
		CHECK_EQUAL(((unsigned int)&pFoundNode->z - (unsigned int)pFoundNode), 56);
		CHECK_EQUAL(((unsigned int)&pFoundNode->D - (unsigned int)pFoundNode), 60);
		CHECK_EQUAL(((unsigned int)&pFoundNode->MA - (unsigned int)pFoundNode), 72);
		CHECK_EQUAL(((unsigned int)&pFoundNode->bb - (unsigned int)pFoundNode), 136);
		CHECK_EQUAL(((unsigned int)&pFoundNode->MB - (unsigned int)pFoundNode), 140);
		CHECK_EQUAL(((unsigned int)&pFoundNode->w - (unsigned int)pFoundNode), 204);
		CHECK_EQUAL(((unsigned int)&pFoundNode->MC - (unsigned int)pFoundNode), 208);
		CHECK_EQUAL(((unsigned int)&pFoundNode->MD - (unsigned int)pFoundNode), 272);
		CHECK_EQUAL(((unsigned int)&pFoundNode->cc - (unsigned int)pFoundNode), 336);
		CHECK_EQUAL(((unsigned int)&pFoundNode->name - (unsigned int)pFoundNode), 337);
		CHECK_EQUAL(((unsigned int)&pFoundNode->key - (unsigned int)pFoundNode), 532);
		CHECK((0xFF & (*pFoundNode).aa) == 0xe);
		CHECK((0xFF & (*pFoundNode).bb) == 0xe8);
		CHECK((0xFF & (*pFoundNode).cc) == 0xa);
		CHECK((0xFF & (*pFoundNode).dd) == 0x7);
		CHECK((*pFoundNode).x == 10420.878906f);
		CHECK((*pFoundNode).y == 18116.001953f);
		CHECK((*pFoundNode).z == 3637.294434f);
		CHECK((*pFoundNode).w == 2441.684326f);
		CHECK((*pFoundNode).A.x == 22311.681641f);
		CHECK((*pFoundNode).A.y == 26392.271484f);
		CHECK((*pFoundNode).A.z == 7130.277344f);
		CHECK((*pFoundNode).B.x == 3695.925537f);
		CHECK((*pFoundNode).B.y == 30814.800781f);
		CHECK((*pFoundNode).B.z == 6717.419434f);
		CHECK((*pFoundNode).C.x == 27637.845703f);
		CHECK((*pFoundNode).C.y == 3059.874023f);
		CHECK((*pFoundNode).C.z == 19657.781250f);
		CHECK((*pFoundNode).D.x == 32029.228516f);
		CHECK((*pFoundNode).D.y == 9179.236328f);
		CHECK((*pFoundNode).D.z == 31475.716797f);
		CHECK((*pFoundNode).MA.m00 == 1340.649658f);
		CHECK((*pFoundNode).MA.m01 == 16427.142578f);
		CHECK((*pFoundNode).MA.m02 == 14463.948242f);
		CHECK((*pFoundNode).MA.m03 == 16658.214844f);
		CHECK((*pFoundNode).MA.m10 == 17774.873047f);
		CHECK((*pFoundNode).MA.m11 == 15835.750000f);
		CHECK((*pFoundNode).MA.m12 == 14588.989258f);
		CHECK((*pFoundNode).MA.m13 == 20279.994141f);
		CHECK((*pFoundNode).MA.m20 == 13947.911133f);
		CHECK((*pFoundNode).MA.m21 == 8486.875977f);
		CHECK((*pFoundNode).MA.m22 == 10511.761719f);
		CHECK((*pFoundNode).MA.m23 == 20492.447266f);
		CHECK((*pFoundNode).MA.m30 == 10595.417969f);
		CHECK((*pFoundNode).MA.m31 == 7175.306152f);
		CHECK((*pFoundNode).MA.m32 == 27546.560547f);
		CHECK((*pFoundNode).MA.m33 == 26240.275391f);
		CHECK((*pFoundNode).MB.m00 == 18825.052734f);
		CHECK((*pFoundNode).MB.m01 == 11776.132813f);
		CHECK((*pFoundNode).MB.m02 == 15651.704102f);
		CHECK((*pFoundNode).MB.m03 == 31813.646484f);
		CHECK((*pFoundNode).MB.m10 == 24372.921875f);
		CHECK((*pFoundNode).MB.m11 == 31382.732422f);
		CHECK((*pFoundNode).MB.m12 == 15955.292969f);
		CHECK((*pFoundNode).MB.m13 == 8275.979492f);
		CHECK((*pFoundNode).MB.m20 == 8721.644531f);
		CHECK((*pFoundNode).MB.m21 == 12240.356445f);
		CHECK((*pFoundNode).MB.m22 == 3703.579346f);
		CHECK((*pFoundNode).MB.m23 == 30051.353516f);
		CHECK((*pFoundNode).MB.m30 == 7088.049316f);
		CHECK((*pFoundNode).MB.m31 == 31932.359375f);
		CHECK((*pFoundNode).MB.m32 == 30210.980469f);
		CHECK((*pFoundNode).MB.m33 == 12405.546875f);
		CHECK((*pFoundNode).MC.m00 == 6659.484863f);
		CHECK((*pFoundNode).MC.m01 == 6122.045898f);
		CHECK((*pFoundNode).MC.m02 == 8457.699219f);
		CHECK((*pFoundNode).MC.m03 == 10059.694336f);
		CHECK((*pFoundNode).MC.m10 == 12770.762695f);
		CHECK((*pFoundNode).MC.m11 == 22000.138672f);
		CHECK((*pFoundNode).MC.m12 == 27077.986328f);
		CHECK((*pFoundNode).MC.m13 == 28396.572266f);
		CHECK((*pFoundNode).MC.m20 == 20873.726563f);
		CHECK((*pFoundNode).MC.m21 == 20452.882813f);
		CHECK((*pFoundNode).MC.m22 == 13077.010742f);
		CHECK((*pFoundNode).MC.m23 == 2594.509521f);
		CHECK((*pFoundNode).MC.m30 == 25368.437500f);
		CHECK((*pFoundNode).MC.m31 == 6629.764160f);
		CHECK((*pFoundNode).MC.m32 == 21242.373047f);
		CHECK((*pFoundNode).MC.m33 == 10235.923828f);
		CHECK((*pFoundNode).MD.m00 == 32530.998047f);
		CHECK((*pFoundNode).MD.m01 == 2450.856934f);
		CHECK((*pFoundNode).MD.m02 == 3353.223145f);
		CHECK((*pFoundNode).MD.m03 == 29260.478516f);
		CHECK((*pFoundNode).MD.m10 == 11998.990234f);
		CHECK((*pFoundNode).MD.m11 == 3217.798828f);
		CHECK((*pFoundNode).MD.m12 == 7484.024414f);
		CHECK((*pFoundNode).MD.m13 == 27689.871094f);
		CHECK((*pFoundNode).MD.m20 == 16201.537109f);
		CHECK((*pFoundNode).MD.m21 == 3850.386963f);
		CHECK((*pFoundNode).MD.m22 == 20945.925781f);
		CHECK((*pFoundNode).MD.m23 == 24686.240234f);
		CHECK((*pFoundNode).MD.m30 == 8963.002930f);
		CHECK((*pFoundNode).MD.m31 == 29225.800781f);
		CHECK((*pFoundNode).MD.m32 == 13929.772461f);
		CHECK((*pFoundNode).MD.m33 == 24634.207031f);
		CHECK((*pFoundNode).ME.m00 == 25886.304688f);
		CHECK((*pFoundNode).ME.m01 == 4768.449707f);
		CHECK((*pFoundNode).ME.m02 == 20027.724609f);
		CHECK((*pFoundNode).ME.m03 == 20847.525391f);
		CHECK((*pFoundNode).ME.m10 == 11154.850586f);
		CHECK((*pFoundNode).ME.m11 == 24354.447266f);
		CHECK((*pFoundNode).ME.m12 == 24223.519531f);
		CHECK((*pFoundNode).ME.m13 == 3379.378418f);
		CHECK((*pFoundNode).ME.m20 == 18875.115234f);
		CHECK((*pFoundNode).ME.m21 == 32489.703125f);
		CHECK((*pFoundNode).ME.m22 == 18835.351563f);
		CHECK((*pFoundNode).ME.m23 == 3698.277100f);
		CHECK((*pFoundNode).ME.m30 == 25305.822266f);
		CHECK((*pFoundNode).ME.m31 == 2097.657471f);
		CHECK((*pFoundNode).ME.m32 == 30777.367188f);
		CHECK((*pFoundNode).ME.m33 == 12377.604492f);
		CHECK((unsigned char)(*pFoundNode).name[0x00] == (unsigned char)0xac);
		CHECK((unsigned char)(*pFoundNode).name[0x01] == (unsigned char)0x77);
		CHECK((unsigned char)(*pFoundNode).name[0x02] == (unsigned char)0x03);
		CHECK((unsigned char)(*pFoundNode).name[0x03] == (unsigned char)0xe2);
		CHECK((unsigned char)(*pFoundNode).name[0x04] == (unsigned char)0xad);
		CHECK((unsigned char)(*pFoundNode).name[0x05] == (unsigned char)0x80);
		CHECK((unsigned char)(*pFoundNode).name[0x06] == (unsigned char)0x5a);
		CHECK((unsigned char)(*pFoundNode).name[0x07] == (unsigned char)0x4d);
		CHECK((unsigned char)(*pFoundNode).name[0x08] == (unsigned char)0xc6);
		CHECK((unsigned char)(*pFoundNode).name[0x09] == (unsigned char)0x1c);
		CHECK((unsigned char)(*pFoundNode).name[0x0a] == (unsigned char)0x5e);
		CHECK((unsigned char)(*pFoundNode).name[0x0b] == (unsigned char)0xed);
		CHECK((unsigned char)(*pFoundNode).name[0x0c] == (unsigned char)0x2f);
		CHECK((unsigned char)(*pFoundNode).name[0x0d] == (unsigned char)0x16);
		CHECK((unsigned char)(*pFoundNode).name[0x0e] == (unsigned char)0x3d);
		CHECK((unsigned char)(*pFoundNode).name[0x0f] == (unsigned char)0xda);
		CHECK((unsigned char)(*pFoundNode).name[0x10] == (unsigned char)0x7a);
		CHECK((unsigned char)(*pFoundNode).name[0x11] == (unsigned char)0xd8);
		CHECK((unsigned char)(*pFoundNode).name[0x12] == (unsigned char)0x60);
		CHECK((unsigned char)(*pFoundNode).name[0x13] == (unsigned char)0x10);
		CHECK((unsigned char)(*pFoundNode).name[0x14] == (unsigned char)0x61);
		CHECK((unsigned char)(*pFoundNode).name[0x15] == (unsigned char)0x09);
		CHECK((unsigned char)(*pFoundNode).name[0x16] == (unsigned char)0xc2);
		CHECK((unsigned char)(*pFoundNode).name[0x17] == (unsigned char)0x29);
		CHECK((unsigned char)(*pFoundNode).name[0x18] == (unsigned char)0x11);
		CHECK((unsigned char)(*pFoundNode).name[0x19] == (unsigned char)0xd1);
		CHECK((unsigned char)(*pFoundNode).name[0x1a] == (unsigned char)0x09);
		CHECK((unsigned char)(*pFoundNode).name[0x1b] == (unsigned char)0x02);
		CHECK((unsigned char)(*pFoundNode).name[0x1c] == (unsigned char)0x66);
		CHECK((unsigned char)(*pFoundNode).name[0x1d] == (unsigned char)0x07);
		CHECK((unsigned char)(*pFoundNode).name[0x1e] == (unsigned char)0xb5);
		CHECK((unsigned char)(*pFoundNode).name[0x1f] == (unsigned char)0xd4);
		CHECK((unsigned char)(*pFoundNode).name[0x20] == (unsigned char)0x28);
		CHECK((unsigned char)(*pFoundNode).name[0x21] == (unsigned char)0x49);
		CHECK((unsigned char)(*pFoundNode).name[0x22] == (unsigned char)0xc9);
		CHECK((unsigned char)(*pFoundNode).name[0x23] == (unsigned char)0xb5);
		CHECK((unsigned char)(*pFoundNode).name[0x24] == (unsigned char)0x8d);
		CHECK((unsigned char)(*pFoundNode).name[0x25] == (unsigned char)0x3e);
		CHECK((unsigned char)(*pFoundNode).name[0x26] == (unsigned char)0x2e);
		CHECK((unsigned char)(*pFoundNode).name[0x27] == (unsigned char)0xa7);
		CHECK((unsigned char)(*pFoundNode).name[0x28] == (unsigned char)0x2d);
		CHECK((unsigned char)(*pFoundNode).name[0x29] == (unsigned char)0x1a);
		CHECK((unsigned char)(*pFoundNode).name[0x2a] == (unsigned char)0x23);
		CHECK((unsigned char)(*pFoundNode).name[0x2b] == (unsigned char)0x8d);
		CHECK((unsigned char)(*pFoundNode).name[0x2c] == (unsigned char)0x20);
		CHECK((unsigned char)(*pFoundNode).name[0x2d] == (unsigned char)0xfe);
		CHECK((unsigned char)(*pFoundNode).name[0x2e] == (unsigned char)0xb0);
		CHECK((unsigned char)(*pFoundNode).name[0x2f] == (unsigned char)0x39);
		CHECK((unsigned char)(*pFoundNode).name[0x30] == (unsigned char)0x74);
		CHECK((unsigned char)(*pFoundNode).name[0x31] == (unsigned char)0x7d);
		CHECK((unsigned char)(*pFoundNode).name[0x32] == (unsigned char)0xc0);
		CHECK((unsigned char)(*pFoundNode).name[0x33] == (unsigned char)0xe8);
		CHECK((unsigned char)(*pFoundNode).name[0x34] == (unsigned char)0x3e);
		CHECK((unsigned char)(*pFoundNode).name[0x35] == (unsigned char)0xab);
		CHECK((unsigned char)(*pFoundNode).name[0x36] == (unsigned char)0x5b);
		CHECK((unsigned char)(*pFoundNode).name[0x37] == (unsigned char)0x61);
		CHECK((unsigned char)(*pFoundNode).name[0x38] == (unsigned char)0x5b);
		CHECK((unsigned char)(*pFoundNode).name[0x39] == (unsigned char)0x27);
		CHECK((unsigned char)(*pFoundNode).name[0x3a] == (unsigned char)0x39);
		CHECK((unsigned char)(*pFoundNode).name[0x3b] == (unsigned char)0x83);
		CHECK((unsigned char)(*pFoundNode).name[0x3c] == (unsigned char)0xc4);
		CHECK((unsigned char)(*pFoundNode).name[0x3d] == (unsigned char)0x79);
		CHECK((unsigned char)(*pFoundNode).name[0x3e] == (unsigned char)0x23);
		CHECK((unsigned char)(*pFoundNode).name[0x3f] == (unsigned char)0x82);
		CHECK((unsigned char)(*pFoundNode).name[0x40] == (unsigned char)0x76);
		CHECK((unsigned char)(*pFoundNode).name[0x41] == (unsigned char)0x2a);
		CHECK((unsigned char)(*pFoundNode).name[0x42] == (unsigned char)0xcc);
		CHECK((unsigned char)(*pFoundNode).name[0x43] == (unsigned char)0x20);
		CHECK((unsigned char)(*pFoundNode).name[0x44] == (unsigned char)0x4b);
		CHECK((unsigned char)(*pFoundNode).name[0x45] == (unsigned char)0x7f);
		CHECK((unsigned char)(*pFoundNode).name[0x46] == (unsigned char)0xa5);
		CHECK((unsigned char)(*pFoundNode).name[0x47] == (unsigned char)0x97);
		CHECK((unsigned char)(*pFoundNode).name[0x48] == (unsigned char)0x5a);
		CHECK((unsigned char)(*pFoundNode).name[0x49] == (unsigned char)0x32);
		CHECK((unsigned char)(*pFoundNode).name[0x4a] == (unsigned char)0x45);
		CHECK((unsigned char)(*pFoundNode).name[0x4b] == (unsigned char)0x07);
		CHECK((unsigned char)(*pFoundNode).name[0x4c] == (unsigned char)0xad);
		CHECK((unsigned char)(*pFoundNode).name[0x4d] == (unsigned char)0x99);
		CHECK((unsigned char)(*pFoundNode).name[0x4e] == (unsigned char)0x04);
		CHECK((unsigned char)(*pFoundNode).name[0x4f] == (unsigned char)0x1d);
		CHECK((unsigned char)(*pFoundNode).name[0x50] == (unsigned char)0x68);
		CHECK((unsigned char)(*pFoundNode).name[0x51] == (unsigned char)0x0f);
		CHECK((unsigned char)(*pFoundNode).name[0x52] == (unsigned char)0xd0);
		CHECK((unsigned char)(*pFoundNode).name[0x53] == (unsigned char)0xce);
		CHECK((unsigned char)(*pFoundNode).name[0x54] == (unsigned char)0x26);
		CHECK((unsigned char)(*pFoundNode).name[0x55] == (unsigned char)0x17);
		CHECK((unsigned char)(*pFoundNode).name[0x56] == (unsigned char)0x54);
		CHECK((unsigned char)(*pFoundNode).name[0x57] == (unsigned char)0xc6);
		CHECK((unsigned char)(*pFoundNode).name[0x58] == (unsigned char)0x36);
		CHECK((unsigned char)(*pFoundNode).name[0x59] == (unsigned char)0x09);
		CHECK((unsigned char)(*pFoundNode).name[0x5a] == (unsigned char)0x82);
		CHECK((unsigned char)(*pFoundNode).name[0x5b] == (unsigned char)0x7b);
		CHECK((unsigned char)(*pFoundNode).name[0x5c] == (unsigned char)0x79);
		CHECK((unsigned char)(*pFoundNode).name[0x5d] == (unsigned char)0xbc);
		CHECK((unsigned char)(*pFoundNode).name[0x5e] == (unsigned char)0x9e);
		CHECK((unsigned char)(*pFoundNode).name[0x5f] == (unsigned char)0x7c);
		CHECK((unsigned char)(*pFoundNode).name[0x60] == (unsigned char)0x7c);
		CHECK((unsigned char)(*pFoundNode).name[0x61] == (unsigned char)0x0b);
		CHECK((unsigned char)(*pFoundNode).name[0x62] == (unsigned char)0x54);
		CHECK((unsigned char)(*pFoundNode).name[0x63] == (unsigned char)0x6a);
		CHECK((unsigned char)(*pFoundNode).name[0x64] == (unsigned char)0xab);
		CHECK((unsigned char)(*pFoundNode).name[0x65] == (unsigned char)0x94);
		CHECK((unsigned char)(*pFoundNode).name[0x66] == (unsigned char)0xeb);
		CHECK((unsigned char)(*pFoundNode).name[0x67] == (unsigned char)0x37);
		CHECK((unsigned char)(*pFoundNode).name[0x68] == (unsigned char)0x1c);
		CHECK((unsigned char)(*pFoundNode).name[0x69] == (unsigned char)0x9d);
		CHECK((unsigned char)(*pFoundNode).name[0x6a] == (unsigned char)0x3d);
		CHECK((unsigned char)(*pFoundNode).name[0x6b] == (unsigned char)0x11);
		CHECK((unsigned char)(*pFoundNode).name[0x6c] == (unsigned char)0xd4);
		CHECK((unsigned char)(*pFoundNode).name[0x6d] == (unsigned char)0x0b);
		CHECK((unsigned char)(*pFoundNode).name[0x6e] == (unsigned char)0xe3);
		CHECK((unsigned char)(*pFoundNode).name[0x6f] == (unsigned char)0x22);
		CHECK((unsigned char)(*pFoundNode).name[0x70] == (unsigned char)0xab);
		CHECK((unsigned char)(*pFoundNode).name[0x71] == (unsigned char)0xaa);
		CHECK((unsigned char)(*pFoundNode).name[0x72] == (unsigned char)0xd9);
		CHECK((unsigned char)(*pFoundNode).name[0x73] == (unsigned char)0x04);
		CHECK((unsigned char)(*pFoundNode).name[0x74] == (unsigned char)0x72);
		CHECK((unsigned char)(*pFoundNode).name[0x75] == (unsigned char)0xe6);
		CHECK((unsigned char)(*pFoundNode).name[0x76] == (unsigned char)0xfb);
		CHECK((unsigned char)(*pFoundNode).name[0x77] == (unsigned char)0x0d);
		CHECK((unsigned char)(*pFoundNode).name[0x78] == (unsigned char)0xa2);
		CHECK((unsigned char)(*pFoundNode).name[0x79] == (unsigned char)0x98);
		CHECK((unsigned char)(*pFoundNode).name[0x7a] == (unsigned char)0x20);
		CHECK((unsigned char)(*pFoundNode).name[0x7b] == (unsigned char)0x59);
		CHECK((unsigned char)(*pFoundNode).name[0x7c] == (unsigned char)0xd3);
		CHECK((unsigned char)(*pFoundNode).name[0x7d] == (unsigned char)0x83);
		CHECK((unsigned char)(*pFoundNode).name[0x7e] == (unsigned char)0x37);
		CHECK((unsigned char)(*pFoundNode).name[0x7f] == (unsigned char)0x00);
		CHECK((*pFoundNode).key == 0x1c663af9);

		// Make sure its not used below
		pFoundNode = nullptr;

	//-----------------------------------------------------------------------------
	// Convert to HotCold
	//-----------------------------------------------------------------------------

	// Create a timer objects
	PerformanceTimer t3;

	// start timer
	t3.Tic();

		// -----------------------------------------------------------------------
		//  This is your new function
		// -----------------------------------------------------------------------
		//          Use this API signature to convert the bloated list to hot/cold
		//          You cannot reference the original data, you need to copy 
		//          and convert Original data into your new layout
		// -----------------------------------------------------------------------
		pHotCold = new HotCold(pBloated);

	// stop timer
	t3.Toc();

	CHECK(pHotCold != nullptr);

	//-----------------------------------------------------------------------------
	// Make sure you haven't reference the data
	//-----------------------------------------------------------------------------
	delete pBloated;
	pBloated = nullptr;

	//-----------------------------------------------------------------------------
	// Find a specific Key
	//-----------------------------------------------------------------------------

	HotNode  *pFoundHotNode;
	ColdNode *pFoundColdNode;

	// Create a timer objects
	PerformanceTimer t4;

	// start timer
	t4.Tic();

		// find a specific key
		foundFlag = pHotCold->FindKey(0x1c663af9, pFoundColdNode, pFoundHotNode);

	// stop timer
	t4.Toc();
	CHECK(foundFlag == true);

	//-----------------------------------------------------------------------------
	// Verify
	//-----------------------------------------------------------------------------

	CHECK_EQUAL(((unsigned int)&pFoundColdNode->aa - (unsigned int)pFoundColdNode), 4);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->x - (unsigned int)pFoundColdNode), 8);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->A - (unsigned int)pFoundColdNode), 24);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->y - (unsigned int)pFoundColdNode), 12);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->B - (unsigned int)pFoundColdNode), 36);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->C - (unsigned int)pFoundColdNode), 48);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->z - (unsigned int)pFoundColdNode), 16);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->D - (unsigned int)pFoundColdNode), 60);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->MA - (unsigned int)pFoundColdNode), 72);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->bb - (unsigned int)pFoundColdNode), 5);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->MB - (unsigned int)pFoundColdNode), 136);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->w - (unsigned int)pFoundColdNode), 20);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->MC - (unsigned int)pFoundColdNode), 200);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->MD - (unsigned int)pFoundColdNode), 264);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->cc - (unsigned int)pFoundColdNode), 6);
	CHECK_EQUAL(((unsigned int)&pFoundColdNode->name - (unsigned int)pFoundColdNode), 392);

	CHECK_EQUAL(((unsigned int)&pFoundHotNode->pNext - (unsigned int)pFoundHotNode), 0);
	CHECK_EQUAL(((unsigned int)&pFoundHotNode->pPrev - (unsigned int)pFoundHotNode), 4);
	CHECK_EQUAL(((unsigned int)&pFoundHotNode->key - (unsigned int)pFoundHotNode), 8);
	CHECK_EQUAL(((unsigned int)&pFoundHotNode->pCold - (unsigned int)pFoundHotNode), 12);

	CHECK((0xFF & (*pFoundColdNode).aa) == 0xe);
	CHECK((0xFF & (*pFoundColdNode).bb) == 0xe8);
	CHECK((0xFF & (*pFoundColdNode).cc) == 0xa);
	CHECK((0xFF & (*pFoundColdNode).dd) == 0x7);
	CHECK((*pFoundColdNode).x == 10420.878906f);
	CHECK((*pFoundColdNode).y == 18116.001953f);
	CHECK((*pFoundColdNode).z == 3637.294434f);
	CHECK((*pFoundColdNode).w == 2441.684326f);
	CHECK((*pFoundColdNode).A.x == 22311.681641f);
	CHECK((*pFoundColdNode).A.y == 26392.271484f);
	CHECK((*pFoundColdNode).A.z == 7130.277344f);
	CHECK((*pFoundColdNode).B.x == 3695.925537f);
	CHECK((*pFoundColdNode).B.y == 30814.800781f);
	CHECK((*pFoundColdNode).B.z == 6717.419434f);
	CHECK((*pFoundColdNode).C.x == 27637.845703f);
	CHECK((*pFoundColdNode).C.y == 3059.874023f);
	CHECK((*pFoundColdNode).C.z == 19657.781250f);
	CHECK((*pFoundColdNode).D.x == 32029.228516f);
	CHECK((*pFoundColdNode).D.y == 9179.236328f);
	CHECK((*pFoundColdNode).D.z == 31475.716797f);
	CHECK((*pFoundColdNode).MA.m00 == 1340.649658f);
	CHECK((*pFoundColdNode).MA.m01 == 16427.142578f);
	CHECK((*pFoundColdNode).MA.m02 == 14463.948242f);
	CHECK((*pFoundColdNode).MA.m03 == 16658.214844f);
	CHECK((*pFoundColdNode).MA.m10 == 17774.873047f);
	CHECK((*pFoundColdNode).MA.m11 == 15835.750000f);
	CHECK((*pFoundColdNode).MA.m12 == 14588.989258f);
	CHECK((*pFoundColdNode).MA.m13 == 20279.994141f);
	CHECK((*pFoundColdNode).MA.m20 == 13947.911133f);
	CHECK((*pFoundColdNode).MA.m21 == 8486.875977f);
	CHECK((*pFoundColdNode).MA.m22 == 10511.761719f);
	CHECK((*pFoundColdNode).MA.m23 == 20492.447266f);
	CHECK((*pFoundColdNode).MA.m30 == 10595.417969f);
	CHECK((*pFoundColdNode).MA.m31 == 7175.306152f);
	CHECK((*pFoundColdNode).MA.m32 == 27546.560547f);
	CHECK((*pFoundColdNode).MA.m33 == 26240.275391f);
	CHECK((*pFoundColdNode).MB.m00 == 18825.052734f);
	CHECK((*pFoundColdNode).MB.m01 == 11776.132813f);
	CHECK((*pFoundColdNode).MB.m02 == 15651.704102f);
	CHECK((*pFoundColdNode).MB.m03 == 31813.646484f);
	CHECK((*pFoundColdNode).MB.m10 == 24372.921875f);
	CHECK((*pFoundColdNode).MB.m11 == 31382.732422f);
	CHECK((*pFoundColdNode).MB.m12 == 15955.292969f);
	CHECK((*pFoundColdNode).MB.m13 == 8275.979492f);
	CHECK((*pFoundColdNode).MB.m20 == 8721.644531f);
	CHECK((*pFoundColdNode).MB.m21 == 12240.356445f);
	CHECK((*pFoundColdNode).MB.m22 == 3703.579346f);
	CHECK((*pFoundColdNode).MB.m23 == 30051.353516f);
	CHECK((*pFoundColdNode).MB.m30 == 7088.049316f);
	CHECK((*pFoundColdNode).MB.m31 == 31932.359375f);
	CHECK((*pFoundColdNode).MB.m32 == 30210.980469f);
	CHECK((*pFoundColdNode).MB.m33 == 12405.546875f);
	CHECK((*pFoundColdNode).MC.m00 == 6659.484863f);
	CHECK((*pFoundColdNode).MC.m01 == 6122.045898f);
	CHECK((*pFoundColdNode).MC.m02 == 8457.699219f);
	CHECK((*pFoundColdNode).MC.m03 == 10059.694336f);
	CHECK((*pFoundColdNode).MC.m10 == 12770.762695f);
	CHECK((*pFoundColdNode).MC.m11 == 22000.138672f);
	CHECK((*pFoundColdNode).MC.m12 == 27077.986328f);
	CHECK((*pFoundColdNode).MC.m13 == 28396.572266f);
	CHECK((*pFoundColdNode).MC.m20 == 20873.726563f);
	CHECK((*pFoundColdNode).MC.m21 == 20452.882813f);
	CHECK((*pFoundColdNode).MC.m22 == 13077.010742f);
	CHECK((*pFoundColdNode).MC.m23 == 2594.509521f);
	CHECK((*pFoundColdNode).MC.m30 == 25368.437500f);
	CHECK((*pFoundColdNode).MC.m31 == 6629.764160f);
	CHECK((*pFoundColdNode).MC.m32 == 21242.373047f);
	CHECK((*pFoundColdNode).MC.m33 == 10235.923828f);
	CHECK((*pFoundColdNode).MD.m00 == 32530.998047f);
	CHECK((*pFoundColdNode).MD.m01 == 2450.856934f);
	CHECK((*pFoundColdNode).MD.m02 == 3353.223145f);
	CHECK((*pFoundColdNode).MD.m03 == 29260.478516f);
	CHECK((*pFoundColdNode).MD.m10 == 11998.990234f);
	CHECK((*pFoundColdNode).MD.m11 == 3217.798828f);
	CHECK((*pFoundColdNode).MD.m12 == 7484.024414f);
	CHECK((*pFoundColdNode).MD.m13 == 27689.871094f);
	CHECK((*pFoundColdNode).MD.m20 == 16201.537109f);
	CHECK((*pFoundColdNode).MD.m21 == 3850.386963f);
	CHECK((*pFoundColdNode).MD.m22 == 20945.925781f);
	CHECK((*pFoundColdNode).MD.m23 == 24686.240234f);
	CHECK((*pFoundColdNode).MD.m30 == 8963.002930f);
	CHECK((*pFoundColdNode).MD.m31 == 29225.800781f);
	CHECK((*pFoundColdNode).MD.m32 == 13929.772461f);
	CHECK((*pFoundColdNode).MD.m33 == 24634.207031f);
	CHECK((*pFoundColdNode).ME.m00 == 25886.304688f);
	CHECK((*pFoundColdNode).ME.m01 == 4768.449707f);
	CHECK((*pFoundColdNode).ME.m02 == 20027.724609f);
	CHECK((*pFoundColdNode).ME.m03 == 20847.525391f);
	CHECK((*pFoundColdNode).ME.m10 == 11154.850586f);
	CHECK((*pFoundColdNode).ME.m11 == 24354.447266f);
	CHECK((*pFoundColdNode).ME.m12 == 24223.519531f);
	CHECK((*pFoundColdNode).ME.m13 == 3379.378418f);
	CHECK((*pFoundColdNode).ME.m20 == 18875.115234f);
	CHECK((*pFoundColdNode).ME.m21 == 32489.703125f);
	CHECK((*pFoundColdNode).ME.m22 == 18835.351563f);
	CHECK((*pFoundColdNode).ME.m23 == 3698.277100f);
	CHECK((*pFoundColdNode).ME.m30 == 25305.822266f);
	CHECK((*pFoundColdNode).ME.m31 == 2097.657471f);
	CHECK((*pFoundColdNode).ME.m32 == 30777.367188f);
	CHECK((*pFoundColdNode).ME.m33 == 12377.604492f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x00] == (unsigned char)0xac);
	CHECK((unsigned char)(*pFoundColdNode).name[0x01] == (unsigned char)0x77);
	CHECK((unsigned char)(*pFoundColdNode).name[0x02] == (unsigned char)0x03);
	CHECK((unsigned char)(*pFoundColdNode).name[0x03] == (unsigned char)0xe2);
	CHECK((unsigned char)(*pFoundColdNode).name[0x04] == (unsigned char)0xad);
	CHECK((unsigned char)(*pFoundColdNode).name[0x05] == (unsigned char)0x80);
	CHECK((unsigned char)(*pFoundColdNode).name[0x06] == (unsigned char)0x5a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x07] == (unsigned char)0x4d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x08] == (unsigned char)0xc6);
	CHECK((unsigned char)(*pFoundColdNode).name[0x09] == (unsigned char)0x1c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0a] == (unsigned char)0x5e);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0b] == (unsigned char)0xed);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0c] == (unsigned char)0x2f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0d] == (unsigned char)0x16);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0e] == (unsigned char)0x3d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0f] == (unsigned char)0xda);
	CHECK((unsigned char)(*pFoundColdNode).name[0x10] == (unsigned char)0x7a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x11] == (unsigned char)0xd8);
	CHECK((unsigned char)(*pFoundColdNode).name[0x12] == (unsigned char)0x60);
	CHECK((unsigned char)(*pFoundColdNode).name[0x13] == (unsigned char)0x10);
	CHECK((unsigned char)(*pFoundColdNode).name[0x14] == (unsigned char)0x61);
	CHECK((unsigned char)(*pFoundColdNode).name[0x15] == (unsigned char)0x09);
	CHECK((unsigned char)(*pFoundColdNode).name[0x16] == (unsigned char)0xc2);
	CHECK((unsigned char)(*pFoundColdNode).name[0x17] == (unsigned char)0x29);
	CHECK((unsigned char)(*pFoundColdNode).name[0x18] == (unsigned char)0x11);
	CHECK((unsigned char)(*pFoundColdNode).name[0x19] == (unsigned char)0xd1);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1a] == (unsigned char)0x09);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1b] == (unsigned char)0x02);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1c] == (unsigned char)0x66);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1d] == (unsigned char)0x07);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1e] == (unsigned char)0xb5);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1f] == (unsigned char)0xd4);
	CHECK((unsigned char)(*pFoundColdNode).name[0x20] == (unsigned char)0x28);
	CHECK((unsigned char)(*pFoundColdNode).name[0x21] == (unsigned char)0x49);
	CHECK((unsigned char)(*pFoundColdNode).name[0x22] == (unsigned char)0xc9);
	CHECK((unsigned char)(*pFoundColdNode).name[0x23] == (unsigned char)0xb5);
	CHECK((unsigned char)(*pFoundColdNode).name[0x24] == (unsigned char)0x8d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x25] == (unsigned char)0x3e);
	CHECK((unsigned char)(*pFoundColdNode).name[0x26] == (unsigned char)0x2e);
	CHECK((unsigned char)(*pFoundColdNode).name[0x27] == (unsigned char)0xa7);
	CHECK((unsigned char)(*pFoundColdNode).name[0x28] == (unsigned char)0x2d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x29] == (unsigned char)0x1a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2a] == (unsigned char)0x23);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2b] == (unsigned char)0x8d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2c] == (unsigned char)0x20);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2d] == (unsigned char)0xfe);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2e] == (unsigned char)0xb0);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2f] == (unsigned char)0x39);
	CHECK((unsigned char)(*pFoundColdNode).name[0x30] == (unsigned char)0x74);
	CHECK((unsigned char)(*pFoundColdNode).name[0x31] == (unsigned char)0x7d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x32] == (unsigned char)0xc0);
	CHECK((unsigned char)(*pFoundColdNode).name[0x33] == (unsigned char)0xe8);
	CHECK((unsigned char)(*pFoundColdNode).name[0x34] == (unsigned char)0x3e);
	CHECK((unsigned char)(*pFoundColdNode).name[0x35] == (unsigned char)0xab);
	CHECK((unsigned char)(*pFoundColdNode).name[0x36] == (unsigned char)0x5b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x37] == (unsigned char)0x61);
	CHECK((unsigned char)(*pFoundColdNode).name[0x38] == (unsigned char)0x5b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x39] == (unsigned char)0x27);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3a] == (unsigned char)0x39);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3b] == (unsigned char)0x83);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3c] == (unsigned char)0xc4);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3d] == (unsigned char)0x79);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3e] == (unsigned char)0x23);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3f] == (unsigned char)0x82);
	CHECK((unsigned char)(*pFoundColdNode).name[0x40] == (unsigned char)0x76);
	CHECK((unsigned char)(*pFoundColdNode).name[0x41] == (unsigned char)0x2a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x42] == (unsigned char)0xcc);
	CHECK((unsigned char)(*pFoundColdNode).name[0x43] == (unsigned char)0x20);
	CHECK((unsigned char)(*pFoundColdNode).name[0x44] == (unsigned char)0x4b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x45] == (unsigned char)0x7f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x46] == (unsigned char)0xa5);
	CHECK((unsigned char)(*pFoundColdNode).name[0x47] == (unsigned char)0x97);
	CHECK((unsigned char)(*pFoundColdNode).name[0x48] == (unsigned char)0x5a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x49] == (unsigned char)0x32);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4a] == (unsigned char)0x45);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4b] == (unsigned char)0x07);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4c] == (unsigned char)0xad);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4d] == (unsigned char)0x99);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4e] == (unsigned char)0x04);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4f] == (unsigned char)0x1d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x50] == (unsigned char)0x68);
	CHECK((unsigned char)(*pFoundColdNode).name[0x51] == (unsigned char)0x0f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x52] == (unsigned char)0xd0);
	CHECK((unsigned char)(*pFoundColdNode).name[0x53] == (unsigned char)0xce);
	CHECK((unsigned char)(*pFoundColdNode).name[0x54] == (unsigned char)0x26);
	CHECK((unsigned char)(*pFoundColdNode).name[0x55] == (unsigned char)0x17);
	CHECK((unsigned char)(*pFoundColdNode).name[0x56] == (unsigned char)0x54);
	CHECK((unsigned char)(*pFoundColdNode).name[0x57] == (unsigned char)0xc6);
	CHECK((unsigned char)(*pFoundColdNode).name[0x58] == (unsigned char)0x36);
	CHECK((unsigned char)(*pFoundColdNode).name[0x59] == (unsigned char)0x09);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5a] == (unsigned char)0x82);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5b] == (unsigned char)0x7b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5c] == (unsigned char)0x79);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5d] == (unsigned char)0xbc);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5e] == (unsigned char)0x9e);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5f] == (unsigned char)0x7c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x60] == (unsigned char)0x7c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x61] == (unsigned char)0x0b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x62] == (unsigned char)0x54);
	CHECK((unsigned char)(*pFoundColdNode).name[0x63] == (unsigned char)0x6a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x64] == (unsigned char)0xab);
	CHECK((unsigned char)(*pFoundColdNode).name[0x65] == (unsigned char)0x94);
	CHECK((unsigned char)(*pFoundColdNode).name[0x66] == (unsigned char)0xeb);
	CHECK((unsigned char)(*pFoundColdNode).name[0x67] == (unsigned char)0x37);
	CHECK((unsigned char)(*pFoundColdNode).name[0x68] == (unsigned char)0x1c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x69] == (unsigned char)0x9d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6a] == (unsigned char)0x3d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6b] == (unsigned char)0x11);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6c] == (unsigned char)0xd4);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6d] == (unsigned char)0x0b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6e] == (unsigned char)0xe3);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6f] == (unsigned char)0x22);
	CHECK((unsigned char)(*pFoundColdNode).name[0x70] == (unsigned char)0xab);
	CHECK((unsigned char)(*pFoundColdNode).name[0x71] == (unsigned char)0xaa);
	CHECK((unsigned char)(*pFoundColdNode).name[0x72] == (unsigned char)0xd9);
	CHECK((unsigned char)(*pFoundColdNode).name[0x73] == (unsigned char)0x04);
	CHECK((unsigned char)(*pFoundColdNode).name[0x74] == (unsigned char)0x72);
	CHECK((unsigned char)(*pFoundColdNode).name[0x75] == (unsigned char)0xe6);
	CHECK((unsigned char)(*pFoundColdNode).name[0x76] == (unsigned char)0xfb);
	CHECK((unsigned char)(*pFoundColdNode).name[0x77] == (unsigned char)0x0d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x78] == (unsigned char)0xa2);
	CHECK((unsigned char)(*pFoundColdNode).name[0x79] == (unsigned char)0x98);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7a] == (unsigned char)0x20);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7b] == (unsigned char)0x59);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7c] == (unsigned char)0xd3);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7d] == (unsigned char)0x83);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7e] == (unsigned char)0x37);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7f] == (unsigned char)0x00);

	CHECK(pFoundHotNode->key == 0x1c663af9);

	//-----------------------------------------------------------------------------
	// Print Results
	//-----------------------------------------------------------------------------

	Trace::out2("\n");
	Trace::out2(" --- HotCold Problem ------------------\n");
	Trace::out2("\n");

	if (HotColdConvert_Test == true  && HotColdLink_Test == true && BloatedFindKey_Test)
	{
		Trace::out2("  Bloated List create: %f s\n", t1.TimeInSeconds());
		Trace::out2("      HotCold convert: %f ms\n", t3.TimeInSeconds() * 1000.0f);
		Trace::out2("\n");
		Trace::out2("         Bloated find: %f ms\n", t2.TimeInSeconds() * 1000.0f);
		Trace::out2("         HotCold find: %f ms\n", t4.TimeInSeconds() * 1000.0f);
		Trace::out2("\n");
		Trace::out2("                Ratio: %f \n", t2.TimeInSeconds() / t4.TimeInSeconds());
		Trace::out2("\n");
	}
	else
	{
		Trace::out2("--- ERROR: Need to pass (Find,Convert,Link) tests for timing scores --- \n", t1.TimeInSeconds());
		Trace::out2("\n");
		Trace::out2("  Bloated List create: %f s\n", t1.TimeInSeconds());
		Trace::out2("      HotCold convert: %f ms  {INVALID}\n", 999.9f);
		Trace::out2("\n");
		Trace::out2("         Bloated find: %f ms  {INVALID}\n", 999.9f);
		Trace::out2("         HotCold find: %f ms  {INVALID}\n", 999.9f);
		Trace::out2("\n");
		Trace::out2("                Ratio: %f  {INVALID} \n", 0.0f);
		Trace::out2("\n");
	}


	delete pBloated;
	delete pHotCold;
	pBloated = nullptr;
	pHotCold = nullptr;

} TEST_END

TEST_TEARDOWN(Timing_HotCold)
{
	delete pBloated;
	delete pHotCold;
}

// ---  End of File ---
