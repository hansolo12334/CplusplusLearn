USE database_hansolo;
DROP TABLE IF EXISTS supermarket;
SELECT '创建 supermarket table';
CREATE TABLE supermarket (
    item_id int NOT NULL AUTO_INCREMENT, 
    item_name char(50) NOT NULL, 
    price int NOT NULL, 
    sold_nums int NOT NULL, 
    type ENUM('fruit', 'meat', 'toy', 'daily_stuff', 'drink', 'vegetable', 'snack') COMMENT '分类', 
    PRIMARY KEY (item_id)
) ENGINE = InnoDB;
SELECT '创建 supermarket table 完成';