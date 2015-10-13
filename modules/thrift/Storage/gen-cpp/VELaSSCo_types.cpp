/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "VELaSSCo_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>




FullyQualifiedModelName::~FullyQualifiedModelName() throw() {
}


void FullyQualifiedModelName::__set_name(const std::string& val) {
  this->name = val;
}

void FullyQualifiedModelName::__set_full_path(const std::string& val) {
  this->full_path = val;
}

void FullyQualifiedModelName::__set_modelID(const std::string& val) {
  this->modelID = val;
}

const char* FullyQualifiedModelName::ascii_fingerprint = "AB879940BD15B6B25691265F7384B271";
const uint8_t FullyQualifiedModelName::binary_fingerprint[16] = {0xAB,0x87,0x99,0x40,0xBD,0x15,0xB6,0xB2,0x56,0x91,0x26,0x5F,0x73,0x84,0xB2,0x71};

uint32_t FullyQualifiedModelName::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->full_path);
          this->__isset.full_path = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->modelID);
          this->__isset.modelID = true;
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

  return xfer;
}

uint32_t FullyQualifiedModelName::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("FullyQualifiedModelName");

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("full_path", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->full_path);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("modelID", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeBinary(this->modelID);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(FullyQualifiedModelName &a, FullyQualifiedModelName &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.full_path, b.full_path);
  swap(a.modelID, b.modelID);
  swap(a.__isset, b.__isset);
}

FullyQualifiedModelName::FullyQualifiedModelName(const FullyQualifiedModelName& other0) {
  name = other0.name;
  full_path = other0.full_path;
  modelID = other0.modelID;
  __isset = other0.__isset;
}
FullyQualifiedModelName& FullyQualifiedModelName::operator=(const FullyQualifiedModelName& other1) {
  name = other1.name;
  full_path = other1.full_path;
  modelID = other1.modelID;
  __isset = other1.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const FullyQualifiedModelName& obj) {
  using apache::thrift::to_string;
  out << "FullyQualifiedModelName(";
  out << "name=" << to_string(obj.name);
  out << ", " << "full_path=" << to_string(obj.full_path);
  out << ", " << "modelID=" << to_string(obj.modelID);
  out << ")";
  return out;
}


rvGetListOfModels::~rvGetListOfModels() throw() {
}


void rvGetListOfModels::__set_status(const std::string& val) {
  this->status = val;
}

void rvGetListOfModels::__set_report(const std::string& val) {
  this->report = val;
}

void rvGetListOfModels::__set_models(const std::vector<FullyQualifiedModelName> & val) {
  this->models = val;
}

const char* rvGetListOfModels::ascii_fingerprint = "979D51C4D7C36D568BA276F63093B227";
const uint8_t rvGetListOfModels::binary_fingerprint[16] = {0x97,0x9D,0x51,0xC4,0xD7,0xC3,0x6D,0x56,0x8B,0xA2,0x76,0xF6,0x30,0x93,0xB2,0x27};

uint32_t rvGetListOfModels::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->status);
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->report);
          this->__isset.report = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->models.clear();
            uint32_t _size2;
            ::apache::thrift::protocol::TType _etype5;
            xfer += iprot->readListBegin(_etype5, _size2);
            this->models.resize(_size2);
            uint32_t _i6;
            for (_i6 = 0; _i6 < _size2; ++_i6)
            {
              xfer += this->models[_i6].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.models = true;
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

  return xfer;
}

uint32_t rvGetListOfModels::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("rvGetListOfModels");

  xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->status);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("report", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->report);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("models", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->models.size()));
    std::vector<FullyQualifiedModelName> ::const_iterator _iter7;
    for (_iter7 = this->models.begin(); _iter7 != this->models.end(); ++_iter7)
    {
      xfer += (*_iter7).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(rvGetListOfModels &a, rvGetListOfModels &b) {
  using ::std::swap;
  swap(a.status, b.status);
  swap(a.report, b.report);
  swap(a.models, b.models);
  swap(a.__isset, b.__isset);
}

rvGetListOfModels::rvGetListOfModels(const rvGetListOfModels& other8) {
  status = other8.status;
  report = other8.report;
  models = other8.models;
  __isset = other8.__isset;
}
rvGetListOfModels& rvGetListOfModels::operator=(const rvGetListOfModels& other9) {
  status = other9.status;
  report = other9.report;
  models = other9.models;
  __isset = other9.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const rvGetListOfModels& obj) {
  using apache::thrift::to_string;
  out << "rvGetListOfModels(";
  out << "status=" << to_string(obj.status);
  out << ", " << "report=" << to_string(obj.report);
  out << ", " << "models=" << to_string(obj.models);
  out << ")";
  return out;
}


rvOpenModel::~rvOpenModel() throw() {
}


void rvOpenModel::__set_status(const std::string& val) {
  this->status = val;
}

void rvOpenModel::__set_report(const std::string& val) {
  this->report = val;
}

void rvOpenModel::__set_modelID(const std::string& val) {
  this->modelID = val;
}

const char* rvOpenModel::ascii_fingerprint = "AB879940BD15B6B25691265F7384B271";
const uint8_t rvOpenModel::binary_fingerprint[16] = {0xAB,0x87,0x99,0x40,0xBD,0x15,0xB6,0xB2,0x56,0x91,0x26,0x5F,0x73,0x84,0xB2,0x71};

uint32_t rvOpenModel::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->status);
          this->__isset.status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->report);
          this->__isset.report = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->modelID);
          this->__isset.modelID = true;
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

  return xfer;
}

uint32_t rvOpenModel::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  oprot->incrementRecursionDepth();
  xfer += oprot->writeStructBegin("rvOpenModel");

  xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->status);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("report", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->report);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("modelID", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeBinary(this->modelID);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  oprot->decrementRecursionDepth();
  return xfer;
}

void swap(rvOpenModel &a, rvOpenModel &b) {
  using ::std::swap;
  swap(a.status, b.status);
  swap(a.report, b.report);
  swap(a.modelID, b.modelID);
  swap(a.__isset, b.__isset);
}

rvOpenModel::rvOpenModel(const rvOpenModel& other10) {
  status = other10.status;
  report = other10.report;
  modelID = other10.modelID;
  __isset = other10.__isset;
}
rvOpenModel& rvOpenModel::operator=(const rvOpenModel& other11) {
  status = other11.status;
  report = other11.report;
  modelID = other11.modelID;
  __isset = other11.__isset;
  return *this;
}
std::ostream& operator<<(std::ostream& out, const rvOpenModel& obj) {
  using apache::thrift::to_string;
  out << "rvOpenModel(";
  out << "status=" << to_string(obj.status);
  out << ", " << "report=" << to_string(obj.report);
  out << ", " << "modelID=" << to_string(obj.modelID);
  out << ")";
  return out;
}


