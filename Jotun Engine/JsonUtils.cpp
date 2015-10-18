#include "stdafx.h"
#include "JsonUtils.h"

namespace core_services {
    namespace JsonUtils {
        glm::vec3 loadVec3( rapidjson::Value &value ) {
            assert( value.IsArray() );

            glm::vec3 retVal;
            int curPos = 0;
            for( auto itr = value.Begin(); itr != value.End(); ++itr ) {
                retVal[curPos] = itr->GetDouble();
                curPos++;
            }

            return retVal;
        }
    }
}