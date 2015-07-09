/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef VELaSSCo_H
#define VELaSSCo_H

#include <thrift/TDispatchProcessor.h>
#include "velassco_types.h"



class VELaSSCoIf {
 public:
  virtual ~VELaSSCoIf() {}

  /**
   * Return the status of the different services
   * which run on the Data Layer.
   * @return string - returns a structured list of avialbe vertices,
   * 	with the attached list of double
   * 	if errors occur the contect is also returned here?
   * 
   * @param sessionID
   * @param modelID
   * @param analysisID
   * @param timeStep
   * @param resultID
   * @param listOfVertices
   */
  virtual void GetResultFormVerticesID(std::string& _return, const std::string& sessionID, const std::string& modelID, const std::string& analysisID, const double timeStep, const std::string& resultID, const std::string& listOfVertices) = 0;
};

class VELaSSCoIfFactory {
 public:
  typedef VELaSSCoIf Handler;

  virtual ~VELaSSCoIfFactory() {}

  virtual VELaSSCoIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(VELaSSCoIf* /* handler */) = 0;
};

class VELaSSCoIfSingletonFactory : virtual public VELaSSCoIfFactory {
 public:
  VELaSSCoIfSingletonFactory(const boost::shared_ptr<VELaSSCoIf>& iface) : iface_(iface) {}
  virtual ~VELaSSCoIfSingletonFactory() {}

  virtual VELaSSCoIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(VELaSSCoIf* /* handler */) {}

 protected:
  boost::shared_ptr<VELaSSCoIf> iface_;
};

class VELaSSCoNull : virtual public VELaSSCoIf {
 public:
  virtual ~VELaSSCoNull() {}
  void GetResultFormVerticesID(std::string& /* _return */, const std::string& /* sessionID */, const std::string& /* modelID */, const std::string& /* analysisID */, const double /* timeStep */, const std::string& /* resultID */, const std::string& /* listOfVertices */) {
    return;
  }
};

typedef struct _VELaSSCo_GetResultFormVerticesID_args__isset {
  _VELaSSCo_GetResultFormVerticesID_args__isset() : sessionID(false), modelID(false), analysisID(false), timeStep(false), resultID(false), listOfVertices(false) {}
  bool sessionID :1;
  bool modelID :1;
  bool analysisID :1;
  bool timeStep :1;
  bool resultID :1;
  bool listOfVertices :1;
} _VELaSSCo_GetResultFormVerticesID_args__isset;

class VELaSSCo_GetResultFormVerticesID_args {
 public:

  static const char* ascii_fingerprint; // = "028F20434CE844656C7FFE290B942938";
  static const uint8_t binary_fingerprint[16]; // = {0x02,0x8F,0x20,0x43,0x4C,0xE8,0x44,0x65,0x6C,0x7F,0xFE,0x29,0x0B,0x94,0x29,0x38};

  VELaSSCo_GetResultFormVerticesID_args(const VELaSSCo_GetResultFormVerticesID_args&);
  VELaSSCo_GetResultFormVerticesID_args& operator=(const VELaSSCo_GetResultFormVerticesID_args&);
  VELaSSCo_GetResultFormVerticesID_args() : sessionID(), modelID(), analysisID(), timeStep(0), resultID(), listOfVertices() {
  }

  virtual ~VELaSSCo_GetResultFormVerticesID_args() throw();
  std::string sessionID;
  std::string modelID;
  std::string analysisID;
  double timeStep;
  std::string resultID;
  std::string listOfVertices;

  _VELaSSCo_GetResultFormVerticesID_args__isset __isset;

  void __set_sessionID(const std::string& val);

  void __set_modelID(const std::string& val);

  void __set_analysisID(const std::string& val);

  void __set_timeStep(const double val);

  void __set_resultID(const std::string& val);

  void __set_listOfVertices(const std::string& val);

  bool operator == (const VELaSSCo_GetResultFormVerticesID_args & rhs) const
  {
    if (!(sessionID == rhs.sessionID))
      return false;
    if (!(modelID == rhs.modelID))
      return false;
    if (!(analysisID == rhs.analysisID))
      return false;
    if (!(timeStep == rhs.timeStep))
      return false;
    if (!(resultID == rhs.resultID))
      return false;
    if (!(listOfVertices == rhs.listOfVertices))
      return false;
    return true;
  }
  bool operator != (const VELaSSCo_GetResultFormVerticesID_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const VELaSSCo_GetResultFormVerticesID_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const VELaSSCo_GetResultFormVerticesID_args& obj);
};


