add_rules("mode.debug", "mode.release")

target("main")
    set_kind("binary")
    add_files("./src/*.c")
    set_default(true)
    on_config(function (target)
        if is_plat("windows") then
            target:add("cxflags", "/source-charset:utf-8", {force = true})
        end
    end)
    on_run(function (target)
        if is_plat("linux") then
            os.exec("valgrind --leak-check=full --track-origins=yes --read-var-info=yes --trace-children=yes --show-leak-kinds=all --read-inline-info=yes --errors-for-leak-kinds=all --expensive-definedness-checks=yes --gen-suppressions=all --redzone-size=16 --show-error-list=yes " .. target:targetfile())
        else
            os.exec(target:targetfile())
        end
    end)
