
// CLib
#include <cstdio>
#include <cstdlib>
#include <cstring>

// STL
#include <iostream>
#include <string>

// VELaSSCo
#include "AccessLib.h"

// from Helpers.h
  // returns NULL if dst_len is too short, otherwise return dst
  static const char *ToHexString( char *dst, size_t dst_len, const char *src, const size_t src_len) {
    if ( !dst) return NULL;
    if ( dst_len <= 0) return NULL;
    size_t isrc = 0;
    for ( size_t idst = 0; 
	  ( isrc < src_len) && ( idst < dst_len - 1); 
	  isrc++, idst += 2) {
      sprintf( &dst[ idst], "%02x", ( unsigned char)src[ isrc]);
    }
    // if all chars converted, then return dst
    return ( isrc == src_len) ? dst : NULL;
  }
  static bool ModelID_IsBinary( const std::string &modelID) {
    return ( modelID.length() == 16);
  }
  static std::string ModelID_DoHexStringConversionIfNecesary( const std::string &modelID, char *tmp_buf, size_t size_tmp_buf) {
    if ( modelID.length() == 16) {
      return ( std::string) ToHexString( tmp_buf, size_tmp_buf, modelID.c_str(), modelID.size());
    } else {
      return modelID;
    }
  }

void CheckVALResult(VAL_Result result, const std::string &error_message = "")
{
  if (result != VAL_SUCCESS)
  {
    const char* message;
    valErrorMessage(result, &message);

    std::cout << "VELaSSCo ERROR: " << std::endl;
    std::cout << "  " << message    << std::endl;
    if ( error_message.length() > 0) {
      std::cout << "  Query message: " << error_message    << std::endl;
    }
    exit(EXIT_FAILURE);
  }
}


#ifdef _WIN32
#ifndef strcasecmp
#define strcasecmp  _stricmp
#endif
#endif // _WIN32

bool askForHelp( const char *txt) {
  return !strcasecmp( txt, "-h") || !strcasecmp( txt, "--h") || !strcasecmp( txt, "-help") || !strcasecmp( txt, "--help");
}

std::string getStringFromCharPointers( const char *str1, const char *str2) {
  return std::string( str1 ? str1 : "") + std::string( str2 ? str2 : "");
}