class VELaSSCo_GetResultFormVerticesID_pargs {
 public:

  static const char* ascii_fingerprint; // = "028F20434CE844656C7FFE290B942938";
  static const uint8_t binary_fingerprint[16]; // = {0x02,0x8F,0x20,0x43,0x4C,0xE8,0x44,0x65,0x6C,0x7F,0xFE,0x29,0x0B,0x94,0x29,0x38};


  virtual ~VELaSSCo_GetResultFormVerticesID_pargs() throw();
  const std::string* sessionID;
  const std::string* modelID;
  const std::string* analysisID;
  const double* timeStep;
  const std::string* resultID;
  const std::string* listOfVertices;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const VELaSSCo_GetResultFormVerticesID_pargs& obj);
};

typedef struct _VELaSSCo_GetResultFormVerticesID_result__isset {
  _VELaSSCo_GetResultFormVerticesID_result__isset() : success(false) {}
  bool success :1;
} _VELaSSCo_GetResultFormVerticesID_result__isset;

class VELaSSCo_GetResultFormVerticesID_result {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};

  VELaSSCo_GetResultFormVerticesID_result(const VELaSSCo_GetResultFormVerticesID_result&);
  VELaSSCo_GetResultFormVerticesID_result& operator=(const VELaSSCo_GetResultFormVerticesID_result&);
  VELaSSCo_GetResultFormVerticesID_result() : success() {
  }

  virtual ~VELaSSCo_GetResultFormVerticesID_result() throw();
  std::string success;

  _VELaSSCo_GetResultFormVerticesID_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const VELaSSCo_GetResultFormVerticesID_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const VELaSSCo_GetResultFormVerticesID_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const VELaSSCo_GetResultFormVerticesID_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const VELaSSCo_GetResultFormVerticesID_result& obj);
};

typedef struct _VELaSSCo_GetResultFormVerticesID_presult__isset {
  _VELaSSCo_GetResultFormVerticesID_presult__isset() : success(false) {}
  bool success :1;
} _VELaSSCo_GetResultFormVerticesID_presult__isset;

class VELaSSCo_GetResultFormVerticesID_presult {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};


  virtual ~VELaSSCo_GetResultFormVerticesID_presult() throw();
  std::string* success;

  _VELaSSCo_GetResultFormVerticesID_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const VELaSSCo_GetResultFormVerticesID_presult& obj);
};

class VELaSSCoClient : virtual public VELaSSCoIf {
 public:
  VELaSSCoClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  VELaSSCoClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void GetResultFormVerticesID(std::string& _return, const std::string& sessionID, const std::string& modelID, const std::string& analysisID, const double timeStep, const std::string& resultID, const std::string& listOfVertices);
  void send_GetResultFormVerticesID(const std::string& sessionID, const std::string& modelID, const std::string& analysisID, const double timeStep, const std::string& resultID, const std::string& listOfVertices);
  void recv_GetResultFormVerticesID(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class VELaSSCoProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<VELaSSCoIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (VELaSSCoProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_GetResultFormVerticesID(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  VELaSSCoProcessor(boost::shared_ptr<VELaSSCoIf> iface) :
    iface_(iface) {
    processMap_["GetResultFormVerticesID"] = &VELaSSCoProcessor::process_GetResultFormVerticesID;
  }

  virtual ~VELaSSCoProcessor() {}
};

class VELaSSCoProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  VELaSSCoProcessorFactory(const ::boost::shared_ptr< VELaSSCoIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< VELaSSCoIfFactory > handlerFactory_;
};

class VELaSSCoMultiface : virtual public VELaSSCoIf {
 public:
  VELaSSCoMultiface(std::vector<boost::shared_ptr<VELaSSCoIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~VELaSSCoMultiface() {}
 protected:
  std::vector<boost::shared_ptr<VELaSSCoIf> > ifaces_;
  VELaSSCoMultiface() {}
  void add(boost::shared_ptr<VELaSSCoIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void GetResultFormVerticesID(std::string& _return, const std::string& sessionID, const std::string& modelID, const std::string& analysisID, const double timeStep, const std::string& resultID, const std::string& listOfVertices) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetResultFormVerticesID(_return, sessionID, modelID, analysisID, timeStep, resultID, listOfVertices);
    }
    ifaces_[i]->GetResultFormVerticesID(_return, sessionID, modelID, analysisID, timeStep, resultID, listOfVertices);
    return;
  }

};



#endif
