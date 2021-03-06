#include <sstream>
#include <stddef.h>  // defines NULL
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <vector>

#include "Helpers.h"
#include "Graphics.h"

using namespace VELaSSCo::Graphics;

// Global static pointer used to ensure a single instance of the class.
GraphicsModule *GraphicsModule::m_pInstance = NULL;

GraphicsModule *GraphicsModule::getInstance() {
  // Only allow one instance of class to be generated.
  std::cout << "in GraphicsModule::getInstance" << std::endl;
  if ( !m_pInstance) {
    m_pInstance = new GraphicsModule;
  }
  return m_pInstance;
}

void GraphicsModule::fromatMeshForDrawing(VELaSSCo::RTFormat::File& _return_, const MeshInfo& meshInfo, 
  const std::vector<std::vector<Vertex>>& vertices, const std::vector<Element>& elements, 
  const std::vector<ElementAttrib>& elementAttribs, const std::vector<ElementGroup>& elementGroupInfos)
{	
	
	switch(meshInfo.elementType.shape){
	case ElementShapeType::type::SphereElement:
		fromatSphereMeshForDrawing(_return_, meshInfo, vertices[0], elements, elementAttribs);
		break;
		
	case ElementShapeType::type::TetrahedraElement:
	    fromatTetrahedraMeshForDrawing(_return_, meshInfo, vertices[0], elements, elementAttribs);
		break;

	case ElementShapeType::type::PointElement:
	case ElementShapeType::type::LineElement:
	case ElementShapeType::type::TriangleElement:
	    fromatElementaryMeshForDrawing(_return_, meshInfo, vertices, elements, elementAttribs);
	    break;
		
	case ElementShapeType::type::UnknownElement:
	case ElementShapeType::type::QuadrilateralElement:
	case ElementShapeType::type::HexahedraElement:
	case ElementShapeType::type::PrismElement:
	case ElementShapeType::type::PyramidElement:
	case ElementShapeType::type::CircleElement:
	case ElementShapeType::type::ComplexParticleElement:
	default:
	    std::cout << "not implemented.\n";
	    return;
	}
	
	
}

static int getNumberOfIndicesPerElement(const MeshInfo& meshInfo){
	int num_indices_per_element = meshInfo.elementType.num_nodes;
	if(num_indices_per_element <= 0){
		switch(meshInfo.elementType.shape){
		case ElementShapeType::type::SphereElement:
			num_indices_per_element = 1;
			break;
		
		case ElementShapeType::type::TetrahedraElement:
			num_indices_per_element = 4;
			break;

		case ElementShapeType::type::PointElement:
			num_indices_per_element = 1;
			break;
		
		case ElementShapeType::type::LineElement:
			num_indices_per_element = 2;
			break;
			
		case ElementShapeType::type::TriangleElement:
			num_indices_per_element = 3;
			break;
		
		case ElementShapeType::type::UnknownElement:
			num_indices_per_element = -1;
			break;
		
		case ElementShapeType::type::QuadrilateralElement:
			num_indices_per_element = 4;
			break;
		
		case ElementShapeType::type::HexahedraElement:
			num_indices_per_element = 4;
			break;
		
		case ElementShapeType::type::PrismElement:
			num_indices_per_element = 6;
			break;
		
		case ElementShapeType::type::PyramidElement:
			num_indices_per_element = 5;
			break;
		
		case ElementShapeType::type::CircleElement:
			num_indices_per_element = 3;
			break;
		
		case ElementShapeType::type::ComplexParticleElement:
			num_indices_per_element = -1;
			break;
		}
	}
	
	return num_indices_per_element;
}

