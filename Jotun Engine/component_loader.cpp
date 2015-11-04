#include "stdafx.h"
#include "component_loader.h"

namespace core_services {
    const std::string& component_loader::get_handled_type() const {
        return m_handled_type;
    }

   void component_loader::load_from_json( rapidjson::Value &json ) {

        for( auto itr = json.Begin(); itr != json.End(); ++itr ) {
            load_one_component( *itr );
        }
    }
}
