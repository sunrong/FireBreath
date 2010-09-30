/**********************************************************\ 
Original Author: Richard Bateman (taxilian)

Created:    Sep 21, 2010
License:    Dual license model; choose one of two:
            New BSD License
            http://www.opensource.org/licenses/bsd-license.php
            - or -
            GNU Lesser General Public License, version 2.1
            http://www.gnu.org/licenses/lgpl-2.1.html

Copyright 2010 Facebook, Inc and the Firebreath development team
\**********************************************************/

#pragma once
#ifndef H_AXDOM_WINDOW
#define H_AXDOM_WINDOW

#include "Win/win_common.h"
#include <atlctl.h>
#include <string>
#include <boost/shared_ptr.hpp>
#include "DOM/Window.h"

namespace AXDOM {

    /**
     * Window
     *
     * Provides a wrapper around a JSObject * that represents a DOM element
     **/
    class Window : public FB::DOM::Window
    {
    public:
        Window(FB::JSObjectPtr obj, IWebBrowser2 *web);
        virtual ~Window();

    public:
        virtual FB::DOM::DocumentPtr getDocument();
        virtual void alert(const std::string& str);
        virtual std::string getLocation();

    protected:
        CComQIPtr<IHTMLWindow2> m_htmlWin;
        CComPtr<IWebBrowser2> m_webBrowser;
    };

};

#endif // H_AXDOM_WINDOW
