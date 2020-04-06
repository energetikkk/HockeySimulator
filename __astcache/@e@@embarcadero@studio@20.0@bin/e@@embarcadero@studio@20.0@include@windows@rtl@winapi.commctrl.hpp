// CodeGear C++Builder
// Copyright (c) 1995, 2018 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Winapi.CommCtrl.pas' rev: 33.00 (Windows)

#ifndef Winapi_CommctrlHPP
#define Winapi_CommctrlHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Messages.hpp>
#include <Winapi.Windows.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

#include <CommCtrl.h>


#if defined(NMSEARCHWEB)

typedef NMSEARCHWEB TNMSEARCHWEB;

#endif


namespace Winapi
{
namespace Commctrl
{
//-- forward type declarations -----------------------------------------------
struct tagNMCUSTOMTEXT;
struct TBMETRICSA;
struct TBMETRICSW;
struct tagNMREBARSPLITTER;
struct tagNMREBARAUTOBREAK;
struct _TTGETTITLE;
struct tagNMTTDISPINFOA;
struct tagNMTTDISPINFOW;
struct tagLITEM;
struct tagLHITTESTINFO;
struct tagNMLINK;
struct tagLVGROUP;
struct tagLVGROUPMETRICS;
struct tagLVINSERTGROUPSORTED;
struct tagLVTILEVIEWINFO;
struct tagLVTILEINFO;
struct tagLVINSERTMARK;
struct tagLVSETINFOTIP;
struct tagLVFOOTERINFO;
struct tagLVFOOTERITEM;
struct tagLVITEMINDEX;
struct tagNMLVLINK;
struct tagNMLVSCROLL;
struct tagNMLVEMPTYMARKUP;
struct tagNMTVSTATEIMAGECHANGING;
struct tagTVGETITEMPARTRECTINFO;
struct tagNMTVITEMCHANGE;
struct BUTTON_IMAGELIST;
struct tagNMBCHOTITEM;
struct tagBUTTON_SPLITINFO;
struct tagNMBCDROPDOWN;
struct _tagEDITBALLOONTIP;
struct TASKDIALOG_BUTTON;
struct TASKDIALOGCONFIG;
struct TWMNotifyHC;
struct TWMNotifyTV;
struct TWMNotifyTRB;
struct TWMNotifyUD;
struct TWMNotifyLV;
struct TWMNotifyTLB;
struct TWMNotifyMC;
struct TWMNotifyDT;
struct TWMNotifyPS;
struct TTCMAdjustRect;
//-- type declarations -------------------------------------------------------
typedef void * HPropSheetPage;

typedef _PROPSHEETPAGEA *PPropSheetPageA;

typedef _PROPSHEETPAGEW *PPropSheetPageW;

typedef PPropSheetPageW PPropSheetPage;

typedef LPFNPSPCALLBACKA TFNPSPCallbackA;

typedef LPFNPSPCALLBACKW TFNPSPCallbackW;

typedef LPFNPSPCALLBACKW TFNPSPCallback;

typedef _PROPSHEETPAGEA TPropSheetPageA;

typedef _PROPSHEETPAGEW TPropSheetPageW;

typedef _PROPSHEETPAGEW TPropSheetPage;

typedef PFNPROPSHEETCALLBACK TFNPropSheetCallback;

typedef _PROPSHEETHEADERA *PPropSheetHeaderA;

typedef _PROPSHEETHEADERW *PPropSheetHeaderW;

typedef PPropSheetHeaderW PPropSheetHeader;

typedef _PROPSHEETHEADERA TPropSheetHeaderA;

typedef _PROPSHEETHEADERW TPropSheetHeaderW;

typedef _PROPSHEETHEADERW TPropSheetHeader;

typedef LPFNADDPROPSHEETPAGE TFNAddPropSheetPage;

typedef LPFNADDPROPSHEETPAGES TFNAddPropSheetPages;

typedef tagINITCOMMONCONTROLSEX *PInitCommonControlsEx;

typedef tagINITCOMMONCONTROLSEX TInitCommonControlsEx;

typedef tagCOLORSCHEME *PColorScheme;

typedef tagCOLORSCHEME TColorScheme;

typedef tagNMMOUSE *PNMMouse;

typedef tagNMMOUSE TNMMouse;

typedef tagNMMOUSE *PNMClick;

typedef tagNMMOUSE TNMClick;

typedef tagNMOBJECTNOTIFY *PNMObjectNotify;

typedef tagNMOBJECTNOTIFY TNMObjectNotify;

typedef tagNMKEY *PNMKey;

typedef tagNMKEY TNMKey;

typedef tagNMCHAR *PNMChar;

typedef tagNMCHAR TNMChar;

struct DECLSPEC_DRECORD tagNMCUSTOMTEXT
{
public:
	tagNMHDR hdr;
	HDC hDC;
	System::WideChar *lpString;
	int nCount;
	System::Types::TRect *lpRect;
	unsigned uFormat;
	System::LongBool fLink;
};


typedef tagNMCUSTOMTEXT *PNMCustomText;

typedef tagNMCUSTOMTEXT TNMCustomText;

typedef tagNMCUSTOMDRAWINFO *PNMCustomDraw;

typedef tagNMCUSTOMDRAWINFO TNMCustomDraw;

typedef tagNMTTCUSTOMDRAW *PNMTTCustomDraw;

typedef tagNMTTCUSTOMDRAW TNMTTCustomDraw;

typedef tagNMCUSTOMSPLITRECTINFO *PNMCustomSplitRectInfo;

typedef tagNMCUSTOMSPLITRECTINFO TNMCustomSplitRectInfo;

typedef _IMAGELISTDRAWPARAMS *PImageListDrawParams;

typedef _IMAGELISTDRAWPARAMS TImageListDrawParams;

typedef _IMAGEINFO *PImageInfo;

typedef _IMAGEINFO TImageInfo;

typedef _HD_TEXTFILTERA *PHDTextFilterA;

typedef _HD_TEXTFILTERW *PHDTextFilterW;

typedef PHDTextFilterW PHDTextFilter;

typedef _HD_TEXTFILTERA THDTextFilterA;

typedef _HD_TEXTFILTERW THDTextFilterW;

typedef _HD_TEXTFILTERW THDTextFilter;

typedef _HD_ITEMA *PHDItemA;

typedef _HD_ITEMW *PHDItemW;

typedef PHDItemW PHDItem;

typedef _HD_ITEMA THDItemA;

typedef _HD_ITEMW THDItemW;

typedef _HD_ITEMW THDItem;

typedef _HD_LAYOUT *PHDLayout;

typedef _HD_LAYOUT THDLayout;

typedef _HD_HITTESTINFO *PHDHitTestInfo;

typedef _HD_HITTESTINFO THDHitTestInfo;

typedef tagNMHEADERA *PHDNotifyA;

typedef tagNMHEADERW *PHDNotifyW;

typedef PHDNotifyW PHDNotify;

typedef tagNMHEADERA THDNotifyA;

typedef tagNMHEADERW THDNotifyW;

typedef tagNMHEADERW THDNotify;

typedef tagNMHDDISPINFOA *PNMHDispInfoA;

typedef tagNMHDDISPINFOW *PNMHDispInfoW;

typedef PNMHDispInfoW PNMHDispInfo;

typedef tagNMHDDISPINFOA TNMHDispInfoA;

typedef tagNMHDDISPINFOW TNMHDispInfoW;

typedef tagNMHDDISPINFOW TNMHDispInfo;

typedef tagNMHDFILTERBTNCLICK *PNMHDFilterBtnClick;

typedef tagNMHDFILTERBTNCLICK TNMHDFilterBtnClick;

typedef _TBBUTTON *PTBButton;

typedef _TBBUTTON TTBButton;

typedef _COLORMAP *PColorMap;

typedef _COLORMAP TColorMap;

typedef _NMTBCUSTOMDRAW *PNMTBCustomDraw;

typedef _NMTBCUSTOMDRAW TNMTBCustomDraw;

typedef tagTBADDBITMAP *PTBAddBitmap;

typedef tagTBADDBITMAP TTBAddBitmap;

typedef tagTBSAVEPARAMSA *PTBSaveParamsA;

typedef tagTBSAVEPARAMSW *PTBSaveParamsW;

typedef PTBSaveParamsW PTBSaveParams;

typedef tagTBSAVEPARAMSA TTBSaveParamsA;

typedef tagTBSAVEPARAMSW TTBSaveParamsW;

typedef tagTBSAVEPARAMSW TTBSaveParams;

typedef TBINSERTMARK *PTBInsertMark;

typedef TBINSERTMARK TTBInsertMark;

typedef TBREPLACEBITMAP *PTBReplaceBitmap;

typedef TBREPLACEBITMAP TTBReplaceBitmap;

typedef TBBUTTONINFOA *PTBButtonInfoA;

typedef TBBUTTONINFOW *PTBButtonInfoW;

typedef PTBButtonInfoW PTBButtonInfo;

typedef TBBUTTONINFOA TTBButtonInfoA;

typedef TBBUTTONINFOW TTBButtonInfoW;

typedef TBBUTTONINFOW TTBButtonInfo;

struct DECLSPEC_DRECORD TBMETRICSA
{
public:
	unsigned cbSize;
	unsigned dwMask;
	int cxPad;
	int cyPad;
	int cxBarPad;
	int cyBarPad;
	int cxButtonSpacing;
	int cyButtonSpacing;
};


struct DECLSPEC_DRECORD TBMETRICSW
{
public:
	unsigned cbSize;
	unsigned dwMask;
	int cxPad;
	int cyPad;
	int cxBarPad;
	int cyBarPad;
	int cxButtonSpacing;
	int cyButtonSpacing;
};


typedef TBMETRICSA *PTBMetricsA;

typedef TBMETRICSW *PTBMetricsW;

typedef PTBMetricsW PTBMetrics;

typedef TBMETRICSA TTBMetricsA;

typedef TBMETRICSW TTBMetricsW;

typedef TBMETRICSW TTBMetrics;

typedef tagNMTBHOTITEM *PNMTBHotItem;

typedef tagNMTBHOTITEM TNMTBHotItem;

typedef tagNMTBSAVE *PNMTBSave;

typedef tagNMTBSAVE TNMTBSave;

typedef tagNMTBRESTORE *PNMTBRestore;

typedef tagNMTBRESTORE TNMTBRestore;

typedef tagNMTBGETINFOTIPA *PNMTBGetInfoTipA;

typedef tagNMTBGETINFOTIPW *PNMTBGetInfoTipW;

typedef PNMTBGetInfoTipW PNMTBGetInfoTip;

typedef tagNMTBGETINFOTIPA TNMTBGetInfoTipA;

typedef tagNMTBGETINFOTIPW TNMTBGetInfoTipW;

typedef tagNMTBGETINFOTIPW TNMTBGetInfoTip;

typedef NMTBDISPINFOA *PNMTBDispInfoA;

typedef NMTBDISPINFOW *PNMTBDispInfoW;

typedef PNMTBDispInfoW PNMTBDispInfo;

typedef NMTBDISPINFOA TNMTBDispInfoA;

typedef NMTBDISPINFOW TNMTBDispInfoW;

typedef NMTBDISPINFOW TNMTBDispInfo;

typedef tagNMTOOLBARA *PNMToolBarA;

typedef tagNMTOOLBARW *PNMToolBarW;

typedef PNMToolBarW PNMToolBar;

typedef tagNMTOOLBARA TNMToolBarA;

typedef tagNMTOOLBARW TNMToolBarW;

typedef tagNMTOOLBARW TNMToolBar;

typedef tagREBARINFO *PReBarInfo;

typedef tagREBARINFO TReBarInfo;

typedef tagREBARBANDINFOA *PReBarBandInfoA;

typedef tagREBARBANDINFOW *PReBarBandInfoW;

typedef PReBarBandInfoW PReBarBandInfo;

typedef tagREBARBANDINFOA TReBarBandInfoA;

typedef tagREBARBANDINFOW TReBarBandInfoW;

typedef tagREBARBANDINFOW TReBarBandInfo;

typedef tagNMREBARCHILDSIZE *PNMReBarChildSize;

typedef tagNMREBARCHILDSIZE TNMReBarChildSize;

typedef tagNMREBAR *PNMReBar;

typedef tagNMREBAR TNMReBar;

typedef tagNMRBAUTOSIZE *PNMRBAutoSize;

typedef tagNMRBAUTOSIZE TNMRBAutoSize;

typedef tagNMREBARCHEVRON *PNMReBarChevron;

typedef tagNMREBARCHEVRON TNMReBarChevron;

struct DECLSPEC_DRECORD tagNMREBARSPLITTER
{
public:
	tagNMHDR hdr;
	System::Types::TRect rcSizing;
};


typedef tagNMREBARSPLITTER *PNMReBarSplitter;

typedef tagNMREBARSPLITTER TNMReBarSplitter;

struct DECLSPEC_DRECORD tagNMREBARAUTOBREAK
{
public:
	tagNMHDR hdr;
	unsigned uBand;
	unsigned wID;
	NativeInt lParam;
	unsigned uMsg;
	unsigned fStyleCurrent;
	System::LongBool fAutoBreak;
};


typedef tagNMREBARAUTOBREAK *PNMReBarAutoBreak;

typedef tagNMREBARAUTOBREAK TNMReBarAutoBreak;

typedef _RB_HITTESTINFO *PRBHitTestInfo;

typedef _RB_HITTESTINFO TRBHitTestInfo;

typedef tagTOOLINFOA *PToolInfoA;

typedef tagTOOLINFOW *PToolInfoW;

typedef PToolInfoW PToolInfo;

typedef tagTOOLINFOA TToolInfoA;

typedef tagTOOLINFOW TToolInfoW;

typedef tagTOOLINFOW TToolInfo;

struct DECLSPEC_DRECORD _TTGETTITLE
{
public:
	unsigned dwSize;
	unsigned uTitleBitmap;
	unsigned cch;
	System::WideChar *pszTitle;
};


typedef _TTGETTITLE *PTTGetTitle;

typedef _TTGETTITLE TTTGetTitle;

typedef _TT_HITTESTINFOA *PTTHitTestInfoA;

typedef _TT_HITTESTINFOW *PTTHitTestInfoW;

typedef PTTHitTestInfoW PTTHitTestInfo;

typedef _TT_HITTESTINFOA TTTHitTestInfoA;

typedef _TT_HITTESTINFOW TTTHitTestInfoW;

typedef _TT_HITTESTINFOW TTTHitTestInfo;

struct DECLSPEC_DRECORD tagNMTTDISPINFOA
{
public:
	tagNMHDR hdr;
	char *lpszText;
	System::StaticArray<char, 80> szText;
	NativeUInt hinst;
	unsigned uFlags;
	NativeInt lParam;
};


struct DECLSPEC_DRECORD tagNMTTDISPINFOW
{
public:
	tagNMHDR hdr;
	System::WideChar *lpszText;
	System::StaticArray<System::WideChar, 80> szText;
	NativeUInt hinst;
	unsigned uFlags;
	NativeInt lParam;
};


typedef tagNMTTDISPINFOW tagNMTTDISPINFO;

typedef tagNMTTDISPINFOA *PNMTTDispInfoA;

typedef tagNMTTDISPINFOW *PNMTTDispInfoW;

typedef PNMTTDispInfoW PNMTTDispInfo;

typedef tagNMTTDISPINFOA TNMTTDispInfoA;

typedef tagNMTTDISPINFOW TNMTTDispInfoW;

typedef tagNMTTDISPINFOW TNMTTDispInfo;

typedef tagNMTTDISPINFOA TToolTipTextA;

typedef tagNMTTDISPINFOW TToolTipTextW;

typedef tagNMTTDISPINFOW TToolTipText;

typedef tagNMTTDISPINFOA *PToolTipTextA;

typedef tagNMTTDISPINFOW *PToolTipTextW;

typedef PToolTipTextW PToolTipText;

typedef tagTRBTHUMBPOSCHANGING TNMTRBThumbPosChanging;

typedef tagDRAGLISTINFO *PDragListInfo;

typedef tagDRAGLISTINFO TDragListInfo;

typedef _UDACCEL *PUDAccel;

typedef _UDACCEL TUDAccel;

typedef _NM_UPDOWN *PNMUpDown;

typedef _NM_UPDOWN TNMUpDown;

typedef PBRANGE *PPBRange;

typedef PBRANGE TPBRange;

struct DECLSPEC_DRECORD tagLITEM
{
public:
	unsigned mask;
	int iLink;
	unsigned state;
	unsigned stateMask;
	System::StaticArray<System::WideChar, 48> szID;
	System::StaticArray<System::WideChar, 2084> szUrl;
};


typedef tagLITEM *PLItem;

typedef tagLITEM TLItem;

struct DECLSPEC_DRECORD tagLHITTESTINFO
{
public:
	System::Types::TPoint pt;
	tagLITEM item;
};


typedef tagLHITTESTINFO *PLHitTestInfo;

typedef tagLHITTESTINFO TLHitTestInfo;

struct DECLSPEC_DRECORD tagNMLINK
{
public:
	tagNMHDR hdr;
	tagLITEM item;
};


typedef tagNMLINK *PNMLink;

typedef tagNMLINK TNMLink;

typedef tagLVITEMA *PLVItemA;

typedef tagLVITEMW *PLVItemW;

typedef PLVItemW PLVItem;

typedef tagLVITEMA TLVItemA;

typedef tagLVITEMW TLVItemW;

typedef tagLVITEMW TLVItem;

typedef tagLVFINDINFOA *PLVFindInfoA;

typedef tagLVFINDINFOW *PLVFindInfoW;

typedef PLVFindInfoW PLVFindInfo;

typedef tagLVFINDINFOA TLVFindInfoA;

typedef tagLVFINDINFOW TLVFindInfoW;

typedef tagLVFINDINFOW TLVFindInfo;

typedef tagLVHITTESTINFO *PLVHitTestInfo;

typedef tagLVHITTESTINFO TLVHitTestInfo;

typedef tagLVCOLUMNA *PLVColumnA;

typedef tagLVCOLUMNW *PLVColumnW;

typedef PLVColumnW PLVColumn;

typedef tagLVCOLUMNA TLVColumnA;

typedef tagLVCOLUMNW TLVColumnW;

typedef tagLVCOLUMNW TLVColumn;

typedef PFNLVCOMPARE TLVCompare;

typedef tagLVBKIMAGEA *PLVBKImageA;

typedef tagLVBKIMAGEW *PLVBKImageW;

typedef PLVBKImageW PLVBKImage;

typedef tagLVBKIMAGEA TLVBKImageA;

typedef tagLVBKIMAGEW TLVBKImageW;

typedef tagLVBKIMAGEW TLVBKImage;

struct DECLSPEC_DRECORD tagLVGROUP
{
public:
	unsigned cbSize;
	unsigned mask;
	System::WideChar *pszHeader;
	int cchHeader;
	System::WideChar *pszFooter;
	int cchFooter;
	int iGroupId;
	unsigned stateMask;
	unsigned state;
	unsigned uAlign;
	System::WideChar *pszSubtitle;
	unsigned cchSubtitle;
	System::WideChar *pszTask;
	unsigned cchTask;
	System::WideChar *pszDescriptionTop;
	unsigned cchDescriptionTop;
	System::WideChar *pszDescriptionBottom;
	unsigned cchDescriptionBottom;
	int iTitleImage;
	int iExtendedImage;
	int iFirstItem;
	unsigned cItems;
	System::WideChar *pszSubsetTitle;
	unsigned cchSubsetTitle;
};


typedef tagLVGROUP *PLVGroup;

typedef tagLVGROUP TLVGroup;

struct DECLSPEC_DRECORD tagLVGROUPMETRICS
{
public:
	unsigned cbSize;
	unsigned mask;
	unsigned Left;
	unsigned Top;
	unsigned Right;
	unsigned Bottom;
	unsigned crLeft;
	unsigned crTop;
	unsigned crRight;
	unsigned crBottom;
	unsigned crHeader;
	unsigned crFooter;
};


typedef tagLVGROUPMETRICS *PLVGroupMetrics;

typedef tagLVGROUPMETRICS TLVGroupMetrics;

typedef int __stdcall (*PFNLVGROUPCOMPARE)(int Group1_ID, int Group2_ID, void * pvData);

typedef PFNLVGROUPCOMPARE TFNLVGroupCompare;

struct DECLSPEC_DRECORD tagLVINSERTGROUPSORTED
{
public:
	PFNLVGROUPCOMPARE pfnGroupCompare;
	void *pvData;
	tagLVGROUP lvGroup;
};


typedef tagLVINSERTGROUPSORTED *PLVInsertGroupSorted;

typedef tagLVINSERTGROUPSORTED TLVInsertGroupSorted;

struct DECLSPEC_DRECORD tagLVTILEVIEWINFO
{
public:
	unsigned cbSize;
	unsigned dwMask;
	unsigned dwFlags;
	System::Types::TSize sizeTile;
	int cLines;
	System::Types::TRect rcLabelMargin;
};


typedef tagLVTILEVIEWINFO *PLVTileViewInfo;

typedef tagLVTILEVIEWINFO TLVTileViewInfo;

struct DECLSPEC_DRECORD tagLVTILEINFO
{
public:
	unsigned cbSize;
	int iItem;
	unsigned cColumns;
	unsigned *puColumns;
	int *piColFmt;
};


typedef tagLVTILEINFO *PLVTileInfo;

typedef tagLVTILEINFO TLVTileInfo;

struct DECLSPEC_DRECORD tagLVINSERTMARK
{
public:
	unsigned cbSize;
	unsigned dwFlags;
	int iItem;
	unsigned dwReserved;
};


typedef tagLVINSERTMARK *PLVInsertMark;

typedef tagLVINSERTMARK TLVInsertMark;

struct DECLSPEC_DRECORD tagLVSETINFOTIP
{
public:
	unsigned cbSize;
	unsigned dwFlags;
	System::WideChar *pszText;
	int iItem;
	int iSubItem;
};


typedef tagLVSETINFOTIP *PLVSetInfoTip;

typedef tagLVSETINFOTIP TLVSetInfoTip;

struct DECLSPEC_DRECORD tagLVFOOTERINFO
{
public:
	unsigned mask;
	System::WideChar *pszText;
	int cchTextMax;
	unsigned cItems;
};


typedef tagLVFOOTERINFO *PLVFooterInfo;

typedef tagLVFOOTERINFO TLVFooterInfo;

struct DECLSPEC_DRECORD tagLVFOOTERITEM
{
public:
	unsigned mask;
	int iItem;
	System::WideChar *pszText;
	int cchTextMax;
	unsigned state;
	unsigned stateMask;
};


typedef tagLVFOOTERITEM *PLVFooterItem;

typedef tagLVFOOTERITEM TLVFooterItem;

struct DECLSPEC_DRECORD tagLVITEMINDEX
{
public:
	int iItem;
	int iGroup;
};


typedef tagLVITEMINDEX *PLVItemIndex;

typedef tagLVITEMINDEX TLVItemIndex;

typedef tagNMLISTVIEW *PNMListView;

typedef tagNMLISTVIEW TNMListView;

typedef tagNMITEMACTIVATE *PNMItemActivate;

typedef tagNMITEMACTIVATE TNMItemActivate;

typedef tagNMLVCUSTOMDRAW *PNMLVCustomDraw;

typedef tagNMLVCUSTOMDRAW TNMLVCustomDraw;

typedef tagNMLVCACHEHINT *PNMLVCacheHint;

typedef tagNMLVCACHEHINT TNMLVCacheHint;

typedef tagNMLVCACHEHINT *PNMCacheHint;

typedef tagNMLVCACHEHINT TNMCacheHint;

typedef tagNMLVFINDITEMA *PNMLVFinditemA;

typedef tagNMLVFINDITEMW *PNMLVFinditemW;

typedef PNMLVFinditemW PNMLVFinditem;

typedef tagNMLVFINDITEMA TNMLVFinditemA;

typedef tagNMLVFINDITEMW TNMLVFinditemW;

typedef tagNMLVFINDITEMW TNMLVFinditem;

typedef tagNMLVFINDITEMA *PNMFinditemA;

typedef tagNMLVFINDITEMW *PNMFinditemW;

typedef PNMFinditemW PNMFinditem;

typedef tagNMLVFINDITEMA TNMFinditemA;

typedef tagNMLVFINDITEMW TNMFinditemW;

typedef tagNMLVFINDITEMW TNMFinditem;

typedef tagNMLVODSTATECHANGE *PNMLVODStateChange;

typedef tagNMLVODSTATECHANGE TNMLVODStateChange;

typedef tagLVDISPINFOW *PLVDispInfoA;

typedef tagLVDISPINFOW *PLVDispInfoW;

typedef PLVDispInfoW PLVDispInfo;

typedef tagLVDISPINFOW TLVDispInfoW;

typedef tagLVDISPINFOW TLVDispInfoA;

typedef tagLVDISPINFOW TLVDispInfo;

typedef tagLVKEYDOWN *PLVKeyDown;

typedef tagLVKEYDOWN TLVKeyDown;

struct DECLSPEC_DRECORD tagNMLVLINK
{
public:
	tagNMHDR hdr;
	tagLITEM link;
	int iItem;
	int iSubItem;
};


typedef tagNMLVLINK *PNMLVLink;

typedef tagNMLVLINK TNMLVLink;

typedef tagNMLVGETINFOTIPA *PNMLVGetInfoTipA;

typedef tagNMLVGETINFOTIPW *PNMLVGetInfoTipW;

typedef PNMLVGetInfoTipW PNMLVGetInfoTip;

typedef tagNMLVGETINFOTIPA TNMLVGetInfoTipA;

typedef tagNMLVGETINFOTIPW TNMLVGetInfoTipW;

typedef tagNMLVGETINFOTIPW TNMLVGetInfoTip;

struct DECLSPEC_DRECORD tagNMLVSCROLL
{
public:
	tagNMHDR hdr;
	int dx;
	int dy;
};


typedef tagNMLVSCROLL *PNMLVScroll;

typedef tagNMLVSCROLL TNMLVScroll;

struct DECLSPEC_DRECORD tagNMLVEMPTYMARKUP
{
public:
	tagNMHDR hdr;
	unsigned dwFlags;
	System::StaticArray<System::WideChar, 2084> szMarkup;
};


typedef tagNMLVEMPTYMARKUP *PNMLVEmptyMarkup;

typedef tagNMLVEMPTYMARKUP TNMLVEmptyMarkup;

struct DECLSPEC_DRECORD tagNMTVSTATEIMAGECHANGING
{
public:
	tagNMHDR hdr;
	_TREEITEM *hti;
	int iOldStateImageIndex;
	int iNewStateImageIndex;
};


typedef tagNMTVSTATEIMAGECHANGING *PNMTVStateImageChanging;

typedef tagNMTVSTATEIMAGECHANGING TNMTVStateImageChanging;

typedef tagTVITEMA *PTVItemA;

typedef tagTVITEMW *PTVItemW;

typedef PTVItemW PTVItem;

typedef tagTVITEMA TTVItemA;

typedef tagTVITEMW TTVItemW;

typedef tagTVITEMW TTVItem;

typedef tagTVITEMEXA *PTVItemExA;

typedef tagTVITEMEXW *PTVItemExW;

typedef PTVItemExW PTVItemEx;

typedef tagTVITEMEXA TTVItemExA;

typedef tagTVITEMEXW TTVItemExW;

typedef tagTVITEMEXW TTVItemEx;

typedef tagTVINSERTSTRUCTA *PTVInsertStructA;

typedef tagTVINSERTSTRUCTW *PTVInsertStructW;

typedef PTVInsertStructW PTVInsertStruct;

typedef tagTVINSERTSTRUCTA TTVInsertStructA;

typedef tagTVINSERTSTRUCTW TTVInsertStructW;

typedef tagTVINSERTSTRUCTW TTVInsertStruct;

typedef tagTVHITTESTINFO *PTVHitTestInfo;

typedef tagTVHITTESTINFO TTVHitTestInfo;

typedef PFNTVCOMPARE TTVCompare;

typedef tagTVSORTCB TTVSortCB;

enum DECLSPEC_DENUM TVITEMPART : unsigned int { TVGIPR_BUTTON = 0x1 };

typedef TVITEMPART TTVItemPart;

struct DECLSPEC_DRECORD tagTVGETITEMPARTRECTINFO
{
public:
	_TREEITEM *hti;
	System::Types::TRect *prc;
	TVITEMPART partID;
};


typedef tagTVGETITEMPARTRECTINFO *PTVGetItemPartRectInfo;

typedef tagTVGETITEMPARTRECTINFO TTVGetItemPartRectInfo;

typedef tagNMTREEVIEWA *PNMTreeViewA;

typedef tagNMTREEVIEWW *PNMTreeViewW;

typedef PNMTreeViewW PNMTreeView;

typedef tagNMTREEVIEWA TNMTreeViewA;

typedef tagNMTREEVIEWW TNMTreeViewW;

typedef tagNMTREEVIEWW TNMTreeView;

typedef tagTVDISPINFOA *PTVDispInfoA;

typedef tagTVDISPINFOW *PTVDispInfoW;

typedef PTVDispInfoW PTVDispInfo;

typedef tagTVDISPINFOA TTVDispInfoA;

typedef tagTVDISPINFOW TTVDispInfoW;

typedef tagTVDISPINFOW TTVDispInfo;

typedef tagTVDISPINFOEXA *PNMTVDispInfoExA;

typedef tagTVDISPINFOEXW *PNMTVDispInfoExW;

typedef PNMTVDispInfoExW PNMTVDispInfoEx;

typedef tagTVDISPINFOEXW tagTVDISPINFOEX;

typedef tagTVDISPINFOEXA tagNMTVDISPINFOEXA _DEPRECATED_ATTRIBUTE1("Use tagTVDISPINFOEXA") ;

typedef tagTVDISPINFOEXW tagNMTVDISPINFOEXW _DEPRECATED_ATTRIBUTE1("Use tagTVDISPINFOEXW") ;

typedef tagTVDISPINFOEXW tagNMTVDISPINFOEX _DEPRECATED_ATTRIBUTE1("Use tagTVDISPINFOEX") ;

typedef tagTVDISPINFOEXA TNMTVDispInfoExA;

typedef tagTVDISPINFOEXW TNMTVDispInfoExW;

typedef tagTVDISPINFOEXW TNMTVDispInfoEx;

typedef tagTVKEYDOWN TTVKeyDown;

typedef tagNMTVCUSTOMDRAW *PNMTVCustomDraw;

typedef tagNMTVCUSTOMDRAW TNMTVCustomDraw;

typedef tagNMTVGETINFOTIPA *PNMTVGetInfoTipA;

typedef tagNMTVGETINFOTIPW *PNMTVGetInfoTipW;

typedef PNMTVGetInfoTipW PNMTVGetInfoTip;

typedef tagNMTVGETINFOTIPA TNMTVGetInfoTipA;

typedef tagNMTVGETINFOTIPW TNMTVGetInfoTipW;

typedef tagNMTVGETINFOTIPW TNMTVGetInfoTip;

struct DECLSPEC_DRECORD tagNMTVITEMCHANGE
{
public:
	tagNMHDR hdr;
	unsigned uChanged;
	_TREEITEM *hItem;
	unsigned uStateNew;
	unsigned uStateOld;
	NativeInt lParam;
};


typedef tagNMTVITEMCHANGE *PNMTVItemChange;

typedef tagNMTVITEMCHANGE TNMTVItemChange;

typedef tagNMTVASYNCDRAW *PNMTVAsyncDraw;

typedef tagNMTVASYNCDRAW TNMTVAsyncDraw;

typedef tagCOMBOBOXEXITEMA *PComboBoxExItemA;

typedef tagCOMBOBOXEXITEMW *PComboBoxExItemW;

typedef PComboBoxExItemW PComboBoxExItem;

typedef tagCOMBOBOXEXITEMA TComboBoxExItemA;

typedef tagCOMBOBOXEXITEMW TComboBoxExItemW;

typedef tagCOMBOBOXEXITEMW TComboBoxExItem;

typedef NMCOMBOBOXEXA *PNMComboBoxExA;

typedef NMCOMBOBOXEXW *PNMComboBoxExW;

typedef PNMComboBoxExW PNMComboBoxEx;

typedef NMCOMBOBOXEXA TNMComboBoxExA;

typedef NMCOMBOBOXEXW TNMComboBoxExW;

typedef NMCOMBOBOXEXW TNMComboBoxEx;

typedef NMCBEDRAGBEGINA *PNMCBEDragBeginA;

typedef NMCBEDRAGBEGINW *PNMCBEDragBeginW;

typedef PNMCBEDragBeginW PNMCBEDragBegin;

typedef NMCBEDRAGBEGINA TNMCBEDragBeginA;

typedef NMCBEDRAGBEGINW TNMCBEDragBeginW;

typedef NMCBEDRAGBEGINW TNMCBEDragBegin;

typedef NMCBEENDEDITA *PNMCBEEndEditA;

typedef NMCBEENDEDITW *PNMCBEEndEditW;

typedef PNMCBEEndEditW PNMCBEEndEdit;

typedef NMCBEENDEDITA TNMCBEEndEditA;

typedef NMCBEENDEDITW TNMCBEEndEditW;

typedef NMCBEENDEDITW TNMCBEEndEdit;

typedef tagTCITEMHEADERA *PTCItemHeaderA;

typedef tagTCITEMHEADERW *PTCItemHeaderW;

typedef PTCItemHeaderW PTCItemHeader;

typedef tagTCITEMHEADERA TTCItemHeaderA;

typedef tagTCITEMHEADERW TTCItemHeaderW;

typedef tagTCITEMHEADERW TTCItemHeader;

typedef tagTCITEMA *PTCItemA;

typedef tagTCITEMW *PTCItemW;

typedef PTCItemW PTCItem;

typedef tagTCITEMA TTCItemA;

typedef tagTCITEMW TTCItemW;

typedef tagTCITEMW TTCItem;

typedef tagTCHITTESTINFO *PTCHitTestInfo;

typedef tagTCHITTESTINFO TTCHitTestInfo;

typedef tagTCKEYDOWN TTCKeyDown;

typedef unsigned *PMonthDayState;

typedef unsigned TMonthDayState;

typedef MCHITTESTINFO *PMCHitTestInfo;

typedef MCHITTESTINFO TMCHitTestInfo;

typedef tagNMSELCHANGE *PNMSelChange;

typedef tagNMSELCHANGE TNMSelChange;

typedef tagNMDAYSTATE *PNMDayState;

typedef tagNMDAYSTATE TNMDayState;

typedef tagNMSELCHANGE *PNMSelect;

typedef tagNMSELCHANGE TNMSelect;

typedef System::StaticArray<_SYSTEMTIME, 2> TSystemTimeRangeArray;

typedef tagMCGRIDINFO *PMCGridInfo;

typedef tagMCGRIDINFO TMCGridInfo;

typedef tagNMDATETIMECHANGE *PNMDateTimeChange;

typedef tagNMDATETIMECHANGE TNMDateTimeChange;

typedef tagNMDATETIMESTRINGA *PNMDateTimeStringA;

typedef tagNMDATETIMESTRINGW *PNMDateTimeStringW;

typedef PNMDateTimeStringW PNMDateTimeString;

typedef tagNMDATETIMESTRINGA TNMDateTimeStringA;

typedef tagNMDATETIMESTRINGW TNMDateTimeStringW;

typedef tagNMDATETIMESTRINGW TNMDateTimeString;

typedef tagNMDATETIMEWMKEYDOWNA *PNMDateTimeWMKeyDownA;

typedef tagNMDATETIMEWMKEYDOWNW *PNMDateTimeWMKeyDownW;

typedef PNMDateTimeWMKeyDownW PNMDateTimeWMKeyDown;

typedef tagNMDATETIMEWMKEYDOWNA TNMDateTimeWMKeyDownA;

typedef tagNMDATETIMEWMKEYDOWNW TNMDateTimeWMKeyDownW;

typedef tagNMDATETIMEWMKEYDOWNW TNMDateTimeWMKeyDown;

typedef tagNMDATETIMEFORMATA *PNMDateTimeFormatA;

typedef tagNMDATETIMEFORMATW *PNMDateTimeFormatW;

typedef PNMDateTimeFormatW PNMDateTimeFormat;

typedef tagNMDATETIMEFORMATA TNMDateTimeFormatA;

typedef tagNMDATETIMEFORMATW TNMDateTimeFormatW;

typedef tagNMDATETIMEFORMATW TNMDateTimeFormat;

typedef tagNMDATETIMEFORMATQUERYA *PNMDateTimeFormatQueryA;

typedef tagNMDATETIMEFORMATQUERYW *PNMDateTimeFormatQueryW;

typedef PNMDateTimeFormatQueryW PNMDateTimeFormatQuery;

typedef tagNMDATETIMEFORMATQUERYA TNMDateTimeFormatQueryA;

typedef tagNMDATETIMEFORMATQUERYW TNMDateTimeFormatQueryW;

typedef tagNMDATETIMEFORMATQUERYW TNMDateTimeFormatQuery;

typedef tagDATETIMEPICKERINFO *PDateTimePickerInfo;

typedef tagDATETIMEPICKERINFO TDateTimePickerInfo;

typedef tagNMIPADDRESS *PNMIPAddress;

typedef tagNMIPADDRESS TNMIPAddress;

typedef NMPGSCROLL *PNMPGScroll;

typedef NMPGSCROLL TNMPGScroll;

typedef NMPGCALCSIZE *PNMPGCalcSize;

typedef NMPGCALCSIZE TNMPGCalcSize;

struct DECLSPEC_DRECORD BUTTON_IMAGELIST
{
public:
	NativeUInt himl;
	System::Types::TRect margin;
	unsigned uAlign;
};


typedef BUTTON_IMAGELIST *PButtonImageList;

typedef BUTTON_IMAGELIST TButtonImageList;

struct DECLSPEC_DRECORD tagNMBCHOTITEM
{
public:
	tagNMHDR hdr;
	unsigned dwFlags;
};


typedef tagNMBCHOTITEM *PNMBCHotItem;

typedef tagNMBCHOTITEM TNMBCHotItem;

struct DECLSPEC_DRECORD tagBUTTON_SPLITINFO
{
public:
	unsigned mask;
	NativeUInt himlGlyph;
	unsigned uSplitStyle;
	System::Types::TSize size;
};


typedef tagBUTTON_SPLITINFO *PButtonSplitinfo;

typedef tagBUTTON_SPLITINFO TButtonSplitinfo;

struct DECLSPEC_DRECORD tagNMBCDROPDOWN
{
public:
	tagNMHDR hdr;
	System::Types::TRect rcButton;
};


typedef tagNMBCDROPDOWN *PNMBCDropDown;

typedef tagNMBCDROPDOWN TNMBCDropDown;

struct DECLSPEC_DRECORD _tagEDITBALLOONTIP
{
public:
	unsigned cbStruct;
	System::WideChar *pszTitle;
	System::WideChar *pszText;
	int ttiIcon;
};


typedef _tagEDITBALLOONTIP *PEditBalloonTip;

typedef _tagEDITBALLOONTIP TEditBalloonTip;

typedef HRESULT __stdcall (*PFTASKDIALOGCALLBACK)(HWND hwnd, unsigned msg, NativeUInt wParam, NativeInt lParam, NativeInt lpRefData);

typedef PFTASKDIALOGCALLBACK TFTaskDialogCallback;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TASKDIALOG_BUTTON
{
public:
	int nButtonID;
	System::WideChar *pszButtonText;
};
#pragma pack(pop)


typedef TASKDIALOG_BUTTON _TASKDIALOG_BUTTON;

typedef TASKDIALOG_BUTTON *PTaskDialogButton;

typedef TASKDIALOG_BUTTON TTaskDialogButton;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TASKDIALOGCONFIG
{
public:
	unsigned cbSize;
	HWND hwndParent;
	NativeUInt hInstance;
	unsigned dwFlags;
	unsigned dwCommonButtons;
	System::WideChar *pszWindowTitle;
	
public:
	union
	{
		struct 
		{
			System::WideChar *pszMainIcon;
			System::WideChar *pszMainInstruction;
			System::WideChar *pszContent;
			unsigned cButtons;
			TASKDIALOG_BUTTON *pButtons;
			int nDefaultButton;
			unsigned cRadioButtons;
			TASKDIALOG_BUTTON *pRadioButtons;
			int nDefaultRadioButton;
			System::WideChar *pszVerificationText;
			System::WideChar *pszExpandedInformation;
			System::WideChar *pszExpandedControlText;
			System::WideChar *pszCollapsedControlText;union
			{
				struct 
				{
					System::WideChar *pszFooterIcon;
					System::WideChar *pszFooter;
					PFTASKDIALOGCALLBACK pfCallback;
					NativeInt lpCallbackData;
					unsigned cxWidth;
				};
				struct 
				{
					HICON hFooterIcon;
				};
				
			};
		};
		struct 
		{
			HICON hMainIcon;
		};
		
	};
};
#pragma pack(pop)


typedef TASKDIALOGCONFIG *PTaskDialogConfig;

typedef TASKDIALOGCONFIG TTaskDialogConfig;

typedef tagTRACKMOUSEEVENT *PTrackMouseEvent;

typedef tagTRACKMOUSEEVENT TTrackMouseEvent;

typedef NativeInt __stdcall (*SUBCLASSPROC)(HWND hWnd, unsigned uMsg, NativeUInt wParam, NativeInt lParam, NativeUInt uIdSubclass, NativeUInt dwRefData);

typedef SUBCLASSPROC TSubClassProc;

struct DECLSPEC_DRECORD TWMNotifyHC
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	Winapi::Messages::TDWordFiller MsgFiller;
#endif /* _WIN64 */
	NativeUInt IDCtrl;
	
public:
	union
	{
		struct 
		{
			tagNMHEADERW *HDNotify;
			NativeInt Result;
		};
		struct 
		{
			tagNMHDR *NMHdr;
		};
		
	};
};


struct DECLSPEC_DRECORD TWMNotifyTV
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	Winapi::Messages::TDWordFiller MsgFiller;
#endif /* _WIN64 */
	NativeUInt IDCtrl;
	
public:
	union
	{
		struct 
		{
			tagTVDISPINFOW *TVDispInfo;
			NativeInt Result;
		};
		struct 
		{
			tagNMTTDISPINFOW *ToolTipTextW;
		};
		struct 
		{
			tagNMTVCUSTOMDRAW *NMTVCustomDraw;
		};
		struct 
		{
			tagNMTREEVIEWW *NMTreeView;
		};
		struct 
		{
			tagNMCUSTOMDRAWINFO *NMCustomDraw;
		};
		struct 
		{
			tagNMHDR *NMHdr;
		};
		
	};
};


