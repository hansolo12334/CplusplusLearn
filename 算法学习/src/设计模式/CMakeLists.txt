add_executable(hungry_guy_parten 单例模式/饿汉模式.cc)
add_executable(hungry_guy_parten_with_thread_locker 单例模式/饿汉模式_线程安全加锁.cc)


add_executable(abstract_factory_mode 工厂模式/抽象工厂模式.cc)
add_executable(simple_factory_mode 工厂模式/简单工厂模式.cc)


add_executable(observer_mode 观察者模式/观察者模式.cc)

add_executable(producer_custmer 生产者消费者模式/producer_custmer.cc )
target_link_libraries(producer_custmer pthread)


add_executable(produer_custmer_c20 生产者消费者模式/produer_custmer_c20.cc )
target_link_libraries(produer_custmer_c20 pthread)


add_executable(practice_thread practice/thread.cc)
target_link_libraries(practice_thread pthread)


add_executable(practice_thread2 practice/thread2.cc)
target_link_libraries(practice_thread2 pthread)
