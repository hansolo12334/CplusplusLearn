### 访问级别摘要  

|访问级别|访问说明符|成员访问|派生类访问|公共访问|
|------|------|------|------|------|
|Public|public:|yes|yes|yes|
|Protected|protected:|yes|yes|no|
|Private|private:|yes|no|no|  

### 既然class和struct差不多 什么时候使用class,什么时候使用struct？  

#### 当满足以下条件时,使用struct  

 1. 有一个简单的数据集合，不会从限制访问中获益  
 2. 聚合初始化已足够  
 3. 没有类不变性、设置初始需求和清理需求  

#### 如果使用任何使struct成为非聚合的功能，就应该转用class
