INCLUDE(vf_plugin)


SET(ADM_vf_mSharpen_SRCS ADM_vidMSharpen.cpp)
SET(FILTERSRC ${ADM_vf_mSharpen_SRCS})
SET(FILTERNAME ADM_vf_msharpen)
ADD_VIDEO_FILTER( ${FILTERNAME} ${FILTERSRC}  )
INIT_VIDEO_FILTER(${FILTERNAME})
INSTALL_VIDEO_FILTER(${FILTERNAME})
