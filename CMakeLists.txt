cmake_minimum_required(VERSION 3.6)
project(stock)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        controller/productutil.cpp
        controller/productutil.h
        controller/providerutil.cpp
        controller/providerutil.h
        controller/purchaseutil.cpp
        controller/purchaseutil.h
        controller/salecontroller.cpp
        controller/salecontroller.h
        controller/saleutil.cpp
        controller/saleutil.h
        controller/util.cpp
        controller/util.h
        demo/appinit.cpp
        demo/appinit.h
        demo/sliderbar.cpp
        demo/sliderbar.h
        entity/employee.cpp
        entity/employee.h
        entity/product.cpp
        entity/product.h
        entity/provider.cpp
        entity/provider.h
        entity/purchase.cpp
        entity/purchase.h
        entity/sale.cpp
        entity/sale.h
        entity/user.cpp
        entity/user.h
        form/quiwidget.cpp
        form/quiwidget.h
        tab/form11.cpp
        tab/form11.h
        tab/form12.cpp
        tab/form12.h
        dialog.cpp
        dialog.h
        head.h
        login.cpp
        login.h
        loginform.cpp
        loginform.h
        main.cpp)

add_executable(stock ${SOURCE_FILES})