void GraphicsModule::fromatElementaryMeshForDrawing(VELaSSCo::RTFormat::File& _return_, const MeshInfo& meshInfo, 
  const std::vector<std::vector<Vertex>>& vertices, const std::vector<Element>& elements, 
  const std::vector<ElementAttrib>& elementAttribs)
{
	std::cout << "============>22\n";
        // const size_t num_vertices    = vertices.size();
	const size_t num_elements    = elements.size();
	// const size_t num_attribs     = elementAttribs.size();
	//size_t num_groupInfos  = elementInfos.size();
	
	std::vector<std::map<int64_t, int64_t>> vertexIdx_map( vertices.size() );
	
	// Total number of vertices
	size_t num_vertices = 0;
	for(size_t i = 0; i < vertices.size(); i++){
	  num_vertices += vertices[i].size();
	}
	
	// Fill vertex buffer
	std::vector<VertexElement> vertexElements( num_vertices );
	size_t vertex_idx = 0;
	for(size_t i = 0; i < vertices.size(); i++){
	  for(size_t j = 0; j < vertices[i].size(); j++){
		vertexElements[vertex_idx].x = vertices[i][j].x;
		vertexElements[vertex_idx].y = vertices[i][j].y;
		vertexElements[vertex_idx].z = vertices[i][j].z;
		vertexElements[vertex_idx].vertexID = vertices[i][j].id;
		vertexIdx_map[i][ vertexElements[vertex_idx].vertexID ] = vertex_idx;
		vertex_idx++;
	  }
	}
	
	std::cout << "2das=d=asd=as\n";
	
	int num_indices_per_element = getNumberOfIndicesPerElement(meshInfo);
	std::vector<int64_t> strips( num_elements * (num_indices_per_element + 1) );

	for(size_t idx = 0; idx < elements.size(); idx++){
		
		if(meshInfo.name == "p2p contacts"){
			strips[idx * (num_indices_per_element+1) + 0] = vertexIdx_map[0][ elements[idx].nodes_ids[0] ];
			strips[idx * (num_indices_per_element+1) + 1] = vertexIdx_map[1][ elements[idx].nodes_ids[2] ];
			strips[idx * (num_indices_per_element+1) + 2] = vertexIdx_map[0][ elements[idx].nodes_ids[1] ];
			strips[idx * (num_indices_per_element+1) + 3] = -1;
		} else if(meshInfo.name == "p2w contacts"){
			strips[idx * (num_indices_per_element+1) + 0] = vertexIdx_map[0][ elements[idx].nodes_ids[0] ];
			strips[idx * (num_indices_per_element+1) + 1] = vertexIdx_map[1][ elements[idx].nodes_ids[1] ];
			strips[idx * (num_indices_per_element+1) + 2] = -1;
		} else {
			int i = 0;
			for(; i < num_indices_per_element; i++){
				strips[idx * (num_indices_per_element+1) + i] = vertexIdx_map[0][ elements[idx].nodes_ids[i] ];
				//std::cout << strips[idx * (num_indices_per_element+1) + i] << std::endl;
			}
			strips[idx * (num_indices_per_element+1) + i] = -1;
	    }
		
	}
		
	char description[] =
		"# TEST PLY DATA                                        \n"
		"VertexDefinition         = position, vertexIdx         \n"
		"vertexDefinitionsType    = float3, int64               \n"	
		"OgLPrimitiveRestartIndex = -1                          \n";
	  
	  _return_.header.magic[0] = 'V';
	  _return_.header.magic[1] = 'E';
	  _return_.header.magic[2] = 'L';
	  _return_.header.magic[3] = 'a';
	  _return_.header.magic[4] = 'S';
	  _return_.header.magic[5] = 'S';
	  _return_.header.magic[6] = 'C';
	  _return_.header.magic[7] = 'o';

	  _return_.header.version = 100;
	  _return_.header.descriptionBytes = sizeof(description);

	  _return_.header.metaBytes = 0;

	  _return_.header.vertexDefinitionsBytes  = static_cast<uint64_t>(vertexElements.size() * sizeof(VertexElement));
	  _return_.header.vertexAttributesBytes   = 0;
	  _return_.header.cellDefinitionsBytes    = 0;
	  _return_.header.cellAttributesBytes     = 0;
	  
	  _return_.data.meta              = 0;
	  _return_.data.vertexDefinitions = new uint8_t[ _return_.header.vertexDefinitionsBytes ];
	  _return_.data.vertexAttributes  = 0;
	  _return_.data.cellDefinitions   = 0;
	  _return_.data.cellAttributes    = 0;
	  
	  switch(meshInfo.elementType.shape){
	  case ElementShapeType::type::PointElement:
		break;
	  case ElementShapeType::type::LineElement:
          //std::cout << "Line Element.\n";
		  _return_.header.edgeDefinitionsBytes    = static_cast<uint64_t>(strips.size() * sizeof(int64_t));
		  _return_.header.edgeAttributesBytes     = 0;
		  _return_.header.faceDefinitionsBytes    = 0;
		  _return_.header.faceAttributesBytes     = 0;
		  
		  _return_.data.edgeDefinitions   = new uint8_t[  _return_.header.edgeDefinitionsBytes ];;
		  _return_.data.edgeAttributes    = 0;
		  _return_.data.faceDefinitions   = 0;
		  _return_.data.faceAttributes    = 0;
		  
		  memcpy(_return_.data.edgeDefinitions, (const char*)strips.data(), _return_.header.edgeDefinitionsBytes);
		  		  
		  break;
	case ElementShapeType::type::TriangleElement:
		  _return_.header.edgeDefinitionsBytes    = 0;
		  _return_.header.edgeAttributesBytes     = 0;
		  _return_.header.faceDefinitionsBytes    = static_cast<uint64_t>(strips.size() * sizeof(int64_t));
		  _return_.header.faceAttributesBytes     = 0;
		  
		  _return_.data.edgeDefinitions   = 0;
		  _return_.data.edgeAttributes    = 0;
		  _return_.data.faceDefinitions   = new uint8_t[  _return_.header.faceDefinitionsBytes ];
		  _return_.data.faceAttributes    = 0;
		  		  		  
		  memcpy(_return_.data.faceDefinitions, (const char*)strips.data(), _return_.header.faceDefinitionsBytes);
		  break;
	  default: // not handled
	    // ElementShapeType::type::UnknownElement
	    // ElementShapeType::type::QuadrilateralElement
	    // ElementShapeType::type::TetrahedraElement
	    // ElementShapeType::type::HexahedraElement
	    // ElementShapeType::type::PrismElement
	    // ElementShapeType::type::PyramidElement
	    // ElementShapeType::type::SphereElement
	    // ElementShapeType::type::CircleElement
	    // ElementShapeType::type::ComplexParticleElement
	    break;
    }
    
    _return_.data.description       = new uint8_t[ _return_.header.descriptionBytes ];
    memcpy(_return_.data.description, description, _return_.header.descriptionBytes);
    memcpy(_return_.data.vertexDefinitions, (const char*)vertexElements.data(), _return_.header.vertexDefinitionsBytes);
	
}

