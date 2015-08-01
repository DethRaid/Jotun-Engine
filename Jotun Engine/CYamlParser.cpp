#include "CYamlParser.h"

namespace Loading {
    void openSceneFile( std::string &fileName ) {
        sceneFile = YAML::Load( fileName );

        // Check that the scene file is valid... somehow

	    // iterate through all high-level YAML things, loading each with the
    	// registered loader
	    // TODO: check this for correctness
    	for( std::string &groupName : sceneFile ) {
            // Since I can override the () operator, I can have loading functions
            // by objects, which allows them to hold data, such as where to
            // put the loaded components
	        int err = loadingFunctions[groupName]( sceneFile[groupName] );
            if( err != 0 ) {
                // TODO: Implement some mapping from error code to error message
                std::cerr<<"ERROR: Loading of component type " <<groupName
                    <<" failed with error code " <<err <<"\n";
            }
    	}
    }

    void registerLoadingFunction( std::string &type, loadingFunction function ) {
        loadingFunctions.emplace( type, function );
    } 
}

