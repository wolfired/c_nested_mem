add_rules("mode.debug", "mode.release")

target("nested")
    set_kind("static")
    add_includedirs("./src/nested", { public = true })
    add_files("./src/nested/*.c")
    on_config(function (target)
        if is_plat("windows") then
            target:add("cxflags", "/source-charset:utf-8", {force = true})
        end
        if is_plat("linux") then
            target:add("cxflags", "--coverage", {force = true})
            target:add("ldflags", "--coverage -lgcov", {force = true})
        end
    end)
    after_build(function (target)
        if is_plat("linux") then
            os.exec("mkdir -p $(builddir)/.codecov")
            for _, obj in ipairs(target:objectfiles()) do
                os.cp(obj, "$(builddir)/.codecov")
                os.cp(path.join(path.directory(obj), path.basename(obj)) .. ".gcno", "$(builddir)/.codecov")
                
            end
        end
    end)

target("test")
    set_kind("binary")
    add_files("./test/main.c")
    add_deps("nested")
    set_default(false)
    on_config(function (target)
        if is_plat("windows") then
            target:add("cxflags", "/source-charset:utf-8", {force = true})
        end
        if is_plat("linux") then
            target:add("cxflags", "--coverage", {force = true})
            target:add("ldflags", "--coverage -lgcov", {force = true})
        end
    end)
    after_build(function (target)
        if is_plat("linux") then
            os.exec("mkdir -p $(builddir)/.codecov")
            for _, obj in ipairs(target:objectfiles()) do
                os.cp(obj, "$(builddir)/.codecov")
                os.cp(path.join(path.directory(obj), path.basename(obj)) .. ".gcno", "$(builddir)/.codecov")
            end
        end
    end)
    on_run(function (target)
        if is_plat("linux") then
            os.exec("valgrind --leak-check=full --track-origins=yes --read-var-info=yes --trace-children=yes --show-leak-kinds=all --read-inline-info=yes --errors-for-leak-kinds=all --expensive-definedness-checks=yes --gen-suppressions=all --redzone-size=16 --show-error-list=yes " .. target:targetfile())
        else
            os.exec(target:targetfile())
        end
    end)

target("main")
    set_kind("binary")
    add_files("./src/main.c")
    set_default(true)
    on_config(function (target)
        if is_plat("windows") then
            target:add("cxflags", "/source-charset:utf-8", {force = true})
        end
    end)
