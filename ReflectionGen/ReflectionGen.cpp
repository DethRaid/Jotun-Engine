// ReflectionGen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Ew, global state

int getAllFiles( vector<string> &files, char *dir );
int getFilesOfExtention( vector<string> &files, vector<string> &withExt, string extention );

int getAllFiles( vector<string> &files, char *dir ) {
    DIR *direct;
    struct dirent *ent;
    if( (direct = opendir( dir )) != NULL ) {
        /* print all the files and directories within directory */
        while( (ent = readdir( direct )) != NULL ) {
            files.push_back( ent->d_name );
        }
        closedir( direct );
        return 0;
    } else {
        return EXIT_FAILURE;
    }
}

int getFilesOfExtention( vector<string> &files, vector<string> &withExt, string extention ) {
    for( string &s : files ) {
        if( s.find_last_of( extention ) == s.size() - extention.size() - 1 ) {
            withExt.push_back( s );
        }
    }
    return 0;
}

int main( int argc, char* argv[] )
{
    // Look at all files in the specified directory
    // Get the names of all functions
    // Insert variables
    //  - __className : string
    //  - __methods : map<string, auto>
    // Insert code (into constructor) to bind functions (using functional::bind)
    //     so they can be put into the map
    vector<string> files;
    int err = getAllFiles( files, argv[1] );
    if( err == EXIT_FAILURE ) {
        cerr << "ERROR: Could not open directory\n";
        return -1;
    }

    vector<string> withExt;
    getFilesOfExtention( files, withExt, ".h" );

    for( string &s : withExt ) {
        // Get the names of all functions
        // Add in __className, __methods
        // Open corresponding .cpp file
        // Find constructor
        // Insert code to load up
    }

	return 0;
}

