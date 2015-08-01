#ifndef RRENDERABLEMESHLOADER_H
#define RRENDERABLEMESHLOADER_H

/*
 * To class or not to class, that is the question. Whether tis nobler in
 * the mind to follow in decades of experience or to maintain one's faulty
 * perceptions of reality.
 */

#include <vector>
#include <map>
#include <string>
#include <mutex>

#include "RRenderComponents.h"

class RenderableMeshLoader {
public:
    RenderMeshLoader( RenderComponentDatabase * );
    ~RenderMeshLoader();

    void operator()( std::map componentsList );

private:
    RenderComponentDatabase *database;
};

#endif

