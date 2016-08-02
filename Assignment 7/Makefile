# NAME : Yujia Lin
# tar command
TAR = tar
TARFLAG = czf
TARFILENAME = lectures.tar.gz
# mkdir command
MKD = mkdir
DIRNAME = www
MKDFLAG = -p
# cp command
COPY = cp
# ppttopdf conmand
PPTTOPDF = ppttopdf
# rm command
REMOVE = rm
REMOVEFLAG = -f
# all pdf and ppt
ALLPDF = *.pdf
ALLPPT = *.ppt
PPTFILES = $(wildcard *.ppt)
PDFFILES = $(PPTFILES:.ppt=.pdf)
# =================
.PHONY : all clean
# =================
# ----------------------------
all : $(PDFFILES) mkdirwww ${TARFILENAME}
# ----------------------------

# ----------------------------
# Create new pdf files
%.pdf : %.ppt
	echo "Create New PDF"
	${PPTTOPDF} $<
# ----------------------------

# ----------------------------
# Create a new dir
mkdirwww :
	$(MKD) $(MKDFLAG) ${DIRNAME}
# ----------------------------

# ----------------------------
# Tar all ppt and pdf files
${TARFILENAME} : $(PPTFILES)
	${TAR} ${TARFLAG} ${TARFILENAME} ${ALLPDF} ${ALLPPT}
	${COPY} ${TARFILENAME} ${DIRNAME}/
# ----------------------------

# ----------------------------
# Clean all pdf files and lectures.tar.gz
clean :
	echo "Clean All PDF Files and lectures.tar.gz"
	${REMOVE} ${REMOVEFLAG} ${ALLPDF} ${TARFILENAME}
