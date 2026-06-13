#pragma once

#include <optional>

#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::Ballast::Telemetry::Api
{
    struct State
    {
        std::optional<NormalizedFraction> Position;

        [[nodiscard]] constexpr bool operator==(const State& other) const noexcept
        {
            return OptionalPositionEqual(Position, other.Position);
        }

    private:
        [[nodiscard]] static constexpr bool OptionalPositionEqual(
            const std::optional<NormalizedFraction>& left,
            const std::optional<NormalizedFraction>& right) noexcept
        {
            if (left.has_value() != right.has_value())
            {
                return false;
            }

            return !left.has_value() || static_cast<double>(*left) == static_cast<double>(*right);
        }
    };
}
