/* Utility class to draw SFML on a screen that will be displayed in the background */

#ifndef _H_SFMLSCREEN_H_
#define _H_SFMLSCREEN_H_

#include <boost/noncopyable.hpp>

#define GL_GLEXT_PROTOTYPES
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics/Shader.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class SFMLScreen : public sf::RenderTexture, public boost::noncopyable
{
public: 
    SFMLScreen();

    void init(float w, float h, float ww, float wh);

    void render(glm::mat4 & vp);

    const glm::mat4 & getModel() { return model; }

    void setModel(const glm::mat4 & m) { model = m; }
private:
    glm::mat4 model;

    float width;
    float height;
    float wwidth;
    float wheight;
    sf::Shader shader;
    GLuint vbo_vertices;
    GLuint vbo_texcoords;
    GLuint ibo_elements;

    /* Shader internals */
    GLhandleARB program;
    GLint attribute_coord3d;
    GLint attribute_texcoord;
    GLint uniform_transform;
};

#endif
