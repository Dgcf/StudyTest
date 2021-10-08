cmake_minimum_required(VERSION 3.20)
project(DesignModel)

set(CMAKE_CXX_STANDARD 14)

include_directories(DesignModel)

add_executable(DesignModel
        DesignModel/AbstractFactory.h
        DesignModel/Bridge.h
        DesignModel/ChainOfResponsibility.cpp
        DesignModel/ChainOfResponsibility.h
        DesignModel/Command.h
        DesignModel/common.h
        DesignModel/Composite.h
        DesignModel/decorator.h
        DesignModel/DesignModel.cpp
        DesignModel/Facade.h
        DesignModel/factory.cpp
        DesignModel/factory.h
        DesignModel/ForTest.cpp
        DesignModel/ForTest.h
        DesignModel/Functor.h
        DesignModel/Interpreter.cpp
        DesignModel/Interpreter.h
        DesignModel/Iterator.h
        DesignModel/Mediator.cpp
        DesignModel/Mediator.h
        DesignModel/MemAlloc.cpp
        DesignModel/MemAlloc.h
        DesignModel/Memento.h
        DesignModel/Multimethods.h
        DesignModel/Observer.h
        DesignModel/policy.h
        DesignModel/Proxy.h
        DesignModel/Singletons.cpp
        DesignModel/Singletons.h
        DesignModel/SmartPtr.h
        DesignModel/State.h
        DesignModel/static_check.h
        DesignModel/Strategy.h
        DesignModel/TemplateMethod.h
        DesignModel/TypeInfo.h
        DesignModel/typelist.h
        DesignModel/typetraits.h
        DesignModel/visitable.cpp
        DesignModel/visitable.h
        DesignModel/visitor.cpp
        DesignModel/visitor.h)
