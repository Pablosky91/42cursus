NAME := inception
COMPOSE_PATH := srcs/docker-compose.yml
VOLUME_DB_PATH := /home/user/data/DB
VOLUME_WP_PATH := /home/user/data/WordPress

all: create_volumes
	docker compose -f $(COMPOSE_PATH) up --build -d

$(NAME): all

up:
	docker compose -f $(COMPOSE_PATH) up -d

down:
	docker compose -f $(COMPOSE_PATH) down

start:
	docker compose -f $(COMPOSE_PATH) start

stop:
	docker compose -f $(COMPOSE_PATH) stop

re:
	docker compose -f $(COMPOSE_PATH) restart

ps:
	docker compose -f $(COMPOSE_PATH) ps

clean:
	-docker stop $$(docker ps -qa);
	-docker rm $$(docker ps -qa);
	-docker rmi -f $$(docker images -qa);
	-docker volume rm $$(docker volume ls -q);
	-docker network rm $$(docker network ls -q) 2> /dev/null
	-docker system prune -af

fclean: clean
	-rm -rf $(VOLUME_DB_PATH) $(VOLUME_WP_PATH)

create_volumes: $(VOLUME_DB_PATH) $(VOLUME_WP_PATH)

$(VOLUME_DB_PATH):
	mkdir -p $(VOLUME_DB_PATH)

$(VOLUME_WP_PATH):
	mkdir -p $(VOLUME_WP_PATH)

.PHONY: all up doen start stop re ps clean fclean create_volumes
