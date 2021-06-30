#version 300 es

#undef lowp
#undef mediump
#undef highp

precision mediump float;
layout (location = 0) in vec3 Position;
uniform float Scale;
uniform mat4 mat;

void main()
{
    
    gl_Position = mat * vec4(Scale * Position.x, Scale * Position.y, Position.z, 1.0);
}