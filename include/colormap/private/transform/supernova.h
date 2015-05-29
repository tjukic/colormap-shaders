#pragma once
#include "../../colormap.h"

namespace colormap
{
namespace transform
{

class Supernova : public Colormap
{
private:
	class Wrapper : public WrapperBase
	{
	public:
		#include "../../../../shaders/transform_supernova.frag"
	};

public:
	Color getColor(float x) const override
	{
		Wrapper w;
		vec4 c = w.colormap(x);
		Color result;
		result.r = c.r;
		result.g = c.g;
		result.b = c.b;
		result.a = c.a;
		return result;
	}

	std::string getTitle() const override
	{
		return std::string("supernova");
	}

	std::string getCategory() const override
	{
		return std::string("transform");
	}
};

} // namespace transform
} // namespace colormap
