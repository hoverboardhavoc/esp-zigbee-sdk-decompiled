/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_get_pib_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_iface_get_pib_attr(int *param_1,uint param_2,uint *param_3)

{
  byte bVar1;
  void *__src;
  byte bVar2;
  undefined2 uVar3;
  uint uVar4;
  
  __src = (void *)*param_1;
  if (param_3 == (uint *)0x0) {
    return 2;
  }
  if (param_2 == 0x52) {
    bVar2 = (byte)(*(uint *)((int)__src + 0x28) >> 0x11) & 1;
  }
  else {
    if (param_2 < 0x53) {
      if (param_2 == 0x4a) {
        __src = (void *)((int)__src + 0x10);
_L45:
        memcpy(param_3,__src,8);
        return 0;
      }
      if (param_2 < 0x4b) {
        if (param_2 == 0x46) {
          bVar2 = *(byte *)((int)__src + 0x23);
        }
        else if (param_2 < 0x47) {
          if (param_2 != 0x41) {
            if (param_2 != 0x45) {
              if (param_2 != 0x40) {
                return 500;
              }
              goto _L45;
            }
            uVar4 = *(uint *)((int)__src + 0x24);
_L0:
            *param_3 = uVar4;
            return 0;
          }
          bVar2 = (byte)*(undefined2 *)((int)__src + 0x2a) & 1;
        }
        else {
          if (param_2 == 0x47) {
            uVar4 = 0xf;
            goto _L0;
          }
          if (param_2 != 0x49) {
            return 500;
          }
          bVar2 = *(byte *)((int)__src + 0xd);
        }
      }
      else if (param_2 == 0x4e) {
        bVar2 = *(byte *)((int)__src + 0x22);
      }
      else if (param_2 < 0x4f) {
        if (param_2 == 0x4b) {
          uVar3 = *(undefined2 *)((int)__src + 0xe);
_L0:
          *(undefined2 *)param_3 = uVar3;
          return 0;
        }
        if (param_2 != 0x4c) {
          return 500;
        }
        bVar2 = *(byte *)((int)__src + 0xc);
      }
      else {
        if (param_2 != 0x4f) {
          if (param_2 != 0x50) {
            return 500;
          }
          uVar3 = *(undefined2 *)((int)__src + 10);
          goto _L0;
        }
        bVar2 = *(byte *)((int)__src + 0x20);
      }
      *(byte *)param_3 = bVar2;
      return 0;
    }
    if (param_2 == 0x5a) {
      bVar2 = *(byte *)((int)__src + 0x1f);
    }
    else {
      if (0x5a < param_2) {
        if (param_2 == 0x61) {
          bVar2 = *(byte *)((int)__src + 0x43);
          bVar1 = *(byte *)((int)__src + 0x44);
        }
        else {
          if (param_2 < 0x62) {
            if (param_2 == 0x5d) {
_L0:
              *param_3 = 0;
              return 0;
            }
            if (param_2 != 0x60) {
              return 500;
            }
          }
          else {
            if (param_2 != 0x62) {
              if (param_2 != 99) {
                return 500;
              }
              uVar4 = *(uint *)((int)__src + 0x18);
              goto _L0;
            }
            if ((*(byte *)((int)__src + 0x9c) & 2) == 0) goto _L0;
          }
          bVar2 = *(byte *)((int)__src + 0x41);
          bVar1 = *(byte *)((int)__src + 0x42);
        }
        uVar4 = (uint)(0x20 << (bVar2 & 0x1f)) >> 5 | (uint)bVar1 << 0x1b;
_L0:
        *param_3 = uVar4;
        return 0;
      }
      if (param_2 != 0x57) {
        if (param_2 < 0x58) {
          if (param_2 == 0x54) {
            uVar4 = 0xf;
            goto _L0;
          }
          if (param_2 == 0x55) {
            uVar3 = *(undefined2 *)((int)__src + 0x28);
          }
          else {
            if (param_2 != 0x53) {
              return 500;
            }
            uVar3 = *(undefined2 *)((int)__src + 8);
          }
        }
        else {
          if (param_2 != 0x58) {
            bVar2 = *(byte *)((int)__src + 0x1e);
            goto _L0;
          }
          uVar3 = *(undefined2 *)((int)__src + 0x1c);
        }
        *(undefined2 *)param_3 = uVar3;
        return 0;
      }
      bVar2 = *(byte *)((int)__src + 0x21);
    }
  }
_L0:
  *(byte *)param_3 = bVar2;
  return 0;
}

