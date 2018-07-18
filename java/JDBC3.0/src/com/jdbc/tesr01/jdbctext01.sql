drop database if exists jdbctest01;

create database jdbctest01;

use jdbctest01;

create table account(
id int not null,
userName varchar(30) not null,
password varchar(30) not null,
primary key (id)
);

insert into account(id,userName,password)
values (1,'wng','123456');