#include "stdafx.h"
#include "Animation.h"



void Animation::addFrame(const sf::IntRect & rect, float timeToNextFrame)
{
	m_frames.emplace_back(rect, timeToNextFrame);
}

sf::IntRect Animation::getFrame(float dt)
{
	deltaTime += dt;
	if (deltaTime >= m_frames.at(m_currentFrame).timeToNextFrame)
	{
		m_currentFrame++;
		deltaTime = 0;

		if (m_currentFrame == m_frames.size())
		{
			m_currentFrame = 0;
		}
	}
	return m_frames.at(m_currentFrame).rect;
}

void Animation::ClearFrames()
{
	m_frames.clear();
	deltaTime = 0;
	m_currentFrame = 0;
}