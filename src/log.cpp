#include <filesystem>
#include <glog/logging.h>
namespace fs = std::filesystem;

namespace flowAnalysis
{
void InitLogSystem()
{
    google::InitGoogleLogging("flowAnalysis"); // 初始化 glog

    fs::path path = fs::current_path().append("logs");

    // 设置日志输出路径
    google::SetLogDestination(google::GLOG_INFO, path.append("info").string().c_str());
    google::SetLogDestination(google::GLOG_WARNING, path.append("warning").string().c_str());
    google::SetLogDestination(google::GLOG_ERROR, path.append("error").string().c_str());

    // 启动 glog
    google::InstallFailureSignalHandler();
}
} // namespace flowAnalysis
