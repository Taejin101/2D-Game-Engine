#include "ObjectFactory.h"
#include "Enemy.h"
#include "Hero.h"

ObjectFactory* ObjectFactory::s_Instance = nullptr;

void ObjectFactory::RegisterType(std::string className, std::function<gameobject*(properties* props)> type){
	m_TypeRegistry[className] = type;
}

gameobject* ObjectFactory::CreateObject(std::string type, properties *props){
	gameobject* object = nullptr;
	auto it = m_TypeRegistry.find(type);
	
	if(it!=m_TypeRegistry.end()){
		object = it->second(props);
	}
	
	return object;
}
