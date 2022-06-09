#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <iostream>
#include <vector>
#include "Layer.h"
#include "TileLayer.h"

class GameMap{
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
		
	private:
		friend class MapParser;
		std::vector <layer* > m_MapLayers;
};

#endif
