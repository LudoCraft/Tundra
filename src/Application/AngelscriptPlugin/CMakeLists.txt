set(ASCRIPT_DIR ${ENV_TUNDRA_DEP_PATH}/angelscript)
include_directories(${ASCRIPT_DIR}/sdk/angelscript/include)
include_directories(${ASCRIPT_DIR}/sdk/add_on)
link_directories(${ASCRIPT_DIR}/sdk/angelscript/lib)

# Define target name and output directory
init_target (AngelscriptPlugin OUTPUT plugins)

GetEntityComponents()

MocFolder ()

# Define source files
file (GLOB CPP_FILES *.cpp)
file (GLOB H_FILES *.h)
file (GLOB UI_FILES ui/*.ui)
file (GLOB MOC_FILES AngelscriptPlugin.h AngelscriptInstance.h)
set (SOURCE_FILES ${CPP_FILES} ${H_FILES})

set (FILES_TO_TRANSLATE ${FILES_TO_TRANSLATE} ${H_FILES} ${CPP_FILES} ${UI_FILES} PARENT_SCOPE)

# Qt4 Wrap
QT4_WRAP_CPP(MOC_SRCS ${MOC_FILES})
QT4_WRAP_UI(UI_SRCS ${UI_FILES})

UseTundraCore()
use_core_modules(TundraCore Math OgreRenderingModule)
use_app_modules(JavascriptModule)

build_library (${TARGET_NAME} SHARED ${SOURCE_FILES} ${MOC_SRCS} ${UI_SRCS})

link_package(QT4)
link_ogre()
link_modules(TundraCore Math JavascriptModule OgreRenderingModule)
link_entity_components(EC_Script)

target_link_libraries(${TARGET_NAME} Angelscript)

SetupCompileFlags()

final_target ()
