/**
 * @author Hugo Belloc <hugo.belloc@ecole.ensicaen.fr> 
 * @date Wed Feb 19 2014
 * 
 */

/**
 * @file Face.hpp
 *  
 * Declaration of the Face class
 *
 */


#ifndef _FACE_HEADER_H
#define _FACE_HEADER_H

#include <iostream>
#include <vector>
#include <stdexcept>

namespace scene
{
    /**
     * A class representing a Face. It contains the index of
     * of the vertices forming the face.
     * For now, all faces are triangles.
     */

    class Face
    {
    public :
	Face();
	Face(unsigned int v1,unsigned int v2,unsigned int v3);	
	~Face();
	void setVertex(unsigned int num,unsigned int value);
	unsigned int  getVertex(unsigned int num) const;
	void displayTTY();

    private:
	std::vector<unsigned int> _vertices;
    };

}
#endif
