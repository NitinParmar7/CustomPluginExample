#include "SettingsMenuEditor.h"

#include "FWidgetConfigCustomization.h"
#include "SettingsMenu.h"

#define LOCTEXT_NAMESPACE "FSettingsMenuEditorModule"

void FSettingsMenuEditorModule::StartupModule()
{
    FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

    PropertyModule.RegisterCustomPropertyTypeLayout("WidgetConfig", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FWidgetConfigCustomization::MakeInstance));

    PropertyModule.NotifyCustomizationModuleChanged();
}

void FSettingsMenuEditorModule::ShutdownModule()
{
    if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
    {
        FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");


        PropertyEditorModule.UnregisterCustomPropertyTypeLayout("WidgetConfig");
    }
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FSettingsMenuEditorModule, SettingsMenuEditor)