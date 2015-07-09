/********************************************************************
* _ROOT_DICT_Numerical.h
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************************/
#ifdef __CINT__
#error _ROOT_DICT_Numerical.h/C is only for compilation. Abort cint.
#endif
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define G__ANSIHEADER
#define G__DICTIONARY
#define G__PRIVATE_GVALUE
#include "G__ci.h"
#include "FastAllocString.h"
extern "C" {
extern void G__cpp_setup_tagtable_ROOT_DICT_Numerical();
extern void G__cpp_setup_inheritance_ROOT_DICT_Numerical();
extern void G__cpp_setup_typetable_ROOT_DICT_Numerical();
extern void G__cpp_setup_memvar_ROOT_DICT_Numerical();
extern void G__cpp_setup_global_ROOT_DICT_Numerical();
extern void G__cpp_setup_memfunc_ROOT_DICT_Numerical();
extern void G__cpp_setup_func_ROOT_DICT_Numerical();
extern void G__set_cpp_environment_ROOT_DICT_Numerical();
}


#include "TObject.h"
#include "TMemberInspector.h"
#include "Spline.h"
#include "GFunc.h"
#include "RandomGen.h"
#include "GBFunc.h"
#include "FunctionMap.h"
#include "UnifGridDimension.h"
#include "Simpson2DFixN.h"
#include "Simpson2D.h"
#include "BLI2D.h"
#include "GridDimension.h"
#include "IntegratorI.h"
#include "GSFunc.h"
#include "GVFunc.h"
#include "Simpson1D.h"
#include "UnifGrid.h"
#include <algorithm>
namespace std { }
using namespace std;

#ifndef G__MEMFUNCBODY
#endif

extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TClass;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TBuffer;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TMemberInspector;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TObject;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_vectorlEunsignedsPintcOallocatorlEunsignedsPintgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_vectorlEdoublecOallocatorlEdoublegRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_basic_ostreamlEcharcOchar_traitslEchargRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_basic_ofstreamlEcharcOchar_traitslEchargRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_string;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TVectorTlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TVectorTlEdoublegR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TGraph;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TSpline3;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TNtupleD;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TTree;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TSQLServer;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_genie;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLSpline;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLGFunc;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_vectorlEstringcOallocatorlEstringgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_reverse_iteratorlEvectorlEstringcOallocatorlEstringgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TRandom3;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLRandomGen;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLGBFunc;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_maplElongcOdoublecOlesslElonggRcOallocatorlEpairlEconstsPlongcOdoublegRsPgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLUnifGrid;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLFunctionMap;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLEGridSpacing;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLGridSpacing;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLGridDimension;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLUnifGridDimension;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLEAlgStatus;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLEAlgCmp;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TMatrixTBaselEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_TMatrixTBaselEdoublegR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLAlgId;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLERgType;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_maplEstringcOgeniecLcLRegistryItemImUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOgeniecLcLRegistryItemImUgRsPgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_pairlEstringcOgeniecLcLRegistryItemImUgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_maplEstringcOgeniecLcLRegistryItemImUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOgeniecLcLRegistryItemImUgRsPgRsPgRcLcLiterator;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLRegistry;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLAlgorithm;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_maplEstringcOgeniecLcLAlgorithmmUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOgeniecLcLAlgorithmmUgRsPgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_pairlEstringcOgeniecLcLAlgorithmmUgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_maplEstringcOgeniecLcLAlgorithmmUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOgeniecLcLAlgorithmmUgRsPgRsPgRcLcLiterator;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLGSFunc;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLIntegratorI;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLSimpson2DFixN;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLSimpson2D;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLBLI2DGrid;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLBLI2DUnifGrid;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLBLI2DNonUnifGrid;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLGVFunc;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_geniecLcLSimpson1D;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_vectorlEgeniecLcLUnifGridDimensionmUcOallocatorlEgeniecLcLUnifGridDimensionmUgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NumericalLN_reverse_iteratorlEvectorlEgeniecLcLUnifGridDimensionmUcOallocatorlEgeniecLcLUnifGridDimensionmUgRsPgRcLcLiteratorgR;

/* STUB derived class for protected member access */
