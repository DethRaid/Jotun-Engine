#version 450

layout(location = 0) in vec3 vertex_position_modelspace;
layout(location = 1) in vec3 vertex_normal_modelspace;
layout(location = 2) in vec2 vertex_uv;

out vec2 uv;
//out vec3 normal_cameraspace;

uniform mat4 mvp;
uniform mat4 model_matrix;
uniform mat4 view_matrix;

void main() {
    gl_Position = mvp * vec4( vertex_position_modelspace, 1.0 );
    
   // normal_cameraspace = (view_matrix * model_matrix * vec4( vertex_normal_modelspace, 1.0 )).xyz;

    uv = vertex_uv;
}
