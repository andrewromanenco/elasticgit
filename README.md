# elasticgit

A SaaS git hosting service, retired in 2011. Some sources.

## Key elements
- openssh server reads keys from mysql database (to make keys available in sharded environment)
- git has additional modifications to report usage statistics per user (see history of commits)
- web front is a drupal instance

Introduction article in russian: https://habrahabr.ru/post/128609/
