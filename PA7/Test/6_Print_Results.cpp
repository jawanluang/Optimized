//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"
#include "SearchList.h"
#include "Node.h"


extern PerformanceTimer t_List;
extern PerformanceTimer t_Insert;
extern PerformanceTimer t_Merge;
extern PerformanceTimer t_Combo;
extern int CutoffLength;
extern PerformanceTimer t_Create;
extern PerformanceTimer t_Recreate;
extern PerformanceTimer t_Verify;
extern bool VerifyResult;

void PrintResults()
{
	Trace::out2("\n");
	Trace::out2("Creation of original List: %f ms\n", t_List.TimeInSeconds() * 1000.0f);
	Trace::out2("\n");
	Trace::out2("       Insertion Time: %f ms\n", t_Insert.TimeInSeconds() * 1000.0f);
	Trace::out2("           Merge Time: %f ms\n", t_Merge.TimeInSeconds() * 1000.0f);
	Trace::out2("\n");
	Trace::out2("Merge_Vs_Insert Ratio: %f faster\n", t_Insert.TimeInSeconds() / t_Merge.TimeInSeconds());
	Trace::out2("\n");
	Trace::out2("           Combo Time: %f ms   Cutoff length: %d\n", t_Combo.TimeInSeconds() * 1000.0f, CutoffLength);
	Trace::out2("\n");
	Trace::out2(" Combo_Vs_Merge Ratio: %f faster\n", t_Merge.TimeInSeconds() / t_Combo.TimeInSeconds());
	Trace::out2("\n");
	Trace::out2("    Time to create File: %f ms  \n", t_Create.TimeInSeconds() * 1000.0f);
	Trace::out2("  Time to recreate list: %f ms  \n", t_Recreate.TimeInSeconds() * 1000.0f);
	Trace::out2("\n  Verify Time: %f ms  Result: %d\n", t_Verify.TimeInSeconds() * 1000.0f, VerifyResult);

}

// ---  End of File ---
