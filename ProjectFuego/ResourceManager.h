#pragma once
#include <SFML\Graphics.hpp>
#include <map>


template <typename Enum, typename Resource>
class ResourceManager
{

public:
	const Resource& get(Enum name) const
	{
		return m_resources.at(name);
	}

protected:

	void addResource(Enum name, const std::string& fileName)
	{
		Resource resource;
		resource.loadFromFile(fileName);

		m_resources.insert(std::make_pair(name, resource));
	}

private:
	std::map<Enum, Resource> m_resources;

};

