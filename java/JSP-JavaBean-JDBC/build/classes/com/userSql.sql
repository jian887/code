drop database if exists jdbctest01;

create database userinfo;

use userinfo;

create table account(
id int not null auto_increment,
userName varchar(30) not null,
password varchar(30) not null,
primary key (id)
);

