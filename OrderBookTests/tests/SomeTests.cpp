#include <gtest/gtest.h>
#include <OrderBook.h>

TEST(OrderBookTests, OrderBookEmptyByDefault)
{
    OrderBook book;
    EXPECT_TRUE(book.is_empty());
}

TEST(OrderBookTests, OrderAdditionWorks)
{
    OrderBook book;
    book.add_bid(123, 456);
    auto bidask = book.get_bid_ask();
    EXPECT_TRUE(bidask.bid.is_initialized());\
    auto bid = bidask.bid.get();
    EXPECT_EQ(123, bid.first);
    EXPECT_EQ(456, bid.second);
}

TEST(OrderBookTests, OrderRemovalWorks){
    OrderBook book;
    book.add_bid(123, 456);
    book.remove_bid(123,156);
    auto bidask = book.get_bid_ask();
    EXPECT_TRUE(bidask.bid.is_initialized());
    auto bid = bidask.bid.get();
    EXPECT_EQ(123, bid.first);
    EXPECT_EQ(456-156, bid.second);
}

TEST(OrderBookTests, SpreadCalculated){
    OrderBook book;
    book.add_bid(50, 100);
    book.add_ask(70, 100);
    auto bidask = book.get_bid_ask();
    EXPECT_TRUE(bidask.bid.is_initialized());
    EXPECT_TRUE(bidask.ask.is_initialized());
    auto spread = bidask.spread();
    EXPECT_TRUE(spread.is_initialized());
    EXPECT_EQ(20, spread.get());
}
