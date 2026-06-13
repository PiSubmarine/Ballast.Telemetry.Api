#include <gtest/gtest.h>

#include "PiSubmarine/Ballast/Telemetry/Api/IProviderMock.h"

namespace PiSubmarine::Ballast::Telemetry::Api
{
    TEST(IProviderMockTest, GetStateReturnsConfiguredState)
    {
        IProviderMock providerMock;
        const State expectedState{.Position = NormalizedFraction(0.5)};

        EXPECT_CALL(providerMock, GetState())
            .WillOnce(testing::Return(Error::Api::Result<State>(expectedState)));

        const auto result = providerMock.GetState();

        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(result.value(), expectedState);
    }
}
