#include "stdafx.h"
#include "ISceneLoader.h"

const std::string& CoreServices::ISceneLoader::get_handled_type() const {
    return m_handled_type;
}
