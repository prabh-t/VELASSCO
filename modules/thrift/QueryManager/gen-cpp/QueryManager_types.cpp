/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "QueryManager_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace VELaSSCo {

int _kResultValues[] = {
  Result::SUCCESS,
  Result::FAILURE
};
const char* _kResultNames[] = {
  "SUCCESS",
  "FAILURE"
};
const std::map<int, const char*> _Result_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kResultValues, _kResultNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));


UserLogin_Result::~UserLogin_Result() throw() {
}


void UserLogin_Result::__set_result(const Result::type val) {
  this->result = val;
}

void UserLogin_Result::__set_sessionID(const SessionID val) {
  this->sessionID = val;
__isset.sessionID = true;
}

const char* UserLogin_Result::ascii_fingerprint = "1662AAADFABAB647546029B578B3B69B";
const uint8_t UserLogin_Result::binary_fingerprint[16] = {0x16,0x62,0xAA,0xAD,0xFA,0xBA,0xB6,0x47,0x54,0x60,0x29,0xB5,0x78,0xB3,0xB6,0x9B};

uint32_t UserLogin_Result::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_result = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->result = (Result::type)ecast0;
          isset_result = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sessionID);
          this->__isset.sessionID = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_result)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t UserLogin_Result::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("UserLogin_Result");

  xfer += oprot->writeFieldBegin("result", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->result);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.sessionID) {
    xfer += oprot->writeFieldBegin("sessionID", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->sessionID);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(UserLogin_Result &a, UserLogin_Result &b) {
  using ::std::swap;
  swap(a.result, b.result);
  swap(a.sessionID, b.sessionID);
  swap(a.__isset, b.__isset);
}

UserLogin_Result::UserLogin_Result(const UserLogin_Result& other1) {
  result = other1.result;
  sessionID = other1.sessionID;
  __isset = other1.__isset;
}
UserLogin_Result& UserLogin_Result::operator=(const UserLogin_Result& other2) {
  result = other2.result;
  sessionID = other2.sessionID;
  __isset = other2.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const UserLogin_Result& obj) {
  using apache::thrift::to_string;
  out << "UserLogin_Result(";
  out << "result=" << to_string(obj.result);
  out << ", " << "sessionID="; (obj.__isset.sessionID ? (out << to_string(obj.sessionID)) : (out << "<null>"));
  out << ")";
  return out;
}


UserLogout_Result::~UserLogout_Result() throw() {
}


void UserLogout_Result::__set_result(const Result::type val) {
  this->result = val;
}

const char* UserLogout_Result::ascii_fingerprint = "8BBB3D0C3B370CB38F2D1340BB79F0AA";
const uint8_t UserLogout_Result::binary_fingerprint[16] = {0x8B,0xBB,0x3D,0x0C,0x3B,0x37,0x0C,0xB3,0x8F,0x2D,0x13,0x40,0xBB,0x79,0xF0,0xAA};

uint32_t UserLogout_Result::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_result = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast3;
          xfer += iprot->readI32(ecast3);
          this->result = (Result::type)ecast3;
          isset_result = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_result)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t UserLogout_Result::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("UserLogout_Result");

  xfer += oprot->writeFieldBegin("result", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->result);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(UserLogout_Result &a, UserLogout_Result &b) {
  using ::std::swap;
  swap(a.result, b.result);
}

UserLogout_Result::UserLogout_Result(const UserLogout_Result& other4) {
  result = other4.result;
}
UserLogout_Result& UserLogout_Result::operator=(const UserLogout_Result& other5) {
  result = other5.result;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const UserLogout_Result& obj) {
  using apache::thrift::to_string;
  out << "UserLogout_Result(";
  out << "result=" << to_string(obj.result);
  out << ")";
  return out;
}


Query_Result::~Query_Result() throw() {
}


void Query_Result::__set_result(const Result::type val) {
  this->result = val;
}

void Query_Result::__set_data(const std::string& val) {
  this->data = val;
__isset.data = true;
}

const char* Query_Result::ascii_fingerprint = "24652790C81ECE22B629CB60A19F1E93";
const uint8_t Query_Result::binary_fingerprint[16] = {0x24,0x65,0x27,0x90,0xC8,0x1E,0xCE,0x22,0xB6,0x29,0xCB,0x60,0xA1,0x9F,0x1E,0x93};

