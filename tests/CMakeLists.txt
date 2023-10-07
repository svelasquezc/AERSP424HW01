foreach(X RANGE 1 3)
    add_executable(question${X} ${AIRCRAFT_HEADERS} question${X}.cpp)

    target_include_directories(question${X} PUBLIC ../include)

    target_link_libraries(question${X} PRIVATE aircraft)

    add_test(NAME question${X} COMMAND question${X})    
endforeach()


foreach(X RANGE 4 9)
    add_executable(question${X} ${AIRCRAFT_HEADERS} question${X}.cpp)

    target_include_directories(question${X} PUBLIC ../include)

    target_link_libraries(question${X} PRIVATE classifier)

    add_test(NAME question${X} COMMAND question${X})    
endforeach()