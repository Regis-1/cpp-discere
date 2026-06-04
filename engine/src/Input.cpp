#include "Engine/Input.h"

void Input::begin_frame()
{
    this->pressed.reset();
    this->released.reset();
    this->exit = false;
}

const bool Input::is_down(const Action action) const
{
    return this->down.test(static_cast<size_t>(action));
}

const bool Input::is_pressed(const Action action) const
{
    return this->pressed.test(static_cast<size_t>(action));
}

const bool Input::is_released(const Action action) const
{
    return this->released.test(static_cast<size_t>(action));
}

const bool Input::should_exit() const
{
    return this->exit;
}