struct DECLSPEC_DRECORD TWMNotifyTRB
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	Winapi::Messages::TDWordFiller MsgFiller;
#endif /* _WIN64 */
	NativeUInt IDCtrl;
	
public:
	union
	{
		struct 
		{
			tagNMCUSTOMDRAWINFO *NMCustomDraw;
			NativeInt Result;
		};
		struct 
		{
			tagNMHDR *NMHdr;
		};
		
	};
};


struct DECLSPEC_DRECORD TWMNotifyUD
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	Winapi::Messages::TDWordFiller MsgFiller;
#endif /* _WIN64 */
	NativeUInt IDCtrl;
	
public:
	union
	{
		struct 
		{
			_NM_UPDOWN *NMUpDown;
			NativeInt Result;
		};
		struct 
		{
			tagNMHDR *NMHdr;
		};
		
	};
};


struct DECLSPEC_DRECORD TWMNotifyLV
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	Winapi::Messages::TDWordFiller MsgFiller;
#endif /* _WIN64 */
	NativeUInt IDCtrl;
	
public:
	union
	{
		struct 
		{
			tagNMLVODSTATECHANGE *NMLVODStateChange;
			NativeInt Result;
		};
		struct 
		{
			tagNMLVFINDITEMW *NMLVFindItem;
		};
		struct 
		{
			tagNMLVCUSTOMDRAW *NMLVCustomDraw;
		};
		struct 
		{
			tagNMLVCACHEHINT *NMLVCacheHint;
		};
		struct 
		{
			tagNMLISTVIEW *NMListView;
		};
		struct 
		{
			tagNMCUSTOMDRAWINFO *NMCustomDraw;
		};
		struct 
		{
			tagLVDISPINFOW *LVDispInfo;
		};
		struct 
		{
			tagNMHEADERW *HDNotify;
		};
		struct 
		{
			tagNMHDR *NMHdr;
		};
		
	};
};


