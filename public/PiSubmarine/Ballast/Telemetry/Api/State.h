#pragma once

#include <optional>

#include "PiSubmarine/Ballast/BallastFillFraction.h"

namespace PiSubmarine::Ballast::Telemetry::Api
{
    struct State
    {
        std::optional<BallastFillFraction> Position;

        [[nodiscard]] constexpr bool operator==(const State& other) const noexcept
        {
            return OptionalPositionEqual(Position, other.Position);
        }

    private:
        [[nodiscard]] static constexpr bool OptionalPositionEqual(
            const std::optional<BallastFillFraction>& left,
            const std::optional<BallastFillFraction>& right) noexcept
        {
            if (left.has_value() != right.has_value())
            {
                return false;
            }

            return !left.has_value() || static_cast<double>(*left) == static_cast<double>(*right);
        }
    };
}
