FROM buck2
RUN apt update
RUN apt install -y python3
RUN apt install -y python3-dev
RUN apt install -y libc++-15-dev
RUN apt install -y clang
RUN apt install -y lld
RUN apt install -y vim
COPY playground playground
WORKDIR /playground
