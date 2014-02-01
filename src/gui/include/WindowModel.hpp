#ifndef WINDOWMODEL_HPP
#define WINDOWMODEL_HPP

#include <iostream>
#include <vector>
#include "WindowContent.hpp"
namespace gui
{

/**
 * @author Hugo Belloc
 * @brief Represents all the data displayable
 * in the window.
 *
 * This class stores all the contents of the window
 * and selects the content to be displayed.
 *
 */
class WindowModel
{
public:
    WindowModel();
    virtual ~WindowModel();
    void addContent(WindowContent *content);
    void deleteContent(WindowContent *content);
    WindowContent * getCurrentContent();
    void nextContent();
    bool getLoop();
    void setLoop(bool loop);

private:
    std::vector<WindowContent*> _contents;
    int _current;
    bool _loop;

};

}
#endif // WINDOWMODEL_HPP
