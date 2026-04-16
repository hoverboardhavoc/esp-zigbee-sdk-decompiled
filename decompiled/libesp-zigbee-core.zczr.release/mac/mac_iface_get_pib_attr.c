/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_get_pib_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_iface_get_pib_attr
                    (mac_interface_t *iface,mac_pib_attr_t pib_attr,void *value,size_t value_size)

{
  byte bVar1;
  undefined3 in_register_0000202d;
  void *__src;
  byte bVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar5 = CONCAT31(in_register_0000202d,pib_attr);
  __src = iface->dev;
  if (value == (void *)0x0) {
    return 2;
  }
  if (uVar5 == 0x52) {
    bVar2 = (byte)(*(uint *)((int)__src + 0x28) >> 0x11) & 1;
  }
  else {
    if (uVar5 < 0x53) {
      if (uVar5 == 0x4a) {
        __src = (void *)((int)__src + 0x10);
_L45:
        memcpy(value,__src,8);
        return 0;
      }
      if (uVar5 < 0x4b) {
        if (uVar5 == 0x46) {
          bVar2 = *(byte *)((int)__src + 0x23);
        }
        else if (uVar5 < 0x47) {
          if (uVar5 != 0x41) {
            if (uVar5 != 0x45) {
              if (uVar5 != 0x40) {
                return 500;
              }
              goto _L45;
            }
            uVar4 = *(undefined4 *)((int)__src + 0x24);
_L0:
            *(undefined4 *)value = uVar4;
            return 0;
          }
          bVar2 = (byte)*(undefined2 *)((int)__src + 0x2a) & 1;
        }
        else {
          if (uVar5 == 0x47) {
            uVar4 = 0xf;
            goto _L0;
          }
          if (uVar5 != 0x49) {
            return 500;
          }
          bVar2 = *(byte *)((int)__src + 0xd);
        }
      }
      else if (uVar5 == 0x4e) {
        bVar2 = *(byte *)((int)__src + 0x22);
      }
      else if (uVar5 < 0x4f) {
        if (uVar5 == 0x4b) {
          uVar3 = *(undefined2 *)((int)__src + 0xe);
_L0:
          *(undefined2 *)value = uVar3;
          return 0;
        }
        if (uVar5 != 0x4c) {
          return 500;
        }
        bVar2 = *(byte *)((int)__src + 0xc);
      }
      else {
        if (uVar5 != 0x4f) {
          if (uVar5 != 0x50) {
            return 500;
          }
          uVar3 = *(undefined2 *)((int)__src + 10);
          goto _L0;
        }
        bVar2 = *(byte *)((int)__src + 0x20);
      }
      *(byte *)value = bVar2;
      return 0;
    }
    if (uVar5 == 0x5a) {
      bVar2 = *(byte *)((int)__src + 0x1f);
    }
    else {
      if (0x5a < uVar5) {
        if (uVar5 == 0x61) {
          bVar2 = *(byte *)((int)__src + 0x43);
          bVar1 = *(byte *)((int)__src + 0x44);
        }
        else {
          if (uVar5 < 0x62) {
            if (uVar5 == 0x5d) {
_L0:
              *(undefined4 *)value = 0;
              return 0;
            }
            if (uVar5 != 0x60) {
              return 500;
            }
          }
          else {
            if (uVar5 != 0x62) {
              if (uVar5 != 99) {
                return 500;
              }
              uVar5 = *(uint *)((int)__src + 0x18);
              goto _L0;
            }
            if ((*(byte *)((int)__src + 0x9c) & 2) == 0) goto _L0;
          }
          bVar2 = *(byte *)((int)__src + 0x41);
          bVar1 = *(byte *)((int)__src + 0x42);
        }
        uVar5 = (uint)(0x20 << (bVar2 & 0x1f)) >> 5 | (uint)bVar1 << 0x1b;
_L0:
        *(uint *)value = uVar5;
        return 0;
      }
      if (uVar5 != 0x57) {
        if (uVar5 < 0x58) {
          if (uVar5 == 0x54) {
            uVar5 = 0xf;
            goto _L0;
          }
          if (uVar5 == 0x55) {
            uVar3 = *(undefined2 *)((int)__src + 0x28);
          }
          else {
            if (uVar5 != 0x53) {
              return 500;
            }
            uVar3 = *(undefined2 *)((int)__src + 8);
          }
        }
        else {
          if (uVar5 != 0x58) {
            bVar2 = *(byte *)((int)__src + 0x1e);
            goto _L0;
          }
          uVar3 = *(undefined2 *)((int)__src + 0x1c);
        }
        *(undefined2 *)value = uVar3;
        return 0;
      }
      bVar2 = *(byte *)((int)__src + 0x21);
    }
  }
_L0:
  *(byte *)value = bVar2;
  return 0;
}

