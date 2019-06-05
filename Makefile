
all: doc


print-contributors:
	python3 tools/contributors.py print contributors.yml 

create-contributors:
	python3 tools/contributors.py create contributors.yml doc/source/contributors.rst

doc: create-contributors
	cd doc && make html

zip:
	- rm sha.zip
	- cd sha && make clean
	zip sha.zip sha/*
	zip sha.zip sha/*/*
