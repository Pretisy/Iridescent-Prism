#include "IridescentPrism.h"
#include "imgui.h"

namespace IridescentPrism
{
    void RenderUI()
    {
            ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
            ImGui::ShowDemoWindow();

    }
}
