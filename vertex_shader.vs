#version 300 es

#undef lowp
#undef mediump
#undef highp

precision mediump float;

out vec4 Color;
layout (location = 0) in vec3 Position;
uniform mat4 mat;

void main()
{
    Color = vec4(clamp(Position,0.0,1.0),1.0);
    gl_Position = mat * vec4(Position, 1.0);
}