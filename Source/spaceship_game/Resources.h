#pragma once

#include <string>
#include <map>

using namespace std;

class Resources 
{
private:
    using Texture2D = Texture;
    using TextureMap = map<int, Texture2D>;
    using TextureMapList = map<string, TextureMap>;

	static const string RES_DIR;
    static bool loadTexture(Texture2D& texture, const string& filename);

    map<string, TextureMap> _textures;

public:
	Resources();
    ~Resources();

    void loadResources();
    Texture2D& getTexture(const string& name, int frame);
};
