{ pkgs }: {
    deps = [
        pkgs.valgrind-light
        pkgs.sfml
        pkgs.gcc
        pkgs.ccls
    ];
}