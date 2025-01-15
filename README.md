Documentation for the SettingsMenu Plugin 


Introduction

The SettingsMenu plugin for Unreal Engine simplifies the creation of settings menus for
games. It provides a modular and reusable solution for configuring gameplay settings, such as
graphics quality, audio volume, and muting. Designed for integration into both Main Menus and
in-game settings, this plugin also supports persistent settings using Unreal's Save Game
system.


Features Overview
The SettingsMenu plugin includes:
1. Quality Selector: Allows users to choose between graphics quality levels (Low, Medium,
High, Epic).
2. Volume Slider: Adjusts audio volume with a range from 0% to 100%.
3. Mute Toggle: Enables or disables audio.
4. Back Button: Navigate back to the previous menu.
5. Quit Button: Available only in the in-game settings menu to exit to the Main Menu.
6. Save and Load System: Ensures settings persist between play sessions.

   
Setup Instructions


1. Installing the Plugin
1. Clone or download the SettingsMenu plugin and place it in your project's Plugins
folder.
2. Open the project in Unreal Engine.
3. Go to Edit > Plugins and ensure the SettingsMenu plugin is enabled.
4. Restart the editor if prompted.


Customization Options

1. Adding New Settings
1. Open the DA_WidgetConfig data asset in Settings Content Folder > Data.
2. Add new configuration data for the desired widget type (e.g., Slider, Selector).
  ○ For a Selector:
    ■ Add an entry to the Options array with the selectable values
    ■ Set the DefaultOption to the value you want pre-selected.
    ■ Provide a LabelText to describe the selector (e.g., "Graphics Quality").
  ○ For a Slider:
    ■ Set DefaultValue to specify the initial value.
    ■ Provide a LabelText to describe the slider (e.g., "Volume").
  ○ For a Toggle:
    ■ Set the bIsChecked (True or False).
  ■ Provide a LabelText to describe the toggle (e.g., "Mute").
3. Save the DA_WidgetConfig data asset.
4. The WBP_BaseSettingsMenu or WBP_GameSettingsMenu dynamically reads from this data asset during initialization.
