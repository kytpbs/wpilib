// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// THIS FILE WAS AUTO-GENERATED BY ./ntcore/generate_topics.py. DO NOT MODIFY

#pragma once

#include <vector>

#include "networktables/IntegerArrayTopic.h"
#include "networktables/NetworkTableType.h"
#include "ntcore_cpp.h"

namespace nt {

inline IntegerArraySubscriber::IntegerArraySubscriber(
    NT_Subscriber handle, ParamType defaultValue)
    : Subscriber{handle},
      m_defaultValue{defaultValue.begin(), defaultValue.end()} {}

inline std::vector<int64_t> IntegerArraySubscriber::Get() const {
  return Get(m_defaultValue);
}

inline std::vector<int64_t> IntegerArraySubscriber::Get(
    ParamType defaultValue) const {
  return ::nt::GetIntegerArray(m_subHandle, defaultValue);
}

inline std::span<int64_t> IntegerArraySubscriber::Get(wpi::SmallVectorImpl<int64_t>& buf) const {
  return Get(buf, m_defaultValue);
}

inline std::span<int64_t> IntegerArraySubscriber::Get(wpi::SmallVectorImpl<int64_t>& buf, ParamType defaultValue) const {
  return nt::GetIntegerArray(m_subHandle, buf, defaultValue);
}

inline TimestampedIntegerArray IntegerArraySubscriber::GetAtomic() const {
  return GetAtomic(m_defaultValue);
}

inline TimestampedIntegerArray IntegerArraySubscriber::GetAtomic(
    ParamType defaultValue) const {
  return ::nt::GetAtomicIntegerArray(m_subHandle, defaultValue);
}

inline TimestampedIntegerArrayView IntegerArraySubscriber::GetAtomic(wpi::SmallVectorImpl<int64_t>& buf) const {
  return GetAtomic(buf, m_defaultValue);
}

inline TimestampedIntegerArrayView IntegerArraySubscriber::GetAtomic(wpi::SmallVectorImpl<int64_t>& buf, ParamType defaultValue) const {
  return nt::GetAtomicIntegerArray(m_subHandle, buf, defaultValue);
}

inline std::vector<TimestampedIntegerArray>
IntegerArraySubscriber::ReadQueue() {
  return ::nt::ReadQueueIntegerArray(m_subHandle);
}

inline IntegerArrayTopic IntegerArraySubscriber::GetTopic() const {
  return IntegerArrayTopic{::nt::GetTopicFromHandle(m_subHandle)};
}

inline IntegerArrayPublisher::IntegerArrayPublisher(NT_Publisher handle)
    : Publisher{handle} {}

inline void IntegerArrayPublisher::Set(ParamType value,
                                         int64_t time) {
  ::nt::SetIntegerArray(m_pubHandle, value, time);
}

inline void IntegerArrayPublisher::SetDefault(ParamType value) {
  ::nt::SetDefaultIntegerArray(m_pubHandle, value);
}

inline IntegerArrayTopic IntegerArrayPublisher::GetTopic() const {
  return IntegerArrayTopic{::nt::GetTopicFromHandle(m_pubHandle)};
}

inline IntegerArrayEntry::IntegerArrayEntry(
    NT_Entry handle, ParamType defaultValue)
    : IntegerArraySubscriber{handle, defaultValue},
      IntegerArrayPublisher{handle} {}

inline IntegerArrayTopic IntegerArrayEntry::GetTopic() const {
  return IntegerArrayTopic{::nt::GetTopicFromHandle(m_subHandle)};
}

inline void IntegerArrayEntry::Unpublish() {
  ::nt::Unpublish(m_pubHandle);
}

inline IntegerArraySubscriber IntegerArrayTopic::Subscribe(
    std::span<const int64_t> defaultValue,
    const PubSubOptions& options) {
  return IntegerArraySubscriber{
      ::nt::Subscribe(m_handle, NT_INTEGER_ARRAY, "int[]", options),
      defaultValue};
}
inline IntegerArraySubscriber IntegerArrayTopic::SubscribeEx(
    std::string_view typeString, std::span<const int64_t> defaultValue,
    const PubSubOptions& options) {
  return IntegerArraySubscriber{
      ::nt::Subscribe(m_handle, NT_INTEGER_ARRAY, typeString, options),
      defaultValue};
}

inline IntegerArrayPublisher IntegerArrayTopic::Publish(
    const PubSubOptions& options) {
  return IntegerArrayPublisher{
      ::nt::Publish(m_handle, NT_INTEGER_ARRAY, "int[]", options)};
}

inline IntegerArrayPublisher IntegerArrayTopic::PublishEx(
    std::string_view typeString,
    const wpi::json& properties, const PubSubOptions& options) {
  return IntegerArrayPublisher{
      ::nt::PublishEx(m_handle, NT_INTEGER_ARRAY, typeString, properties, options)};
}

inline IntegerArrayEntry IntegerArrayTopic::GetEntry(
    std::span<const int64_t> defaultValue,
    const PubSubOptions& options) {
  return IntegerArrayEntry{
      ::nt::GetEntry(m_handle, NT_INTEGER_ARRAY, "int[]", options),
      defaultValue};
}
inline IntegerArrayEntry IntegerArrayTopic::GetEntryEx(
    std::string_view typeString, std::span<const int64_t> defaultValue,
    const PubSubOptions& options) {
  return IntegerArrayEntry{
      ::nt::GetEntry(m_handle, NT_INTEGER_ARRAY, typeString, options),
      defaultValue};
}

}  // namespace nt
