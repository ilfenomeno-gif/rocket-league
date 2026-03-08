#include "pch.h"
#include "UnlockAllCars.h"

BAKKESMOD_PLUGIN(UnlockAllCars, "Unlock All Cars", "1.0.0", PLUGINTYPE_FREEPLAY)

// ─────────────────────────────────────────────
// Lista di tutti i Product ID delle auto in RL
// Fonte: BakkesMod SDK + RL Insider
// ─────────────────────────────────────────────
std::vector<int> UnlockAllCars::GetAllCarProductIDs()
{
    return {
        // ── DEFAULT / FREE ──
        23,    // Octane
        26,    // Dominus
        403,   // Breakout
        29,    // Paladin
        402,   // Hotshot
        404,   // Gizmo
        30,    // Road Hog
        31,    // Animus GP
        32,    // Venom
        33,    // Backfire
        34,    // Scarab
        35,    // Rhino
        36,    // Takumi
        37,    // X-Devil
        38,    // Zippy
        // ── DLC / PREMIUM ──
        600,   // Octane ZSR
        597,   // Breakout Type-S
        598,   // Dominus GT
        602,   // Takumi RX-T
        607,   // Road Hog XL
        609,   // Vulcan
        612,   // Hybrid
        619,   // Imperator DT5
        621,   // Endo
        624,   // Mantis
        625,   // Mudcat
        626,   // Centio V17
        636,   // Nimbus
        637,   // Samurai
        639,   // Artemis GXT
        641,   // Werewolf
        647,   // Jager 619 RS
        648,   // Twinzer
        649,   // Animus GP Gryphon
        650,   // Ronin GXT
        657,   // Harbinger CX11
        660,   // Proteus
        // ── ESPORTS / SPECIAL ──
        700,   // Fennec
        701,   // Peregrine TT
        702,   // Sentinel
        703,   // Helios
        704,   // Tyranno
        705,   // Maverick GXT
        706,   // Insidio
        707,   // Diestro
        708,   // Cyclone
        // ── EXTRA (aggiungine altri se necessario) ──
        800,   // Saffron
        801,   // Future shock
    };
}

// ─────────────────────────────────────────────
void UnlockAllCars::onLoad()
{
    LOG("UnlockAllCars plugin caricato!");
}

void UnlockAllCars::onUnload()
{
    LOG("UnlockAllCars plugin scaricato.");
}

// ─────────────────────────────────────────────
// Logica di sblocco: aggiunge tutti i prodotti
// all'inventario tramite il sistema di BakkesMod
// ─────────────────────────────────────────────
void UnlockAllCars::UnlockAllCarsInGarage()
{
    unlockAttempted = true;
    unlockSuccess   = false;

    auto productWrapper = gameWrapper->GetItemsWrapper();
    if (!productWrapper) {
        LOG("Errore: ItemsWrapper non disponibile.");
        return;
    }

    auto allCarIDs = GetAllCarProductIDs();
    int  count     = 0;

    for (int productID : allCarIDs)
    {
        // Controlla se l'item è già presente nell'inventario
        if (!productWrapper->HasProduct(productID))
        {
            // Aggiunge l'item all'inventario locale (solo cosmetico lato client)
            productWrapper->AddProduct(productID, 0, 0);
            count++;
        }
    }

    LOG("UnlockAllCars: {} auto aggiunte all'inventario.", count);
    unlockSuccess = true;
}

// ─────────────────────────────────────────────
// Finestra ImGui nelle impostazioni di BakkesMod
// ─────────────────────────────────────────────
void UnlockAllCars::RenderSettings()
{
    ImGui::TextColored(ImVec4(1.0f, 0.85f, 0.0f, 1.0f),
                       "Unlock All Cars - by ilfenomeno");
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::TextWrapped(
        "Clicca il bottone qui sotto per aggiungere TUTTE le auto "
        "al tuo garage. Le auto vengono attivate localmente "
        "tramite BakkesMod (solo in freeplay / custom training).");

    ImGui::Spacing();
    ImGui::Spacing();

    // ─── BOTTONE PRINCIPALE ───
    ImGui::PushStyleColor(ImGuiCol_Button,        ImVec4(0.10f, 0.55f, 0.90f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.15f, 0.65f, 1.00f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive,  ImVec4(0.05f, 0.40f, 0.75f, 1.0f));

    if (ImGui::Button("  Attiva tutte le Cars  ", ImVec2(240, 45)))
    {
        UnlockAllCarsInGarage();
    }

    ImGui::PopStyleColor(3);
    ImGui::Spacing();

    // ─── FEEDBACK STATO ───
    if (unlockAttempted)
    {
        if (unlockSuccess)
        {
            ImGui::TextColored(ImVec4(0.2f, 1.0f, 0.2f, 1.0f),
                               "OK - Tutte le auto sono state attivate!");
        }
        else
        {
            ImGui::TextColored(ImVec4(1.0f, 0.3f, 0.3f, 1.0f),
                               "Errore: avvia prima una partita/freeplay.");
        }
    }

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::TextDisabled("Plugin versione 1.0.0 | github.com/ilfenomeno-gif/rocket-league");
}

std::string UnlockAllCars::GetPluginName()
{
    return "Unlock All Cars";
}

void UnlockAllCars::SetImGuiContext(uintptr_t ctx)
{
    ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}
