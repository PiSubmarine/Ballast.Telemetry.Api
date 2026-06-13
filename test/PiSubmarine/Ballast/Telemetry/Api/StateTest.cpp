#include <gtest/gtest.h>

#include "PiSubmarine/Ballast/Telemetry/Api/State.h"

namespace PiSubmarine::Ballast::Telemetry::Api
{
    TEST(StateTest, StoresOptionalPosition)
    {
        const State state{.Position = NormalizedFraction(0.35)};

        ASSERT_TRUE(state.Position.has_value());
        EXPECT_EQ(static_cast<double>(*state.Position), 0.35);
    }

    TEST(StateTest, EqualityComparesPositionByValue)
    {
        const State left{.Position = NormalizedFraction(0.2)};
        const State right{.Position = NormalizedFraction(0.2)};

        EXPECT_EQ(left, right);
    }
}
