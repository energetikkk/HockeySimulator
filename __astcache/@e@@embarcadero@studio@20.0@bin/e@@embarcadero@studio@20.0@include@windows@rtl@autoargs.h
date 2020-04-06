//------------------------------------------------------------------------------
// AOTOARGS.H - Wrapper of VARIANT array used in Automation
//
// $Rev: 47950 $
//
// Copyright(c) 1995-2011 Embarcadero Technologies, Inc.
//------------------------------------------------------------------------------
#ifndef __AUTOARGS_H
#define __AUTOARGS_H

  // We default to TVariant for disp wrappers if it's been seen
#if defined(__UTILCLS_H)
  typedef TVariantT<VARIANT, true> VARIANTOBJ;
#elif defined(SystemHPP)
  // Here VCL is already in use, we default to using OleVariant
  // for disp-automation support.
  #include <sysvari.h>
  typedef System::Variant VARIANTOBJ;
#elif defined(_Windows)
  // Here we go raw Variant -
  // NOTE: This option is not really valid as raw VARIANT
  //       lacks the proper assignment/conversion operators
  //       for OleAutomation compatible types.
  #define VARIANT_NATIVE_SUPPORT
  #include <oaidl.h>
  #include <wtypes.h>
  #include <unknwn.h>
  typedef VARIANT VARIANTOBJ;
#else
  #pragma error No Variant support provided for AutoArgs!
#endif

#ifndef _ASSERTE
  #include <assert.h>
  #define _ASSERTE(x) assert(x)
  #define _ASSERTE_(x) assert(x)
#endif

class TAutoArgsBase
{
protected:
  TAutoArgsBase(VARIANTOBJ *pVariant, int count) : m_Variant(pVariant), m_Count(count)
  {}

public:
  VARIANTOBJ& operator[](int index) const
  {
    // NOTE: It's OK to use Count - there's an extra Variant for return result
    //       Zero'th entry's reserved for return value.
    //
    _ASSERTE_(index <= m_Count);
    _ASSERTE_(index >= 0);

    // Make up for C++ vs. Basic reverse indexing
    //
    return m_Variant[index ? (m_Count+1-index) : 0];
  }

  VARIANTOBJ* GetRetVal() const
  {
    return &m_Variant[0];
  }

  VARIANTOBJ& GetRetVariant()
  {
    return *m_Variant;
  }

  VARIANTOBJ* GetArgs() const
  {
    return (VARIANTOBJ*)(m_Variant+1);
  }

  int GetCount() const
  {
    return m_Count;
  }

private:
  TAutoArgsBase(const TAutoArgsBase&);
  TAutoArgsBase& operator=(const TAutoArgsBase&);

  VARIANTOBJ *m_Variant;
  int         m_Count;
};


// TAutoArgs - Encapsulates array of Variants. Use for Invoke calls
//
template <int Count>
class TAutoArgs : public TAutoArgsBase
{
public:
  TAutoArgs() : TAutoArgsBase(m_Array, Count) {};
 ~TAutoArgs() {};
  TAutoArgs(TAutoArgs& src);

private:
  // Allocate an extra Variant. It's the first entry  and
  // it is reserved for return result. The rest are for parameters
  //
  VARIANTOBJ m_Array[Count+1];
};

#endif // __AUTOARGS_H