void GraphicsModule::fromatTetrahedraMeshForDrawing(VELaSSCo::RTFormat::File& _return_, const MeshInfo& meshInfo, 
  const std::vector<Vertex>& vertices, const std::vector<Element>& elements, 
  const std::vector<ElementAttrib>& elementAttribs)
{
        // const size_t num_vertices    = vertices.size();
	const size_t num_elements    = elements.size();
	// const size_t num_attribs     = elementAttribs.size();
	//size_t num_groupInfos  = elementInfos.size();
	
	std::map<int64_t, int64_t> vertexIdx_map;
	
	std::vector<VertexElement> vertexElements( vertices.size() );
	for(size_t i = 0; i < vertices.size(); i++){
		vertexElements[i].x = vertices[i].x;
		vertexElements[i].y = vertices[i].y;
		vertexElements[i].z = vertices[i].z;
		vertexElements[i].vertexID = vertices[i].id;
		vertexIdx_map[ vertexElements[i].vertexID ] = i;
	}
	
	
	std::vector<int64_t> triangle_strips( num_elements * 7 );

	for(size_t idx = 0; idx < elements.size(); idx++){
		
		triangle_strips[idx * 7 + 0] = vertexIdx_map[ elements[idx].nodes_ids[0] ];
		triangle_strips[idx * 7 + 1] = vertexIdx_map[ elements[idx].nodes_ids[1] ];
		triangle_strips[idx * 7 + 2] = vertexIdx_map[ elements[idx].nodes_ids[3] ];
		triangle_strips[idx * 7 + 3] = vertexIdx_map[ elements[idx].nodes_ids[2] ];
		triangle_strips[idx * 7 + 4] = vertexIdx_map[ elements[idx].nodes_ids[0] ];
		triangle_strips[idx * 7 + 5] = vertexIdx_map[ elements[idx].nodes_ids[1] ];
		triangle_strips[idx * 7 + 6] = -1;
		
	}
		
	char description[] =
		"# TEST PLY DATA                                        \n"
		"VertexDefinition         = position, vertexIdx         \n"
		"vertexDefinitionsType    = float3, int64               \n"	
		"OgLPrimitiveRestartIndex = -1                          \n";
	  
	  _return_.header.magic[0] = 'V';
	  _return_.header.magic[1] = 'E';
	  _return_.header.magic[2] = 'L';
	  _return_.header.magic[3] = 'a';
	  _return_.header.magic[4] = 'S';
	  _return_.header.magic[5] = 'S';
	  _return_.header.magic[6] = 'C';
	  _return_.header.magic[7] = 'o';

	  _return_.header.version = 100;
	  _return_.header.descriptionBytes = sizeof(description);

	  _return_.header.metaBytes = 0;

	  _return_.header.vertexDefinitionsBytes  = static_cast<uint64_t>(vertexElements.size() * sizeof(VertexElement));
	  _return_.header.vertexAttributesBytes   = 0;
	  _return_.header.edgeDefinitionsBytes    = 0;
	  _return_.header.edgeAttributesBytes     = 0;
	  _return_.header.faceDefinitionsBytes    = static_cast<uint64_t>(triangle_strips.size() * sizeof(int64_t));
	  _return_.header.faceAttributesBytes     = 0;
	  _return_.header.cellDefinitionsBytes    = 0;
	  _return_.header.cellAttributesBytes     = 0;

	  _return_.data.description       = new uint8_t[ _return_.header.descriptionBytes ];
	  _return_.data.meta              = 0;
      _return_.data.vertexDefinitions = new uint8_t[ _return_.header.vertexDefinitionsBytes ];
	  _return_.data.vertexAttributes  = 0;
	  _return_.data.edgeDefinitions   = 0;
	  _return_.data.edgeAttributes    = 0;
	  _return_.data.faceDefinitions   = new uint8_t[  _return_.header.faceDefinitionsBytes ];
	  _return_.data.faceAttributes    = 0;
	  _return_.data.cellDefinitions   = 0;
	  _return_.data.cellAttributes    = 0;
	  
	  memcpy(_return_.data.description, description, _return_.header.descriptionBytes);
	  memcpy(_return_.data.vertexDefinitions, (const char*)vertexElements.data(), _return_.header.vertexDefinitionsBytes);
	  memcpy(_return_.data.faceDefinitions, (const char*)triangle_strips.data(), _return_.header.faceDefinitionsBytes);
}

