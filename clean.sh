#/bin/sh

find . -mindepth 1 -maxdepth 1 -type d -exec bash -c "cd '{}' && make fclean" \;
