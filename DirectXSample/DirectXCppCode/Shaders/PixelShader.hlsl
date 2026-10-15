//--------------------------------------------------------------------------------------
struct VS_OUTPUT
{
    float4 Pos : SV_POSITION;
	//float3 Normal: NORMAL;
	float3 ObjectPos : TEXCOORD0;
	float4 color : COLOR0;
};
//Texture2D  gTexture : register(t0);

TextureCube gTexture : register(t0);
SamplerState TextureSampler
{
	Filter = MIN_MAG_MIP_LINEAR;
	AddressU = CLAMP;
	AddressV = CLAMP;
};
//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 main( VS_OUTPUT input ) : SV_Target
{
	float3 direction = normalize(input.ObjectPos);
	return gTexture.Sample(TextureSampler, direction);
	//return input.color;
}
