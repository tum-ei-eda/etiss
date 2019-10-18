#!/bin/bash
case `uname` in

  Linux)
	case `lsb_release -is` in
		
		Ubuntu)
			# Ah... the shining highlands of modern Linux desktop Distro sanity
			# ... and Windows-subsystem for Linux
			PREFIX=/opt
		;;
		
		RedHatEnterpriseServer)
			# Oh shit.. looks like the "come back OS/360 all is forgiven" R&D Cluster
			PREFIX=/home/aifordes.work/share
		;;
	
	esac
  ;;
  
  MINGW64*)
	PREFIX=/c/inicio/tools/64
  ;;
  
esac

ETISS_HOME="$PREFIX/etiss-0.6" 
export CC=`which gcc`
export CXX=`which g++`
cmake -DCMAKE_BUILD_TYPE=Release -DETISS_BUILD_MANUAL_DOC=ON -DETISS_USE_PYTHON=OFF \
  -DCMAKE_INSTALL_PREFIX:PATH="$ETISS_HOME" --graphviz=test.dot -G "CodeBlocks - Unix Makefiles" ..
