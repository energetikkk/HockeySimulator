// -----------------------------------------------------------------------------------
// syscurr.h: Currency Wrapper
//
// $Rev: 89537 $
//
// Copyright(c) 1995-2011 Embarcadero Technologies, Inc.
// -----------------------------------------------------------------------------------
#if !defined(SYSCURR_H)
#define SYSCURR_H

#if !defined(SystemHPP)
#error Do not include this file directly.  Include 'System.hpp'.
#endif

#if !defined(SYSMAC_H)
#include <sysmac.h>
#endif
#if !defined(DSTRING_H)
#include <dstring.h>
#endif
#if !defined(WSTRING_H)
#include <wstring.h>
#endif

#pragma option push -w-inl -w-lvc

namespace System
{

// Forward ref.
class RTL_DELPHIRETURN Currency;

#if defined(__linux__) && defined(__x86_64__)
  // Use _MulDivComp for Linux 64
  __int64 _MulDivComp(__int64 AValue, __int64 AMul, __int64 ADiv);
#elif defined(__arm__) || defined(__arm64__)
  // See System.pas
  __int64 _MulDivInt64(__int64 AValue, __int64 AMul, __int64 ADiv);
#elif defined(_WIN32) || defined(__APPLE__)
  // Use __currMul for WIN32, WIN64 and OSX
  // (See classcre.asm, currency.cpp, classcreate.c)
  extern "C" void __fastcall __currMul(const System::Currency c1, System::Currency &c2);
#else
  #error "Need __currMul/_MulDivInt64 Helper"
#endif

  class RTL_DELPHIRETURN CurrencyBase
  {
  public:
    __int64 Val;  // struct { unsigned long Lo; long Hi; };
  };

  class RTL_DELPHIRETURN Currency : public CurrencyBase
  {
    friend Currency __fastcall operator +(int lhs, const Currency& rhs);
    friend Currency __fastcall operator -(int lhs, const Currency& rhs);
    friend Currency __fastcall operator *(int lhs, const Currency& rhs);
    friend Currency __fastcall operator /(int lhs, const Currency& rhs);
    friend Currency __fastcall operator +(double lhs, const Currency& rhs);
    friend Currency __fastcall operator -(double lhs, const Currency& rhs);
    friend Currency __fastcall operator *(double lhs, const Currency& rhs);
    friend Currency __fastcall operator /(double lhs, const Currency& rhs);
  public:
    __fastcall Currency()                        {Val = 0;}
    __fastcall Currency(int val)                 {Val = 10000*(__int64)val;}
    __fastcall Currency(const CurrencyBase& src) {Val = src.Val;}
    __fastcall Currency(const System::String& src);
    __fastcall Currency(double val);

    Currency& __fastcall operator =(double rhs);

    Currency& __fastcall operator =(int rhs)
    {Val = 10000*(__int64)rhs; return *this;}
    Currency& __fastcall operator =(const CurrencyBase& rhs)
    {Val=rhs.Val;return *this;}
    Currency& __fastcall operator =(const Currency& rhs)
    {Val = rhs.Val; return *this;}

    Currency& __fastcall operator +=(const Currency& rhs)
    {Val += rhs.Val; return *this;}
    Currency& __fastcall operator -=(const Currency& rhs)
    {Val -= rhs.Val; return *this;}

    Currency& __fastcall operator *=(const Currency& rhs)
  #if defined(__linux__) && defined(__x86_64__)
    { Val = _MulDivComp(Val, rhs.Val, 10000); return *this; }
  #elif defined(__arm__) || defined(__arm64__)
    { Val = _MulDivInt64(Val, rhs.Val, 10000); return *this; }
  #elif defined(_WIN32) || defined(__APPLE__)
    { __currMul(rhs, *this); return *this; }
  #else
    #error "Need Currency *= implemented"
  #endif

    Currency& __fastcall operator /=(const Currency& rhs)
    {Val *= 10000; Val /= rhs.Val; return *this;}
    Currency& __fastcall operator %=(int rhs)
    {Val %= 10000 * (__int64)rhs; return *this;}

    Currency& operator ++() {Val += 10000; return *this;}
    Currency operator ++(int) {Currency tmp(*this); Val += 10000; return tmp;}
    Currency& operator --() {Val -= 10000; return *this;}
    Currency operator --(int) {Currency tmp(*this); Val -= 10000; return tmp;}

    Currency __fastcall operator +(const Currency& rhs) const
    {Currency tmp(*this); return tmp += rhs;}
    Currency __fastcall operator -(const Currency& rhs) const
    {Currency tmp(*this); return tmp -= rhs;}
    Currency __fastcall operator *(const Currency& rhs) const
    {Currency tmp(*this); return tmp *= rhs;}
    Currency __fastcall operator /(const Currency& rhs) const
    {Currency tmp(*this); return tmp /= rhs;}

