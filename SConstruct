env = Environment()

env.Append(CPPFLAGS = ["-std=c++11"])
env.Append(LIBS = ["OgreMain", "boost_system", "lua"])

SConscript("src/SConscript", exports = 'env')
SConscript("techdemos/SConscript", exports = 'env')
