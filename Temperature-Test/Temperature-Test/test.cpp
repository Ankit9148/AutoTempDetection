#include "pch.h"
#include "D:\AutoTempDetection\AutoTempDetection\AutoTempDetection\AutoTempDetection.cpp"

TEST(TemperatureTest, TestCase1) {
  EXPECT_EQ(runAutoTempControl(50, 30, 32), "Minimum room temperature cannot be more than maximum room temperature\n");
  EXPECT_TRUE(true);
}

TEST(TemperatureTest, TestCase2) {
	EXPECT_EQ(runAutoTempControl("Hello", 30, 32), "Invalid Input Type. Use integer number to set temperature\n");
	EXPECT_TRUE(true);
}

TEST(TemperatureTest, TestCase3) {
	EXPECT_EQ(runAutoTempControl(50), "Please enter minimum, maximum and present room temperature. Missing Arguments\n");
	EXPECT_TRUE(true);
}


TEST(TemperatureTest, TestCase4) {
	EXPECT_EQ(runAutoTempControl(50, 50, 50), "Warning!! both heater and cooler running at the same time. Adjust temperature\n");
	EXPECT_TRUE(true);
}

TEST(TemperatureTest, TestCase5) {
	EXPECT_EQ(runAutoTempControl(-500, 30, 32), "No temperature can be less than -270 degree C\n");
	EXPECT_TRUE(true);
}

TEST(TemperatureTest, TestCase6) {
	EXPECT_EQ(runAutoTempControl(20, 40, 32), "Pleasant Room Temperatutre. Both heater and cooler are off\n");
	EXPECT_TRUE(true);
}

TEST(TemperatureTest, TestCase7) {
	EXPECT_EQ(runAutoTempControl(20, 30, 15), "Heating started\n");
	EXPECT_TRUE(true);
}

TEST(TemperatureTest, TestCase8) {
	EXPECT_EQ(runAutoTempControl(10, 25, 32), "Cooling started\n");
	EXPECT_TRUE(true);
}

TEST(TemperatureTest, TestCase9) {
	EXPECT_EQ(runAutoTempControl(10, 2000, 32), "No temperature can be more than 100 degree C\n");
	EXPECT_TRUE(true);
}