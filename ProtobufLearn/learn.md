# protobuf： 一种高效的数据序列化机制


# 一、protobuf 语法

## 1.1 .proto 文件语法  

```proto
syntax="proto2";//指定proto的语法 proto2 还是proto3
package test.msgs;

message Person{
  optional string name = 1; //分配 字段编号 (不是初始化!) 字段编号必须唯一!   1~ 536870911
  optional int32 age = 2;  
  optional int32 id = 3;
  repeated int32 my_vector=4;
}
```  

## 1.2 消息字段类型

 对于最常设置的字段，应使用字段编号 1 到 15。字段编号值越小，在导线格式中占用的空间越小
 因为 1-15字段编号 采用一个字节编码 16-2z047按照两个字节

 ```optional```: 两种状态  
 1 未被设置 则返回默认值 不会序列化到线路上  
 2 设置    包含值  则会被序列化到线路上  

 ```repeated```: 可以在格式正确的消息中 重复零次或多次 重复值的顺序保持不变  

 ```map```: 成对的键/值字段类型

 ```required```: ！！！最好不要使用 proto3语法已经删除  

 由于历史原因， repeated 标量数值类型（例如， ```int32``` 、 ```int64``` 、 ```enum``` ）的字段编码效率不高。新代码应使用特殊选项 [packed = true] 来获得更有效的编码：

 ```proto
  repeated int32 samples = 4 [packed = true];
  repeated ProtoEnum results = 5 [packed = true];
 ```  

## 1.3 其他  

可以在单个proto文件中定义多个消息 例如:  

```proto
  message SearchRequest {
    optional string query = 1;
    optional int32 page_number = 2;
    optional int32 results_per_page = 3;
  }

  message SearchResponse {
  ...
  }
```  

  但是这样会导致膨胀，建议单个.proto文件尽可能少的定义消息类型  

## 1.4 删除字段  

1. 不要删除 require字段  
2. 当不需要某个非必填字段时，可以在message中删除，但是必须3保留已删除的字段编号，以免后续开发者重复使用该编号  

## 1.5 保留字段  

1. 如果完全删除字段或者注释掉，可能带来问题，所以应该将删除的字段编号添加到reserved列表中：

```proto
  message Han{
    reserved 2,15, 9 to 11;
    reserved "Han" , "bo"
  }
```  

## 1.6标量值类型

|.proto 类型|注释|c++ 类型|
|------|------|------|
|double||double|
|float||float|
|int32|使用可变长度编码。编码负数效率低下 – 如果您的字段可能具有负值，请改用 sint32|int32|
|int64|使用可变长度编码。编码负数效率低下 – 如果您的字段可能具有负值，请改用 sint64|int64|
|uint32|使用可变长度编码|uint32|
|uint64|使用可变长度编码|uint64|
|sint32|使用可变长度编码。有符号的 int 值。它们比常规 int32 更有效地编码负数|int32|
|sint64|使用可变长度编码。有符号的 int 值。它们比常规 int64 更有效地编码负数|int64|
|fixed32|始终为 4 个字节。如果值通常大于 2^28，则比 uint32 更有效|uint32|
|fixed64|始终为 8 个字节。如果值通常大于 2^56，则比 uint64 更有效|uint64|
|sfixed32|始终为 4 个字节|int32|
|sfixed64|始终为 8 个字节|int64|
|bool|字符串必须始终包含 UTF-8 编码或 7 位 ASCII 文本，并且长度不能超过 2^32|bool|
|string||string|
|bytes|可以包含任何不超过 2^32 的任意字节序列|string|

### 1.7 可选字段和默认值

 使用default

 ```proto
  optional int32 index=3 [default=10];
  optional string name=1 [default="hansolo"];
 ```  

 对于字符串，默认值为空字符串  
 对于字节，默认值为空字节  
 对于bool，默认为 false  
 对于 数值类型，默认为0  