uint32_t Query_Result::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_result = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast6;
          xfer += iprot->readI32(ecast6);
          this->result = (Result::type)ecast6;
          isset_result = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->data);
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_result)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t Query_Result::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("Query_Result");

  xfer += oprot->writeFieldBegin("result", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->result);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.data) {
    xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeBinary(this->data);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(Query_Result &a, Query_Result &b) {
  using ::std::swap;
  swap(a.result, b.result);
  swap(a.data, b.data);
  swap(a.__isset, b.__isset);
}

Query_Result::Query_Result(const Query_Result& other7) {
  result = other7.result;
  data = other7.data;
  __isset = other7.__isset;
}
Query_Result& Query_Result::operator=(const Query_Result& other8) {
  result = other8.result;
  data = other8.data;
  __isset = other8.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const Query_Result& obj) {
  using apache::thrift::to_string;
  out << "Query_Result(";
  out << "result=" << to_string(obj.result);
  out << ", " << "data="; (obj.__isset.data ? (out << to_string(obj.data)) : (out << "<null>"));
  out << ")";
  return out;
}


StatusDB_Result::~StatusDB_Result() throw() {
}


void StatusDB_Result::__set_result(const Result::type val) {
  this->result = val;
}

void StatusDB_Result::__set_status(const std::string& val) {
  this->status = val;
__isset.status = true;
}

const char* StatusDB_Result::ascii_fingerprint = "24652790C81ECE22B629CB60A19F1E93";
const uint8_t StatusDB_Result::binary_fingerprint[16] = {0x24,0x65,0x27,0x90,0xC8,0x1E,0xCE,0x22,0xB6,0x29,0xCB,0x60,0xA1,0x9F,0x1E,0x93};

uint32_t StatusDB_Result::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_result = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast9;
          xfer += iprot->readI32(ecast9);
          this->result = (Result::type)ecast9;
          isset_result = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->status);
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_result)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t StatusDB_Result::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("StatusDB_Result");

  xfer += oprot->writeFieldBegin("result", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->result);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.status) {
    xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->status);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(StatusDB_Result &a, StatusDB_Result &b) {
  using ::std::swap;
  swap(a.result, b.result);
  swap(a.status, b.status);
  swap(a.__isset, b.__isset);
}

StatusDB_Result::StatusDB_Result(const StatusDB_Result& other10) {
  result = other10.result;
  status = other10.status;
  __isset = other10.__isset;
}
StatusDB_Result& StatusDB_Result::operator=(const StatusDB_Result& other11) {
  result = other11.result;
  status = other11.status;
  __isset = other11.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const StatusDB_Result& obj) {
  using apache::thrift::to_string;
  out << "StatusDB_Result(";
  out << "result=" << to_string(obj.result);
  out << ", " << "status="; (obj.__isset.status ? (out << to_string(obj.status)) : (out << "<null>"));
  out << ")";
  return out;
}


StopVELaSSCo_Result::~StopVELaSSCo_Result() throw() {
}


void StopVELaSSCo_Result::__set_result(const Result::type val) {
  this->result = val;
}

void StopVELaSSCo_Result::__set_status(const std::string& val) {
  this->status = val;
__isset.status = true;
}

const char* StopVELaSSCo_Result::ascii_fingerprint = "24652790C81ECE22B629CB60A19F1E93";
const uint8_t StopVELaSSCo_Result::binary_fingerprint[16] = {0x24,0x65,0x27,0x90,0xC8,0x1E,0xCE,0x22,0xB6,0x29,0xCB,0x60,0xA1,0x9F,0x1E,0x93};

uint32_t StopVELaSSCo_Result::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_result = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast12;
          xfer += iprot->readI32(ecast12);
          this->result = (Result::type)ecast12;
          isset_result = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->status);
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_result)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t StopVELaSSCo_Result::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("StopVELaSSCo_Result");

  xfer += oprot->writeFieldBegin("result", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->result);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.status) {
    xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->status);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(StopVELaSSCo_Result &a, StopVELaSSCo_Result &b) {
  using ::std::swap;
  swap(a.result, b.result);
  swap(a.status, b.status);
  swap(a.__isset, b.__isset);
}

StopVELaSSCo_Result::StopVELaSSCo_Result(const StopVELaSSCo_Result& other13) {
  result = other13.result;
  status = other13.status;
  __isset = other13.__isset;
}
StopVELaSSCo_Result& StopVELaSSCo_Result::operator=(const StopVELaSSCo_Result& other14) {
  result = other14.result;
  status = other14.status;
  __isset = other14.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const StopVELaSSCo_Result& obj) {
  using apache::thrift::to_string;
  out << "StopVELaSSCo_Result(";
  out << "result=" << to_string(obj.result);
  out << ", " << "status="; (obj.__isset.status ? (out << to_string(obj.status)) : (out << "<null>"));
  out << ")";
  return out;
}

} // namespace
