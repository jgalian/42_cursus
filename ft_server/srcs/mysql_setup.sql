CREATE DATABASE wordpress;
CREATE USER 'wp-user'@'localhost' IDENTIFIED BY '1234';
GRANT ALL PRIVILEGES ON wordpress.* TO 'wp-user'@'localhost' IDENTIFIED BY '1234';
FLUSH PRIVILEGES;
update mysql.user set plugin = 'mysql_native_password' where user='root';

