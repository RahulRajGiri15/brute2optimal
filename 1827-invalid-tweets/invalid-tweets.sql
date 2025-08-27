# Write your MySQL query statement below

# Select tweet_id from Tweets where length(content) > 15 ;

# another method

Select tweet_id from Tweets where char_length(content) > 15 ;