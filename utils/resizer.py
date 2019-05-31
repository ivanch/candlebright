import cv2, glob, os
import numpy as np

for file in glob.iglob("*.png"):
    im = cv2.imread(file, -1)
    os.rename(file, ".raw/"+file)
    rim = cv2.resize(im, (30,65))
    cv2.imwrite(file, rim)
    print("Saved", file)
