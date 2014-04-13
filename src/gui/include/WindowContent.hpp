#ifndef WINDOWCONTENT_HPP
#define WINDOWCONTENT_HPP

namespace gui
{


/**
 * @author Hugo Belloc
 * Represents one type of content
 * that can be displayed in the window.
 */
    class WindowContent
    {
    public :
/**
 * Virtual destructor ...
 */
	virtual ~WindowContent();

/**
 * This methode is to be executed just before the 
 * WindowModel transit from a content to another
 */
	virtual void onTransition()=0;

/**
 * The methode call to display a content
 */
	virtual void display()=0;

    private:
    };

}
#endif // WINDOWCONTENT_HPP
