// A print inside a loop, which is how a learner looks at what their code is
// doing. The runner keeps the first 50K of each stream and drops the rest, so
// the summary line the rag-lambda reads is thrown away and the run is amber
// even though the test passes.
#include "hiker.hpp"
#include "mock_logger.hpp"
#include <gmock/gmock.h>
#include <iostream>

using namespace ::testing;

namespace {

TEST(Hiker, Life_the_universe_and_everything)
{
    MockLogger logger;
    EXPECT_CALL(logger, log("Hiker::answer()")).Times(Exactly(1));
    Hiker arthur(logger);
    int total = 0;
    for (int i = 0; i != 5000; i++)
    {
        std::cout << "debug: i is " << i << ", total is " << total << std::endl;
        total += i;
    }
    ASSERT_THAT(arthur.answer(), Eq(42));
}

}
