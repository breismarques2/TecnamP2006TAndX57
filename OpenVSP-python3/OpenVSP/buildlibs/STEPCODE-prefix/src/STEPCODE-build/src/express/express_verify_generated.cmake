# Inherit the parent CMake setting
set(DEBUGGING_GENERATED_SOURCES )
set(CURRENT_SOURCE_DIR "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/express")

# Include the file the provides the baseline against which
# current files will be compared
if(NOT DEBUGGING_GENERATED_SOURCES)

  include("/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/express/generated/verification_info.cmake")

  # Define a variety of convenience routines
  include("/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/cmake/Generated_Source_Utils.cmake")

  # Individually verify all of the files in question.
  set(filelist "/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/express/generated/expscan.c;/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/express/generated/expscan.h;/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/express/generated/expparse.c;/Users/Bruno/OpenVSP-python3/OpenVSP/buildlibs/STEPCODE-prefix/src/STEPCODE/src/express/generated/expparse.h")
  VERIFY_FILES("${filelist}" 1 srcs_pass)
  if( srcs_pass)
    message( "Generated source code has not been modified.")
  else(srcs_pass)
    message(FATAL_ERROR "Generated sources have been modified.  These files should never be modified directly except when debugging faulty output from the generators - changes to lexer and parser logic should be made to the generator input files.  If this is a debugging situation, set the variable DEBUGGING_GENERATED_SOURCES to ON during the CMake configure.")
  endif(srcs_pass)

  # If we got by that test, see if it looks like these
  # sources came from the current input files.  It's not
  # a failure condition if they didn't, but warn about it.
  set(filelist "expscan.l;expparse.y")
  VERIFY_FILES("${filelist}" 0 inputs_same)
  if(NOT inputs_same)
    message("Note: cached generated sources are not in sync with input files.")
  endif(NOT inputs_same)

endif(NOT DEBUGGING_GENERATED_SOURCES)

# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8
