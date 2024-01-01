#include "IridescentPrism.h"
#include "imgui.h"
#include <vector>

namespace IridescentPrism
{

    // Function to render the Gold Per 5 Seconds graph
    void RenderStatistics()
    {
        // Dummy data for the Gold Per 5 Seconds graph (replace this with your actual data)
        static const float goldData[] = { 0.0f, 10.0f, 20.0f, 15.0f, 25.0f, 30.0f, 35.0f, 40.0f, 50.0f, 45.0f };

        // Number of data points
        const int numDataPoints = IM_ARRAYSIZE(goldData);

        // Plot the Gold Per 5 Seconds graph
        ImGui::PlotLines("Gold Per 5 Seconds", goldData, numDataPoints, 0, nullptr, 0.0f, 60.0f, ImVec2(0, 80));
    }

    // Enum representing different item types
    enum class ItemType
    {
        Weapon,
        Armor,
        Consumable,
        // Add more item types as needed
    };

    // Struct representing an item
    struct Item
    {
        const char* name;
        ItemType type;
        // Add more item attributes as needed
    };

    // Struct representing a god
    struct God
    {
        const char* name;
        const char* description;
        // Add more god attributes as needed
    };

    // Function to render the item inventory
    void RenderItemInventory()
    {
        static const int numColumns = 4;  // Number of columns in the grid
        static const Item items[] = {
            {"Sword", ItemType::Weapon},
            {"Shield", ItemType::Armor},
            {"Health Potion", ItemType::Consumable},
            // Add more items as needed
        };

        for (const auto& item : items)
        {
            // Render each item as a button
            ImGui::Button(item.name, ImVec2(100, 100));

            // Display item information on hover
            if (ImGui::IsItemHovered())
            {
                ImGui::BeginTooltip();
                ImGui::Text("Name: %s", item.name);
                ImGui::Text("Type: %d", static_cast<int>(item.type));
                // Add more item information as needed
                ImGui::EndTooltip();
            }

            // Break the grid into the specified number of columns
            if (ImGui::GetColumnIndex() < numColumns - 1)
                ImGui::SameLine();
        }
    }

    // Function to render details of the selected god
    void RenderGodDetails(const God& god)
    {
        // Display details of the selected god
        ImGui::Text("Name: %s", god.name);
        ImGui::Text("Description: %s", god.description);
        // Add more details as needed
    }

    // Function to render the list of gods with columns
    void RenderGodList(const std::vector<God>& gods, int& selectedGodIndex)
    {
        const int godsPerRow = 10;  // Adjust this value based on the number of gods per row
        const float buttonSize = 100.0f;  // Adjust this value based on the size of each button
        const float spacing = 10.0f;  // Adjust this value based on the spacing between buttons

        for (int i = 0; i < gods.size(); ++i)
        {
            // Calculate the position of the button
            float x = (i % godsPerRow) * (buttonSize + spacing);
            float y = (i / godsPerRow) * (buttonSize + spacing);

            ImGui::SetCursorPos(ImVec2(x, y));

            // Render each god as a button
            if (ImGui::Button(gods[i].name, ImVec2(buttonSize, buttonSize)))
            {
                selectedGodIndex = i;
            }
        }
    }

    void RenderUI()
    {
        static char inputBuffer[256] = {};  // Buffer to store entered text
        static const char* buttonLabels[] = { "Gods", "Items", "Builds", "Statistics", "Settings" };
        static int selectedButton = -1;

        // Variables for view options
        static bool showGods = true;
        static bool showItems = true;

        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

        //list of gods
        static std::vector<God> gods = {
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            {"Zeus", "God of the sky and thunder"},
            {"Athena", "Goddess of wisdom and warfare"},
            // Add more gods as needed
        };

        // Index of the selected god
        static int selectedGodIndex = -1;

        // Main window
        ImGui::Begin("Smite Build Tool", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_MenuBar);

        // Menu bar
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                // Add menu items related to file operations
                ImGui::MenuItem("New Build", nullptr, false, true);  // Example: New Build functionality
                ImGui::MenuItem("Open Build", nullptr, false, true); // Example: Open Build functionality
                ImGui::Separator();
                ImGui::MenuItem("Save Build", nullptr, false, true); // Example: Save Build functionality
                ImGui::MenuItem("Save Build As...", nullptr, false, true); // Example: Save Build As functionality
                ImGui::Separator();
                ImGui::MenuItem("Exit", nullptr, false, true);  // Example: Exit functionality
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("View"))
            {
                if (ImGui::BeginMenu("God Filters"))
                {
                    // Add menu items related to God filters
                    bool showAssassin = true; // Change this based on your logic
                    bool showHunter = true;   // Change this based on your logic
                    bool showMage = true;     // Change this based on your logic
                    bool showGuardian = true; // Change this based on your logic
                    bool showWarrior = true;  // Change this based on your logic

                    ImGui::MenuItem("Assassin", nullptr, &showAssassin);  // Toggle Assassin filter
                    ImGui::MenuItem("Hunter", nullptr, &showHunter);       // Toggle Hunter filter
                    ImGui::MenuItem("Mage", nullptr, &showMage);           // Toggle Mage filter
                    ImGui::MenuItem("Guardian", nullptr, &showGuardian);   // Toggle Guardian filter
                    ImGui::MenuItem("Warrior", nullptr, &showWarrior);     // Toggle Warrior filter

                    // Add more roles as needed

                    ImGui::EndMenu();
                }


                if (ImGui::BeginMenu("Item Filters"))
                {
                    // Add menu items related to Item filters
                    bool showMagical = true; // Change this based on your logic
                    bool showPhysical = true; // Change this based on your logic

                    ImGui::MenuItem("Magical", nullptr, &showMagical);  // Toggle Magical filter
                    ImGui::MenuItem("Physical", nullptr, &showPhysical); // Toggle Physical filter

                    // Add more filters as needed
                    ImGui::EndMenu();
                }

                ImGui::EndMenu();
            }

