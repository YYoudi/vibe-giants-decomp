// Giants Vanilla-Native Recomp — TGA texture parser. See VanillaTGA.h.
#include "VanillaTGA.h"
#include "VanillaVFS.h"
#include <cstdio>
#include <cstring>

extern FILE* g_vTrace;

namespace VanillaTGA {

static uint16_t rdU16(const uint8_t* p) {
    return uint16_t(p[0]) | (uint16_t(p[1]) << 8);
}

Image Parse(const uint8_t* data, size_t len) {
    Image img{};
    if (len < 18) return img;
    uint8_t  idLen     = data[0];
    uint8_t  colorMapType = data[1];
    /*uint8_t dataTypeCode = data[2];*/
    img.imageType   = data[2];
    /*colorMapOrigin = rdU16(data+3); colorMapLen = rdU16(data+5); cmapDepth=data[7];*/
    img.width       = rdU16(data + 12);
    img.height      = rdU16(data + 14);
    img.bitsPerPixel = data[16];
    uint8_t  descriptor = data[17];
    bool topOrigin    = (descriptor & 0x20) != 0;   // bit 5 = top-left origin
    (void)topOrigin; (void)colorMapType; (void)idLen;

    if (img.width == 0 || img.height == 0 || img.width > 8192 || img.height > 8192) return img;
    if (img.imageType != 2 && img.imageType != 10) return img;   // only true-color
    uint32_t bpp = img.bitsPerPixel / 8;
    if (bpp != 2 && bpp != 3 && bpp != 4) return img;

    size_t pos = 18 + idLen;
    // skip color map if present (rare for type 2)
    if (colorMapType == 1) {
        uint16_t cmLen = rdU16(data + 5);
        uint8_t  cmDepth = data[7];
        pos += (size_t)cmLen * ((cmDepth + 7) / 8);
    }

    size_t pixBytes = (size_t)img.width * img.height * bpp;
    img.pixels.resize(pixBytes);

    if (img.imageType == 2) {
        // uncompressed
        if (pos + pixBytes > len) return img;
        memcpy(img.pixels.data(), data + pos, pixBytes);
    } else {
        // RLE (type 10): packets of [header byte][pixel(s)]. high bit=1 → RLE (1 pixel, count+1 times); =0 → raw (count+1 pixels).
        size_t out = 0;
        while (out < pixBytes && pos < len) {
            uint8_t hdr = data[pos++];
            uint32_t count = (hdr & 0x7f) + 1;
            if (hdr & 0x80) {
                if (pos + bpp > len) break;
                for (uint32_t i = 0; i < count && out + bpp <= pixBytes; i++) {
                    memcpy(img.pixels.data() + out, data + pos, bpp);
                    out += bpp;
                }
                pos += bpp;
            } else {
                uint32_t raw = count * bpp;
                if (pos + raw > len) break;
                uint32_t cpy = (out + raw <= pixBytes) ? raw : (uint32_t)(pixBytes - out);
                memcpy(img.pixels.data() + out, data + pos, cpy);
                out += cpy; pos += raw;
            }
        }
    }
    img.ok = true;
    return img;
}

bool SelfTest() {
    auto data = VanillaVFS::GzpReadFile("Bin\\w_intro_island.gzp", "intro_sea.tga");
    if (data.empty()) {
        if (g_vTrace) { fprintf(g_vTrace, "[VTGA] intro_sea.tga not found\n"); fflush(g_vTrace); }
        return false;
    }
    Image img = Parse(data.data(), data.size());
    if (!img.ok) {
        if (g_vTrace) { fprintf(g_vTrace, "[VTGA] parse FAILED (type=%u)\n", img.imageType); fflush(g_vTrace); }
        return false;
    }
    if (g_vTrace) {
        fprintf(g_vTrace, "[VTGA] intro_sea.tga: %ux%u %ubpp type=%u pixels=%zu\n",
                img.width, img.height, img.bitsPerPixel, img.imageType, img.pixels.size());
        fflush(g_vTrace);
    }
    return true;
}

} // namespace VanillaTGA
