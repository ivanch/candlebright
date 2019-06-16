import cv2, os, sys
import numpy as np

if(len(sys.argv) == 0):
    print("Erro: python sheeter.py [arquivo.png]")
    sys.exit(1)

# Define o tamanho Y,X do Sprite
size = (120,170)

name = sys.argv[1]
nname = "new-" + name

img = cv2.imread(name, -1)
nimg = np.zeros(shape=(size[0],0,4))
print(nimg.shape)
tem = False
start = -1
end = -1

maxy = -1
miny = -1
for x in range(img.shape[1]):
    encontrou = False # encontrou alguma coisa no eixo Y
    for y in range(img.shape[0]):
        if(np.sum(img[y][x]) > 0): # > 0 ou < 765, depende da imagem
            if(start == -1):
                start = x
            if(y > maxy): maxy = y
            if(y < miny or miny == -1): miny = y
            tem = True
            encontrou = True
    if(tem == True and encontrou == False):
        end = x

        print(start, end, miny, maxy) # começo e fim no eixo X do sprite | começo e fim no eixo Y do sprite
        
        temp = np.zeros(shape=(maxy-miny,end-start,4))
        #for ty in range(img.shape[0]):
        for ty in range(miny, maxy):
            for tx in range(start, end):
                temp[ty-miny][tx-start] = img[ty][tx]
        # pré processamento
        print(temp.shape)
        temp = cv2.resize(temp, (size[1],size[0]), interpolation=cv2.INTER_NEAREST)
        nimg = np.append(nimg, temp, axis=1)
        
        start = -1
        end = -1
        maxy = -1
        miny = -1
    tem = encontrou

print(nimg.shape)
cv2.imwrite(nname, nimg)
