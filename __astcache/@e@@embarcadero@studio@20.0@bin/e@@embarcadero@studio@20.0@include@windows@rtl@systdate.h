// -----------------------------------------------------------------------------------
// SYSTDATE.H: C++ Encapsulation of Delphi's TDateTime
//
// $Rev: 96297 $
//
// Copyright(c) 1995-2011 Embarcadero Technologies, Inc.
// -----------------------------------------------------------------------------------
#if !defined(SYSTDATE_H)
#define SYSTDATE_H

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
  class RTL_DELPHIRETURN TDateTimeBase
  {
  public:
    double Val;
  };

  class RTL_DELPHIRETURN TDateTime : public TDateTimeBase
  {
  public:
    // Used by TDateTime(const System::String& src)
    enum TDateTimeFlag {Date, Time, DateTime};

    static TDateTime __fastcall CurrentDate();
    static TDateTime __fastcall CurrentTime();
    static TDateTime __fastcall CurrentDateTime();
    static TDateTime __fastcall FileDateToDateTime(int fileDate);

    __fastcall TDateTime()                                  {Val = 0;}
    __fastcall TDateTime(const TDateTimeBase& src)          {Val = src.Val;}
    __fastcall TDateTime(const double src)                  {Val = src;}
    __fastcall TDateTime(const int src)                     {Val = src;}
    __fastcall TDateTime(const System::String& src, TDateTimeFlag flag = DateTime);
    __fastcall TDateTime(unsigned short year, unsigned short month,
            unsigned short day);
    __fastcall TDateTime(unsigned short hour, unsigned short min,
            unsigned short sec, unsigned short msec);
    __fastcall TDateTime(unsigned short year, unsigned short month,
            unsigned short day, unsigned short hour, unsigned short min,
            unsigned short sec, unsigned short msec);

    TDateTime& __fastcall operator =(const TDateTimeBase& rhs)
    {Val = rhs.Val;return *this;}
    TDateTime& __fastcall operator =(const TDateTime& rhs)
    {Val = rhs.Val;  return *this;}
    TDateTime& __fastcall operator =(const double rhs)
    {Val = rhs; return *this;}
    TDateTime& __fastcall operator =(const int rhs)
    {Val = rhs; return *this;}

    TDateTime& __fastcall operator +=(const TDateTimeBase& rhs)
    {Val+=rhs.Val;return *this;}
    TDateTime& __fastcall operator +=(const TDateTime& rhs)
    {Val += rhs.Val; return *this;}
    TDateTime& __fastcall operator +=(const double rhs)
    {Val += rhs; return *this;}
    TDateTime& __fastcall operator +=(const int rhs)
    {Val += rhs; return *this;}

    TDateTime& __fastcall operator -=(const TDateTimeBase& rhs)
    {Val-=rhs.Val;return *this;}
    TDateTime& __fastcall operator -=(const TDateTime& rhs)
    {Val -= rhs.Val; return *this;}
    TDateTime& __fastcall operator -=(const double rhs)
    {Val -= rhs; return *this;}
    TDateTime& __fastcall operator -=(const int rhs)
    {Val -= rhs; return *this;}

    TDateTime& operator ++() {Val++; return *this;}
    TDateTime operator ++(int) {TDateTime tmp(*this); Val++; return tmp;}
    TDateTime& operator --() {Val--; return *this;}
    TDateTime operator --(int) {TDateTime tmp(*this); Val--; return tmp;}

    TDateTime __fastcall operator +(const TDateTimeBase& rhs) const
    {return Val+rhs.Val;}
    TDateTime __fastcall operator +(const TDateTime& rhs) const
    {return Val+rhs.Val;}
    TDateTime __fastcall operator +(const double rhs) const {return Val+rhs;}
    TDateTime __fastcall operator +(const int rhs) const {return Val+rhs;}

    TDateTime __fastcall operator -(const TDateTimeBase& rhs) const
    {return Val-rhs.Val;}
    TDateTime __fastcall operator -(const TDateTime& rhs) const
    {return Val-rhs.Val;}
    TDateTime __fastcall operator -(const double rhs) const {return Val-rhs;}
    TDateTime __fastcall operator -(const int rhs) const {return Val-rhs;}

    // comparisons
    bool __fastcall operator ==(const TDateTime& rhs) const
    {return Val == rhs.Val;}
    bool __fastcall operator !=(const TDateTime& rhs) const
    {return Val != rhs.Val;}
    bool __fastcall operator >(const TDateTime& rhs) const
    {return Val > rhs.Val;}
    bool __fastcall operator <(const TDateTime& rhs) const
    {return Val < rhs.Val;}
    bool __fastcall operator >=(const TDateTime& rhs) const
    {return Val >= rhs.Val;}
    bool __fastcall operator <=(const TDateTime& rhs) const
    {return Val <= rhs.Val;}

#if defined(TDATETIME_IMPLICIT_CONV_OP)
    // The classic compiler did not properly implement the standard in allowing
    // 2 user-defined conversions from TDateTime to AnsiString. This resulted
    // in reports like http://vmsfjira.embarcadero.com:8665/browse/RS-84894 
    // that claim that clang's at fault for now allow the same - :(
    //
    // This operator is to placate such reports and allow clang to handle
    // constructs like:
    //
    //      AnsiString s = System::SysUtils::Now();
    //
    // Use at your own risk: This operator may result in ambiguity errors!
    _DEPRECATED_ATTRIBUTE1("use toAnsiString")
    __fastcall operator System::AnsiString() const
    {return System::AnsiString(operator System::String());}
#endif
    __fastcall System::AnsiString toAnsiString() const
    {return System::AnsiString(operator System::String());}

    __fastcall operator System::String() const;//<Date||Time||DateTime>String(smart)
    System::String __fastcall FormatString(const System::String& format) const;
    System::String __fastcall DateString() const;
    System::String __fastcall TimeString() const;
    System::String __fastcall DateTimeString() const;
    __fastcall operator double() const {return Val;}
    __fastcall operator int() const    {return (int)Val;}

    int __fastcall DayOfWeek() const;
    int __fastcall FileDate() const;
    void __fastcall DecodeDate(unsigned short* year, unsigned short*
           month, unsigned short* day) const;
    void __fastcall DecodeTime(unsigned short* hour, unsigned short*
           min, unsigned short* sec, unsigned short* msec) const;
  };

