#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

class UnlockAllCars : public BakkesMod::Plugin::BakkesModPlugin,
                      public BakkesMod::Plugin::PluginSettingsWindow
{
public:
    void onLoad() override;
    void onUnload() override;

    // Settings window (ImGui)
    void RenderSettings() override;
    std::string GetPluginName() override;
    void SetImGuiContext(uintptr_t ctx) override;

private:
    // Unlock all cars via BakkesMod inventory
    void UnlockAllCarsInGarage();

    // List of all known car product IDs in Rocket League
    // IDs reference: https://rl.insider.gg / BakkesMod SDK
    std::vector<int> GetAllCarProductIDs();

    bool unlockSuccess = false;
    bool unlockAttempted = false;
};
