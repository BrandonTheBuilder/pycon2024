# A list of available rules and their signatures can be found here: https://buck2.build/docs/api/rules/

prebuilt_cxx_library(
    name = "libpython",
    header_only = True,
    exported_preprocessor_flags = ["-I/usr/include/python3.11", "-v", "-std=c++17", "-stdlib=libc++"],
    exported_linker_flags = ["-lpython3.11"],
)

genrule(
    name = "hello_world",
    out = "out.txt",
    cmd = "echo BUILT BY BUCK2> $OUT",
)

python_binary(
    name = "hello",
    main = "hello.py",
    main_function = "hello.hi",
    executable_name = "native_main",
    native_link_strategy = "native",
    executable_deps = [":libpython"],
)
