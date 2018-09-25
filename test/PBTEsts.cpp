//
// Created by ren on 25.9.2018.
//
#include <gtest/gtest.h>
#include "../Model.h"
#include "../View.h"
#include "../ScrolledPanel.h"

TEST(runAllTests, testAddFile){
    Model* myTestingModel = new Model;
    ASSERT_TRUE(myTestingModel->addFile("/C/Windows"))<<"invalid file path";
}




