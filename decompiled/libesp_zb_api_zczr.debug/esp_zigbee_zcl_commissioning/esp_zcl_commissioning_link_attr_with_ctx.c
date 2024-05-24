/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_link_attr_with_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zcl_commissioning_link_attr_with_ctx(int param_1)

{
  void *__src;
  ushort uVar1;
  ushort *puVar2;
  size_t __n;
  int iVar3;
  
  for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)(param_1 + 2); iVar3 = iVar3 + 1) {
    puVar2 = (ushort *)(*(int *)(param_1 + 4) + iVar3 * 10);
    __src = *(void **)(puVar2 + 3);
    __n = esp_zb_zcl_get_attribute_size((char)puVar2[1],__src);
    uVar1 = *puVar2;
    if (uVar1 == 0x15) {
      *(undefined1 *)(puVar2 + 3) = 0x98;
      *(undefined1 *)((int)puVar2 + 7) = 0x17;
      *(undefined1 *)(puVar2 + 4) = 1;
      *(undefined1 *)((int)puVar2 + 9) = 0;
    }
    else if (uVar1 < 0x16) {
      if (uVar1 == 6) {
        *(undefined1 *)(puVar2 + 3) = 0x98;
        *(undefined1 *)((int)puVar2 + 7) = 0x17;
        *(undefined1 *)(puVar2 + 4) = 1;
        *(undefined1 *)((int)puVar2 + 9) = 0;
      }
      else if (uVar1 < 7) {
        if (uVar1 == 3) {
          *(undefined1 *)(puVar2 + 3) = 0x98;
          *(undefined1 *)((int)puVar2 + 7) = 0x17;
          *(undefined1 *)(puVar2 + 4) = 1;
          *(undefined1 *)((int)puVar2 + 9) = 0;
        }
        else if (uVar1 < 4) {
          if (uVar1 == 1) {
            *(undefined1 *)(puVar2 + 3) = 0x98;
            *(undefined1 *)((int)puVar2 + 7) = 0x17;
            *(undefined1 *)(puVar2 + 4) = 1;
            *(undefined1 *)((int)puVar2 + 9) = 0;
          }
          else if (uVar1 == 2) {
            *(undefined1 *)(puVar2 + 3) = 0x98;
            *(undefined1 *)((int)puVar2 + 7) = 0x17;
            *(undefined1 *)(puVar2 + 4) = 1;
            *(undefined1 *)((int)puVar2 + 9) = 0;
          }
          else if (uVar1 == 0) {
            *(undefined1 *)(puVar2 + 3) = 0x98;
            *(undefined1 *)((int)puVar2 + 7) = 0x17;
            *(undefined1 *)(puVar2 + 4) = 1;
            *(undefined1 *)((int)puVar2 + 9) = 0;
          }
        }
        else if (uVar1 == 4) {
          *(undefined1 *)(puVar2 + 3) = 0x98;
          *(undefined1 *)((int)puVar2 + 7) = 0x17;
          *(undefined1 *)(puVar2 + 4) = 1;
          *(undefined1 *)((int)puVar2 + 9) = 0;
        }
        else if (uVar1 == 5) {
          *(undefined1 *)(puVar2 + 3) = 0x98;
          *(undefined1 *)((int)puVar2 + 7) = 0x17;
          *(undefined1 *)(puVar2 + 4) = 1;
          *(undefined1 *)((int)puVar2 + 9) = 0;
        }
      }
      else if (uVar1 == 0x12) {
        *(undefined1 *)(puVar2 + 3) = 0x98;
        *(undefined1 *)((int)puVar2 + 7) = 0x17;
        *(undefined1 *)(puVar2 + 4) = 1;
        *(undefined1 *)((int)puVar2 + 9) = 0;
      }
      else if (uVar1 < 0x13) {
        if (uVar1 == 0x10) {
          *(undefined1 *)(puVar2 + 3) = 0x98;
          *(undefined1 *)((int)puVar2 + 7) = 0x17;
          *(undefined1 *)(puVar2 + 4) = 1;
          *(undefined1 *)((int)puVar2 + 9) = 0;
        }
        else if (uVar1 == 0x11) {
          *(undefined1 *)(puVar2 + 3) = 0x98;
          *(undefined1 *)((int)puVar2 + 7) = 0x17;
          *(undefined1 *)(puVar2 + 4) = 1;
          *(undefined1 *)((int)puVar2 + 9) = 0;
        }
      }
      else if (uVar1 == 0x13) {
        *(undefined1 *)(puVar2 + 3) = 0x98;
        *(undefined1 *)((int)puVar2 + 7) = 0x17;
        *(undefined1 *)(puVar2 + 4) = 1;
        *(undefined1 *)((int)puVar2 + 9) = 0;
      }
      else if (uVar1 == 0x14) {
        *(undefined1 *)(puVar2 + 3) = 0x98;
        *(undefined1 *)((int)puVar2 + 7) = 0x17;
        *(undefined1 *)(puVar2 + 4) = 1;
        *(undefined1 *)((int)puVar2 + 9) = 0;
      }
    }
    else if (uVar1 == 0x23) {
      *(undefined1 *)(puVar2 + 3) = 0x98;
      *(undefined1 *)((int)puVar2 + 7) = 0x17;
      *(undefined1 *)(puVar2 + 4) = 1;
      *(undefined1 *)((int)puVar2 + 9) = 0;
    }
    else if (uVar1 < 0x24) {
      if (uVar1 == 0x20) {
        *(undefined1 *)(puVar2 + 3) = 0x98;
        *(undefined1 *)((int)puVar2 + 7) = 0x17;
        *(undefined1 *)(puVar2 + 4) = 1;
        *(undefined1 *)((int)puVar2 + 9) = 0;
      }
      else if (uVar1 < 0x21) {
        if (uVar1 == 0x16) {
          *(undefined1 *)(puVar2 + 3) = 0x98;
          *(undefined1 *)((int)puVar2 + 7) = 0x17;
          *(undefined1 *)(puVar2 + 4) = 1;
          *(undefined1 *)((int)puVar2 + 9) = 0;
        }
        else if (uVar1 == 0x17) {
          *(undefined1 *)(puVar2 + 3) = 0x98;
          *(undefined1 *)((int)puVar2 + 7) = 0x17;
          *(undefined1 *)(puVar2 + 4) = 1;
          *(undefined1 *)((int)puVar2 + 9) = 0;
        }
      }
      else if (uVar1 == 0x21) {
        *(undefined1 *)(puVar2 + 3) = 0x98;
        *(undefined1 *)((int)puVar2 + 7) = 0x17;
        *(undefined1 *)(puVar2 + 4) = 1;
        *(undefined1 *)((int)puVar2 + 9) = 0;
      }
      else if (uVar1 == 0x22) {
        *(undefined1 *)(puVar2 + 3) = 0x98;
        *(undefined1 *)((int)puVar2 + 7) = 0x17;
        *(undefined1 *)(puVar2 + 4) = 1;
        *(undefined1 *)((int)puVar2 + 9) = 0;
      }
    }
    else if (uVar1 == 0x40) {
      *(undefined1 *)(puVar2 + 3) = 0x98;
      *(undefined1 *)((int)puVar2 + 7) = 0x17;
      *(undefined1 *)(puVar2 + 4) = 1;
      *(undefined1 *)((int)puVar2 + 9) = 0;
    }
    else if (uVar1 < 0x41) {
      if (uVar1 == 0x30) {
        *(undefined1 *)(puVar2 + 3) = 0x98;
        *(undefined1 *)((int)puVar2 + 7) = 0x17;
        *(undefined1 *)(puVar2 + 4) = 1;
        *(undefined1 *)((int)puVar2 + 9) = 0;
      }
      else if (uVar1 == 0x31) {
        *(undefined1 *)(puVar2 + 3) = 0x98;
        *(undefined1 *)((int)puVar2 + 7) = 0x17;
        *(undefined1 *)(puVar2 + 4) = 1;
        *(undefined1 *)((int)puVar2 + 9) = 0;
      }
    }
    else if (uVar1 == 0x41) {
      *(undefined1 *)(puVar2 + 3) = 0x98;
      *(undefined1 *)((int)puVar2 + 7) = 0x17;
      *(undefined1 *)(puVar2 + 4) = 1;
      *(undefined1 *)((int)puVar2 + 9) = 0;
    }
    else if (uVar1 == 0x42) {
      *(undefined1 *)(puVar2 + 3) = 0x98;
      *(undefined1 *)((int)puVar2 + 7) = 0x17;
      *(undefined1 *)(puVar2 + 4) = 1;
      *(undefined1 *)((int)puVar2 + 9) = 0;
    }
    memcpy(*(void **)(puVar2 + 3),__src,__n);
    free(__src);
  }
  return;
}

