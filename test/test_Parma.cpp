#include "Parma.hpp"
#include <filesystem>
#include <fmt/core.h>
#include <fstream>
#include <gtest/gtest.h>
namespace fs = std::filesystem;
using std::string;

TEST(Parma, ToString)
{
    flowAnalysis::Parma p{
        .xmax = 1,
        .ymax = 1,
        .imax = 1,
        .jmax = 1,
        .pressure = 1,
        .voltage = 1,
        .dt = 1,
        .gamma = 1,
        .i2 = 1,
        .i3 = 1,
        .F_He = 1,
        .F_CO_2 = 1,
    };
    auto jsonString = p.ToString();

    fmt::print("jsonString = {}\n", jsonString);
}

TEST(Parma, ToFile)
{
    flowAnalysis::Parma p{
        .xmax = 1,
        .ymax = 1,
        .imax = 1,
        .jmax = 1,
        .pressure = 1,
        .voltage = 1,
        .dt = 1,
        .gamma = 1,
        .i2 = 1,
        .i3 = 1,
        .F_He = 1,
        .F_CO_2 = 1,
    };
    fs::path path = fs::current_path().append("input").append("Parma.json");
    ASSERT_TRUE(p.ToFile(path.string()));
}

TEST(Parma, Parse)
{
    std::ifstream inputFile(fs::current_path().append("input").append("Parma.json").string());
    if (inputFile.is_open())
    {
        // 读取文件的所有内容
        std::string strJson((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
        auto p = flowAnalysis::Parma::Parse(strJson);
        fmt::print("jsonString = {}\n", p->ToString());
        inputFile.close(); // 关闭文件
        ASSERT_TRUE(true);
    }
    else
    {
        std::cerr << "Error opening file." << std::endl;
        ASSERT_TRUE(false);
    }
    
}