#!/bin/bash -u
# NAME : Yujia Lin
# The function will create PDF from PPT
createPDF(){
	FLAG="NO"
	DIRFILES=`ls .`
	PDF=".pdf"
	# Get all filename
	for filename in ${DIRFILES} ; do
		# Judg filename includes ppt
		if [ "${filename##*.}" = "ppt" ] ; then
			if [ -f ${filename%.*}${PDF} ] ; then
				pdffilename=${filename%.*}${PDF}
				pptdate=`date -r ${filename} +%s`
				pdfdate=`date -r ${pdffilename} +%s`
				# Print out ppt and pdf date
				echo "--------------------------------------------------"
				echo "PPTNAME : ${filename} , PDFNAME : ${pdffilename}"
				echo "PPTDATE : ${pptdate} , PDFDATE : ${pdfdate}"
				echo "--------------------------------------------------"
				# Judg which file is new one
				if [ ${pptdate} -gt ${pdfdate}  ] ; then
					FLAG="YES"
					# Create a new pdf
					echo "| CREATE A NEW PDF : ${pdffilename} |"
					ppttopdf ${filename}
				fi
			else
				FLAG="YES"
				# Create a new pdf
				echo "| CREATE A NEW PDF : ${filename%.*}${PDF} |"
				ppttopdf ${filename}
			fi
		fi
	done
	# Archive all PDF and PPT files to lectures.tar.gz
	# Then copy that to www directory
	if [ ${FLAG} = "YES" ] ; then
		echo "--------------------------------------------------"
		echo "CREATE A FILE lectures.tar.gz"
		echo "--------------------------------------------------"
		tar czf lectures.tar.gz *.pdf *.ppt
		mkdir -p www
		cp lectures.tar.gz www/
	fi
}

# Start
if [ $# == 1 ] ; then
	# Clean all pdf files and lectures.tar.gz
	if [ $1 = "clean" ] ; then
		echo "--------------------------------------------------"
		echo "Clean All PDF Files and lectures.tar.gz"
		echo "--------------------------------------------------"
		rm -f *.pdf lectures.tar.gz
	fi
else
	# Call function createPDF to create PDF from PPT
	createPDF
fi