            // Add more menu items if necessary

            ImGui::EndMenuBar();
        }


        // Sidebar (Buttons)
        ImGui::BeginChild("ButtonList", ImVec2(150, 0), true);
        for (int i = 0; i < IM_ARRAYSIZE(buttonLabels); ++i)
        {
            if (ImGui::Button(buttonLabels[i]))
            {
                // Button clicked, update content based on the selected button
                selectedButton = i;
            }
        }
        ImGui::EndChild();

        // Main content area
        ImGui::SameLine();
        float remainingWidth = ImGui::GetContentRegionAvail().x;
        float inputFieldHeight = 30.0f;
        ImGui::BeginChild("ContentArea", ImVec2(remainingWidth - 150, ImGui::GetContentRegionAvail().y - inputFieldHeight), true);
        if (selectedButton != -1)
        {
            // Switch based on the selected button
            switch (selectedButton)
            {
            case 0: // Gods button
                RenderGodList(gods, selectedGodIndex);
                if (selectedGodIndex >= 0 && selectedGodIndex < static_cast<int>(gods.size()))
                {
                    RenderGodDetails(gods[selectedGodIndex]);
                }
                break;
            case 1: // Items button
                RenderItemInventory();
                break;
            case 2: // Builds button
                // Render content for Builds
                ImGui::Text("Content for Builds button goes here");
                break;

            case 3: // Statistics button
                RenderStatistics();
                break;

            case 4: // Settings button
            {
                ImGui::TextColored(ImVec4(0.4f, 0.8f, 1.0f, 1.0f), "General Settings:");  // Light blue color for emphasis
                // Add customizable options here, e.g., language, theme, etc.

                ImGui::Separator();

                ImGui::TextColored(ImVec4(0.4f, 0.8f, 1.0f, 1.0f), "Display Options:");  // Light blue color for emphasis
                // Add options for resolution, brightness, etc.

                ImGui::Separator();

                // About/Help section
                ImGui::TextColored(ImVec4(0.4f, 0.8f, 1.0f, 1.0f), "About/Help");  // Light blue color for emphasis
                ImGui::Separator();

                ImGui::Text("Version:");
                ImGui::Indent();
                ImGui::Text("0.0.0");  // Set your version number here
                ImGui::Unindent();

                ImGui::Spacing();

                ImGui::Text("Made with:");
                ImGui::Indent();
                ImGui::Text("- Direct X 12");
                ImGui::Text("- Dear ImGui");
                ImGui::Unindent();

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Text("Developer: Pretisy");

                break;
            }

            // Add more cases for other buttons if needed
            default:
                ImGui::Text("Content for %s button goes here", buttonLabels[selectedButton]);
                break;
            }
        }
        ImGui::EndChild();

        // Input field at the bottom
        ImGui::SetCursorPos(ImVec2(150 + 2 * ImGui::GetStyle().ItemSpacing.x, ImGui::GetWindowSize().y - inputFieldHeight));
        ImGui::PushItemWidth(remainingWidth - 150); // Set the width to match the remaining width
        ImGui::InputText("##InputField", inputBuffer, IM_ARRAYSIZE(inputBuffer), ImGuiInputTextFlags_EnterReturnsTrue);
        ImGui::PopItemWidth();

        ImGui::End(); // End main window
    }

}
