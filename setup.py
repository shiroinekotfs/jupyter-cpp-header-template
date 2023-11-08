from setuptools import setup, find_packages

setup(
      name='jupyter-cpp-extension-template',
      version='1.0.0a5',
      description='C++ kernel for Jupyter headers template. Used to provide additional abilities for the kernel.',
      author='Shiroi Neko',
      author_email='shiroineko.tfs@gmail.com',
      license='MIT',
      classifiers=[
        'Programming Language :: Python :: 3',
        'Programming Language :: C++',
        'License :: OSI Approved :: MIT License',
        'Operating System :: Unix',
        'Operating System :: MacOS',
        'Operating System :: POSIX :: Linux',
        'Operating System :: Microsoft :: Windows'
      ],
      url='https://github.com/shiroinekotfs/jupyter-cpp-header-template',
      include_package_data=True,
      install_requires = ['jupyter-cpp-kernel>=1.0.0a5'],
      data_files = [
          ("share/cpp_header", ['sample/sample.hpp']),
          ("share/cpp_header/res", ['sample/res/legacy.h', 'sample/res/linker.hpp'])
      ]
)
