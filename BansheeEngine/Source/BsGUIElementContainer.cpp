#include "BsGUIElementContainer.h"
#include "BsGUISkin.h"

using namespace CamelotFramework;
using namespace BansheeEngine;

namespace BansheeEngine
{
	GUIElementContainer::GUIElementContainer(GUIWidget& parent, const GUILayoutOptions& layoutOptions)
		:GUIElement(parent, &GUISkin::DefaultStyle, layoutOptions, false)
	{ }

	GUIElementContainer::~GUIElementContainer()
	{ }

	UINT32 GUIElementContainer::getNumRenderElements() const
	{
		return 0;
	}

	const GUIMaterialInfo& GUIElementContainer::getMaterial(UINT32 renderElementIdx) const
	{
		CM_EXCEPT(InvalidStateException, "Trying to retrieve a material from an element with no render elements.");
	}

	UINT32 GUIElementContainer::getNumQuads(UINT32 renderElementIdx) const
	{
		return 0;
	}

	void GUIElementContainer::updateClippedBounds()
	{
		mClippedBounds = RectI(0, 0, 0, 0); // We don't want any mouse input for this element. This is just a container.
	}

	void GUIElementContainer::fillBuffer(UINT8* vertices, UINT8* uv, UINT32* indices, UINT32 startingQuad, UINT32 maxNumQuads, 
		UINT32 vertexStride, UINT32 indexStride, UINT32 renderElementIdx) const
	{ }

	Vector2I GUIElementContainer::_getOptimalSize() const
	{
		return Vector2I();
	}

	void GUIElementContainer::_changeParentWidget(GUIWidget* widget)
	{
		GUIElement::_changeParentWidget(widget);

		for(UINT32 i = 0; i < getNumChildElements(); i++)
		{
			GUIElement* child = getChildElement(i);

			if(child != nullptr)
				child->_changeParentWidget(widget);
		}
	}
}