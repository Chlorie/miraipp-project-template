#include <mirai/mirai.h>

using unifex::task;

task<bool> repeat(const mpp::Event& ev)
{
    if (const auto* ptr = ev.get_if<mpp::GroupMessageEvent>())
    {
        co_await ptr->send_message_async(ptr->content());
        co_return ptr->content() == "stop";
    }
    co_return false;
}

int main()
{
    using namespace mpp::literals;

    mpp::launch_async_bot([](mpp::Bot& bot) -> task<void>
    {
        co_await bot.authorize_async("auth key", 123456789_uid);
        co_await bot.config_async({ .enable_websocket = true });
        co_await bot.monitor_events_async(repeat);
    });
    return 0;
}
