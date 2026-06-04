#include "Core/Types.h"

class InputManager;

enum class Action
{
    Unknown,

    Pause,
    OpenVillagersMenu,
    OpenInventoryMenu,
    OpenBuildingsMenu,

    Count
};

class Input
{
public:
    Input() = default;

    void begin_frame();

    const bool is_down(Action action) const;
    const bool is_pressed(Action action) const;
    const bool is_released(Action action) const;

    const bool should_exit() const;

private:
    friend class InputManager;

    std::bitset<static_cast<size_t>(Action::Count)> down;
    std::bitset<static_cast<size_t>(Action::Count)> pressed;
    std::bitset<static_cast<size_t>(Action::Count)> released;

    bool exit = false;
};
