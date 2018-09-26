//
// Created by ren on 25.9.2018.
//
#include <gtest/gtest.h>
#include "../Model.h"
#include "../TestObserver.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/progdlg.h>

TEST(runAllTests, testAddFile){
    Model* myTestingModel = new Model;
    ASSERT_FALSE(myTestingModel->addFile("/C/Windows/this/path/doesnt/exist"))<<"invalid file path";
    ASSERT_TRUE(myTestingModel->addFile("/home/ren/Desktop/testFile1"));
    ASSERT_TRUE(myTestingModel->addFile("/home/ren/Desktop/testFile2"));
}

class Model_Fixture:public ::testing::Test{
protected:
    virtual void SetUp(){
        myTestingModel.addFile("/home/ren/Desktop/testFile1");
    }
    Model myTestingModel;
};

TEST_F(Model_Fixture, testReadFile){
    std::vector<std::string> myFiles = myTestingModel.readFiles();
    std:: vector<std::string> myExpect;
    myExpect.push_back("\ntestFile1\n");
    ASSERT_EQ(myExpect, myFiles);
    myTestingModel.addFile("/home/ren/Desktop/testFile2");
    myFiles = myTestingModel.readFiles();
    ASSERT_NE(myExpect, myFiles);
}

TEST_F(Model_Fixture, testGetFileSize){
    EXPECT_NE(112, myTestingModel.getFilesSize());
    EXPECT_EQ(10, myTestingModel.getFilesSize());
}

TEST(runAllTests, testingObserver){
    Model* myTestingModel = new Model;
    ASSERT_TRUE(myTestingModel->addFile("/home/ren/Desktop/testFile1"));
    ASSERT_TRUE(myTestingModel->addFile("/home/ren/Desktop/testFile2"));
    TestObserver* myTestObserver = new TestObserver;
    myTestingModel->addObserver(myTestObserver);
    myTestingModel->notify(10);
    EXPECT_EQ(10, myTestObserver->getTestResult());
}


