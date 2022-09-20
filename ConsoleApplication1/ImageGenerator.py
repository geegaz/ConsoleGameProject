import numpy as np
from PIL import Image
from pathlib import Path

class ImageGenerator:

    COLORS = [
        (12,12,12),
        (0,55,218),
        (19,161,14),
        (58,150,221),
        (197,15,31),
        (136,23,152),
        (193,156,0),
        (204,204,204),
        (118,118,118),
        (59,120,255),
        (22,198,12),
        (97,214,214),
        (231,72,86),
        (180,0,158),
        (249,241,165),
        (242,242,242)
    ]

    def __init__(self) -> None:
        pass

    # https://stackoverflow.com/a/54244301 -------------------------
    def closest_index(self, color):
        np_colors = np.array(self.COLORS)
        np_color = np.array(color)
        distances = np.sqrt(np.sum((np_colors-np_color)**2,axis=1))
        return np.where(distances==np.amin(distances))[0][0]
    
    # def closest_color(self, color):
    #     return self.COLORS[self.closest_index(color)]
    #---------------------------------------------------------------

    def generate(self, filename: str):
        try:
            img = Image.open(filename, "r")
            txt = open(Path(filename).stem + ".txt", "w")

            data = img.getdata()

            txt.write("%s %s\n---\n" % img.size)

            pos: int = 0
            for pixel in data:
                rgb = (pixel[0], pixel[1], pixel[2])
                a = pixel[3]

                if a < 128:
                    txt.write("%s " % -1)
                else:
                    txt.write("%s " % self.closest_index(rgb))
                pos += 1

                if pos >= img.size[1]:
                    txt.write("\n")
                    pos = 0
            
            txt.close()
            img.close()

        except Exception as ex:
            print(ex)

generator = ImageGenerator()
filename = input("File: ")
generator.generate(filename)