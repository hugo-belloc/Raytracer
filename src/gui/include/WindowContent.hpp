#ifndef WINDOWCONTENT_HPP
#define WINDOWCONTENT_HPP

namespace gui
{


/**
 * @author Hugo Belloc
 * @brief Represents one type of content
 * that can be displayed in the window.
 */
class WindowContent
{
public :
    virtual ~WindowContent();
    virtual void display()=0;

private:
};

}
#endif // WINDOWCONTENT_HPP
