FROM debian:bookworm-slim

RUN	apt-get update && \
	apt-get install -y nginx openssl && \
	rm -rf /var/lib/apt/lists/*

RUN	mkdir /etc/nginx/ssl && \
	openssl req \
		-x509 \
		-noenc \
		-keyout /etc/nginx/ssl/private.key \
		-out /etc/nginx/ssl/public.crt \
		-subj "/C=/ST=/L=/O=/OU=/CN=localhost"

COPY ./conf/server.conf /etc/nginx/conf.d/server.conf

CMD ["nginx", "-g", "daemon off;"]
