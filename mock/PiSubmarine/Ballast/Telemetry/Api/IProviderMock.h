#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Ballast/Telemetry/Api/IProvider.h"

namespace PiSubmarine::Ballast::Telemetry::Api
{
    class IProviderMock : public IProvider
    {
    public:
        MOCK_METHOD((Error::Api::Result<State>), GetState, (), (const, override));
    };
}
