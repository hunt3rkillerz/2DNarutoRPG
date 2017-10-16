#pragma once
#include <DirectXMath.h>
#include "GameplayObject.h"

class GraphicsDevice;

class Camera
{
public:
	//Constructors and Destructor
	Camera(int width, int height, float angle, DirectX::XMFLOAT3 scaleFactors);
	Camera();
	~Camera();

	//Game Functions
	void Update(float gameTime);
	void Follow(GameplayObject *following);
	void Unfollow();
	bool IsFollowing() const;
	void SetTransform(GraphicsDevice *gDevice) const;

private:
	float angle;
	DirectX::XMFLOAT3 scaleFactors;
	D3DXMATRIX orthographicMatrix;
	D3DXMATRIX identityMatrix;
	D3DXMATRIX viewMatrix;

	GameplayObject *following;

	int width;
	int height;
};

