add_rules("mode.debug")

target("main")
    set_kind("binary")
    add_files("./src/*.c")
    set_default(true)
    on_config(function (target)
        if is_plat("windows") then
            target:add("cxflags", "/source-charset:utf-8", {force = true})
        end
    end)
