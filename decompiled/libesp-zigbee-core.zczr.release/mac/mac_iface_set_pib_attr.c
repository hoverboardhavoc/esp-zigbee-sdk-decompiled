/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_set_pib_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint mac_iface_set_pib_attr(undefined4 *param_1,uint param_2,uint *param_3)

{
  uint *puVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = (uint *)*param_1;
  if (param_3 == (uint *)0x0) {
    return 2;
  }
  if (param_2 == 0x50) {
    mac_set_panid(puVar1,(short)*param_3);
    return 0;
  }
  if (param_2 < 0x51) {
    if (param_2 == 0x49) {
      *(byte *)((int)puVar1 + 0xd) = (byte)*param_3;
      return 0;
    }
    if (param_2 < 0x4a) {
      if (param_2 == 0x45) {
        puVar1[9] = *param_3;
        return 0;
      }
      if (0x45 < param_2) {
        if (param_2 == 0x46) {
          *(byte *)((int)puVar1 + 0x23) = (byte)*param_3;
          return 0;
        }
        uVar3 = 0xf4;
        if (param_2 != 0x47) goto _L0;
        goto _L0;
      }
      if (param_2 == 0x40) {
        uVar3 = param_3[1];
        *puVar1 = *param_3;
        puVar1[1] = uVar3;
        mac_pal_set_extaddr(puVar1);
        return 0;
      }
      if (param_2 == 0x41) {
        *(byte *)((int)puVar1 + 0x2a) = *(byte *)((int)puVar1 + 0x2a) & 0xfe | (byte)*param_3 & 1;
        return 0;
      }
    }
    else {
      if (param_2 == 0x4c) {
        *(byte *)(puVar1 + 3) = (byte)*param_3;
        return 0;
      }
      if (param_2 < 0x4d) {
        if (param_2 == 0x4a) {
          memcpy(puVar1 + 4,param_3,8);
          return 0;
        }
        *(short *)((int)puVar1 + 0xe) = (short)*param_3;
        return 0;
      }
      if (param_2 == 0x4e) {
        *(byte *)((int)puVar1 + 0x22) = (byte)*param_3;
        return 0;
      }
      if (param_2 == 0x4f) {
        *(byte *)(puVar1 + 8) = (byte)*param_3;
        return 0;
      }
    }
  }
  else {
    if (param_2 == 0x58) {
      *(short *)(puVar1 + 7) = (short)*param_3;
      return 0;
    }
    if (param_2 < 0x59) {
      if (param_2 == 0x54) {
_L0:
        uVar3 = 0xfb;
        goto _L0;
      }
      if (param_2 < 0x55) {
        if (param_2 == 0x52) {
          if ((uint)(byte)*param_3 == (puVar1[10] >> 0x11 & 1)) {
            return 0;
          }
          *(byte *)((int)puVar1 + 0x2a) =
               *(byte *)((int)puVar1 + 0x2a) & 0xfd | (byte)(((byte)*param_3 & 1) << 1);
          mac_pal_set_rx_when_idle();
_L0:
          mac_do_idle(puVar1);
          return 0;
        }
        if (param_2 == 0x53) {
          *(short *)(puVar1 + 2) = (short)*param_3;
          mac_pal_set_shortaddr();
          return 0;
        }
      }
      else {
        if (param_2 == 0x55) {
          *(short *)(puVar1 + 10) = (short)*param_3;
          return 0;
        }
        if (param_2 == 0x57) {
          *(byte *)((int)puVar1 + 0x21) = (byte)*param_3;
          return 0;
        }
      }
    }
    else {
      if (param_2 == 0x60) goto _L0;
      if (param_2 < 0x61) {
        if (param_2 == 0x5a) {
          *(byte *)((int)puVar1 + 0x1f) = (byte)*param_3;
          return 0;
        }
        if (param_2 == 0x5d) goto _L0;
        if (param_2 == 0x59) {
          *(byte *)((int)puVar1 + 0x1e) = (byte)*param_3;
          return 0;
        }
      }
      else {
        if (param_2 == 0x62) {
          if ((*param_3 & 0x7ffffff) == 0) {
            if ((puVar1[0x27] & 2) == 0) {
              return 0;
            }
            *(byte *)(puVar1 + 0x27) = (byte)puVar1[0x27] & 0xfd;
            *(char *)((int)puVar1 + 0x42) = (char)puVar1[0x11];
            *(undefined1 *)((int)puVar1 + 0x41) = *(undefined1 *)((int)puVar1 + 0x43);
          }
          else {
            uVar3 = __ctzsi2(param_3);
            if (((puVar1[6] & 0x7ffffff) >> (uVar3 & 0x1f) & 1) == 0) {
              return 0;
            }
            uVar4 = *param_3;
            *(byte *)(puVar1 + 0x27) = (byte)puVar1[0x27] | 2;
            *(byte *)((int)puVar1 + 0x42) = (byte)(uVar4 >> 0x1b);
            *(char *)((int)puVar1 + 0x41) = (char)uVar3;
          }
          goto _L0;
        }
        if (param_2 == 99) goto _L0;
        if (param_2 == 0x61) {
          uVar3 = *param_3;
          if ((uVar3 & 0x7ffffff) != 0) {
            uVar2 = __ctzsi2(uVar3 & 0x7ffffff);
            mac_set_pan_channel(puVar1,uVar3 >> 0x1b,uVar2);
            return 0;
          }
          return 2;
        }
      }
    }
  }
  uVar3 = 0xf4;
_L0:
  return uVar3 | 0x100;
}

