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
private:
    std::vector<WindowContent*> _contents;

};

}
#endif // WINDOWMODEL_HPP
