# Read and store CSV data in dataframe

dataset_path <- "Dataset/Joint Dataset.csv"
original_df <- read.csv(dataset_path)

# Clean data

#cleaned_df <- na.omit(df) #DOES THIS ROW NOT WORK BECAUSE THE COLUMN DOESN'T CONTAIN NULL VALUES

df <- original_df[rowSums(original_df == ".") == 0, ]

# Add column of SP500 day over day gain by percentage

df$SP500 <- as.numeric(as.character(df$SP500))
df$SP500_DAILY_GAIN <- c(NA, diff(df$SP500) / df$SP500[-nrow(df)]) * 100
df <- df[-1, ]

# Continue cleaning

df_original_cleaned <- df
df <- df[rowSums(df == "") == 0, ]
head(df)

# Add metadata as an attribute to dataframe

df_metadata <- readLines("Dataset/Joint Dataset Metadata.txt")
attr(df, "metadata") <- df_metadata
attributes(df)

# Retrieve text of each speech and store it in its respective row

df$TEXT_OF_SPEECH <- character(nrow(df))
for (i in 1:nrow(df)) {
  file_name <- paste0("Dataset/", df$CHAIR_POWELL_FED_SPEECH_NAMES[i], ".txt")
  speech_text <- readChar(file_name, file.info(file_name)$size)
  df$TEXT_OF_SPEECH[i] <- speech_text
}
#print(df)

# TEXT_OF_SPEECH column data preprocessing - make lowercase, removal of some whitespace

df$TEXT_OF_SPEECH <- tolower(df$TEXT_OF_SPEECH)
df$TEXT_OF_SPEECH <- gsub("[\r\n\t]", " ", df$TEXT_OF_SPEECH)

# Original dataframe summary

summary(original_df)

# EDA 1 - Time Series of S&P500

library(tidyverse) # make sure installed

# This a time series of all S&P500 data
df_original_cleaned$DATE <- as.Date(df_original_cleaned$DATE, format='%m/%d/%Y') # use standard date format 
df_original_cleaned$SP500 <- as.numeric(as.character(df_original_cleaned$SP500))
ggplot(df_original_cleaned, aes(x = DATE, y = SP500)) +
  geom_line() +
  labs(title = "S&P 500 Time Series All Days", x = "Year", y = "SP500 Index Price")

# This a time series of all S&P500 data in all rows without null values
df$DATE <- as.Date(df$DATE, format='%m/%d/%Y') # use standard date format 
df$SP500 <- as.numeric(as.character(df$SP500))
ggplot(df, aes(x = DATE, y = SP500)) +
  geom_line() +
  labs(title = "S&P 500 Time Series Fed Speech Days", x = "Year", y = "SP500 Index Price")

# This a time series of all S&P500 daily gain data
df_original_cleaned$DATE <- as.Date(df_original_cleaned$DATE, format='%m/%d/%Y') # use standard date format 
df_original_cleaned$SP500_DAILY_GAIN <- as.numeric(as.character(df_original_cleaned$SP500_DAILY_GAIN))
ggplot(df_original_cleaned, aes(x = DATE, y = SP500_DAILY_GAIN)) +
  geom_line() +
  labs(title = "S&P 500 Daily % Gain Time Series All Days", x = "Year", y = "SP500 Index Price")

# This a time series of all S&P500 daily gain data in all rows without null values
df$DATE <- as.Date(df$DATE, format='%m/%d/%Y') # use standard date format 
df$SP500_DAILY_GAIN <- as.numeric(as.character(df$SP500_DAILY_GAIN))
ggplot(df, aes(x = DATE, y = SP500_DAILY_GAIN)) +
  geom_line() +
  labs(title = "S&P 500 Daily % Gain Time Series Fed Speech Days", x = "Year", y = "SP500 Index Price")

# EDA 2 - Histogram of the S&P500

# This a histogram of all S&P500 data
ggplot(df_original_cleaned, aes(x = SP500)) +
  geom_histogram(binwidth = 50, fill = "lightblue", color = "black") +
  labs(title = "Histogram of S&P 500 Prices All Days",
       x = "S&P 500 Price",
       y = "Frequency")

# This a histogram of all S&P500 data in all rows without null values
ggplot(df, aes(x = SP500)) +
  geom_histogram(binwidth = 50, fill = "lightblue", color = "black") +
  labs(title = "Histogram of S&P 500 Prices Fed Speech Days",
       x = "S&P 500 Price",
       y = "Frequency")

# This a histogram of all S&P500 daily gain data
ggplot(df_original_cleaned, aes(x = SP500_DAILY_GAIN)) +
  geom_histogram(binwidth = 0.5, fill = "lightblue", color = "black") +
  labs(title = "Histogram of S&P 500 Daily % Gain All Days",
       x = "S&P 500 Price",
       y = "Frequency")

# This a histogram of all S&P500 daily gain data in all rows without null values
ggplot(df, aes(x = SP500_DAILY_GAIN)) +
  geom_histogram(binwidth = 0.5, fill = "lightblue", color = "black") +
  labs(title = "Histogram of S&P 500 Daily % Gain Fed Speech Days",
       x = "S&P 500 Price",
       y = "Frequency")

# EDA 3 - Word Cloud of Speeches

library(stringr)
library(wordcloud)

all_text <- paste(df$TEXT_OF_SPEECH, collapse = " ") # combine all speech text
words <- unlist(strsplit(all_text, " "))
wordcloud(words = words, min.freq = 10, colors = brewer.pal(8, "Dark2"), random.order = FALSE) # create wordcloud
title(main = "Word Cloud of Speeches", col.main = "blue", font.main = 4)

# EDA 4 

summary(df_original_cleaned) # summary of original cleaned dataframe
summary(df) # summary of final dataframe

# Save df as .csv in Dataset folder

write.csv(df, file = "Dataset/Dataset Post EDA.csv", row.names = FALSE)

