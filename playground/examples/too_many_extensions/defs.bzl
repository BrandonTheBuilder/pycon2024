def gen_targets(num):
    deps = []
    for i in range(num):
        name = "extension_{}".format(i)
        native.genrule(
            name="{}_src".format(name),
            out="{}_src.cpp".format(name),
            srcs=[
                "extension.c.template",
            ],
            cmd="sed -e 's/$name/{}/' $SRCDIR/extension.c.template > $OUT".format(name),
        )
        deps.append(":{}".format(name))
        native.cxx_python_extension(
            name=name,
            srcs=[":{}_src".format(name)],
            deps=["root//:libpython"],
        )
    return deps
