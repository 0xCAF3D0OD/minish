FROM archlinux

RUN pacman -Sy --noconfirm git vim make gcc zsh curl

RUN sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

COPY src src

ENTRYPOINT [ "zsh" ]
