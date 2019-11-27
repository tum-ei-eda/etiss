# ETISS INFINEON BUILD/INSTALL 

## R&D Linux specific prerequisites / preparation
source IFX_MODULES_SOURCE_ME on R&D Linux cluster to select prerequisite up-to-date gcc
and cmake available.

## iSCvX specific prerquisites / preparation

Currently native windows build is not support (only WSL)

## iSCvX (WSL) 

# Build configuration (all plaoforms)
run ./IFX_CONFIG.sh to generate makefiles to build  ETISS pre-configured with
correct IFX versions, default locations etc etc iscX Windows, WESL and R&D cluster

    Obviously, you'll need to re-run if your build configuration /settings change.   
    Needs to be extended to support Debug builds etc.
    uses cmake
                    
                    