#ifndef TILELAYER_H
#define TILELAYER_H

#include "TileMap.h"
//#include <vector>
#include <string>

struct TileSet{
	int FirstID,LastID;
	int RowCount,ColCount;
	int TileCount,TileSize;
	std::string Name,Source;
};

using TilesetList = std::vector<TileSet> ;
using TileMatrix = std::vector<std::vector<int> >;

class tilelayer:public layer
{
	public:
		tilelayer(int tilesize,int rowcount,int colcount,TileMatrix tilemap,TilesetList tilesets);
		virtual void Render();
		virtual void Update();
		virtual void Clean();
		inline int GetWidth(){return m_ColCount;}
		inline int GetHeight(){return m_RowCount;}
		inline int GetTileSize(){return m_TileSize;}
		
		inline TileMatrix GetTileMap(){return (m_Tilemap);}
	
	private:
		int m_TileSize;
		int m_RowCount,m_ColCount;
		
		TileMatrix m_Tilemap;
		TilesetList m_Tilesets;
};

#endif
