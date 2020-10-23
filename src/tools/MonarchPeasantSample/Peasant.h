#pragma once

#include "Peasant.g.h"
#include "../cascadia/inc/cppwinrt_utils.h"

// 50dba6cd-1111-4b12-8363-5e06f5d0082c
static constexpr GUID Peasant_clsid{
    0x50dba6cd,
    0x1111,
    0x4b12,
    { 0x83, 0x63, 0x5e, 0x06, 0xf5, 0xd0, 0x08, 0x2c }
};

namespace winrt::MonarchPeasantSample::implementation
{
    struct PeasantBase
    {
        void AssignID(uint64_t id) { id; }
        uint64_t GetID() { return 42; }
        uint64_t GetPID() { return 69; }
        bool ExecuteCommandline(winrt::array_view<const winrt::hstring> args, winrt::hstring currentDirectory)
        {
            args;
            currentDirectory;
            return true;
        }
        TYPED_EVENT(WindowActivated, winrt::Windows::Foundation::IInspectable, winrt::Windows::Foundation::IInspectable);

    private:
    };

    struct Peasant : public PeasantT<Peasant>, public PeasantBase
    {
        Peasant();

    private:
    };
}

namespace winrt::MonarchPeasantSample::factory_implementation
{
    struct Peasant : PeasantT<Peasant, implementation::Peasant>
    {
    };
}
