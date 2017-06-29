#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Animation
{
	struct Frame
	{
		Frame(const sf::IntRect& rect, float timeToNextFrame) :
			rect			(rect),
			timeToNextFrame	(timeToNextFrame)
		{}
		
		const sf::IntRect rect;
		const float timeToNextFrame;
	};

public:
	void addFrame(const sf::IntRect& rect, float timeToNextFrame);
	sf::IntRect getFrame(float dt);
	void ClearFrames();

private:

	std::vector<Frame> m_frames;
	float deltaTime = 0;
	int m_currentFrame = 0;

};

