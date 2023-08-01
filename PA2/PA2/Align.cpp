//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Align.h"

//-------------------------------------------------------------
// PrintME()
//
// Write your alignment printing function here
//-------------------------------------------------------------

Align::Info Align::PrintME(void *pData, int StructSize, char *pString)
{
	// Use Trace::out2(...) to display the data layout and padding

        // NOTE:   out2() NOT out()
        //         it won't be graded without out2()

	// Mimic the KeenanSampleOutput_Debug.txt

        // EXACtLY or the grading system will give a 0
	
	Info info;
	info.NumBytesOfPadding = 0;
	info.NumTotalBytes = StructSize;

	Trace::out2("%s: \n", pString);

	const unsigned char* bytes = (const unsigned char*)pData;
	int size = StructSize;
	int printedBytes = 0;

	while (size > 0)
	{
		if (0 == printedBytes)
		{
			Trace::out2("  0x00: ");
			for (int i = 0; i < 4; i++)
			{
				Trace::out2("%02x ", bytes[i]);
				if (0xAA == bytes[i])
				{
					info.NumBytesOfPadding++;
				}
			}
			printedBytes = printedBytes + 4;
			Trace::out2("\n");
		}
		else
		{
			Trace::out2("  %#04x: ", printedBytes);
			for (int i = printedBytes; i < printedBytes + 4; i++)
			{
				Trace::out2("%02x ", bytes[i]);
				if (0xAA == bytes[i])
				{
					info.NumBytesOfPadding++;
				}
			}
			printedBytes = printedBytes + 4;
			Trace::out2("\n");
		}

		size = size - 4;
	}

	Trace::out2("------------------------\n");
	Trace::out2("size : %d padding : %d\n\n", StructSize, info.NumBytesOfPadding);

	return info;
}

// ---  End of File ---

