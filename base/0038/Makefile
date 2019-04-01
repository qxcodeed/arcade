CFLAGS = -Wall
video:
	rm -f video.mp4
	ffmpeg -framerate 5 -pattern_type glob -i '*.png' -c:v libx264 -profile:v high -crf 20 -pix_fmt yuv420p video.mp4
clean:
	rm -f *.png
