/********************************************************************
* _ROOT_DICT_MuELoss.h
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************************/
#ifdef __CINT__
#error _ROOT_DICT_MuELoss.h/C is only for compilation. Abort cint.
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
extern void G__cpp_setup_tagtable_ROOT_DICT_MuELoss();
extern void G__cpp_setup_inheritance_ROOT_DICT_MuELoss();
extern void G__cpp_setup_typetable_ROOT_DICT_MuELoss();
extern void G__cpp_setup_memvar_ROOT_DICT_MuELoss();
extern void G__cpp_setup_global_ROOT_DICT_MuELoss();
extern void G__cpp_setup_memfunc_ROOT_DICT_MuELoss();
extern void G__cpp_setup_func_ROOT_DICT_MuELoss();
extern void G__set_cpp_environment_ROOT_DICT_MuELoss();
}


#include "TObject.h"
#include "TMemberInspector.h"
#include "KokoulinPetrukhinModel.h"
#include "MuELossI.h"
#include "PetrukhinShestakovModel.h"
#include "BezrukovBugaevModel.h"
#include "BetheBlochModel.h"
#include <algorithm>
namespace std { }
using namespace std;

#ifndef G__MEMFUNCBODY
#endif

extern G__linked_taginfo G___ROOT_DICT_MuELossLN_basic_ostreamlEcharcOchar_traitslEchargRsPgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_string;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_genie;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLEAlgStatus;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLEAlgCmp;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_TVectorTlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_TVectorTlEdoublegR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_TMatrixTBaselEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_TMatrixTBaselEdoublegR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLAlgId;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLERgType;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_maplEstringcOgeniecLcLRegistryItemImUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOgeniecLcLRegistryItemImUgRsPgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_pairlEstringcOgeniecLcLRegistryItemImUgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_maplEstringcOgeniecLcLRegistryItemImUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOgeniecLcLRegistryItemImUgRsPgRsPgRcLcLiterator;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_vectorlEstringcOallocatorlEstringgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_reverse_iteratorlEvectorlEstringcOallocatorlEstringgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLRegistry;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLAlgorithm;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_maplEstringcOgeniecLcLAlgorithmmUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOgeniecLcLAlgorithmmUgRsPgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_pairlEstringcOgeniecLcLAlgorithmmUgR;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_maplEstringcOgeniecLcLAlgorithmmUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOgeniecLcLAlgorithmmUgRsPgRsPgRcLcLiterator;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLmueloss;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLmuelosscLcLEMuELMaterial;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLmuelosscLcLEMuELProcess;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLmuelosscLcLMuELossI;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLIntegratorI;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLmuelosscLcLKokoulinPetrukhinModel;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLmuelosscLcLPetrukhinShestakovModel;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLmuelosscLcLBezrukovBugaevModel;
extern G__linked_taginfo G___ROOT_DICT_MuELossLN_geniecLcLmuelosscLcLBetheBlochModel;

/* STUB derived class for protected member access */
