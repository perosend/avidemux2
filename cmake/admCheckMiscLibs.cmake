########################################
# gettext
########################################
INCLUDE(admCheckGettext)

if (NOT CROSS)
	checkGettext()
endif (NOT CROSS)

SET(ADM_LOCALE "${CMAKE_INSTALL_PREFIX}/share/locale")

########################################
# SDL
########################################
OPTION(SDL "" ON)

MESSAGE(STATUS "Checking for SDL")
MESSAGE(STATUS "****************")

IF (SDL)
	FIND_PACKAGE(SDL)
	PRINT_LIBRARY_INFO("SDL" SDL_FOUND "${SDL_INCLUDE_DIR}" "${SDL_LIBRARY}")

	MARK_AS_ADVANCED(SDLMAIN_LIBRARY)
	MARK_AS_ADVANCED(SDL_INCLUDE_DIR)
	MARK_AS_ADVANCED(SDL_LIBRARY)

	IF (SDL_FOUND)
		SET(USE_SDL 1)
	ENDIF (SDL_FOUND)
ELSE (SDL)
	MESSAGE("${MSG_DISABLE_OPTION}")
ENDIF (SDL)

APPEND_SUMMARY_LIST("Miscellaneous" "SDL" "${USE_SDL}")

MESSAGE("")

########################################
# XVideo
########################################
IF (UNIX AND NOT APPLE)
	OPTION(XVIDEO "" ON)

	IF (XVIDEO)
		MESSAGE(STATUS "Checking for XVideo")
		MESSAGE(STATUS "*******************")

		FIND_HEADER_AND_LIB(XVIDEO X11/extensions/Xvlib.h Xv XvShmPutImage)
		PRINT_LIBRARY_INFO("XVideo" XVIDEO_FOUND "${XVIDEO_INCLUDE_DIR}" "${XVIDEO_LIBRARY_DIR}")

		IF (XVIDEO_FOUND)
			SET(USE_XV 1)
		ENDIF (XVIDEO_FOUND)

		MESSAGE("")
	ENDIF (XVIDEO)

	APPEND_SUMMARY_LIST("Miscellaneous" "XVideo" "${XVIDEO_FOUND}")
ELSE (UNIX AND NOT APPLE)
	SET(XVIDEO_CAPABLE FALSE)
ENDIF (UNIX AND NOT APPLE)

########################################
# Execinfo
########################################
MESSAGE(STATUS "Checking for execinfo")
MESSAGE(STATUS "*********************")

FIND_HEADER_AND_LIB(execinfo execinfo.h execinfo backtrace_symbols)
PRINT_LIBRARY_INFO("execinfo" EXECINFO_FOUND "${LIBEXECINFO_INCLUDE_DIR}" "${LIBEXECINFO_LIBRARY_DIR}")

IF (LIBEXECINFO_INCLUDE_DIR)
	# Try linking without -lexecinfo
	ADM_COMPILE(execinfo.cpp "" ${LIBEXECINFO_INCLUDE_DIR} "" WITHOUT_LIBEXECINFO outputWithoutLibexecinfo)

	IF (WITHOUT_LIBEXECINFO)
		SET(LIBEXECINFO_LIBRARY_DIR "")
		SET(HAVE_EXECINFO 1)

		MESSAGE(STATUS "execinfo not required")
	ELSE (WITHOUT_LIBEXECINFO)
		ADM_COMPILE(execinfo.cpp "" ${LIBEXECINFO_INCLUDE_DIR} ${LIBEXECINFO_LIBRARY_DIR} WITH_LIBEXECINFO outputWithLibexecinfo)

		IF (WITH_LIBEXECINFO)
			SET(HAVE_EXECINFO 1)

			MESSAGE(STATUS "execinfo is required")
		ELSE (WITH_LIBEXECINFO)
			MESSAGE(STATUS "Does not work, without ${outputWithoutLibexecinfo}")
			MESSAGE(STATUS "Does not work, with ${outputWithLibexecinfo}")
		ENDIF (WITH_LIBEXECINFO)
	ENDIF (WITHOUT_LIBEXECINFO)
ENDIF (LIBEXECINFO_INCLUDE_DIR)

MESSAGE("")