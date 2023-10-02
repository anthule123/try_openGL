#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

void main() {
  //muốn tạo thành 4 phần với 4 màu khác nhau thì dùng if else
  float mix_ratio[] = float[](0.0, 0.2, 0.5, 0.8, 1.0);
  bool left = TexCoord.x < 0.5;
  bool bottom = TexCoord.y < 0.5;
  // if (left && bottom) {
  //   FragColor = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), mix_ratio[0]);
  // } else if (left && !bottom) {
  //   FragColor = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), mix_ratio[1]);
  // } else if (!left && bottom) {
  //   FragColor = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), mix_ratio[2]);
  // } else {
  //   FragColor = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), mix_ratio[3]);
  // }
  FragColor = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.3);

}