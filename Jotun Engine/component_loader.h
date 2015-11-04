#pragma once

#include "stdafx.h"

/*!\brief Defines a template capable of*/
namespace core_services {
    /*!\brief Defines an interface for all scene loaders*/
    class component_loader {
    public:
        component_loader() {}
        virtual ~component_loader() {}

        /*!\brief Returns the name of the node that this loader can load*/
        const std::string& get_handled_type() const;

        void load_from_json( rapidjson::Value &json );

    protected:
        std::string m_handled_type;

        virtual void load_one_component( rapidjson::Value& ) = 0;
    };
}
