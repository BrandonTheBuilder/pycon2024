def static_linked_python_binary(*args, **kwargs):
    return native.python_binary(
        native_link_strategy="native",
        executable_name="native_main",
        executable_deps=["//:libpython"],
        *args,
        **kwargs
    )
