kkmanual Readme.md
mdpp Readme.md
mdpp base/* -q
# git add .
# git commit -m "updating"
# git push origin master

#copy missing or changed files
cd ..
cp arcade/Readme.md moodle2

#updating
kkmirror arcade moodle2 qxcodefup moodle2

cd moodle2
kkmanual --root Readme.md
# pushing moodle
# git add .
# git commit -m "updating"
# git push origin master