int main(int argc, char* argv[])
{
  VAL_Result    result;
  VAL_SessionID sessionID;

  //
  // Test UserLogin()
  //

  char hostname_port[ 1024];
  int remote_port = 9990; // default port
  int velassco_default_port  = 26267;
  if ( argc == 2) {
    if ( askForHelp( argv[ 1])) {
      printf( "Usage: %s [ hostname [ port (default %d, VELaSSCo EngineLayer/QueryManager default port = %d)]]\n", 
	      argv[ 0], remote_port, velassco_default_port);
      return EXIT_FAILURE;
    }
    sprintf( hostname_port, "%s:%d", argv[ 1], remote_port);
  } else if ( argc == 3) {
    sprintf( hostname_port, "%s:%s", argv[ 1], argv[ 2]);
  } else {
    strcpy( hostname_port, "localhost:9990");
  }

  printf( "Connecting to '%s' ...\n", hostname_port);

  result = valUserLogin( hostname_port, "andreas", "1234", &sessionID);
  CheckVALResult(result, "valUserLogin");

  // Test StatusDB

  const char *status = NULL;
  result = valGetStatusDB( sessionID, &status);
  CheckVALResult(result, getStringFromCharPointers( "valGetStatusDB ", status));
  std::cout << "status = " << status << std::endl;

  //
  // Test GetListOfModels()
  //
  const char *return_list = NULL;
  const char *group_qualifier = ""; // loop over all available 4 tables
  const char *name_pattern = "*";
  result = valGetListOfModels( sessionID, group_qualifier, name_pattern, &status, &return_list);
  CheckVALResult(result, getStringFromCharPointers( "valGetListOfModels ", status));
  std::cout << "in VELaSSCo_models:" << std::endl;
  std::cout << "   status = " << status << std::endl;
  std::cout << "   model_list = " << return_list << std::endl;
  // group_qualifier = "Test_VELaSSCo_Models";
  // result = valGetListOfModels( sessionID, group_qualifier, name_pattern, &status, &return_list);
  // CheckVALResult(result);
  // std::cout << "in VELaSSCo_Models_V4CIMNE:" << std::endl;
  // std::cout << "   status = " << status << std::endl;
  // std::cout << "   model_list = " << return_list << std::endl;
  
  // result = valGetStatusDB( sessionID, &status);
  // CheckVALResult(result);
  // std::cout << "status = " << status << std::endl;

  // 
  // Test OpenModel

  // unique_name is of the form ModelName or /Full/Path:ModelName or TableName:/Full/Path:ModelName
  // ModelName is Properties:fp
  // /Full/Path is Properties:nm
  // const char *unique_name = ""; // can be empty to get the first one
  // const char *unique_name = "*:*"; // can be empty to get the first one
  // const char *unique_name = "Test_VELaSSCo_Models:*:*"; // or using only the table's name and get the first one
  // const char *unique_name = "VELaSSCo_Models:/localfs/home/velassco/common/simulation_files/DEM_examples/FluidizedBed_small.p3c:*";
  // const char *unique_name = "VELaSSCo_Models:/localfs/home/velassco/common/simulation_files/DEM_examples/FluidizedBed_small.p3c:FluidizedBed_small.p3c";
  //const char *unique_name = "VELaSSCo_Models_V4CIMNE:/home/jsperez/Sources/CIMNE/VELASSCO-Data/VELaSSCo_HbaseBasicTest_FEM:VELaSSCo_HbaseBasicTest-part-";
  // const char *unique_name = "T_VELaSSCo_Models:/localfs/home/velassco/common/simulation_files/D2C/Data/Fluidized_Bed_Small:FluidizedBed";

  // const char *unique_name = "Test_VELaSSCo_Models:/localfs/home/velassco/common/simulation_files/DEM_examples/:FluidizedBed_small";
  // const char *unique_name = "Test_VELaSSCo_Models:localfs/home/velassco/common/simulation_files/:DEM_box";
  const char *unique_name = "Test_VELaSSCo_Models:/localfs/home/velassco/common/simulation_files/DEM_examples/Fluidized_Bed_Large/:FluidizedBed_large_1timestep";
  const char *access = "";
  const char *return_modelID = NULL;
  result = valOpenModel( sessionID, unique_name, access, &status, &return_modelID);
  std::cout << "OpenModel: " << std::endl;
  std::cout << "   status = " << status << std::endl;
  char hex_string[ 1024];
  if ( return_modelID) {
    std::cout << "   model_modelID = " << ModelID_DoHexStringConversionIfNecesary( return_modelID, hex_string, 1024) << std::endl;
  } else {
    // logout as it is not valid ...
    std::cout << "   ERROR model could not be opened, login out ..." << std::endl;
    result = valUserLogout(sessionID);
    CheckVALResult(result);
    
    return EXIT_SUCCESS;
  }

 // need to store as return_modelID points to a temporary storage that will be reused in next query
  std::string opened_modelID( return_modelID);

  //
  // Test GetResultFromVerticesID()
  //

  const char*   modelID     = "d94ca29be534ca1ed578e90123b7"; // current DEM_box example in VELaSSCo_Models as of 10.11.2015, two days ago there where two models !
  const char*   resultID    = "MASS";
  const char*   analysisID  = "DEM";
  const int64_t vertexIDs[] = { 1, 2, 3, 4, 5, 6, 7, 0 };
  const double  timeStep    = 10000.0;
  
  const int64_t* resultVertexIDs;
  const double*  resultValues;
  size_t         resultNumVertices;
  
  // This call does not comply with the VQuery form, but in the meantime ...
  result = valGetResultFromVerticesID(sessionID, modelID,
                                      resultID,
                                      analysisID,
                                      vertexIDs,
                                      timeStep,
                                      &resultVertexIDs,
                                      &resultValues,
                                      &resultNumVertices);
  CheckVALResult(result, "valGetResultFromVerticesID");
  
  //
  // Print received data
  //
  
  for (size_t i=0; i<resultNumVertices; i++)
  {
    std::cout << "Vertex: " << i;
    std::cout << "  ID: " << resultVertexIDs[i];
    std::cout << "  Values: [";
    for (size_t j=0; j<3; j++)
      std::cout << " " << resultValues[3*i+j];
    std::cout << " ]" << std::endl;
  }

  //
  // Test GetListOfMeshes
  //
  bool do_get_list_of_meshes = true;
  if ( do_get_list_of_meshes) {
    const char *return_list = NULL;
    const char *return_error_str = NULL;
    std::cout << "doing valGetListOfMeshes" << std::endl;
    const char *analysisID = ""; // for static meshes
    double stepValue = 0.0; // for static meshes
    // const char *analysisID = "DEM"; // for dynamic meshes
    // double stepValue = 0.0; // for dynamic meshes
    result = valGetListOfMeshes( sessionID, opened_modelID.c_str(),
				 analysisID, stepValue,
				 &return_error_str, &return_list);
    CheckVALResult(result, getStringFromCharPointers( "valGetListOfMeshes ", return_error_str));
    ModelID_DoHexStringConversionIfNecesary( opened_modelID, hex_string, 1024);
    std::cout << "GetListOfMeshes: " << opened_modelID << 
      ( ModelID_IsBinary( opened_modelID) ? " ( binary)" : " ( ascii)") << std::endl;
    if ( return_list) {
      std::cout << "   mesh_list = " << return_list << std::endl;
    } else {
      std::cout << "Error: " << return_error_str << std::endl;
    }
  }


  //
  // Test GetBoundingBox()
  //

  bool do_bbox = false;
  if ( do_bbox) {
    const double *return_bbox = NULL;
    const char *return_error_str = NULL;
    std::cout << "doing valGetBoundingBox" << std::endl;
    
    result = valGetBoundingBox( sessionID, opened_modelID.c_str(), // the already opened model
				NULL, 0, // use all vertices ID
				"", // don't care about analysisID
				"ALL", NULL, 0, // use all steps / or don't care
				&return_bbox, &return_error_str);
    CheckVALResult(result, getStringFromCharPointers( "valGetBoundingBox ", return_error_str));
    ModelID_DoHexStringConversionIfNecesary( opened_modelID, hex_string, 1024);
    std::cout << "GetBoundingBox: " << opened_modelID << 
      ( ModelID_IsBinary( opened_modelID) ? " ( binary)" : " ( ascii)") << std::endl;
    if ( return_bbox) {
      std::cout << "         bbox = ( " ;
      std::cout << return_bbox[ 0] << ", " << return_bbox[ 1] << ", " << return_bbox[ 2] << ") - ("
		<< return_bbox[ 3] << ", " << return_bbox[ 4] << ", " << return_bbox[ 5] << ")." << std::endl;
    } else {
      std::cout << "Error: " << return_error_str << std::endl;
    }
  }

  //
  // Test CloseModel() & UserLogout()
  //

  result = valCloseModel( sessionID, modelID, &status);
  CheckVALResult(result);
  std::cout << "CloseModel: " << std::endl;
  std::cout << "   status = " << status << std::endl;
  
  result = valUserLogout(sessionID);
  CheckVALResult(result);

  return EXIT_SUCCESS;
}