struct DECLSPEC_DRECORD TWMNotifyTLB
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	Winapi::Messages::TDWordFiller MsgFiller;
#endif /* _WIN64 */
	NativeUInt IDCtrl;
	
public:
	union
	{
		struct 
		{
			tagNMTOOLBARW *NMToolBar;
			NativeInt Result;
		};
		struct 
		{
			_NMTBCUSTOMDRAW *NMTBCustomDraw;
		};
		struct 
		{
			tagNMHDR *NMHdr;
		};
		
	};
};


struct DECLSPEC_DRECORD TWMNotifyMC
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	Winapi::Messages::TDWordFiller MsgFiller;
#endif /* _WIN64 */
	NativeUInt IDCtrl;
	
public:
	union
	{
		struct 
		{
			tagNMSELCHANGE *NMSelChange;
			NativeInt Result;
		};
		struct 
		{
			tagNMDAYSTATE *NMDayState;
		};
		struct 
		{
			tagNMHDR *NMHdr;
		};
		
	};
};


struct DECLSPEC_DRECORD TWMNotifyDT
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	Winapi::Messages::TDWordFiller MsgFiller;
#endif /* _WIN64 */
	NativeUInt IDCtrl;
	
public:
	union
	{
		struct 
		{
			tagNMDATETIMESTRINGW *NMDateTimeString;
			NativeInt Result;
		};
		struct 
		{
			tagNMDATETIMECHANGE *NMDateTimeChange;
		};
		struct 
		{
			tagNMHDR *NMHdr;
		};
		
	};
};


