//============================================================================
//
//   SSSS    tt          lll  lll
//  SS  SS   tt           ll   ll
//  SS     tttttt  eeee   ll   ll   aaaa
//   SSSS    tt   ee  ee  ll   ll      aa
//      SS   tt   eeeeee  ll   ll   aaaaa  --  "An Atari 2600 VCS Emulator"
//  SS  SS   tt   ee      ll   ll  aa  aa
//   SSSS     ttt  eeeee llll llll  aaaaa
//
// Copyright (c) 1995-2017 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//============================================================================

#ifndef INPUT_DIALOG_HXX
#define INPUT_DIALOG_HXX

class OSystem;
class GuiObject;
class TabWidget;
class EventMappingWidget;
class CheckboxWidget;
class EditTextWidget;
class PopUpWidget;
class SliderWidget;
class StaticTextWidget;

#include "Dialog.hxx"
#include "JoystickDialog.hxx"
#include "bspf.hxx"

class InputDialog : public Dialog
{
  public:
    InputDialog(OSystem& osystem, DialogContainer& parent,
                const GUI::Font& font, int max_w, int max_h);
    virtual ~InputDialog() = default;

  private:
    void handleKeyDown(StellaKey key, StellaMod mod) override;
    void handleJoyDown(int stick, int button) override;
    void handleJoyAxis(int stick, int axis, int value) override;
    bool handleJoyHat(int stick, int hat, int value) override;
    void handleCommand(CommandSender* sender, int cmd, int data, int id) override;

    void loadConfig() override;
    void saveConfig() override;
    void setDefaults() override;

    void addDevicePortTab(const GUI::Font& font);

  private:
    enum {
      kDeadzoneChanged = 'DZch',
      kDPSpeedChanged  = 'PDch',
      kMPSpeedChanged  = 'PMch',
      kTBSpeedChanged  = 'TBch',
      kDBButtonPressed = 'DBbp'
    };

    TabWidget* myTab;

    EventMappingWidget* myEmulEventMapper;
    EventMappingWidget* myMenuEventMapper;

    PopUpWidget* mySAPort;
    PopUpWidget* myMouseControl;
    PopUpWidget* myCursorState;

    EditTextWidget*   myAVoxPort;

    SliderWidget*     myDeadzone;
    StaticTextWidget* myDeadzoneLabel;
    SliderWidget*     myDPaddleSpeed;
    SliderWidget*     myMPaddleSpeed;
    SliderWidget*     myTrackBallSpeed;
    StaticTextWidget* myDPaddleLabel;
    StaticTextWidget* myMPaddleLabel;
    StaticTextWidget* myTrackBallLabel;
    CheckboxWidget*   myAllowAll4;
    CheckboxWidget*   myGrabMouse;
    CheckboxWidget*   myCtrlCombo;

    ButtonWidget*     myJoyDlgButton;

    // Show the list of joysticks that the eventhandler knows about
    unique_ptr<JoystickDialog> myJoyDialog;

  private:
    // Following constructors and assignment operators not supported
    InputDialog() = delete;
    InputDialog(const InputDialog&) = delete;
    InputDialog(InputDialog&&) = delete;
    InputDialog& operator=(const InputDialog&) = delete;
    InputDialog& operator=(InputDialog&&) = delete;
};

#endif
