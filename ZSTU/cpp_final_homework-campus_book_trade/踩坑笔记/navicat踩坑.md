# 自动编号

设计表->选择主键(id)->下方出现属性栏->选中自动编号。

插值语句

```sql
insert into book(isbn,bookName,writer,publisher,owner,takeMethod,price,status,selled) values('a','a','c','d','Mitchell','aa',12,10,1);
```

insert 时不要写主键id的内容，它在插值后会自动编号，前提是要像上述格式书写插值语句。