struct DECLSPEC_DRECORD TWMNotifyPS
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	Winapi::Messages::TDWordFiller MsgFiller;
#endif /* _WIN64 */
	NativeUInt IDCtrl;
	
public:
	union
	{
		struct 
		{
			NMPGSCROLL *NMPGScroll;
			NativeInt Result;
		};
		struct 
		{
			NMPGCALCSIZE *NMPGCalcSize;
		};
		struct 
		{
			tagNMHDR *NMHdr;
		};
		
	};
};


struct DECLSPEC_DRECORD TTCMAdjustRect
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	Winapi::Messages::TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongBool Larger;
#ifndef _WIN64
	
#else /* _WIN64 */
	Winapi::Messages::TDWordFiller LargerFiller;
#endif /* _WIN64 */
	
public:
	union
	{
		struct 
		{
			System::Types::TRect *Prc;
			NativeInt Result;
		};
		struct 
		{
			System::Types::TRect *lpPrc;
		};
		
	};
};


//-- var, const, procedure ---------------------------------------------------
static const System::Word RB_GETBANDINFO_PRE_IE4 = System::Word(0x405);
#define HOTKEYCLASS L"msctls_hotkey32"
static const System::Int8 LVA_ALIGNRIGHT = System::Int8(0x3);
static const System::Int8 LVA_ALIGNBOTTOM = System::Int8(0x4);
static const System::Word LVA_SORTASCENDING = System::Word(0x100);
static const System::Word LVA_SORTDESCENDING = System::Word(0x200);
static const System::Int8 MCS_NOTODAY_PRE_IE4 = System::Int8(0x8);
extern DELPHI_PACKAGE System::LongBool __fastcall ListView_SetBkImageA(HWND hwnd, PLVBKImageA plvbki);
extern DELPHI_PACKAGE System::LongBool __fastcall ListView_SetBkImageW(HWND hwnd, PLVBKImageW plvbki);
extern DELPHI_PACKAGE System::LongBool __fastcall ListView_GetBkImageA(HWND hwnd, PLVBKImageA plvbki);
extern DELPHI_PACKAGE System::LongBool __fastcall ListView_GetBkImageW(HWND hwnd, PLVBKImageW plvbki);
extern DELPHI_PACKAGE HTREEITEM __fastcall TreeView_InsertItemA(HWND hwnd, const tagTVINSERTSTRUCTA &lpis);
extern DELPHI_PACKAGE HTREEITEM __fastcall TreeView_InsertItemW(HWND hwnd, const tagTVINSERTSTRUCTW &lpis);
}	/* namespace Commctrl */
}	/* namespace Winapi */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_WINAPI_COMMCTRL)
using namespace Winapi::Commctrl;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_WINAPI)
using namespace Winapi;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Winapi_CommctrlHPP
