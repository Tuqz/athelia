import os
env = Environment(ENV = {'PATH' : os.environ['PATH']}, TARGET_ARCH='x86', tools=['mingw'])

env["CXX"] = "g++"

debug=ARGUMENTS.get('debug', 0)
if int(debug) == 1:
    print "Debug set true!"
    env.Append(CPPFLAGS = '-g')
    env.Append(LIBPATH = ["../lib/win32/debug"])
    env.Append(LIBS = ["athelia", "OgreMain_d", "OgreOverlay_d", "OIS_d", "boost_system", "boost_thread", "mingw32"])
    env.Append(CPPDEFINES = ["_DEBUG", "STLP_DEBUG"])
else:
    env.Append(LIBPATH = ["../lib/win32/release"])
    env.Append(LIBS = ["athelia", "OgreMain", "OgreOverlay", "OIS", "boost_system", "boost_thread", "mingw32"])
    env.Append(CPPDEFINES = ["NDEBUG"])

env.Append(LIBPATH = ["../lib/boost_1_57_0/stage/lib"])
env.Append(CPPFLAGS = ["-std=c++11"])
env.Append(CPPPATH = ["../include"])

SConscript("src/SConscript", exports = 'env')
SConscript("techdemos/SConscript", exports = ['env', 'debug'])
