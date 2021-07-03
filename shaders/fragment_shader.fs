#version 300 es
#undef lowp
#undef mediump
#undef highp

precision mediump float;
in vec4 Color;
out vec4 FragColor;
void main()
{
    FragColor = Color;
}