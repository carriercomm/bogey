#include "InputEventHandler.h"

InputEventHandler::InputEventHandler(osg::ref_ptr<PlayerState> state)
    : _state(state)
{
}

bool InputEventHandler::handle(const osgGA::GUIEventAdapter& event, osgGA::GUIActionAdapter& action, osg::Object* obj, osg::NodeVisitor* visitor)
{
    (void) action;
    (void) obj;
    (void) visitor;

    bool handled = true;
    switch (event.getEventType()) {

        case osgGA::GUIEventAdapter::KEYDOWN:
            switch (event.getKey()) {
                case 'z': case 'Z':
                    _state->moveForward = true;
                    break;
                case 's': case 'S':
                    _state->moveBackward = true;
                    break;
                case 'q': case 'Q':
                    _state->moveLeft = true;
                    break;
                case 'd': case 'D':
                    _state->moveRight = true;
                    break;
                default:
                    handled = false;
                    break;
            }
            break;

        case osgGA::GUIEventAdapter::KEYUP:
            switch (event.getKey()) {
                case 'z': case 'Z':
                    _state->moveForward = false;
                    break;
                case 's': case 'S':
                    _state->moveBackward = false;
                    break;
                case 'q': case 'Q':
                    _state->moveLeft = false;
                    break;
                case 'd': case 'D':
                    _state->moveRight = false;
                    break;
                default:
                    handled = false;
                    break;
            }
            break;
        default:
            handled = false;
            break;
    }

    return handled;
}