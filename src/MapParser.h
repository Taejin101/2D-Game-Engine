#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <map>
#include <string>
#include "TileLayer.h"
#include "tinyxml.h"

class MapParser{
	public:
		bool Load();
		void Clean();
		
		inline TileMap* GetMap(std::string id){return (m_MapDict[id]);}
		inline static MapParser* GetInstance(){return (s_Instance=(s_Instance!=nullptr)?s_Instance:new MapParser());}
		
	private:
		bool Parse(std::string id,std::string source);
		TileSet ParseTileset(TiXmlElement *xmlTileset);
		tilelayer* ParseTileLayer(TiXmlElement *xmlLayer,TilesetList tilesets,int tilesize,int rowcount,int colcount);
		
	private:
		static MapParser* s_Instance;
		MapParser();
		std::map<std::string,TileMap*> m_MapDict;
};

#endif
