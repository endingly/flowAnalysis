#include "parma.hpp"
#include <fmt/core.h>
#include <fstream>
#include <glog/logging.h>
#include <nlohmann/json.hpp>

namespace fs = std::filesystem;
using std::string, flowAnalysis::parma, std::unique_ptr;

string parma::ToString(/* args */)
{
    nlohmann::json j;
    j["xmax"]     = xmax;
    j["ymax"]     = ymax;
    j["imax"]     = imax;
    j["jmax"]     = jmax;
    j["pressure"] = pressure;
    j["voltage"]  = voltage;
    j["dt"]       = dt;
    j["gamma"]    = gamma;
    j["i2"]       = i2;
    j["i3"]       = i3;
    j["F_He"]     = F_He;
    j["F_CO_2"]   = F_CO_2;
    return j.dump(4);
}

std::unique_ptr<parma> parma::Parse(string jsonString)
{
    nlohmann::json j   = nlohmann::json::parse(jsonString);
    auto           ptr = std::make_unique<parma>();
    auto           p   = *ptr;
    p.xmax             = j["xmax"];
    p.ymax             = j["ymax"];
    p.imax             = j["imax"];
    p.jmax             = j["jmax"];
    p.pressure         = j["pressure"];
    p.voltage          = j["voltage"];
    p.dt               = j["dt"];
    p.gamma            = j["gamma"];
    p.i2               = j["i2"];
    p.i3               = j["i3"];
    p.F_He             = j["F_He"];
    p.F_CO_2           = j["F_CO_2"];
    return std::move(ptr);
}

bool parma::ToFile(string path)
{
    fs::path p(path);

    auto dir = p.remove_filename();
    if (!fs::exists(dir))
    {
        fs::create_directory(dir);
    }
    std::ofstream outputFile(path, std::ios::trunc);
    if (outputFile.is_open())
    {
        outputFile << ToString();
        outputFile.close();
        LOG(INFO) << "JSON data has been written to " << path << "\n";
        return true;
    }
    else
    {
        LOG(ERROR) << "Unable to open file for writing\n";
        return false;
    }
}

std::unique_ptr<parma> FromFile(std::string path)
{
    std::ifstream inputFile(path);
    if (inputFile.is_open())
    {
        // 读取文件的所有内容
        std::string strJson((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
        auto        p = flowAnalysis::parma::Parse(strJson);
        fmt::print("jsonString = {}\n", p->ToString());
        inputFile.close(); // 关闭文件
        LOG(INFO) << "JSON data has been read from " << path << "\n";
        return std::move(p);
    }
    else
    {
        LOG(ERROR) << "JSON data has been read from " << path << "\n";
        return nullptr;
    }
}
