#include "ImgLayer.h"
#include "Graphics.h"

ImgLayer::ImgLayer(std::string texID, int x, int y, float scrollRatio, float scalex, float scaley){
	m_TextureID=texID;
	m_OffsetX=x;
	m_OffsetY=y;
	m_ScrollRatio=scrollRatio;
	m_Repeated=true;
	m_ScaleX=scalex;
	m_ScaleY=scaley;
	QueryImage(m_TextureID);
}

void ImgLayer::Render(){
	textureManager::getInstance()->draw(m_TextureID, m_OffsetX, m_OffsetY, m_ImgWidth, m_ImgHeight, m_Flip, m_ScaleX, m_ScaleY, 0, m_ScrollRatio);
}

void ImgLayer::Update(){
	
}

void ImgLayer::Clean(){
	
}

void ImgLayer::QueryImage(std::string textureID){
	SDL_Texture* texture = textureManager::getInstance()->GetTexture(m_TextureID);
	SDL_QueryTexture(texture, NULL, NULL, &m_ImgWidth, &m_ImgHeight);
}
