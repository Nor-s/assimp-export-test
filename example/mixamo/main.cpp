#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Exporter.hpp>
#include <iostream>

int main()
{
    Assimp::Importer importer;
    std::string fbxPath = ".\\assets\\Capoeira_binary_24fps_nonereduction.fbx";
    fbxPath = ".\\assets\\Capoeira (1).fbx";
    unsigned int assimp_read_flag = aiProcess_Triangulate |
                                    aiProcess_SortByPType |
                                    aiProcess_GenUVCoords |
                                    aiProcess_OptimizeMeshes |
                                    aiProcess_ValidateDataStructure |
                                    aiProcess_GenNormals |
                                    aiProcess_CalcTangentSpace |
                                    aiProcess_LimitBoneWeights |
                                    aiProcess_JoinIdenticalVertices |
                                    aiProcess_FlipWindingOrder;
    importer.SetPropertyBool(AI_CONFIG_IMPORT_FBX_PRESERVE_PIVOTS, false);

    const aiScene *scene = importer.ReadFile(fbxPath, assimp_read_flag);

    if (scene == nullptr ||  scene->mRootNode == nullptr)
    {
        std::cout << "error: " << importer.GetErrorString() << std::endl;
        return -1;
    }
    std::cout << "import success!\n";

    Assimp::Exporter exporter;

    if (exporter.Export(scene, "fbx", ".//assets/result.fbx") != AI_SUCCESS)
    {
        std::cout << "export failed: " << exporter.GetErrorString() << std::endl;
        return -1;
    }
    std::cout << "export success!" << std::endl;

    return 0;
}