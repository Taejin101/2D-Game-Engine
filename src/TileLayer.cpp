#include "TileLayer.h"
#include "Graphics.h"

tilelayer::tilelayer(int tilesize,int rowcount,int colcount,TileMatrix tilemap,TilesetList tilesets):
m_TileSize(tilesize),m_ColCount(colcount),m_RowCount(rowcount),m_Tilemap(tilemap),m_Tilesets(tilesets)
{
	for(unsigned int i=0;i<m_Tilesets.size();i++)
	{
		textureManager::getInstance()->load(m_Tilesets[i].Name,"assets/maps/"+m_Tilesets[i].Source);
	}
}

void tilelayer::Render()
{
	for(unsigned int i=0;i<m_RowCount;i++)
	{
		for(unsigned int j=0;j<m_ColCount;j++)
		{
			int tileID=m_Tilemap[i][j];
			int temp=tileID;
			
			if(tileID==0)
			{
				continue;
			}
			else
			{
				int index=0;
				if(m_Tilesets.size()>1)
				{
					for(unsigned int k=1;k<m_Tilesets.size();k++)
					{
						if(tileID>=m_Tilesets[k].FirstID&&tileID<=m_Tilesets[k].LastID)
						{
							tileID=tileID+m_Tilesets[k].TileCount-m_Tilesets[k].LastID;
							index=k;
							break;
						}
					}
				}
			
				TileSet ts = m_Tilesets[index];
				int tileRow = tileID/ts.ColCount;
				int tileCol = tileID - (tileRow*ts.ColCount)-1; 
				
				if(tileID%ts.ColCount==0)
				{
					tileRow--;
					tileCol=ts.ColCount-1;
				}
				
				textureManager::getInstance()->drawTile(ts.Name,ts.TileSize,j*ts.TileSize,i*ts.TileSize,tileRow,tileCol); 
			}
		}
	}
}

void tilelayer::Update()
{
}

void tilelayer::Clean()
{
}
