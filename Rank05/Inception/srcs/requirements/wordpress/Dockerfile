FROM debian:bookworm-slim

RUN	apt-get update && \
	apt-get install -y curl php-fpm php-mysql && \
	rm -rf /var/lib/apt/lists/*

RUN	curl -o /tmp/latest.tar.gz https://wordpress.org/latest.tar.gz && \
	mkdir -p /var/www && \
	tar -xzf /tmp/latest.tar.gz -C /var/www && \
	rm /tmp/latest.tar.gz

RUN curl -o /bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x /bin/wp

RUN	sed -i 's/^listen =.*/listen = 9000/' /etc/php/8.2/fpm/pool.d/www.conf

COPY tools/entrypoint.sh /bin

ENTRYPOINT ["entrypoint.sh"]
