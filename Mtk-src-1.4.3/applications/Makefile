#
#  Makefile for applications using MISR Toolkit
#

# To set MTK flags (csh: source Mtk_c_env.csh or bash: . Mtk_c_env.sh)

CFLAGS	?= $(MTK_CFLAGS)	# Add you own CFLAGS here
LDFLAGS ?= $(MTK_LDFLAGS)	# Add your own LDFLAGS here
INSTALL :=      /usr/bin/install
INSTALLDIR ?= $(shell printenv MTK_INSTALLDIR)

APPS	:= MtkSurfaceBRFRegression \
	   MtkL1B2Reproject \
	   MtkL2ASCloudMaskReproject \
	   MtkResampleGeom

all: $(APPS)

clean:
	@rm -f $(APPS) *.o

install:
	$(INSTALL) -m 755 $(APPS) $(INSTALLDIR)/bin
