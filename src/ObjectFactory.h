#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include <map>
#include <string>
#include <memory>
#include "GameObject.h"

class ObjectFactory{
	public:
		gameobject *CreateObject(std::string type, properties *props);
		void RegisterType(std::string className, std::function<gameobject*(properties* props)>type);
		static ObjectFactory* GetInstance(){return s_Instance=(s_Instance!=nullptr)? s_Instance : new ObjectFactory();}
		
	private:
		ObjectFactory(){}
		static ObjectFactory* s_Instance;
		std::map<std::string,std::function<gameobject*(properties *props)>>m_TypeRegistry;
};

template <class Type>
class Registrar {
	
	public:
		Registrar(std::string className){
			ObjectFactory::GetInstance()->RegisterType(className, [](properties *props)->gameobject* {return new Type(props);});
		}
};

#endif
