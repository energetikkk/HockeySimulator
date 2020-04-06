// -----------------------------------------------------------------------------------
// SystemRtti.h C++ Declarations of types from the System.Rtti unit
//
// $Rev: 90147 $
//
// Copyright(c) 2012 Embarcadero Technologies, Inc.
// -----------------------------------------------------------------------------------
#ifndef SystemRtti_H
#define SystemRtti_H

#if !defined(System_RttiHPP)
#error Do not include this file directly.  Include 'System.Rtti.hpp'.
#endif

namespace System {
 namespace Internal {
  namespace Varhlpr {
   extern PACKAGE System::Typinfo::PTypeInfo __fastcall GetTypeInfoHelper(unsigned I);
  }
 }
}

namespace System
{
namespace Rtti
{
  enum class TypeInfoIndex : unsigned int {
                   tiiBoolean = 1,
                   tiiByte,
                   tiiShortInt,
                   tiiWord,
                   tiiSmallInt,
                   tiiLongInt,
                   tiiLongWord,
                   tiiInt64,
                   tiiUInt64,
                   tiiFloat,
                   tiiDouble,
                   tiiExtended,
                   tiiAnsiChar,
                   tiiWideChar,
                   tiiCurrency,
                   tiiTDateTime,
                   tiiAnsiString,
                   tiiUnicodeString,
                   tiiWideString,
                   tiiTPointF,
                   tiiTAlphaColor,
                   tiiTNotifyEvent,
                   tiiIInterface,
                   tiiIInvokable,
                   tiiVariant,
                   tiiOleVariant,
                   tiiLast
                };

  template <typename T>
  struct _TValueDataHlpr
  {
    typedef void* RetType;
    static RetType get(const T& Value)
    { return const_cast<T*>(&Value); }
  };

  template <typename T>
  struct _TValueRTTIHlpr
  {
    static System::Typinfo::PTypeInfo get()
    { return __delphirtti(T); }
  };

  template <TypeInfoIndex E>
  struct _TRTTIGetter
  {
    static System::Typinfo::PTypeInfo get()
    { return System::Internal::Varhlpr::GetTypeInfoHelper(static_cast<unsigned>(E)); }
  };

  template <>
  struct _TValueRTTIHlpr<System::Types::TPointF>
  {
    static System::Typinfo::PTypeInfo get()
    { return _TRTTIGetter<TypeInfoIndex::tiiTPointF>::get(); }
  };

  // Make sure to include System.Classes.hpp *before* System.Rtti.hpp
  // when using TNotifyEvent in a TValue to get the correct TypeInfo
#if defined(System_ClassesHPP)
//  template <>
//  struct _TValueRTTIHlpr<System::Classes::TNotifyEvent>
//  {
//    static System::Typinfo::PTypeInfo get()
//    { return _TRTTIGetter<TypeInfoIndex::tiiTNotifyEvent>::get(); }
//  };
#endif

  template <typename T,
            typename _DATA = _TValueDataHlpr<T>,
            typename _RTTI = _TValueRTTIHlpr<T> >
  struct _TValueHelper
  {
    static TValue From(const T Value)
    {
      TValue result = TValue::Empty;
      TValue::Make(_DATA::get(Value), _RTTI::get(), result);
      return result;
    }
  };

  template <typename T>
  TValue __fastcall TValue::From(const T Value)
  {
    // Force error if TValue::From<T> is missing pointer on objects
    // Use TValue::From<TObject*>(pObj) for delphi-style classes
    typedef int _dummyType[__is_base_of(System::TObject, T) ? -1 : 1];
    TValue result = TValue::Empty;
    TValue::Make(_TValueDataHlpr<T>::get(Value), _TValueRTTIHlpr<T>::get(), result);
    return result;
  }

  template <typename T>
  void __fastcall TValue::Get(/* out */ T &Result)
  {
    if (!FData.FTypeInfo)
      memset(&Result, 0, sizeof(T));
    else
      ExtractRawData(&Result);
  }

  template <typename T>
  bool __fastcall TValue::TryAsType(/* out */ T &AResult, const bool EmptyAsAnyType)
  {
    TValue val;
    bool result = TryCast(_TValueRTTIHlpr<T>::get(), val, EmptyAsAnyType);
    if (result)
      val.Get<T>(AResult);
    return result;
  }

  template<typename T>
  bool __fastcall TValue::IsType(const bool EmptyAsAnyType)/* overload */
  {
    return IsType(_TValueRTTIHlpr<T>::get(), EmptyAsAnyType);
  }

  template <typename T>
  T __fastcall TValue::AsType(const bool EmptyAsAnyType)
  {
    T result;
    if (!TryAsType<T>(result, EmptyAsAnyType))
      throw Sysutils::EInvalidCast(System_Sysconst_SInvalidCast);
    return result;
  }

  template <typename T>
  TValue __fastcall TValue::Cast(const bool EmptyAsAnyType)/* overload */
  {
    TValue result;
    if (!TryCast(_TValueRTTIHlpr<T>::get(), result, EmptyAsAnyType))
      throw Sysutils::EInvalidCast(System_Sysconst_SInvalidCast);
    return result;
  }

#ifndef __clang__
  // Fix for RSP-11348 but bcc32 mishandles the decl and produces an 
  // invalid PUBDEF,instead of the desired EXTDEF record :(
 #if 0 
  extern template<>
  TValue __fastcall TValue::From<String>(const String);
 #endif
#else
 #if defined(_WIN32) && !defined(_WIN64) 
  extern template
  TValue __fastcall TValue::From<String>(const String);
 #endif 
#endif

} /* namespace Rtti */
} /* namespace System */

#endif // SystemRtti_H