#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <vector>
#include "Layer.h"
#include "TileLayer.h"

class TileMap{
	public:
		void Render()
		{
			for(unsigned int i=0;i<m_MapLayers.size();++i)
			{
				m_MapLayers[i]->Render();
			}
		}
		
		void Update()
		{
			for(unsigned int i=0;i<m_MapLayers.size();++i)
			{
				m_MapLayers[i]->Update();
			}
		}
		
		std::vector <layer*> GetMapLayers(){
			return (m_MapLayers);
		}
		
		void Clean()
		{
			for(unsigned int i=0;i<m_MapLayers.size();++i)
			{
				m_MapLayers[i]->Clean();
			}
		}
		
	private:
		friend class MapParser;
		std::vector <layer* > m_MapLayers;
};

#endif