void GraphicsModule::fromatSphereMeshForDrawing(VELaSSCo::RTFormat::File& _return_, const MeshInfo& meshInfo, 
  const std::vector<Vertex>& vertices, const std::vector<Element>& elements, 
  const std::vector<ElementAttrib>& elementAttribs)
{
        // const size_t num_vertices    = vertices.size();
	const size_t num_elements    = elements.size();
	// const size_t num_attribs     = elementAttribs.size();
	//size_t num_groupInfos  = elementInfos.size();
	
	std::vector<SphereElement> ret_vertices( num_elements );

    std::map<int64_t, int64_t> vertexID_map;

	for(size_t idx = 0; idx < elements.size(); idx++){
		
		int64_t vertexID = elements[idx].nodes_ids.size() > 0 ? static_cast<int64_t>( elements[idx].nodes_ids[0] ) : -1;
		vertexID_map[ vertexID ] = idx;
		if(vertexID > 0){
		  ret_vertices[idx].x        = vertices[vertexID - 1].x;
		  ret_vertices[idx].y        = vertices[vertexID - 1].y;
		  ret_vertices[idx].z        = vertices[vertexID - 1].z;
		  ret_vertices[idx].radius   = 1.0f;
		  ret_vertices[idx].vertexID = vertices[vertexID - 1].id;
	    }
	    else
	    {
		  ret_vertices[idx].x        = 0.0f;
		  ret_vertices[idx].y        = 0.0f;
		  ret_vertices[idx].z        = 0.0f;
		  ret_vertices[idx].radius   = 1.0f;
		  ret_vertices[idx].vertexID = 0;
		}
	}
	
	for(size_t idx = 0; idx < elementAttribs.size(); idx++){
		
		if(elementAttribs[idx].name == "Radius" && vertexID_map.find(elementAttribs[idx].id) != vertexID_map.end()){
			
			ret_vertices[vertexID_map[elementAttribs[idx].id]].radius = elementAttribs[idx].value.size() > 0 ? elementAttribs[idx].value[0] : 1.0f;
		}	
		
	}
	
	char description[] =
		"# TEST PLY DATA                                        \n"
		"VertexDefinition         = position, radius, vertexIdx \n"
		"vertexDefinitionsType    = float3, float, int64        \n"	
		"OgLPrimitiveRestartIndex = -1                          \n";
	  
	  _return_.header.magic[0] = 'V';
	  _return_.header.magic[1] = 'E';
	  _return_.header.magic[2] = 'L';
	  _return_.header.magic[3] = 'a';
	  _return_.header.magic[4] = 'S';
	  _return_.header.magic[5] = 'S';
	  _return_.header.magic[6] = 'C';
	  _return_.header.magic[7] = 'o';

	  _return_.header.version = 100;
	  _return_.header.descriptionBytes = sizeof(description);

	  _return_.header.metaBytes = 0;

	  _return_.header.vertexDefinitionsBytes  = static_cast<uint64_t>(ret_vertices.size() * sizeof(SphereElement));
	  _return_.header.vertexAttributesBytes   = 0;
	  _return_.header.edgeDefinitionsBytes    = 0;
	  _return_.header.edgeAttributesBytes     = 0;
	  _return_.header.faceDefinitionsBytes    = 0;
	  _return_.header.faceAttributesBytes     = 0;
	  _return_.header.cellDefinitionsBytes    = 0;
	  _return_.header.cellAttributesBytes     = 0;

	  _return_.data.description       = new uint8_t[ _return_.header.descriptionBytes ];
	  _return_.data.meta              = 0;
      _return_.data.vertexDefinitions = new uint8_t[ _return_.header.vertexDefinitionsBytes ];
	  _return_.data.vertexAttributes  = 0;
	  _return_.data.edgeDefinitions   = 0;
	  _return_.data.edgeAttributes    = 0;
	  _return_.data.faceDefinitions   = 0;
	  _return_.data.faceAttributes    = 0;
	  _return_.data.cellDefinitions   = 0;
	  _return_.data.cellAttributes    = 0;
	  
	  memcpy(_return_.data.description, description, _return_.header.descriptionBytes);
	  memcpy(_return_.data.vertexDefinitions, (const char*)ret_vertices.data(), _return_.header.vertexDefinitionsBytes);
	  
	  for(size_t i = 0; i < 10; i++)
	    std::cout << ret_vertices[i].x << " " << ret_vertices[i].y << " " << ret_vertices[i].z << " " << ret_vertices[i].radius << " " << ret_vertices[i].vertexID << std::endl;
}
