
import os

class CI:

    def __init__(self):
        import platform

        self._dir_build = os.path.join(os.getcwd(),"build_dir")
        self._dir_install = "ci-bfs"

        self._os = ""
        if platform.system() == "Windows":
            self._os = " -G \"NMake Makefiles\" "

    def __configure__(self):
        os.mkdir(self._dir_build)
        os.chdir(self._dir_build)

        cmd_configure = "cmake " + self._os + os.path.join("..") + " -DCMAKE_INSTALL_PREFIX=" + os.path.join("..", self._dir_install)
        print ("\n\n\n CONFIGURE: " + cmd_configure)
        os.system(cmd_configure)

    def __build__(self):
        cmd_build = "make"
        os.system(cmd_build)

    def __install__(self):
        cmd_install = "make install"
        os.system(cmd_install)

    def __test__(self):
        pass
        cmd_install = "ctest"
        os.system(cmd_install)

    def run(self):
        self.__configure__()
        self.__build__()
        self.__install__()

        print("\n\n\n=== START TESTING ===")
        self.__test__()

if __name__ == "__main__":
    ci = CI()
    ci.run()
