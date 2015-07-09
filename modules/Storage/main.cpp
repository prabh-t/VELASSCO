#include <stdlib.h>
#include <stdio.h>

#include "VELaSSCo.h"

#include "hbaseaccess.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class VELaSSCoHandler : virtual public VELaSSCoIf {
public:
    
    hbaseaccess* hba;
    VELaSSCoHandler()
    {
        hba = new hbaseaccess();
    }
    
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
    void GetResultFormVerticesID(std::string& _return, const std::string& sessionID, const std::string& modelID, const std::string& analysisID, const double timeStep, const std::string& resultID, const std::string& listOfVertices)
    {
        // Your implementation goes here
        _return = hba->GetResultOnVerticesId(sessionID, modelID, analysisID, timeStep, resultID, listOfVertices);
    }
    
};

using namespace std;
int main(int argc, char **argv)
{
    int port = 6664;
    shared_ptr<VELaSSCoHandler> handler(new VELaSSCoHandler());
    shared_ptr<TProcessor> processor(new VELaSSCoProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    
    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve();
    return 0;
      return 0;
}


