FROM debian:bookworm-slim

RUN	apt-get update && \
	apt-get install -y mariadb-server && \
	rm -rf /var/lib/apt/lists/*

RUN	mkdir -p /run/mysqld && \
	chown mysql:mysql /run/mysqld

COPY tools/entrypoint.sh /bin

RUN	sed -i 's/^bind-address.*/bind-address            = 0.0.0.0\nport                    = 3306/' /etc/mysql/mariadb.conf.d/50-server.cnf

ENTRYPOINT ["entrypoint.sh"]
