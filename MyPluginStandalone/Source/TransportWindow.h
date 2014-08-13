/*
  ==============================================================================

    TransportWindow.h
    Created: 13 Aug 2014 3:00:38pm
    Author:  marc

  ==============================================================================
*/

#ifndef TRANSPORTWINDOW_H_INCLUDED
#define TRANSPORTWINDOW_H_INCLUDED

class TransportWindow : public DocumentWindow {
public:
    //==============================================================================
    /** Creates a window with a given title and colour.
     The settings object can be a PropertySet that the class should use to
     store its settings - the object that is passed-in will be owned by this
     class and deleted automatically when no longer needed. (It can also be null)
     */
    TransportWindow (const String& title,
                            const Colour& backgroundColour)
    : DocumentWindow (title, backgroundColour, DocumentWindow::minimiseButton)
    {
        
        
    }
    
    ~TransportWindow() {
        
    }
};

#endif  // TRANSPORTWINDOW_H_INCLUDED
