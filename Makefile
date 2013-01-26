MACHINE = $(shell uname -s)
SOURCE_DIRS = parsers readers nodes
TEST_DIRS = gtest/src $(SOURCE_DIRS)

CXX = g++

ifeq ($(MACHINE), Darwin)
	CXX = clang++ -std=c++0x -stdlib=libc++
endif

ifeq ($(MACHINE), Linux)
	CXX = clang++
endif

OUT = libyayp.a
CFLAGS = -g

INCLUDES =  

TEST_INCLUDES = -Itest/include -Itest/gtest -Isrc

OBJS = $(patsubst src/%.cpp,obj/%.o,$(wildcard src/*.cpp)) $(patsubst src/%.cpp,obj/%.o,$(wildcard src/**/*.cpp))
TEST_OBJS = $(patsubst test/%.cpp,test_obj/%.o,$(wildcard test/*.cpp)) $(patsubst test/%.cpp,test_obj/%.o,$(wildcard test/**/*.cpp))
GTEST_OBJS = $(patsubst test/%.cc,test_obj/%.o,$(wildcard test/gtest/src/*.cc))

$(OUT): $(OBJS)
	ar cr $(OUT) $(OBJS)

obj/%.o: src/%.cpp
	$(CXX) -c $(CFLAGS) -o $@ $< $(INCLUDES)

test_obj/%.o: test/%.cpp
	$(CXX) -c $(CFLAGS) -o $@ $< $(INCLUDES) $(TEST_INCLUDES) -DGTEST_HAS_TR1_TUPLE="0"

test_obj/%.o: test/%.cc
	$(CXX) -c $(CFLAGS) -o $@ $< $(INCLUDES) $(TEST_INCLUDES) -DGTEST_HAS_TR1_TUPLE="0"

test: $(OUT) $(TEST_OBJS) $(GTEST_OBJS)
	$(CXX) $(CFLAGS) -o yayp_test.out $(OUT) $(LIBS) $(TEST_OBJS) $(GTEST_OBJS)

dirs:
	for DIRECTORY in $(SOURCE_DIRS) ; do \
		test -d obj/$$DIRECTORY || mkdir -p obj/$$DIRECTORY; \
	done

	for DIRECTORY in $(TEST_DIRS) ; do \
		test -d test_obj/$$DIRECTORY || mkdir -p test_obj/$$DIRECTORY; \
	done

clean:
	rm -f $(OUT) $(OBJS)

test_clean:
	rm -f yayp_test.out $(OBJS) $(TEST_OBJS)
