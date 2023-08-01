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
extern bool HotColdLink_Test;

TEST_WITH_TEARDOWN(Link_HotCold, TestConfig::ALL)
{

	// Cannot add data to class
	CHECK(sizeof(Node) == 540);
	CHECK(sizeof(Bloated) == 4);
	CHECK(sizeof(HotCold) == 8);
	CHECK(sizeof(HotNode) == 16);
	CHECK(sizeof(ColdNode) == 520);

	//-----------------------------------------------------------------------------
	// It initializes the data if a very bloated way do not modify it!
	//-----------------------------------------------------------------------------

	Bloated *pBloated = new Bloated(1000);
	CHECK(pBloated != nullptr);

	// -----------------------------------------------------------------------
	//  This is your new function
	// -----------------------------------------------------------------------
	//          Use this API signature to convert the bloated list to hot/cold
	//          You cannot reference the original data, you need to copy 
	//          and convert Original data into your new layout
	// -----------------------------------------------------------------------
	pHotCold = new HotCold( pBloated );
	CHECK(pHotCold != nullptr);

	//-----------------------------------------------------------------------------
	// Make sure you haven't reference the data
	//-----------------------------------------------------------------------------
	delete pBloated;
	pBloated = nullptr;

	//-----------------------------------------------------------------------------
	// Find a specific Keys
	//-----------------------------------------------------------------------------

	HotNode  *pFoundHotNode;
	ColdNode *pFoundColdNode;
	bool foundFlag;

	//-------------------------------------------------------------------
	// Find Key A
	//-------------------------------------------------------------------
	foundFlag = pHotCold->FindKey(0x44274d4, pFoundColdNode, pFoundHotNode);
	CHECK(foundFlag == true);

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

	CHECK((0xFF & (*pFoundColdNode).aa) == 0xfd);
	CHECK((0xFF & (*pFoundColdNode).bb) == 0xe8);
	CHECK((0xFF & (*pFoundColdNode).cc) == 0x47);
	CHECK((0xFF & (*pFoundColdNode).dd) == 0x1c);
	CHECK((*pFoundColdNode).x == 15986.185547f);
	CHECK((*pFoundColdNode).y == 30603.710938f);
	CHECK((*pFoundColdNode).z == 5783.308594f);
	CHECK((*pFoundColdNode).w == 2290.570068f);
	CHECK((*pFoundColdNode).A.x == 14609.004883f);
	CHECK((*pFoundColdNode).A.y == 10465.243164f);
	CHECK((*pFoundColdNode).A.z == 27687.509766f);
	CHECK((*pFoundColdNode).B.x == 27372.203125f);
	CHECK((*pFoundColdNode).B.y == 21561.359375f);
	CHECK((*pFoundColdNode).B.z == 11176.781250f);
	CHECK((*pFoundColdNode).C.x == 28827.089844f);
	CHECK((*pFoundColdNode).C.y == 5147.714844f);
	CHECK((*pFoundColdNode).C.z == 23204.388672f);
	CHECK((*pFoundColdNode).D.x == 29040.712891f);
	CHECK((*pFoundColdNode).D.y == 31489.464844f);
	CHECK((*pFoundColdNode).D.z == 13551.084961f);
	CHECK((*pFoundColdNode).MA.m00 == 10575.935547f);
	CHECK((*pFoundColdNode).MA.m01 == 12333.951172f);
	CHECK((*pFoundColdNode).MA.m02 == 27114.000000f);
	CHECK((*pFoundColdNode).MA.m03 == 24960.080078f);
	CHECK((*pFoundColdNode).MA.m10 == 15871.195313f);
	CHECK((*pFoundColdNode).MA.m11 == 25782.871094f);
	CHECK((*pFoundColdNode).MA.m12 == 14825.485352f);
	CHECK((*pFoundColdNode).MA.m13 == 23559.513672f);
	CHECK((*pFoundColdNode).MA.m20 == 21946.007813f);
	CHECK((*pFoundColdNode).MA.m21 == 25927.875000f);
	CHECK((*pFoundColdNode).MA.m22 == 11287.224609f);
	CHECK((*pFoundColdNode).MA.m23 == 28513.115234f);
	CHECK((*pFoundColdNode).MA.m30 == 6986.765625f);
	CHECK((*pFoundColdNode).MA.m31 == 1024.590088f);
	CHECK((*pFoundColdNode).MA.m32 == 31890.765625f);
	CHECK((*pFoundColdNode).MA.m33 == 22927.048828f);
	CHECK((*pFoundColdNode).MB.m00 == 26045.947266f);
	CHECK((*pFoundColdNode).MB.m01 == 16740.679688f);
	CHECK((*pFoundColdNode).MB.m02 == 10489.248047f);
	CHECK((*pFoundColdNode).MB.m03 == 17976.027344f);
	CHECK((*pFoundColdNode).MB.m10 == 1768.278076f);
	CHECK((*pFoundColdNode).MB.m11 == 3803.289063f);
	CHECK((*pFoundColdNode).MB.m12 == 18162.369141f);
	CHECK((*pFoundColdNode).MB.m13 == 22821.076172f);
	CHECK((*pFoundColdNode).MB.m20 == 10719.519531f);
	CHECK((*pFoundColdNode).MB.m21 == 8496.104492f);
	CHECK((*pFoundColdNode).MB.m22 == 27301.992188f);
	CHECK((*pFoundColdNode).MB.m23 == 18628.906250f);
	CHECK((*pFoundColdNode).MB.m30 == 16766.873047f);
	CHECK((*pFoundColdNode).MB.m31 == 21267.050781f);
	CHECK((*pFoundColdNode).MB.m32 == 7486.355469f);
	CHECK((*pFoundColdNode).MB.m33 == 2215.924805f);
	CHECK((*pFoundColdNode).MC.m00 == 1764.021484f);
	CHECK((*pFoundColdNode).MC.m01 == 6040.607422f);
	CHECK((*pFoundColdNode).MC.m02 == 25455.933594f);
	CHECK((*pFoundColdNode).MC.m03 == 1026.856079f);
	CHECK((*pFoundColdNode).MC.m10 == 2035.781738f);
	CHECK((*pFoundColdNode).MC.m11 == 31926.748047f);
	CHECK((*pFoundColdNode).MC.m12 == 21483.898438f);
	CHECK((*pFoundColdNode).MC.m13 == 26672.000000f);
	CHECK((*pFoundColdNode).MC.m20 == 17873.396484f);
	CHECK((*pFoundColdNode).MC.m21 == 15818.506836f);
	CHECK((*pFoundColdNode).MC.m22 == 15852.228516f);
	CHECK((*pFoundColdNode).MC.m23 == 32559.113281f);
	CHECK((*pFoundColdNode).MC.m30 == 25450.443359f);
	CHECK((*pFoundColdNode).MC.m31 == 26129.171875f);
	CHECK((*pFoundColdNode).MC.m32 == 24494.421875f);
	CHECK((*pFoundColdNode).MC.m33 == 6687.903809f);
	CHECK((*pFoundColdNode).MD.m00 == 25579.367188f);
	CHECK((*pFoundColdNode).MD.m01 == 817.097046f);
	CHECK((*pFoundColdNode).MD.m02 == 11506.844727f);
	CHECK((*pFoundColdNode).MD.m03 == 3014.172119f);
	CHECK((*pFoundColdNode).MD.m10 == 31048.640625f);
	CHECK((*pFoundColdNode).MD.m11 == 26545.150391f);
	CHECK((*pFoundColdNode).MD.m12 == 9596.712891f);
	CHECK((*pFoundColdNode).MD.m13 == 13071.556641f);
	CHECK((*pFoundColdNode).MD.m20 == 25271.550781f);
	CHECK((*pFoundColdNode).MD.m21 == 32124.777344f);
	CHECK((*pFoundColdNode).MD.m22 == 15253.677734f);
	CHECK((*pFoundColdNode).MD.m23 == 5511.916016f);
	CHECK((*pFoundColdNode).MD.m30 == 23347.613281f);
	CHECK((*pFoundColdNode).MD.m31 == 10339.684570f);
	CHECK((*pFoundColdNode).MD.m32 == 19082.056641f);
	CHECK((*pFoundColdNode).MD.m33 == 2527.331055f);
	CHECK((*pFoundColdNode).ME.m00 == 6139.596191f);
	CHECK((*pFoundColdNode).ME.m01 == 14487.171875f);
	CHECK((*pFoundColdNode).ME.m02 == 7466.680176f);
	CHECK((*pFoundColdNode).ME.m03 == 29292.734375f);
	CHECK((*pFoundColdNode).ME.m10 == 22288.193359f);
	CHECK((*pFoundColdNode).ME.m11 == 27955.058594f);
	CHECK((*pFoundColdNode).ME.m12 == 1100.358765f);
	CHECK((*pFoundColdNode).ME.m13 == 1962.168335f);
	CHECK((*pFoundColdNode).ME.m20 == 32186.298828f);
	CHECK((*pFoundColdNode).ME.m21 == 1712.262695f);
	CHECK((*pFoundColdNode).ME.m22 == 32071.986328f);
	CHECK((*pFoundColdNode).ME.m23 == 12981.655273f);
	CHECK((*pFoundColdNode).ME.m30 == 18180.923828f);
	CHECK((*pFoundColdNode).ME.m31 == 26991.980469f);
	CHECK((*pFoundColdNode).ME.m32 == 26745.263672f);
	CHECK((*pFoundColdNode).ME.m33 == 30670.708984f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x00] == (unsigned char)0x3e);
	CHECK((unsigned char)(*pFoundColdNode).name[0x01] == (unsigned char)0xac);
	CHECK((unsigned char)(*pFoundColdNode).name[0x02] == (unsigned char)0x84);
	CHECK((unsigned char)(*pFoundColdNode).name[0x03] == (unsigned char)0x5f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x04] == (unsigned char)0x12);
	CHECK((unsigned char)(*pFoundColdNode).name[0x05] == (unsigned char)0x24);
	CHECK((unsigned char)(*pFoundColdNode).name[0x06] == (unsigned char)0x4f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x07] == (unsigned char)0x47);
	CHECK((unsigned char)(*pFoundColdNode).name[0x08] == (unsigned char)0xd5);
	CHECK((unsigned char)(*pFoundColdNode).name[0x09] == (unsigned char)0xea);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0a] == (unsigned char)0xb2);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0b] == (unsigned char)0xac);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0c] == (unsigned char)0x42);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0d] == (unsigned char)0x48);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0e] == (unsigned char)0x42);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0f] == (unsigned char)0x57);
	CHECK((unsigned char)(*pFoundColdNode).name[0x10] == (unsigned char)0x5b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x11] == (unsigned char)0x63);
	CHECK((unsigned char)(*pFoundColdNode).name[0x12] == (unsigned char)0x32);
	CHECK((unsigned char)(*pFoundColdNode).name[0x13] == (unsigned char)0xe1);
	CHECK((unsigned char)(*pFoundColdNode).name[0x14] == (unsigned char)0xcc);
	CHECK((unsigned char)(*pFoundColdNode).name[0x15] == (unsigned char)0x7a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x16] == (unsigned char)0xc3);
	CHECK((unsigned char)(*pFoundColdNode).name[0x17] == (unsigned char)0xe1);
	CHECK((unsigned char)(*pFoundColdNode).name[0x18] == (unsigned char)0x0d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x19] == (unsigned char)0xd0);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1a] == (unsigned char)0xfb);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1b] == (unsigned char)0x0f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1c] == (unsigned char)0x6c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1d] == (unsigned char)0xc5);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1e] == (unsigned char)0xfe);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1f] == (unsigned char)0x74);
	CHECK((unsigned char)(*pFoundColdNode).name[0x20] == (unsigned char)0x1b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x21] == (unsigned char)0xa3);
	CHECK((unsigned char)(*pFoundColdNode).name[0x22] == (unsigned char)0xb2);
	CHECK((unsigned char)(*pFoundColdNode).name[0x23] == (unsigned char)0xe8);
	CHECK((unsigned char)(*pFoundColdNode).name[0x24] == (unsigned char)0xc1);
	CHECK((unsigned char)(*pFoundColdNode).name[0x25] == (unsigned char)0x92);
	CHECK((unsigned char)(*pFoundColdNode).name[0x26] == (unsigned char)0x64);
	CHECK((unsigned char)(*pFoundColdNode).name[0x27] == (unsigned char)0x5e);
	CHECK((unsigned char)(*pFoundColdNode).name[0x28] == (unsigned char)0xb5);
	CHECK((unsigned char)(*pFoundColdNode).name[0x29] == (unsigned char)0x5d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2a] == (unsigned char)0x9d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2b] == (unsigned char)0xbc);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2c] == (unsigned char)0x6c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2d] == (unsigned char)0x5a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2e] == (unsigned char)0xee);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2f] == (unsigned char)0x57);
	CHECK((unsigned char)(*pFoundColdNode).name[0x30] == (unsigned char)0x2e);
	CHECK((unsigned char)(*pFoundColdNode).name[0x31] == (unsigned char)0xaf);
	CHECK((unsigned char)(*pFoundColdNode).name[0x32] == (unsigned char)0x3f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x33] == (unsigned char)0xbe);
	CHECK((unsigned char)(*pFoundColdNode).name[0x34] == (unsigned char)0xb1);
	CHECK((unsigned char)(*pFoundColdNode).name[0x35] == (unsigned char)0x3d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x36] == (unsigned char)0x85);
	CHECK((unsigned char)(*pFoundColdNode).name[0x37] == (unsigned char)0x6d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x38] == (unsigned char)0xa0);
	CHECK((unsigned char)(*pFoundColdNode).name[0x39] == (unsigned char)0x73);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3a] == (unsigned char)0x72);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3b] == (unsigned char)0x9d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3c] == (unsigned char)0xae);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3d] == (unsigned char)0x57);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3e] == (unsigned char)0xe0);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3f] == (unsigned char)0xc2);
	CHECK((unsigned char)(*pFoundColdNode).name[0x40] == (unsigned char)0x38);
	CHECK((unsigned char)(*pFoundColdNode).name[0x41] == (unsigned char)0xed);
	CHECK((unsigned char)(*pFoundColdNode).name[0x42] == (unsigned char)0x25);
	CHECK((unsigned char)(*pFoundColdNode).name[0x43] == (unsigned char)0xed);
	CHECK((unsigned char)(*pFoundColdNode).name[0x44] == (unsigned char)0x26);
	CHECK((unsigned char)(*pFoundColdNode).name[0x45] == (unsigned char)0xef);
	CHECK((unsigned char)(*pFoundColdNode).name[0x46] == (unsigned char)0x09);
	CHECK((unsigned char)(*pFoundColdNode).name[0x47] == (unsigned char)0x23);
	CHECK((unsigned char)(*pFoundColdNode).name[0x48] == (unsigned char)0xf9);
	CHECK((unsigned char)(*pFoundColdNode).name[0x49] == (unsigned char)0xe2);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4a] == (unsigned char)0x12);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4b] == (unsigned char)0x5f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4c] == (unsigned char)0xcd);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4d] == (unsigned char)0x7a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4e] == (unsigned char)0x5b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4f] == (unsigned char)0xde);
	CHECK((unsigned char)(*pFoundColdNode).name[0x50] == (unsigned char)0x23);
	CHECK((unsigned char)(*pFoundColdNode).name[0x51] == (unsigned char)0xf9);
	CHECK((unsigned char)(*pFoundColdNode).name[0x52] == (unsigned char)0x99);
	CHECK((unsigned char)(*pFoundColdNode).name[0x53] == (unsigned char)0xca);
	CHECK((unsigned char)(*pFoundColdNode).name[0x54] == (unsigned char)0x40);
	CHECK((unsigned char)(*pFoundColdNode).name[0x55] == (unsigned char)0x5a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x56] == (unsigned char)0xa9);
	CHECK((unsigned char)(*pFoundColdNode).name[0x57] == (unsigned char)0xff);
	CHECK((unsigned char)(*pFoundColdNode).name[0x58] == (unsigned char)0x99);
	CHECK((unsigned char)(*pFoundColdNode).name[0x59] == (unsigned char)0xf4);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5a] == (unsigned char)0x22);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5b] == (unsigned char)0x05);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5c] == (unsigned char)0x67);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5d] == (unsigned char)0x06);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5e] == (unsigned char)0xe1);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5f] == (unsigned char)0x4c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x60] == (unsigned char)0xe9);
	CHECK((unsigned char)(*pFoundColdNode).name[0x61] == (unsigned char)0x32);
	CHECK((unsigned char)(*pFoundColdNode).name[0x62] == (unsigned char)0x88);
	CHECK((unsigned char)(*pFoundColdNode).name[0x63] == (unsigned char)0x89);
	CHECK((unsigned char)(*pFoundColdNode).name[0x64] == (unsigned char)0x8b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x65] == (unsigned char)0xef);
	CHECK((unsigned char)(*pFoundColdNode).name[0x66] == (unsigned char)0x4b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x67] == (unsigned char)0x0d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x68] == (unsigned char)0xd4);
	CHECK((unsigned char)(*pFoundColdNode).name[0x69] == (unsigned char)0x7f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6a] == (unsigned char)0xa5);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6b] == (unsigned char)0x75);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6c] == (unsigned char)0x67);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6d] == (unsigned char)0xc6);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6e] == (unsigned char)0xcc);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6f] == (unsigned char)0xb8);
	CHECK((unsigned char)(*pFoundColdNode).name[0x70] == (unsigned char)0x6f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x71] == (unsigned char)0xc5);
	CHECK((unsigned char)(*pFoundColdNode).name[0x72] == (unsigned char)0xe0);
	CHECK((unsigned char)(*pFoundColdNode).name[0x73] == (unsigned char)0xca);
	CHECK((unsigned char)(*pFoundColdNode).name[0x74] == (unsigned char)0xca);
	CHECK((unsigned char)(*pFoundColdNode).name[0x75] == (unsigned char)0xfd);
	CHECK((unsigned char)(*pFoundColdNode).name[0x76] == (unsigned char)0x4d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x77] == (unsigned char)0x5e);
	CHECK((unsigned char)(*pFoundColdNode).name[0x78] == (unsigned char)0xcd);
	CHECK((unsigned char)(*pFoundColdNode).name[0x79] == (unsigned char)0xf3);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7a] == (unsigned char)0x50);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7b] == (unsigned char)0x0e);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7c] == (unsigned char)0x59);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7d] == (unsigned char)0xab);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7e] == (unsigned char)0x97);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7f] == (unsigned char)0x00);

	CHECK(pFoundHotNode->key == 0x44274d4);
	CHECK(pFoundHotNode->pCold == pFoundColdNode);

	HotNode *pA = pFoundHotNode;

	CHECK(pA != nullptr);

	CHECK(pA->key == 0x44274d4);
	CHECK(pA->pPrev == nullptr);
	CHECK(pA->pNext != nullptr);
	CHECK(pA->pCold == pFoundColdNode);

	HotNode *pB = pA->pNext;
	CHECK(pB != nullptr);

	CHECK(pB->key == 0x48605e65);
	CHECK(pB->pPrev == pA);
	CHECK(pB->pNext != nullptr);
	CHECK(pB->pCold != nullptr);

	HotNode *pC = pB->pNext;
	CHECK(pC != nullptr);

	CHECK(pC->key == 0x2bdb5c78);
	CHECK(pC->pPrev == pB);
	CHECK(pC->pNext != nullptr);
	CHECK(pC->pCold != nullptr);

	CHECK(pB->pNext == pC);

	pA = nullptr;
	pB = nullptr;
	pC = nullptr;

	//-------------------------------------------------------------------
	// Find Key N
	//-------------------------------------------------------------------
	foundFlag = pHotCold->FindKey(0x20846906, pFoundColdNode, pFoundHotNode);
	CHECK(foundFlag == true);

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

	CHECK((0xFF & (*pFoundColdNode).aa) == 0x6c);
	CHECK((0xFF & (*pFoundColdNode).bb) == 0xba);
	CHECK((0xFF & (*pFoundColdNode).cc) == 0x34);
	CHECK((0xFF & (*pFoundColdNode).dd) == 0x86);
	CHECK((*pFoundColdNode).x == 29649.839844f);
	CHECK((*pFoundColdNode).y == 18842.027344f);
	CHECK((*pFoundColdNode).z == 12037.750977f);
	CHECK((*pFoundColdNode).w == 13419.432617f);
	CHECK((*pFoundColdNode).A.x == 19265.277344f);
	CHECK((*pFoundColdNode).A.y == 24992.097656f);
	CHECK((*pFoundColdNode).A.z == 28398.277344f);
	CHECK((*pFoundColdNode).B.x == 8962.947266f);
	CHECK((*pFoundColdNode).B.y == 13113.744141f);
	CHECK((*pFoundColdNode).B.z == 23890.845703f);
	CHECK((*pFoundColdNode).C.x == 13835.000977f);
	CHECK((*pFoundColdNode).C.y == 18909.681641f);
	CHECK((*pFoundColdNode).C.z == 2108.749756f);
	CHECK((*pFoundColdNode).D.x == 30288.000000f);
	CHECK((*pFoundColdNode).D.y == 19460.980469f);
	CHECK((*pFoundColdNode).D.z == 30414.455078f);
	CHECK((*pFoundColdNode).MA.m00 == 6066.280273f);
	CHECK((*pFoundColdNode).MA.m01 == 32320.857422f);
	CHECK((*pFoundColdNode).MA.m02 == 28832.582031f);
	CHECK((*pFoundColdNode).MA.m03 == 20716.123047f);
	CHECK((*pFoundColdNode).MA.m10 == 29286.867188f);
	CHECK((*pFoundColdNode).MA.m11 == 17738.871094f);
	CHECK((*pFoundColdNode).MA.m12 == 30286.865234f);
	CHECK((*pFoundColdNode).MA.m13 == 18194.980469f);
	CHECK((*pFoundColdNode).MA.m20 == 20232.281250f);
	CHECK((*pFoundColdNode).MA.m21 == 4250.873535f);
	CHECK((*pFoundColdNode).MA.m22 == 27807.576172f);
	CHECK((*pFoundColdNode).MA.m23 == 3679.802246f);
	CHECK((*pFoundColdNode).MA.m30 == 31916.843750f);
	CHECK((*pFoundColdNode).MA.m31 == 8417.933594f);
	CHECK((*pFoundColdNode).MA.m32 == 23242.785156f);
	CHECK((*pFoundColdNode).MA.m33 == 12469.500977f);
	CHECK((*pFoundColdNode).MB.m00 == 25929.371094f);
	CHECK((*pFoundColdNode).MB.m01 == 18645.818359f);
	CHECK((*pFoundColdNode).MB.m02 == 2599.137207f);
	CHECK((*pFoundColdNode).MB.m03 == 11066.414063f);
	CHECK((*pFoundColdNode).MB.m10 == 8251.741211f);
	CHECK((*pFoundColdNode).MB.m11 == 5037.097168f);
	CHECK((*pFoundColdNode).MB.m12 == 24756.728516f);
	CHECK((*pFoundColdNode).MB.m13 == 7386.209961f);
	CHECK((*pFoundColdNode).MB.m20 == 5314.087402f);
	CHECK((*pFoundColdNode).MB.m21 == 31654.863281f);
	CHECK((*pFoundColdNode).MB.m22 == 19347.615234f);
	CHECK((*pFoundColdNode).MB.m23 == 1218.428101f);
	CHECK((*pFoundColdNode).MB.m30 == 11393.608398f);
	CHECK((*pFoundColdNode).MB.m31 == 12416.077148f);
	CHECK((*pFoundColdNode).MB.m32 == 14730.938477f);
	CHECK((*pFoundColdNode).MB.m33 == 4326.636230f);
	CHECK((*pFoundColdNode).MC.m00 == 5632.014160f);
	CHECK((*pFoundColdNode).MC.m01 == 28162.546875f);
	CHECK((*pFoundColdNode).MC.m02 == 9601.682617f);
	CHECK((*pFoundColdNode).MC.m03 == 31868.214844f);
	CHECK((*pFoundColdNode).MC.m10 == 5930.591309f);
	CHECK((*pFoundColdNode).MC.m11 == 25202.519531f);
	CHECK((*pFoundColdNode).MC.m12 == 12552.047852f);
	CHECK((*pFoundColdNode).MC.m13 == 32383.773438f);
	CHECK((*pFoundColdNode).MC.m20 == 28623.896484f);
	CHECK((*pFoundColdNode).MC.m21 == 9501.906250f);
	CHECK((*pFoundColdNode).MC.m22 == 20175.460938f);
	CHECK((*pFoundColdNode).MC.m23 == 18478.171875f);
	CHECK((*pFoundColdNode).MC.m30 == 19491.068359f);
	CHECK((*pFoundColdNode).MC.m31 == 15573.128906f);
	CHECK((*pFoundColdNode).MC.m32 == 32044.197266f);
	CHECK((*pFoundColdNode).MC.m33 == 5002.199707f);
	CHECK((*pFoundColdNode).MD.m00 == 18238.771484f);
	CHECK((*pFoundColdNode).MD.m01 == 13934.592773f);
	CHECK((*pFoundColdNode).MD.m02 == 4248.641602f);
	CHECK((*pFoundColdNode).MD.m03 == 16859.845703f);
	CHECK((*pFoundColdNode).MD.m10 == 32154.767578f);
	CHECK((*pFoundColdNode).MD.m11 == 19264.787109f);
	CHECK((*pFoundColdNode).MD.m12 == 3634.162109f);
	CHECK((*pFoundColdNode).MD.m13 == 2604.211670f);
	CHECK((*pFoundColdNode).MD.m20 == 12184.095703f);
	CHECK((*pFoundColdNode).MD.m21 == 6056.004883f);
	CHECK((*pFoundColdNode).MD.m22 == 5691.616211f);
	CHECK((*pFoundColdNode).MD.m23 == 14282.054688f);
	CHECK((*pFoundColdNode).MD.m30 == 29691.900391f);
	CHECK((*pFoundColdNode).MD.m31 == 24967.689453f);
	CHECK((*pFoundColdNode).MD.m32 == 24216.478516f);
	CHECK((*pFoundColdNode).MD.m33 == 30921.939453f);
	CHECK((*pFoundColdNode).ME.m00 == 31338.861328f);
	CHECK((*pFoundColdNode).ME.m01 == 28353.408203f);
	CHECK((*pFoundColdNode).ME.m02 == 15699.595703f);
	CHECK((*pFoundColdNode).ME.m03 == 15487.024414f);
	CHECK((*pFoundColdNode).ME.m10 == 24051.275391f);
	CHECK((*pFoundColdNode).ME.m11 == 27584.455078f);
	CHECK((*pFoundColdNode).ME.m12 == 17178.566406f);
	CHECK((*pFoundColdNode).ME.m13 == 8711.476563f);
	CHECK((*pFoundColdNode).ME.m20 == 1923.732056f);
	CHECK((*pFoundColdNode).ME.m21 == 25071.064453f);
	CHECK((*pFoundColdNode).ME.m22 == 26047.740234f);
	CHECK((*pFoundColdNode).ME.m23 == 30399.501953f);
	CHECK((*pFoundColdNode).ME.m30 == 8303.437500f);
	CHECK((*pFoundColdNode).ME.m31 == 15935.266602f);
	CHECK((*pFoundColdNode).ME.m32 == 15030.854492f);
	CHECK((*pFoundColdNode).ME.m33 == 17610.005859f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x00] == (unsigned char)0x04);
	CHECK((unsigned char)(*pFoundColdNode).name[0x01] == (unsigned char)0x33);
	CHECK((unsigned char)(*pFoundColdNode).name[0x02] == (unsigned char)0x0e);
	CHECK((unsigned char)(*pFoundColdNode).name[0x03] == (unsigned char)0x6c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x04] == (unsigned char)0xdc);
	CHECK((unsigned char)(*pFoundColdNode).name[0x05] == (unsigned char)0x24);
	CHECK((unsigned char)(*pFoundColdNode).name[0x06] == (unsigned char)0x02);
	CHECK((unsigned char)(*pFoundColdNode).name[0x07] == (unsigned char)0x85);
	CHECK((unsigned char)(*pFoundColdNode).name[0x08] == (unsigned char)0xc3);
	CHECK((unsigned char)(*pFoundColdNode).name[0x09] == (unsigned char)0x15);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0a] == (unsigned char)0xff);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0b] == (unsigned char)0x61);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0c] == (unsigned char)0xe8);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0d] == (unsigned char)0xd8);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0e] == (unsigned char)0xa5);
	CHECK((unsigned char)(*pFoundColdNode).name[0x0f] == (unsigned char)0x92);
	CHECK((unsigned char)(*pFoundColdNode).name[0x10] == (unsigned char)0x09);
	CHECK((unsigned char)(*pFoundColdNode).name[0x11] == (unsigned char)0xfb);
	CHECK((unsigned char)(*pFoundColdNode).name[0x12] == (unsigned char)0xb0);
	CHECK((unsigned char)(*pFoundColdNode).name[0x13] == (unsigned char)0x7d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x14] == (unsigned char)0x69);
	CHECK((unsigned char)(*pFoundColdNode).name[0x15] == (unsigned char)0x3b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x16] == (unsigned char)0xa1);
	CHECK((unsigned char)(*pFoundColdNode).name[0x17] == (unsigned char)0x3c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x18] == (unsigned char)0x1b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x19] == (unsigned char)0x69);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1a] == (unsigned char)0x1c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1b] == (unsigned char)0x55);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1c] == (unsigned char)0x82);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1d] == (unsigned char)0x42);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1e] == (unsigned char)0xf6);
	CHECK((unsigned char)(*pFoundColdNode).name[0x1f] == (unsigned char)0x51);
	CHECK((unsigned char)(*pFoundColdNode).name[0x20] == (unsigned char)0x92);
	CHECK((unsigned char)(*pFoundColdNode).name[0x21] == (unsigned char)0xf8);
	CHECK((unsigned char)(*pFoundColdNode).name[0x22] == (unsigned char)0x37);
	CHECK((unsigned char)(*pFoundColdNode).name[0x23] == (unsigned char)0x25);
	CHECK((unsigned char)(*pFoundColdNode).name[0x24] == (unsigned char)0xad);
	CHECK((unsigned char)(*pFoundColdNode).name[0x25] == (unsigned char)0xed);
	CHECK((unsigned char)(*pFoundColdNode).name[0x26] == (unsigned char)0x5f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x27] == (unsigned char)0x08);
	CHECK((unsigned char)(*pFoundColdNode).name[0x28] == (unsigned char)0x2a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x29] == (unsigned char)0x6f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2a] == (unsigned char)0xd3);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2b] == (unsigned char)0x1f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2c] == (unsigned char)0xd9);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2d] == (unsigned char)0x71);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2e] == (unsigned char)0x3c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x2f] == (unsigned char)0x2b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x30] == (unsigned char)0xa5);
	CHECK((unsigned char)(*pFoundColdNode).name[0x31] == (unsigned char)0x8c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x32] == (unsigned char)0x9c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x33] == (unsigned char)0x04);
	CHECK((unsigned char)(*pFoundColdNode).name[0x34] == (unsigned char)0x11);
	CHECK((unsigned char)(*pFoundColdNode).name[0x35] == (unsigned char)0xbd);
	CHECK((unsigned char)(*pFoundColdNode).name[0x36] == (unsigned char)0x96);
	CHECK((unsigned char)(*pFoundColdNode).name[0x37] == (unsigned char)0xa5);
	CHECK((unsigned char)(*pFoundColdNode).name[0x38] == (unsigned char)0x3d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x39] == (unsigned char)0x3a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3a] == (unsigned char)0x92);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3b] == (unsigned char)0x94);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3c] == (unsigned char)0xb4);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3d] == (unsigned char)0xca);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3e] == (unsigned char)0x2b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x3f] == (unsigned char)0x54);
	CHECK((unsigned char)(*pFoundColdNode).name[0x40] == (unsigned char)0xa5);
	CHECK((unsigned char)(*pFoundColdNode).name[0x41] == (unsigned char)0x7e);
	CHECK((unsigned char)(*pFoundColdNode).name[0x42] == (unsigned char)0x2d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x43] == (unsigned char)0x49);
	CHECK((unsigned char)(*pFoundColdNode).name[0x44] == (unsigned char)0xc9);
	CHECK((unsigned char)(*pFoundColdNode).name[0x45] == (unsigned char)0xb8);
	CHECK((unsigned char)(*pFoundColdNode).name[0x46] == (unsigned char)0x0a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x47] == (unsigned char)0x28);
	CHECK((unsigned char)(*pFoundColdNode).name[0x48] == (unsigned char)0xa2);
	CHECK((unsigned char)(*pFoundColdNode).name[0x49] == (unsigned char)0xca);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4a] == (unsigned char)0x7a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4b] == (unsigned char)0x61);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4c] == (unsigned char)0xd1);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4d] == (unsigned char)0xc3);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4e] == (unsigned char)0x44);
	CHECK((unsigned char)(*pFoundColdNode).name[0x4f] == (unsigned char)0x9d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x50] == (unsigned char)0xa6);
	CHECK((unsigned char)(*pFoundColdNode).name[0x51] == (unsigned char)0x0d);
	CHECK((unsigned char)(*pFoundColdNode).name[0x52] == (unsigned char)0xd6);
	CHECK((unsigned char)(*pFoundColdNode).name[0x53] == (unsigned char)0x40);
	CHECK((unsigned char)(*pFoundColdNode).name[0x54] == (unsigned char)0x34);
	CHECK((unsigned char)(*pFoundColdNode).name[0x55] == (unsigned char)0x81);
	CHECK((unsigned char)(*pFoundColdNode).name[0x56] == (unsigned char)0xad);
	CHECK((unsigned char)(*pFoundColdNode).name[0x57] == (unsigned char)0x81);
	CHECK((unsigned char)(*pFoundColdNode).name[0x58] == (unsigned char)0x05);
	CHECK((unsigned char)(*pFoundColdNode).name[0x59] == (unsigned char)0x1f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5a] == (unsigned char)0x35);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5b] == (unsigned char)0x98);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5c] == (unsigned char)0xba);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5d] == (unsigned char)0xf3);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5e] == (unsigned char)0x25);
	CHECK((unsigned char)(*pFoundColdNode).name[0x5f] == (unsigned char)0x04);
	CHECK((unsigned char)(*pFoundColdNode).name[0x60] == (unsigned char)0xb7);
	CHECK((unsigned char)(*pFoundColdNode).name[0x61] == (unsigned char)0xf9);
	CHECK((unsigned char)(*pFoundColdNode).name[0x62] == (unsigned char)0x75);
	CHECK((unsigned char)(*pFoundColdNode).name[0x63] == (unsigned char)0xe7);
	CHECK((unsigned char)(*pFoundColdNode).name[0x64] == (unsigned char)0x1c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x65] == (unsigned char)0xe7);
	CHECK((unsigned char)(*pFoundColdNode).name[0x66] == (unsigned char)0xfa);
	CHECK((unsigned char)(*pFoundColdNode).name[0x67] == (unsigned char)0x9b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x68] == (unsigned char)0xaf);
	CHECK((unsigned char)(*pFoundColdNode).name[0x69] == (unsigned char)0xc1);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6a] == (unsigned char)0x48);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6b] == (unsigned char)0xc5);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6c] == (unsigned char)0x93);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6d] == (unsigned char)0x25);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6e] == (unsigned char)0xd7);
	CHECK((unsigned char)(*pFoundColdNode).name[0x6f] == (unsigned char)0x3c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x70] == (unsigned char)0xb8);
	CHECK((unsigned char)(*pFoundColdNode).name[0x71] == (unsigned char)0x9b);
	CHECK((unsigned char)(*pFoundColdNode).name[0x72] == (unsigned char)0xa7);
	CHECK((unsigned char)(*pFoundColdNode).name[0x73] == (unsigned char)0x7c);
	CHECK((unsigned char)(*pFoundColdNode).name[0x74] == (unsigned char)0x0f);
	CHECK((unsigned char)(*pFoundColdNode).name[0x75] == (unsigned char)0xf1);
	CHECK((unsigned char)(*pFoundColdNode).name[0x76] == (unsigned char)0x40);
	CHECK((unsigned char)(*pFoundColdNode).name[0x77] == (unsigned char)0xde);
	CHECK((unsigned char)(*pFoundColdNode).name[0x78] == (unsigned char)0xe8);
	CHECK((unsigned char)(*pFoundColdNode).name[0x79] == (unsigned char)0x5a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7a] == (unsigned char)0xdc);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7b] == (unsigned char)0x7a);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7c] == (unsigned char)0x69);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7d] == (unsigned char)0x60);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7e] == (unsigned char)0xa1);
	CHECK((unsigned char)(*pFoundColdNode).name[0x7f] == (unsigned char)0x00);

	CHECK(pFoundHotNode->key == 0x20846906);
	CHECK(pFoundHotNode->pCold == pFoundColdNode);

	HotNode *pR = pFoundHotNode;

	CHECK(pR != nullptr);

	CHECK(pR->key == 0x20846906);
	CHECK(pR->pPrev != nullptr);
	CHECK(pR->pNext == nullptr);
	CHECK(pR->pCold == pFoundColdNode);

	HotNode *pS = pR->pPrev;
	CHECK(pS != nullptr);

	CHECK(pS->key == 0x1d243ecb);
	CHECK(pS->pPrev != nullptr);
	CHECK(pS->pNext == pR);
	CHECK(pS->pCold != nullptr);

	HotNode *pT = pS->pPrev;
	CHECK(pT != nullptr);

	CHECK(pT->key == 0x1d474f01);
	CHECK(pT->pPrev != nullptr);
	CHECK(pT->pNext == pS);
	CHECK(pT->pCold != nullptr);

	CHECK(pS->pPrev == pT);

	pR = nullptr;
	pS = nullptr;
	pT = nullptr;
	
	delete pHotCold;
	pHotCold = nullptr;

	HotColdLink_Test = true;

} TEST_END

TEST_TEARDOWN(Link_HotCold)
{
	delete pHotCold;
}

// ---  End of File ---

