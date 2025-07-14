from PIL import Image
import exifread
import numpy as np
import imageio.v2 as imageio
from scipy.signal import medfilt2d
from scipy.ndimage import gaussian_filter


def extract_exif_metadata(image_path):
    with open(image_path, 'rb') as image_file:
        tags = exifread.process_file(image_file)
        return tags

def detect_jpeg_ghosting(image_path):
    original_image = Image.open(image_path)
    original_image = original_image.convert('L') 
    original_array = original_image.getdata()
    original_image.save('temp.jpg', 'JPEG', quality=90)
    modified_image = Image.open('temp.jpg')
    modified_image = modified_image.convert('L')
    modified_array = modified_image.getdata()
    diff = [abs(a - b) for a, b in zip(original_array, modified_array)]
    threshold = 10
    is_ghosted = any(d > threshold for d in diff)
    return is_ghosted

def analyze_median_filter_residue(image_path, block_size=9, threshold=3):
    image = imageio.imread(image_path)
    if len(image.shape) == 3:
        image = image.mean(axis=2)
    kernal_size = (3, 3)
    filtered_image = medfilt2d(image, kernel_size=block_size)
    noise_residue = image - filtered_image
    noise_std = np.std(noise_residue)
    is_forged = noise_std > threshold
    return is_forged


image_path = 'C:\\Users\\DELL\\Desktop\\LP4\\CSDF\\Miniproj\\img.jpg'
exif_data = extract_exif_metadata(image_path)
print("EXIF Metadata:")
for tag, value in exif_data.items():
    print(f'{tag}: {value}')
is_ghosted = detect_jpeg_ghosting(image_path)
if is_ghosted:
    print("JPEG ghosting detected.")
else:
    print("No JPEG ghosting detected.")
is_forged = analyze_median_filter_residue(image_path)
if is_forged:
    print("Digital forgery detected through median-filter noise residue inconsistencies.")
else:
    print("No digital forgery detected.")
