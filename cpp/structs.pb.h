// Generated by the protocol buffer compiler.  DO NOT EDIT!

#ifndef PROTOBUF_structs_2eproto__INCLUDED
#define PROTOBUF_structs_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>

namespace man {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_structs_2eproto();
void protobuf_AssignDesc_structs_2eproto();
void protobuf_ShutdownFile_structs_2eproto();

class Point;
class Rectangle;

// ===================================================================

class Point : public ::google::protobuf::Message {
 public:
  Point();
  virtual ~Point();
  
  Point(const Point& from);
  
  inline Point& operator=(const Point& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Point& default_instance();
  void Swap(Point* other);
  
  // implements Message ----------------------------------------------
  
  Point* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Point& from);
  void MergeFrom(const Point& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const { _cached_size_ = size; }
  public:
  
  const ::google::protobuf::Descriptor* GetDescriptor() const;
  const ::google::protobuf::Reflection* GetReflection() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required int32 x = 1;
  inline bool has_x() const;
  inline void clear_x();
  static const int kXFieldNumber = 1;
  inline ::google::protobuf::int32 x() const;
  inline void set_x(::google::protobuf::int32 value);
  
  // required int32 y = 2;
  inline bool has_y() const;
  inline void clear_y();
  static const int kYFieldNumber = 2;
  inline ::google::protobuf::int32 y() const;
  inline void set_y(::google::protobuf::int32 value);
  
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::google::protobuf::int32 x_;
  ::google::protobuf::int32 y_;
  friend void  protobuf_AddDesc_structs_2eproto();
  friend void protobuf_AssignDesc_structs_2eproto();
  friend void protobuf_ShutdownFile_structs_2eproto();
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static Point* default_instance_;
};
// -------------------------------------------------------------------

class Rectangle : public ::google::protobuf::Message {
 public:
  Rectangle();
  virtual ~Rectangle();
  
  Rectangle(const Rectangle& from);
  
  inline Rectangle& operator=(const Rectangle& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Rectangle& default_instance();
  void Swap(Rectangle* other);
  
  // implements Message ----------------------------------------------
  
  Rectangle* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Rectangle& from);
  void MergeFrom(const Rectangle& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const { _cached_size_ = size; }
  public:
  
  const ::google::protobuf::Descriptor* GetDescriptor() const;
  const ::google::protobuf::Reflection* GetReflection() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required .man.Point leftTop = 1;
  inline bool has_lefttop() const;
  inline void clear_lefttop();
  static const int kLeftTopFieldNumber = 1;
  inline const ::man::Point& lefttop() const;
  inline ::man::Point* mutable_lefttop();
  
  // required .man.Point rightTop = 2;
  inline bool has_righttop() const;
  inline void clear_righttop();
  static const int kRightTopFieldNumber = 2;
  inline const ::man::Point& righttop() const;
  inline ::man::Point* mutable_righttop();
  
  // required .man.Point leftBottom = 3;
  inline bool has_leftbottom() const;
  inline void clear_leftbottom();
  static const int kLeftBottomFieldNumber = 3;
  inline const ::man::Point& leftbottom() const;
  inline ::man::Point* mutable_leftbottom();
  
  // required .man.Point rightBottom = 4;
  inline bool has_rightbottom() const;
  inline void clear_rightbottom();
  static const int kRightBottomFieldNumber = 4;
  inline const ::man::Point& rightbottom() const;
  inline ::man::Point* mutable_rightbottom();
  
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::man::Point* lefttop_;
  ::man::Point* righttop_;
  ::man::Point* leftbottom_;
  ::man::Point* rightbottom_;
  friend void  protobuf_AddDesc_structs_2eproto();
  friend void protobuf_AssignDesc_structs_2eproto();
  friend void protobuf_ShutdownFile_structs_2eproto();
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static Rectangle* default_instance_;
};
// ===================================================================


// ===================================================================


// ===================================================================

// Point

// required int32 x = 1;
inline bool Point::has_x() const {
  return _has_bit(0);
}
inline void Point::clear_x() {
  x_ = 0;
  _clear_bit(0);
}
inline ::google::protobuf::int32 Point::x() const {
  return x_;
}
inline void Point::set_x(::google::protobuf::int32 value) {
  _set_bit(0);
  x_ = value;
}

// required int32 y = 2;
inline bool Point::has_y() const {
  return _has_bit(1);
}
inline void Point::clear_y() {
  y_ = 0;
  _clear_bit(1);
}
inline ::google::protobuf::int32 Point::y() const {
  return y_;
}
inline void Point::set_y(::google::protobuf::int32 value) {
  _set_bit(1);
  y_ = value;
}

// -------------------------------------------------------------------

// Rectangle

// required .man.Point leftTop = 1;
inline bool Rectangle::has_lefttop() const {
  return _has_bit(0);
}
inline void Rectangle::clear_lefttop() {
  if (lefttop_ != NULL) lefttop_->::man::Point::Clear();
  _clear_bit(0);
}
inline const ::man::Point& Rectangle::lefttop() const {
  return lefttop_ != NULL ? *lefttop_ : *default_instance_->lefttop_;
}
inline ::man::Point* Rectangle::mutable_lefttop() {
  _set_bit(0);
  if (lefttop_ == NULL) lefttop_ = new ::man::Point;
  return lefttop_;
}

// required .man.Point rightTop = 2;
inline bool Rectangle::has_righttop() const {
  return _has_bit(1);
}
inline void Rectangle::clear_righttop() {
  if (righttop_ != NULL) righttop_->::man::Point::Clear();
  _clear_bit(1);
}
inline const ::man::Point& Rectangle::righttop() const {
  return righttop_ != NULL ? *righttop_ : *default_instance_->righttop_;
}
inline ::man::Point* Rectangle::mutable_righttop() {
  _set_bit(1);
  if (righttop_ == NULL) righttop_ = new ::man::Point;
  return righttop_;
}

// required .man.Point leftBottom = 3;
inline bool Rectangle::has_leftbottom() const {
  return _has_bit(2);
}
inline void Rectangle::clear_leftbottom() {
  if (leftbottom_ != NULL) leftbottom_->::man::Point::Clear();
  _clear_bit(2);
}
inline const ::man::Point& Rectangle::leftbottom() const {
  return leftbottom_ != NULL ? *leftbottom_ : *default_instance_->leftbottom_;
}
inline ::man::Point* Rectangle::mutable_leftbottom() {
  _set_bit(2);
  if (leftbottom_ == NULL) leftbottom_ = new ::man::Point;
  return leftbottom_;
}

// required .man.Point rightBottom = 4;
inline bool Rectangle::has_rightbottom() const {
  return _has_bit(3);
}
inline void Rectangle::clear_rightbottom() {
  if (rightbottom_ != NULL) rightbottom_->::man::Point::Clear();
  _clear_bit(3);
}
inline const ::man::Point& Rectangle::rightbottom() const {
  return rightbottom_ != NULL ? *rightbottom_ : *default_instance_->rightbottom_;
}
inline ::man::Point* Rectangle::mutable_rightbottom() {
  _set_bit(3);
  if (rightbottom_ == NULL) rightbottom_ = new ::man::Point;
  return rightbottom_;
}


}  // namespace man
#endif  // PROTOBUF_structs_2eproto__INCLUDED
