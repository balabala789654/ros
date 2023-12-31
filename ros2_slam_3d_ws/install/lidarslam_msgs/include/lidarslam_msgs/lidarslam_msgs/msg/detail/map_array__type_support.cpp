// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from lidarslam_msgs:msg/MapArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "lidarslam_msgs/msg/detail/map_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace lidarslam_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MapArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) lidarslam_msgs::msg::MapArray(_init);
}

void MapArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<lidarslam_msgs::msg::MapArray *>(message_memory);
  typed_message->~MapArray();
}

size_t size_function__MapArray__submaps(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<lidarslam_msgs::msg::SubMap> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MapArray__submaps(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<lidarslam_msgs::msg::SubMap> *>(untyped_member);
  return &member[index];
}

void * get_function__MapArray__submaps(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<lidarslam_msgs::msg::SubMap> *>(untyped_member);
  return &member[index];
}

void fetch_function__MapArray__submaps(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const lidarslam_msgs::msg::SubMap *>(
    get_const_function__MapArray__submaps(untyped_member, index));
  auto & value = *reinterpret_cast<lidarslam_msgs::msg::SubMap *>(untyped_value);
  value = item;
}

void assign_function__MapArray__submaps(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<lidarslam_msgs::msg::SubMap *>(
    get_function__MapArray__submaps(untyped_member, index));
  const auto & value = *reinterpret_cast<const lidarslam_msgs::msg::SubMap *>(untyped_value);
  item = value;
}

void resize_function__MapArray__submaps(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<lidarslam_msgs::msg::SubMap> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MapArray_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidarslam_msgs::msg::MapArray, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "submaps",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<lidarslam_msgs::msg::SubMap>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidarslam_msgs::msg::MapArray, submaps),  // bytes offset in struct
    nullptr,  // default value
    size_function__MapArray__submaps,  // size() function pointer
    get_const_function__MapArray__submaps,  // get_const(index) function pointer
    get_function__MapArray__submaps,  // get(index) function pointer
    fetch_function__MapArray__submaps,  // fetch(index, &value) function pointer
    assign_function__MapArray__submaps,  // assign(index, value) function pointer
    resize_function__MapArray__submaps  // resize(index) function pointer
  },
  {
    "cloud_coordinate",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lidarslam_msgs::msg::MapArray, cloud_coordinate),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MapArray_message_members = {
  "lidarslam_msgs::msg",  // message namespace
  "MapArray",  // message name
  3,  // number of fields
  sizeof(lidarslam_msgs::msg::MapArray),
  MapArray_message_member_array,  // message members
  MapArray_init_function,  // function to initialize message memory (memory has to be allocated)
  MapArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MapArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MapArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace lidarslam_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<lidarslam_msgs::msg::MapArray>()
{
  return &::lidarslam_msgs::msg::rosidl_typesupport_introspection_cpp::MapArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lidarslam_msgs, msg, MapArray)() {
  return &::lidarslam_msgs::msg::rosidl_typesupport_introspection_cpp::MapArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
