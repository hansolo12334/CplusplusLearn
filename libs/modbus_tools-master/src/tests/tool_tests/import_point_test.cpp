#include "tools/import_point.h"
#include "device/device.h"
#include "gtest/gtest.h"
#include "util/env.hpp"

class TestPointImporter : public testing::Test
{
protected:
    virtual void SetUp()
    {
        // auto device = std::make_shared<Device>();
        // PointImporter pointImporter(device, "test");
        // pointImporter.importPointCsv();
    }
};

TEST_F(TestPointImporter, test_import_point_csv)
{
    std::string pcsPath = csvPath() + "tuobang_pcs.csv";
    auto device = std::make_shared<Device>();
    PointImporter pointImporter(device);
    pointImporter.importPointCsv(pcsPath);
    if (pointImporter.device.expired())
        return;
    if (auto sharedDevice = pointImporter.device.lock())
    {
        std::cout << "deviceName:" << sharedDevice->name << std::endl;
        for (const auto &[slaveId, ycList] : sharedDevice->ycMap)
        {
            std::cout << "yc slaveId:" << slaveId << std::endl;
            for (const auto &yc : ycList)
            {
                std::cout << yc->info() << "\n";
            }
            std::cout << std::endl;
            for (const auto &[slaveId, yxList] : sharedDevice->yxMap)
            {
                std::cout << "yx slaveId:" << slaveId << std::endl;
                for (const auto &yx : yxList)
                {
                    std::cout << yx->info() << "\n";
                }
            }
        }
    }
}

TEST_F(TestPointImporter, test_import_cluster_point_csv)
{
    std::string bmsPath = csvPath() + "tuobang_bms.csv";
    std::string clusterPath = csvPath() + "tuobang_bms_cluster.csv";
    auto device = std::make_shared<Device>();
    PointImporter pointImporter(device);
    // pointImporter.importPointCsv(bmsPath);
    pointImporter.importClusterPointCsv(clusterPath);
    if (pointImporter.device.expired())
        return;
    if (auto sharedDevice = pointImporter.device.lock())
    {
        std::cout << "deviceName:" << sharedDevice->name << std::endl;
        for (const auto &[slaveId, ycList] : sharedDevice->ycMap)
        {
            std::cout << "yc slaveId:" << slaveId << std::endl;
            for (const auto &yc : ycList)
            {
                std::cout << yc->info() << "\n";
            }
            std::cout << std::endl;
            for (const auto &[slaveId, yxList] : sharedDevice->yxMap)
            {
                std::cout << "yx slaveId:" << slaveId << std::endl;
                for (const auto &yx : yxList)
                {
                    std::cout << yx->info() << "\n";
                }
            }
        }
    }
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}