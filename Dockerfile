FROM amd64/debian
RUN apt update
RUN apt install -y git
RUN apt install -y curl
RUN apt install -y build-essential
RUN apt install -y python3
RUN apt install -y python3-dev
RUN apt install -y libc++-15-dev
RUN apt install -y clang
RUN apt install -y lld
RUN apt install -y vim
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs > rust_install.sh
RUN chmod u+x ./rust_install.sh
RUN ./rust_install.sh -y
RUN . "$HOME/.cargo/env"
ENV PATH=$PATH:/root/.cargo/bin
RUN rustup install nightly-2024-02-01
RUN cargo +nightly-2024-02-01 install --git https://github.com/facebook/buck2.git buck2
COPY ./example example

