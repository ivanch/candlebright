import imageio, cv2, sys
import numpy as np

gif = imageio.mimread(sys.argv[1] + ".gif")
imgs = [cv2.cvtColor(img, cv2.COLOR_BGRA2RGBA) for img in gif]

sheet = imgs[0]

for i in range(1,len(imgs)):
    print(sheet.shape, imgs[i].shape)
    sheet = np.concatenate([sheet,imgs[i]],axis=1)
cv2.imwrite(sys.argv[1] + "Sheet.png", sheet)
