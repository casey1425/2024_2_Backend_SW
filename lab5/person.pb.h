// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: person.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_person_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_person_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_person_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_person_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_person_2eproto;
namespace mju {
class Person;
struct PersonDefaultTypeInternal;
extern PersonDefaultTypeInternal _Person_default_instance_;
class Person_PhoneNumber;
struct Person_PhoneNumberDefaultTypeInternal;
extern Person_PhoneNumberDefaultTypeInternal _Person_PhoneNumber_default_instance_;
}  // namespace mju
PROTOBUF_NAMESPACE_OPEN
template<> ::mju::Person* Arena::CreateMaybeMessage<::mju::Person>(Arena*);
template<> ::mju::Person_PhoneNumber* Arena::CreateMaybeMessage<::mju::Person_PhoneNumber>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace mju {

enum Person_PhoneType : int {
  Person_PhoneType_MOBILE = 0,
  Person_PhoneType_HOME = 1
};
bool Person_PhoneType_IsValid(int value);
constexpr Person_PhoneType Person_PhoneType_PhoneType_MIN = Person_PhoneType_MOBILE;
constexpr Person_PhoneType Person_PhoneType_PhoneType_MAX = Person_PhoneType_HOME;
constexpr int Person_PhoneType_PhoneType_ARRAYSIZE = Person_PhoneType_PhoneType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Person_PhoneType_descriptor();
template<typename T>
inline const std::string& Person_PhoneType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Person_PhoneType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Person_PhoneType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Person_PhoneType_descriptor(), enum_t_value);
}
inline bool Person_PhoneType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Person_PhoneType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Person_PhoneType>(
    Person_PhoneType_descriptor(), name, value);
}
// ===================================================================

