TXT_TO_CONVERT=$(wildcard drop_to_convert/*.txt)
PNG_TO_CREATE=$(patsubst drop_to_convert/%,%,$(TXT_TO_CONVERT:.txt=.png))

PNGS=$(wildcard *.png) $(PNG_TO_CREATE)
MAPS=$(PNGS:.png=.txt)

all: $(MAPS) $(PNG_TO_CREATE)

%.txt: %.png
	python3 ./converter.py $< $@

%.png: drop_to_convert/%.txt
	python3 ./converter.py $< $@

clean:
	-rm $(MAPS)

