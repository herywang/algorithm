## SQL 调优总结
1. 避免开头模糊查询, 例如:
```sql
select * from t where username like '%陈%';
```
2. 避免使用in 和 not in,会导致引擎扫描全部表数据, 如果数据连续,尽量使用 `between`关键字, 如果是子查询, 可以使用`exist`关键字, 例如:
```SQL
-- 不走索引
select * from A where A.id in (select id from B);
-- 走索引
select * from A where exists (select * from B where B.id = A.id);
```
3. 避免使用`or`关键字, 会导致数据库引擎放弃索引,进行全表扫描, 例如:
```sql
select * from A where A.id = 10 or A.id = 3;
-- 优化方式: 可以使用 union关键字代替or关键字
select * from A where id =10
    union
select * from A where id = 3;
```
4. 避免在`where`关键字等号左边进行表达式, 函数运算, 会导致数据库引擎扫描全部表数据, 例如:
```sql
-- 不走索引, 全表扫描
select * from A where score / 10 = 5;
-- 走索引
select * from A where score = 10*5;
```
5. 当索引列作为查询条件时, 避免使用`!=`条件符号,会导致引擎扫描全部表数据.
6. where 条件复合索引需要满足最左匹配原则, 例如:
```SQL
-- 表A中联合索引<c1, c2, c3>
-- 走索引情况:
select * from A where c1=1 and c2=2 and c3=3;
select * from A where c1=1 and c2=2;
select * from A where c1=1;
-- 不走索引情况
select * from A where c1=1 and c3=3;
select * from A where c2=1 and c3=3;
select * from A where c3=3;
```
7. `order by`要与`where`条件一致, 这种优化方式同样对于`group by`, `union`, `distinct`有效.
```SQL
-- 不走age索引
select * from t order by age;
-- 走age索引
select * from t where age > 0 order by age;
```

## 关于join原理及索引使用事项
Mysql中Join本质上是Nested-Loop Join（嵌套循环链接），但他有很多种变种，能够帮助Mysql更高效的执行JOIN操作。
① Simple Nested-Loop Join：这是在两张表都没有索引的情况下使用的join算法。从驱动表中依次拿出列来和另一张表进行匹配。首先驱动表拿出r1和s表的所有列进行比对匹配，以此类推，这种算法要对s表进行rn次访问，开销极大。

## 存储引擎及存储结构相关面试题

1. InnoDB和MyISAM的区别
    * InnoDB支持事务, MyISAM不支持
2. B+数的深度