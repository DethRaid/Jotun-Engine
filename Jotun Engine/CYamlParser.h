/*!\brief A facade to the YAML parsing subsystem 
 *
 * Tasks needed:
 *  - Create a list of Components of a given type (probs?)
 *  - Specify a file with the scene data
 *  - Other functionality as needed
 */

#ifndef CYAMLPARSER_H
#define CYAMLPARSER_H

#include <string>
#include <unordered_map>
#include <vector>
#include <exception>

#include <yaml-cpp/yaml.h>

namespace Loading {
    // We'll need some sort of scene data structure - a YAML tree maybe?
    YAML::Node sceneFile;

    int loadingFunction( std::map arrayOfComponents );
    std::unordered_map<std::string, loadFunction> loadingFunctions;
    void registerLoadingFunction( std::string &type, loadingFunction function );
    
    void openSceneFile( std::string &fileName );
}

#endif

