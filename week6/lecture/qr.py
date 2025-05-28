import os
import qrcode

link = input("Link: ")

img = qrcode.make(link)

img.save("qr.png", "PNG")
