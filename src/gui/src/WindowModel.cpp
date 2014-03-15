#include "WindowModel.hpp"
using namespace std;

namespace gui
{

/**
 * @brief Default Constructor : create an empty window model.
 */
WindowModel::WindowModel(): _contents(),_current(0),_loop(true)
{}

/**
 * @brief virtual destructor.
 *
 * Desallocate all the contents of the window.
 * (So the content added should not be a local
 * variable and the user should not delete it
 * himself).
 *
 */
WindowModel::~WindowModel()
{
    vector<WindowContent*>::iterator it;
    for(it=_contents.begin();it!=_contents.end();++it)
    {
        delete *it;
    }
}

/**
 * @brief add a new content to the window model.
 * at the end of the content list
 *
 * @param content the new content to add
 */
void WindowModel::addContent(WindowContent *content)
{
    _contents.push_back(content);
}

/**
 * @brief delete a given content from the model
 * an desallocate the memory.
 * @param content the content to be deleted
 */
void WindowModel::deleteContent(WindowContent *content)
{
    vector<WindowContent*>::iterator it;
    for(it=_contents.begin();it!=_contents.end();++it)
    {
        if(*it==content)
        {
            _contents.erase(it,it+1);
        }
    }

    delete content;
}

/**
 * @brief Let us know if the WindowModel is going to loop
 * after reaching the last content
 * @return true if the WindowModel is going to loop
 */
bool WindowModel::getLoop()
{
    return _loop;
}

/**
 * @brief Allow to decide whether the WindowModel
 * loop or not.
 * @param loop true if the model loop
 * @return
*/
void WindowModel::setLoop(bool loop)
{
    _loop=loop;
}

/**
 * @brief Get the current content.
 * @return the current content.
 *
 * Get the current content of the WindowModel that
 * is the content to be displayed.
 *
 */
WindowContent * WindowModel::getCurrentContent()
{
    if(_contents.size()==0)
    {
        return 0;
    }
    return _contents[_current];
}

/**
 * @brief If possible go to the nextContent
 */
void WindowModel::nextContent()
{
    if(_contents.size()!=0)
    {
        if(_loop)
        {
            _current=(_current+1)%_contents.size();
        }
        else
        {
            _current=(_current+1>=((int)_contents.size()))?_current:_current+1;
        }
	_contents[_current]->onTransition();
    }
}

}


