// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test_msg.proto

#include "test_msg.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace hansolo_std {

inline constexpr std_msg::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        datatype_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        timestamp_{nullptr},
        data_{0} {}

template <typename>
PROTOBUF_CONSTEXPR std_msg::std_msg(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct std_msgDefaultTypeInternal {
  PROTOBUF_CONSTEXPR std_msgDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~std_msgDefaultTypeInternal() {}
  union {
    std_msg _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 std_msgDefaultTypeInternal _std_msg_default_instance_;

inline constexpr std_msg_array::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        msg_{},
        timestamp_{nullptr} {}

template <typename>
PROTOBUF_CONSTEXPR std_msg_array::std_msg_array(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct std_msg_arrayDefaultTypeInternal {
  PROTOBUF_CONSTEXPR std_msg_arrayDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~std_msg_arrayDefaultTypeInternal() {}
  union {
    std_msg_array _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 std_msg_arrayDefaultTypeInternal _std_msg_array_default_instance_;
}  // namespace hansolo_std
static ::_pb::Metadata file_level_metadata_test_5fmsg_2eproto[2];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_test_5fmsg_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_test_5fmsg_2eproto = nullptr;
const ::uint32_t TableStruct_test_5fmsg_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    PROTOBUF_FIELD_OFFSET(::hansolo_std::std_msg, _impl_._has_bits_),
    PROTOBUF_FIELD_OFFSET(::hansolo_std::std_msg, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::hansolo_std::std_msg, _impl_.datatype_),
    PROTOBUF_FIELD_OFFSET(::hansolo_std::std_msg, _impl_.data_),
    PROTOBUF_FIELD_OFFSET(::hansolo_std::std_msg, _impl_.timestamp_),
    ~0u,
    ~0u,
    0,
    PROTOBUF_FIELD_OFFSET(::hansolo_std::std_msg_array, _impl_._has_bits_),
    PROTOBUF_FIELD_OFFSET(::hansolo_std::std_msg_array, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::hansolo_std::std_msg_array, _impl_.msg_),
    PROTOBUF_FIELD_OFFSET(::hansolo_std::std_msg_array, _impl_.timestamp_),
    ~0u,
    0,
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, 11, -1, sizeof(::hansolo_std::std_msg)},
        {14, 24, -1, sizeof(::hansolo_std::std_msg_array)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::hansolo_std::_std_msg_default_instance_._instance,
    &::hansolo_std::_std_msg_array_default_instance_._instance,
};
const char descriptor_table_protodef_test_5fmsg_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\016test_msg.proto\022\013hansolo_std\032\037google/pr"
    "otobuf/timestamp.proto\"X\n\007std_msg\022\020\n\010dat"
    "aType\030\001 \001(\t\022\014\n\004data\030\002 \001(\005\022-\n\ttimeStamp\030\003"
    " \001(\0132\032.google.protobuf.Timestamp\"a\n\rstd_"
    "msg_array\022!\n\003msg\030\001 \003(\0132\024.hansolo_std.std"
    "_msg\022-\n\ttimeStamp\030\002 \001(\0132\032.google.protobu"
    "f.Timestampb\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_test_5fmsg_2eproto_deps[1] =
    {
        &::descriptor_table_google_2fprotobuf_2ftimestamp_2eproto,
};
static ::absl::once_flag descriptor_table_test_5fmsg_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_test_5fmsg_2eproto = {
    false,
    false,
    259,
    descriptor_table_protodef_test_5fmsg_2eproto,
    "test_msg.proto",
    &descriptor_table_test_5fmsg_2eproto_once,
    descriptor_table_test_5fmsg_2eproto_deps,
    1,
    2,
    schemas,
    file_default_instances,
    TableStruct_test_5fmsg_2eproto::offsets,
    file_level_metadata_test_5fmsg_2eproto,
    file_level_enum_descriptors_test_5fmsg_2eproto,
    file_level_service_descriptors_test_5fmsg_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_test_5fmsg_2eproto_getter() {
  return &descriptor_table_test_5fmsg_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_test_5fmsg_2eproto(&descriptor_table_test_5fmsg_2eproto);
namespace hansolo_std {
// ===================================================================

class std_msg::_Internal {
 public:
  using HasBits = decltype(std::declval<std_msg>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(std_msg, _impl_._has_bits_);
  static const ::google::protobuf::Timestamp& timestamp(const std_msg* msg);
  static void set_has_timestamp(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

const ::google::protobuf::Timestamp& std_msg::_Internal::timestamp(const std_msg* msg) {
  return *msg->_impl_.timestamp_;
}
void std_msg::clear_timestamp() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (_impl_.timestamp_ != nullptr) _impl_.timestamp_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
std_msg::std_msg(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:hansolo_std.std_msg)
}
inline PROTOBUF_NDEBUG_INLINE std_msg::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        datatype_(arena, from.datatype_) {}

std_msg::std_msg(
    ::google::protobuf::Arena* arena,
    const std_msg& from)
    : ::google::protobuf::Message(arena) {
  std_msg* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::uint32_t cached_has_bits = _impl_._has_bits_[0];
  _impl_.timestamp_ = (cached_has_bits & 0x00000001u)
                ? CreateMaybeMessage<::google::protobuf::Timestamp>(arena, *from._impl_.timestamp_)
                : nullptr;
  _impl_.data_ = from._impl_.data_;

  // @@protoc_insertion_point(copy_constructor:hansolo_std.std_msg)
}
inline PROTOBUF_NDEBUG_INLINE std_msg::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        datatype_(arena) {}

inline void std_msg::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, timestamp_),
           0,
           offsetof(Impl_, data_) -
               offsetof(Impl_, timestamp_) +
               sizeof(Impl_::data_));
}
std_msg::~std_msg() {
  // @@protoc_insertion_point(destructor:hansolo_std.std_msg)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void std_msg::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.datatype_.Destroy();
  delete _impl_.timestamp_;
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void std_msg::Clear() {
// @@protoc_insertion_point(message_clear_start:hansolo_std.std_msg)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.datatype_.ClearToEmpty();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ABSL_DCHECK(_impl_.timestamp_ != nullptr);
    _impl_.timestamp_->Clear();
  }
  _impl_.data_ = 0;
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* std_msg::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 3, 1, 36, 2> std_msg::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(std_msg, _impl_._has_bits_),
    0, // no _extensions_
    3, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967288,  // skipmap
    offsetof(decltype(_table_), field_entries),
    3,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_std_msg_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // string dataType = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(std_msg, _impl_.datatype_)}},
    // int32 data = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(std_msg, _impl_.data_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(std_msg, _impl_.data_)}},
    // .google.protobuf.Timestamp timeStamp = 3;
    {::_pbi::TcParser::FastMtS1,
     {26, 0, 0, PROTOBUF_FIELD_OFFSET(std_msg, _impl_.timestamp_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string dataType = 1;
    {PROTOBUF_FIELD_OFFSET(std_msg, _impl_.datatype_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // int32 data = 2;
    {PROTOBUF_FIELD_OFFSET(std_msg, _impl_.data_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // .google.protobuf.Timestamp timeStamp = 3;
    {PROTOBUF_FIELD_OFFSET(std_msg, _impl_.timestamp_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::google::protobuf::Timestamp>()},
  }}, {{
    "\23\10\0\0\0\0\0\0"
    "hansolo_std.std_msg"
    "dataType"
  }},
};

::uint8_t* std_msg::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:hansolo_std.std_msg)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string dataType = 1;
  if (!this->_internal_datatype().empty()) {
    const std::string& _s = this->_internal_datatype();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "hansolo_std.std_msg.dataType");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  // int32 data = 2;
  if (this->_internal_data() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<2>(
            stream, this->_internal_data(), target);
  }

  cached_has_bits = _impl_._has_bits_[0];
  // .google.protobuf.Timestamp timeStamp = 3;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
        3, _Internal::timestamp(this),
        _Internal::timestamp(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:hansolo_std.std_msg)
  return target;
}

::size_t std_msg::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:hansolo_std.std_msg)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string dataType = 1;
  if (!this->_internal_datatype().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_datatype());
  }

  // .google.protobuf.Timestamp timeStamp = 3;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size +=
        1 + ::google::protobuf::internal::WireFormatLite::MessageSize(*_impl_.timestamp_);
  }

  // int32 data = 2;
  if (this->_internal_data() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_data());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData std_msg::_class_data_ = {
    std_msg::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* std_msg::GetClassData() const {
  return &_class_data_;
}

void std_msg::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<std_msg*>(&to_msg);
  auto& from = static_cast<const std_msg&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:hansolo_std.std_msg)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_datatype().empty()) {
    _this->_internal_set_datatype(from._internal_datatype());
  }
  if ((from._impl_._has_bits_[0] & 0x00000001u) != 0) {
    _this->_internal_mutable_timestamp()->::google::protobuf::Timestamp::MergeFrom(
        from._internal_timestamp());
  }
  if (from._internal_data() != 0) {
    _this->_internal_set_data(from._internal_data());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void std_msg::CopyFrom(const std_msg& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:hansolo_std.std_msg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool std_msg::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* std_msg::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void std_msg::InternalSwap(std_msg* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.datatype_, &other->_impl_.datatype_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(std_msg, _impl_.data_)
      + sizeof(std_msg::_impl_.data_)
      - PROTOBUF_FIELD_OFFSET(std_msg, _impl_.timestamp_)>(
          reinterpret_cast<char*>(&_impl_.timestamp_),
          reinterpret_cast<char*>(&other->_impl_.timestamp_));
}

::google::protobuf::Metadata std_msg::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_test_5fmsg_2eproto_getter, &descriptor_table_test_5fmsg_2eproto_once,
      file_level_metadata_test_5fmsg_2eproto[0]);
}
// ===================================================================

class std_msg_array::_Internal {
 public:
  using HasBits = decltype(std::declval<std_msg_array>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(std_msg_array, _impl_._has_bits_);
  static const ::google::protobuf::Timestamp& timestamp(const std_msg_array* msg);
  static void set_has_timestamp(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

const ::google::protobuf::Timestamp& std_msg_array::_Internal::timestamp(const std_msg_array* msg) {
  return *msg->_impl_.timestamp_;
}
void std_msg_array::clear_timestamp() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (_impl_.timestamp_ != nullptr) _impl_.timestamp_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
std_msg_array::std_msg_array(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:hansolo_std.std_msg_array)
}
inline PROTOBUF_NDEBUG_INLINE std_msg_array::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        msg_{visibility, arena, from.msg_} {}

std_msg_array::std_msg_array(
    ::google::protobuf::Arena* arena,
    const std_msg_array& from)
    : ::google::protobuf::Message(arena) {
  std_msg_array* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::uint32_t cached_has_bits = _impl_._has_bits_[0];
  _impl_.timestamp_ = (cached_has_bits & 0x00000001u)
                ? CreateMaybeMessage<::google::protobuf::Timestamp>(arena, *from._impl_.timestamp_)
                : nullptr;

  // @@protoc_insertion_point(copy_constructor:hansolo_std.std_msg_array)
}
inline PROTOBUF_NDEBUG_INLINE std_msg_array::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        msg_{visibility, arena} {}

inline void std_msg_array::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.timestamp_ = {};
}
std_msg_array::~std_msg_array() {
  // @@protoc_insertion_point(destructor:hansolo_std.std_msg_array)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void std_msg_array::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  delete _impl_.timestamp_;
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void std_msg_array::Clear() {
// @@protoc_insertion_point(message_clear_start:hansolo_std.std_msg_array)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.msg_.Clear();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ABSL_DCHECK(_impl_.timestamp_ != nullptr);
    _impl_.timestamp_->Clear();
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* std_msg_array::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 2, 0, 2> std_msg_array::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(std_msg_array, _impl_._has_bits_),
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    2,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_std_msg_array_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // .google.protobuf.Timestamp timeStamp = 2;
    {::_pbi::TcParser::FastMtS1,
     {18, 0, 1, PROTOBUF_FIELD_OFFSET(std_msg_array, _impl_.timestamp_)}},
    // repeated .hansolo_std.std_msg msg = 1;
    {::_pbi::TcParser::FastMtR1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(std_msg_array, _impl_.msg_)}},
  }}, {{
    65535, 65535
  }}, {{
    // repeated .hansolo_std.std_msg msg = 1;
    {PROTOBUF_FIELD_OFFSET(std_msg_array, _impl_.msg_), -1, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
    // .google.protobuf.Timestamp timeStamp = 2;
    {PROTOBUF_FIELD_OFFSET(std_msg_array, _impl_.timestamp_), _Internal::kHasBitsOffset + 0, 1,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::hansolo_std::std_msg>()},
    {::_pbi::TcParser::GetTable<::google::protobuf::Timestamp>()},
  }}, {{
  }},
};

::uint8_t* std_msg_array::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:hansolo_std.std_msg_array)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // repeated .hansolo_std.std_msg msg = 1;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_msg_size()); i < n; i++) {
    const auto& repfield = this->_internal_msg().Get(i);
    target = ::google::protobuf::internal::WireFormatLite::
        InternalWriteMessage(1, repfield, repfield.GetCachedSize(), target, stream);
  }

  cached_has_bits = _impl_._has_bits_[0];
  // .google.protobuf.Timestamp timeStamp = 2;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
        2, _Internal::timestamp(this),
        _Internal::timestamp(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:hansolo_std.std_msg_array)
  return target;
}

::size_t std_msg_array::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:hansolo_std.std_msg_array)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .hansolo_std.std_msg msg = 1;
  total_size += 1UL * this->_internal_msg_size();
  for (const auto& msg : this->_internal_msg()) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  // .google.protobuf.Timestamp timeStamp = 2;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size +=
        1 + ::google::protobuf::internal::WireFormatLite::MessageSize(*_impl_.timestamp_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData std_msg_array::_class_data_ = {
    std_msg_array::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* std_msg_array::GetClassData() const {
  return &_class_data_;
}

void std_msg_array::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<std_msg_array*>(&to_msg);
  auto& from = static_cast<const std_msg_array&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:hansolo_std.std_msg_array)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_msg()->MergeFrom(
      from._internal_msg());
  if ((from._impl_._has_bits_[0] & 0x00000001u) != 0) {
    _this->_internal_mutable_timestamp()->::google::protobuf::Timestamp::MergeFrom(
        from._internal_timestamp());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void std_msg_array::CopyFrom(const std_msg_array& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:hansolo_std.std_msg_array)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool std_msg_array::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* std_msg_array::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void std_msg_array::InternalSwap(std_msg_array* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.msg_.InternalSwap(&other->_impl_.msg_);
  swap(_impl_.timestamp_, other->_impl_.timestamp_);
}

::google::protobuf::Metadata std_msg_array::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_test_5fmsg_2eproto_getter, &descriptor_table_test_5fmsg_2eproto_once,
      file_level_metadata_test_5fmsg_2eproto[1]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace hansolo_std
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
