#pragma once

#include <cstdint>
#include <bitset>

constexpr size_t MAX_COMPONENTS = 32;
constexpr size_t MAX_ENTITIES = 5'000;

using Entity = std::uint32_t;
using TileId = std::uint16_t;
using ComponentTypeId = std::uint8_t;

using ComponentMask = std::bitset<MAX_COMPONENTS>;
