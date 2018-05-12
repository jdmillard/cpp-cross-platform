# This removes everything in the build folder except clean.sh and clean.bat

# establish build directory path from anywhere
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# flag to detect if changes were made by this script
CHANGES=false

# loop over files
for NAME in ${DIR}/*; do
    FILE="${NAME##*/}"
    #echo "${FILE}"

    # do not delete the clean scripts
    if [ ${FILE} != "clean.sh" ] && [ ${FILE} != "clean.bat"  ]; then
        rm ${DIR}/${FILE} -fr
        echo "${FILE} has been deleted"
        CHANGES=true
    fi
done

# have ending statement make sense
if [ "$CHANGES" = true ]; then
    echo
    echo "build directory is now clean"
else
    echo "build directory is already clean"
fi
