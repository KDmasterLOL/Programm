#version 300 es

#undef lowp
#undef mediump
#undef highp

precision mediump float;
layout (location = 0) in vec3 Position;
void main()
{
    
    gl_Position = vec4(0.5 * Position.x, 0.5 * Position.y, Position.z, 1.0);
}