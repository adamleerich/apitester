library(tidyverse)

cran_db <- tools::CRAN_package_db()
cran_db <- as_tibble(cran_db)

cran_db |> 
  group_by(License) |> 
  summarize(COUNT = n()) |> 
  filter(grepl('^CC', License))




cran_db |> 
  filter(
    NeedsCompilation == 'yes',
    str_starts(License, 'CC') ) |> 
  write_csv('cran-db.csv')



cran_db |> 
  filter(
    NeedsCompilation == 'yes',
    !grepl('cpp', LinkingTo, ignore.case = TRUE),
    grepl('make', SystemRequirements, ignore.case = TRUE)) |> 
  write_csv('cran-db.csv')


