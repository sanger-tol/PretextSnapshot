project('PretextSnapshot', ['c', 'cpp'],
    license: 'MIT',
    meson_version: '>=0.57.1',
    version: '0.0.5'
)

thread_dep = dependency('threads')
math_dep = meson.get_compiler('cpp').find_library('m', required : true)
cpp_dep = meson.get_compiler('cpp').find_library('stdc++', required : true)

base_flags = ['-O3', '-ffast-math']
extensions = {'.avx2': ['-mavx2'], '.avx': ['-mavx'], '.sse42': ['-msse4.2'], '.sse41': ['-msse4.1']}

foreach ext, flag : extensions
    flags = base_flags + flag
    executable('PretextSnapshot' + ext, 'PretextSnapshot.cpp', dependencies : [thread_dep, math_dep, cpp_dep], install : true, cpp_args : flags+['-DPV=' + meson.project_version()], link_with : 
        [   static_library('deflate' + ext, 'libdeflate/lib/deflate_compress.c', 'libdeflate/lib/deflate_decompress.c', 'libdeflate/lib/utils.c', c_args : flags, link_with : 
            [   static_library('deflate_x86' + ext, 'libdeflate/lib/x86/cpu_features.c', c_args : flags),
                static_library('deflate_arm' + ext, 'libdeflate/lib/arm/cpu_features.c', c_args : flags),
                static_library('deflate_zlib' + ext, 'libdeflate/lib/adler32.c', 'libdeflate/lib/zlib_decompress.c', 'libdeflate/lib/zlib_compress.c', c_args : flags)]),
            static_library('mpc' + ext, 'mpc/mpc.c', c_args : flags)],
        include_directories : include_directories('include'))
endforeach

test('Test', executable('PretextSnapshot', 'wrapper/SIMDExtensionWrapper.cpp', install : true, cpp_args : base_flags + ['-DProgramName=PretextSnapshot']))