#if defined(_DELPHI_NEXTGEN) && !defined(_Windows)
  #ifndef _DECLARE_TDATETIME_TYPE_ALIAS
  #define _DECLARE_TDATETIME_TYPE_ALIAS(Base, Alias, Flag)         \
    class Alias : public Base {                                    \
    public:                                                        \
      Alias() : Base() {}                                          \
      Alias(const Base&  o) : Base(o) {}                           \
      Alias(const double src) : Base(src) {}                       \
      Alias(const int src) : Base(src) {}                          \
      Alias(const System::String& src,                             \
            TDateTimeFlag flag = Flag) : Base(src, flag) {}        \
      Alias(unsigned short year, unsigned short month,             \
            unsigned short day) : Base(year, month, day) {}        \
      Alias(unsigned short hour,                                   \
            unsigned short min, unsigned short sec,                \
            unsigned short msec) : Base(hour, min, sec, msec) {}   \
      Alias(unsigned short year, unsigned short month,             \
            unsigned short day, unsigned short hour,               \
            unsigned short min, unsigned short sec,                \
            unsigned short msec) : Base(year, month, day, hour,    \
                                        min, sec, msec) {}         \
    };
  #endif

  _DECLARE_TDATETIME_TYPE_ALIAS(TDateTime, TDate, Date)
  _DECLARE_TDATETIME_TYPE_ALIAS(TDateTime, TTime, Time)

#endif

  // NOTE: Insertion/Extraction operators of VCL classes are only visible
  //       if VCL_IOSTREAM is defined.
  //
  #if defined(VCL_IOSTREAM)
  std::ostream& operator <<(std::ostream& os, const TDateTime& arg);
  std::istream& operator >>(std::istream& is, TDateTime& arg);
  #endif

}

#pragma option pop

#endif