    Currency __fastcall operator +(int rhs) const
    {Currency tmp(*this); return tmp += Currency(rhs);}
    Currency __fastcall operator -(int rhs) const
    {Currency tmp(*this); return tmp -= Currency(rhs);}
    Currency __fastcall operator *(int rhs) const
    {Currency tmp(*this); return tmp *= Currency(rhs);}
    Currency __fastcall operator /(int rhs) const
    {Currency tmp(*this); return tmp /= Currency(rhs);}
    Currency __fastcall operator %(int rhs) const
    {return Currency(static_cast<int>(Val % (10000 * (__int64)rhs))) / 10000;}

    Currency __fastcall operator +(double rhs) const
    {Currency tmp(*this); return tmp += Currency(rhs);}
    Currency __fastcall operator -(double rhs) const
    {Currency tmp(*this); return tmp -= Currency(rhs);}
    Currency __fastcall operator *(double rhs) const
    {Currency tmp(*this); return tmp *= Currency(rhs);}
    Currency __fastcall operator /(double rhs) const
    {Currency tmp(*this); return tmp /= Currency(rhs);}

    Currency __fastcall operator -() const
    {Currency tmp(*this); tmp.Val = -(tmp.Val); return tmp;}

    Currency __fastcall operator !() const
    {Currency tmp(*this); tmp.Val = !(tmp.Val); return tmp;}

    // comparisons (Currency rhs)
    bool __fastcall operator ==(const Currency& rhs) const
    {return Val == rhs.Val;}
    bool __fastcall operator !=(const Currency& rhs) const
    {return Val != rhs.Val;}
    bool __fastcall operator >(const Currency& rhs) const
    {return Val > rhs.Val;}
    bool __fastcall operator <(const Currency& rhs) const
    {return Val < rhs.Val;}
    bool __fastcall operator >=(const Currency& rhs) const
    {return Val >= rhs.Val;}
    bool __fastcall operator <=(const Currency& rhs) const
    {return Val <= rhs.Val;}

    // comparisons (int rhs)
    bool __fastcall operator ==(int rhs) const
    {return Val == 10000 * (__int64)rhs;}
    bool __fastcall operator !=(int rhs) const
    {return Val != 10000 * (__int64)rhs;}
    bool __fastcall operator >(int rhs) const
    {return Val > 10000 * (__int64)rhs;}
    bool __fastcall operator <(int rhs) const
    {return Val < 10000 * (__int64)rhs;}
    bool __fastcall operator >=(int rhs) const
    {return Val >= 10000 * (__int64)rhs;}
    bool __fastcall operator <=(int rhs) const
    {return Val <= 10000 * (__int64)rhs;}

    // comparisons (double rhs)
    bool __fastcall operator ==(double rhs) const
    {return *this == Currency(rhs);}
    bool __fastcall operator !=(double rhs) const
    {return *this != Currency(rhs);}
    bool __fastcall operator >(double rhs) const
    {return *this > Currency(rhs);}
    bool __fastcall operator <(double rhs) const
    {return *this < Currency(rhs);}
    bool __fastcall operator >=(double rhs) const
    {return *this >= Currency(rhs);}
    bool __fastcall operator <=(double rhs) const
    {return *this <= Currency(rhs);}

    __fastcall operator double() const {return ((double)Val) / 10000;}
    __fastcall operator int() const    {return (int) (Val / 10000);}
    __fastcall operator System::String() const;
  };

  // Currency friends
  //
  inline Currency __fastcall operator +(int lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp += rhs;}
  inline Currency __fastcall operator -(int lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp -= rhs;}
  inline Currency __fastcall operator *(int lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp *= rhs;}
  inline Currency __fastcall operator /(int lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp /= rhs;}
  inline Currency __fastcall operator +(double lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp += rhs;}
  inline Currency __fastcall operator -(double lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp -= rhs;}
  inline Currency __fastcall operator *(double lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp *= rhs;}
  inline Currency __fastcall operator /(double lhs, const Currency& rhs)
  {Currency tmp(lhs); return tmp /= rhs;}

  // NOTE: Insertion/Extraction operators of VCL classes are only visible
  //       if VCL_IOSTREAM is defined.
  //
  #if defined(VCL_IOSTREAM)
  std::ostream& operator << (std::ostream& os, const Currency& arg);
  std::istream& operator >> (std::istream& is, Currency& arg);
  #endif

}

#pragma option pop

#endif
