#!/bin/bash

if ! wp core is-installed --allow-root --path=/var/www/wordpress; then

	wp config create \
		--allow-root \
		--path=/var/www/wordpress \
		--dbname=$DB_NAME \
		--dbuser=$DB_USER \
		--dbpass=$DB_PASS \
		--dbhost="mariadb:3306" \

	wp core install \
		--allow-root \
		--path=/var/www/wordpress \
		--url=https://user.42.fr \
		--title="Inception" \
		--admin_user=$WP_ADMIN_NAME \
		--admin_password=$WP_ADMIN_PASS \
		--admin_email=$WP_ADMIN_MAIL \
		--skip-email \

	wp user create "$WP_USER_NAME" "$WP_USER_MAIL" \
		--allow-root \
		--path=/var/www/wordpress \
		--user_pass=$WP_USER_PASS \
		--role="editor" \

fi

exec php-fpm8.2 --nodaemonize