class Person_PhoneNumber final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mju.Person.PhoneNumber) */ {
 public:
  inline Person_PhoneNumber() : Person_PhoneNumber(nullptr) {}
  ~Person_PhoneNumber() override;
  explicit PROTOBUF_CONSTEXPR Person_PhoneNumber(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Person_PhoneNumber(const Person_PhoneNumber& from);
  Person_PhoneNumber(Person_PhoneNumber&& from) noexcept
    : Person_PhoneNumber() {
    *this = ::std::move(from);
  }

  inline Person_PhoneNumber& operator=(const Person_PhoneNumber& from) {
    CopyFrom(from);
    return *this;
  }
  inline Person_PhoneNumber& operator=(Person_PhoneNumber&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Person_PhoneNumber& default_instance() {
    return *internal_default_instance();
  }
  static inline const Person_PhoneNumber* internal_default_instance() {
    return reinterpret_cast<const Person_PhoneNumber*>(
               &_Person_PhoneNumber_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Person_PhoneNumber& a, Person_PhoneNumber& b) {
    a.Swap(&b);
  }
  inline void Swap(Person_PhoneNumber* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Person_PhoneNumber* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Person_PhoneNumber* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Person_PhoneNumber>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Person_PhoneNumber& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Person_PhoneNumber& from) {
    Person_PhoneNumber::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Person_PhoneNumber* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mju.Person.PhoneNumber";
  }
  protected:
  explicit Person_PhoneNumber(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNumberFieldNumber = 1,
    kTypeFieldNumber = 2,
  };
  // required string number = 1;
  bool has_number() const;
  private:
  bool _internal_has_number() const;
  public:
  void clear_number();
  const std::string& number() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_number(ArgT0&& arg0, ArgT... args);
  std::string* mutable_number();
  PROTOBUF_NODISCARD std::string* release_number();
  void set_allocated_number(std::string* number);
  private:
  const std::string& _internal_number() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_number(const std::string& value);
  std::string* _internal_mutable_number();
  public:

  // optional .mju.Person.PhoneType type = 2 [default = HOME];
  bool has_type() const;
  private:
  bool _internal_has_type() const;
  public:
  void clear_type();
  ::mju::Person_PhoneType type() const;
  void set_type(::mju::Person_PhoneType value);
  private:
  ::mju::Person_PhoneType _internal_type() const;
  void _internal_set_type(::mju::Person_PhoneType value);
  public:

  // @@protoc_insertion_point(class_scope:mju.Person.PhoneNumber)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr number_;
    int type_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_person_2eproto;
};
// -------------------------------------------------------------------

class Person final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mju.Person) */ {
 public:
  inline Person() : Person(nullptr) {}
  ~Person() override;
  explicit PROTOBUF_CONSTEXPR Person(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Person(const Person& from);
  Person(Person&& from) noexcept
    : Person() {
    *this = ::std::move(from);
  }

  inline Person& operator=(const Person& from) {
    CopyFrom(from);
    return *this;
  }
  inline Person& operator=(Person&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Person& default_instance() {
    return *internal_default_instance();
  }
  static inline const Person* internal_default_instance() {
    return reinterpret_cast<const Person*>(
               &_Person_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Person& a, Person& b) {
    a.Swap(&b);
  }
  inline void Swap(Person* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Person* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Person* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Person>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Person& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Person& from) {
    Person::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Person* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mju.Person";
  }
  protected:
  explicit Person(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef Person_PhoneNumber PhoneNumber;

  typedef Person_PhoneType PhoneType;
  static constexpr PhoneType MOBILE =
    Person_PhoneType_MOBILE;
  static constexpr PhoneType HOME =
    Person_PhoneType_HOME;
  static inline bool PhoneType_IsValid(int value) {
    return Person_PhoneType_IsValid(value);
  }
  static constexpr PhoneType PhoneType_MIN =
    Person_PhoneType_PhoneType_MIN;
  static constexpr PhoneType PhoneType_MAX =
    Person_PhoneType_PhoneType_MAX;
  static constexpr int PhoneType_ARRAYSIZE =
    Person_PhoneType_PhoneType_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  PhoneType_descriptor() {
    return Person_PhoneType_descriptor();
  }
  template<typename T>
  static inline const std::string& PhoneType_Name(T enum_t_value) {
    static_assert(::std::is_same<T, PhoneType>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function PhoneType_Name.");
    return Person_PhoneType_Name(enum_t_value);
  }
  static inline bool PhoneType_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      PhoneType* value) {
    return Person_PhoneType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kPhonesFieldNumber = 4,
    kNameFieldNumber = 1,
    kIdFieldNumber = 2,
  };
  // repeated .mju.Person.PhoneNumber phones = 4;
  int phones_size() const;
  private:
  int _internal_phones_size() const;
  public:
  void clear_phones();
  ::mju::Person_PhoneNumber* mutable_phones(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mju::Person_PhoneNumber >*
      mutable_phones();
  private:
  const ::mju::Person_PhoneNumber& _internal_phones(int index) const;
  ::mju::Person_PhoneNumber* _internal_add_phones();
  public:
  const ::mju::Person_PhoneNumber& phones(int index) const;
  ::mju::Person_PhoneNumber* add_phones();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mju::Person_PhoneNumber >&
      phones() const;

  // required string name = 1;
  bool has_name() const;
  private:
  bool _internal_has_name() const;
  public:
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // optional int32 id = 2;
  bool has_id() const;
  private:
  bool _internal_has_id() const;
  public:
  void clear_id();
  int32_t id() const;
  void set_id(int32_t value);
  private:
  int32_t _internal_id() const;
  void _internal_set_id(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:mju.Person)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mju::Person_PhoneNumber > phones_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    int32_t id_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_person_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Person_PhoneNumber

// required string number = 1;
inline bool Person_PhoneNumber::_internal_has_number() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Person_PhoneNumber::has_number() const {
  return _internal_has_number();
}
inline void Person_PhoneNumber::clear_number() {
  _impl_.number_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Person_PhoneNumber::number() const {
  // @@protoc_insertion_point(field_get:mju.Person.PhoneNumber.number)
  return _internal_number();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Person_PhoneNumber::set_number(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.number_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:mju.Person.PhoneNumber.number)
}
inline std::string* Person_PhoneNumber::mutable_number() {
  std::string* _s = _internal_mutable_number();
  // @@protoc_insertion_point(field_mutable:mju.Person.PhoneNumber.number)
  return _s;
}
inline const std::string& Person_PhoneNumber::_internal_number() const {
  return _impl_.number_.Get();
}
inline void Person_PhoneNumber::_internal_set_number(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.number_.Set(value, GetArenaForAllocation());
}
inline std::string* Person_PhoneNumber::_internal_mutable_number() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.number_.Mutable(GetArenaForAllocation());
}
inline std::string* Person_PhoneNumber::release_number() {
  // @@protoc_insertion_point(field_release:mju.Person.PhoneNumber.number)
  if (!_internal_has_number()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.number_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.number_.IsDefault()) {
    _impl_.number_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void Person_PhoneNumber::set_allocated_number(std::string* number) {
  if (number != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.number_.SetAllocated(number, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.number_.IsDefault()) {
    _impl_.number_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:mju.Person.PhoneNumber.number)
}

// optional .mju.Person.PhoneType type = 2 [default = HOME];
inline bool Person_PhoneNumber::_internal_has_type() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool Person_PhoneNumber::has_type() const {
  return _internal_has_type();
}
inline void Person_PhoneNumber::clear_type() {
  _impl_.type_ = 1;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline ::mju::Person_PhoneType Person_PhoneNumber::_internal_type() const {
  return static_cast< ::mju::Person_PhoneType >(_impl_.type_);
}
inline ::mju::Person_PhoneType Person_PhoneNumber::type() const {
  // @@protoc_insertion_point(field_get:mju.Person.PhoneNumber.type)
  return _internal_type();
}
inline void Person_PhoneNumber::_internal_set_type(::mju::Person_PhoneType value) {
  assert(::mju::Person_PhoneType_IsValid(value));
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.type_ = value;
}
inline void Person_PhoneNumber::set_type(::mju::Person_PhoneType value) {
  _internal_set_type(value);
  // @@protoc_insertion_point(field_set:mju.Person.PhoneNumber.type)
}

// -------------------------------------------------------------------

// Person

// required string name = 1;
inline bool Person::_internal_has_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Person::has_name() const {
  return _internal_has_name();
}
inline void Person::clear_name() {
  _impl_.name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Person::name() const {
  // @@protoc_insertion_point(field_get:mju.Person.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Person::set_name(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:mju.Person.name)
}
inline std::string* Person::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:mju.Person.name)
  return _s;
}
inline const std::string& Person::_internal_name() const {
  return _impl_.name_.Get();
}
inline void Person::_internal_set_name(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* Person::_internal_mutable_name() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.name_.Mutable(GetArenaForAllocation());
}
inline std::string* Person::release_name() {
  // @@protoc_insertion_point(field_release:mju.Person.name)
  if (!_internal_has_name()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.name_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void Person::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.name_.SetAllocated(name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:mju.Person.name)
}

// optional int32 id = 2;
inline bool Person::_internal_has_id() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool Person::has_id() const {
  return _internal_has_id();
}
inline void Person::clear_id() {
  _impl_.id_ = 0;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline int32_t Person::_internal_id() const {
  return _impl_.id_;
}
inline int32_t Person::id() const {
  // @@protoc_insertion_point(field_get:mju.Person.id)
  return _internal_id();
}
inline void Person::_internal_set_id(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.id_ = value;
}
inline void Person::set_id(int32_t value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:mju.Person.id)
}

// repeated .mju.Person.PhoneNumber phones = 4;
inline int Person::_internal_phones_size() const {
  return _impl_.phones_.size();
}
inline int Person::phones_size() const {
  return _internal_phones_size();
}
inline void Person::clear_phones() {
  _impl_.phones_.Clear();
}
inline ::mju::Person_PhoneNumber* Person::mutable_phones(int index) {
  // @@protoc_insertion_point(field_mutable:mju.Person.phones)
  return _impl_.phones_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mju::Person_PhoneNumber >*
Person::mutable_phones() {
  // @@protoc_insertion_point(field_mutable_list:mju.Person.phones)
  return &_impl_.phones_;
}
inline const ::mju::Person_PhoneNumber& Person::_internal_phones(int index) const {
  return _impl_.phones_.Get(index);
}
inline const ::mju::Person_PhoneNumber& Person::phones(int index) const {
  // @@protoc_insertion_point(field_get:mju.Person.phones)
  return _internal_phones(index);
}
inline ::mju::Person_PhoneNumber* Person::_internal_add_phones() {
  return _impl_.phones_.Add();
}
inline ::mju::Person_PhoneNumber* Person::add_phones() {
  ::mju::Person_PhoneNumber* _add = _internal_add_phones();
  // @@protoc_insertion_point(field_add:mju.Person.phones)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mju::Person_PhoneNumber >&
Person::phones() const {
  // @@protoc_insertion_point(field_list:mju.Person.phones)
  return _impl_.phones_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace mju

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::mju::Person_PhoneType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::mju::Person_PhoneType>() {
  return ::mju::Person_PhoneType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_person_2eproto
