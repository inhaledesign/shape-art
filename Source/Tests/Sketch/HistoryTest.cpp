#include "History.h"
#include "gtest/gtest.h"
#include <stdexcept>


class HistoryTest : public ::testing::Test {
protected:
    THistory<int>* History = new THistory<int>;

    void PostValueSeries(int Count) {
        for(int i = 10; i <= Count * 10; i += 10) {
            History->Post(i);
        }
    }

    void StepPrevious(int Count = 1) {
        for(int i = 0; i < Count; i++) {
            History->StepPrevious();
        }
    }

    void StepNext(int Count = 1) {
        for(int i = 0; i < Count; i++) {
            History->StepNext();
        }
    }

    void PostValue(int Value) { History->Post(Value); }

    THistory<int>::THistoryNode* GetCurrent() { return History->GetCurrent(); }

    THistory<int>::THistoryNode* GetHead() { return History->GetHead(); }

    int GetCurrentValue() { return History->GetCurrent()->GetValue(); }

    bool IsHead() { return History->IsHead(); }

    bool IsTail() { return History->IsTail(); }

};

TEST_F(HistoryTest, GetCurrent) {
    PostValue(10);
    EXPECT_NE(GetCurrent(), nullptr);
    EXPECT_EQ(GetCurrentValue(), 10);

    PostValue(25);
    EXPECT_NE(GetCurrent(), nullptr);
    EXPECT_EQ(GetCurrentValue(), 25);
}

TEST_F(HistoryTest, StepPrevious) {
    PostValueSeries(4);
    
    for(int expected = 30; expected >= 10; expected -= 10) {
        StepPrevious();
        EXPECT_EQ(GetCurrentValue(), expected);
    }
}

TEST_F(HistoryTest, StepPreviousAndPost) {
    PostValueSeries(3);
    StepPrevious(2);
    PostValue(99);
    
    EXPECT_EQ(GetCurrentValue(), 99);
}


TEST_F(HistoryTest, StepNext) {
    PostValueSeries(4);

    StepPrevious(4);

    for(int expected = 10; expected <= 40; expected += 10) {
        StepNext();
        EXPECT_EQ(GetCurrentValue(), expected);
    }
}

TEST_F(HistoryTest, OverstepTail) {
    PostValue(10);
    EXPECT_THROW(StepNext(), std::out_of_range);
}

TEST_F(HistoryTest, OverstepHead) {
    PostValueSeries(10);
    StepPrevious(10);
    EXPECT_THROW(StepPrevious(), std::out_of_range);
}

TEST_F(HistoryTest, GetCurrentOnHead) {
    PostValueSeries(10);
    StepPrevious(10);
    EXPECT_THROW(GetCurrentValue(), std::out_of_range);
}

TEST_F(HistoryTest, IsHead) {
    EXPECT_TRUE(IsHead());
    PostValue(1);
    EXPECT_FALSE(IsHead());
    StepPrevious();
    EXPECT_TRUE(IsHead());
    StepNext();
    EXPECT_FALSE(IsHead());
}

TEST_F(HistoryTest, IsTail) {
    EXPECT_TRUE(IsTail());
    PostValue(1);
    EXPECT_TRUE(IsTail());
    StepPrevious();
    EXPECT_FALSE(IsTail());
    StepNext();
    EXPECT_TRUE(IsTail());
}

TEST_F(HistoryTest, DeleteHistory) {
    PostValueSeries(100);
    delete History;
}