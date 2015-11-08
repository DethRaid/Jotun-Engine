#version 450

in vec2 uv;
//in vec3 normal_cameraspace;

out vec4 color;
//out vec3 normal;

uniform sampler2D albedo_texture;
//uniform sampler2D normal_texture;

void main() {
    vec4 albedo_sample = texture2D( albedo_texture, uv );
    vec3 albedo = albedo_sample.rgb;
    float alpha = albedo_sample.a;

    //vec3 normal_sample = texture2D( normal_texture, uv ) * vec3( 2.0 ) - vec3( 1.0 );

    color = vec4( albedo, alpha );
}