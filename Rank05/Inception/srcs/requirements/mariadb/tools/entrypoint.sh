#!/bin/bash

if [ ! -d "/var/lib/mysql/$DB_NAME" ]; then

	mariadbd-safe --skip-grant-tables --skip-networking &

	while ! mysqladmin -u root -p"$DB_ROOT_PASS" ping -h localhost; do
		echo "Waiting..."
		sleep 1
	done

	mysql -u root -p"$DB_ROOT_PASS" << EOF
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS \`$DB_NAME\`;
CREATE USER IF NOT EXISTS \`$DB_USER\`@'%' IDENTIFIED BY '$DB_PASS';
GRANT ALL ON \`$DB_NAME\`.* TO \`$DB_USER\`@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASS';
FLUSH PRIVILEGES;
EOF

	mariadb-admin -u root -p"$DB_ROOT_PASS" shutdown

fi

exec mariadbd --user=mysql
