/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> metering_desc.o -> ezb_zcl_metering_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_metering_cluster_desc_add_attr
                    (ezb_zcl_cluster_desc_t cluster_desc,uint16_t attr_id,void *value)

{
  ezb_err_t eVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = CONCAT22(in_register_0000202e,attr_id);
  if (cluster_desc == (ezb_zcl_cluster_desc_t)0x0) {
    return 2;
  }
                    /* WARNING: Load size is inaccurate */
  if (*cluster_desc != 0x702) {
    return 2;
  }
  uVar4 = (uint)*(byte *)((int)cluster_desc + 2);
  uVar5 = 1;
  if (1 < (uVar4 - 1 & 0xffff)) {
    uVar4 = 0;
    uVar2 = __assert_func(0,0,0,value);
  }
  if (uVar4 != uVar5) {
    if (7 < uVar2) {
      return 6;
    }
_L0:
    uVar3 = 0x1b;
    goto _L0;
  }
  if (uVar2 < 0x45c) {
    if (0x43f < uVar2) {
_L0:
      uVar3 = 0x23;
      goto _L0;
    }
    if (uVar2 == 0x204) {
      uVar3 = 0x1f;
      goto _L0;
    }
    if (uVar2 < 0x205) {
      if (uVar2 != 0xf) {
        if (uVar2 < 0x10) {
          if (uVar2 == 6) {
            uVar3 = 0x28;
            goto _L0;
          }
          if (uVar2 < 7) {
            if (uVar2 == 5) goto _L0;
          }
          else {
            if (uVar2 < 0xc) {
              if (uVar2 < 10) goto _L95;
              goto _L0;
            }
            if (uVar2 == 0xd) goto _L0;
            uVar4 = 0xe;
_L0:
            if (uVar2 == uVar4) goto _L0;
          }
        }
        else if (uVar2 != 0x1f) {
          if (uVar2 < 0x20) {
            if (0x16 < uVar2) {
              if (uVar2 < 0x1c) goto _L0;
              uVar4 = 0x1e;
              goto _L0;
            }
            if (uVar2 < 0x15) {
              if (uVar2 != 0x13) {
                if (uVar2 != 0x14) {
                  if (1 < (uVar2 - 0x11 & 0xffff)) {
                    return 6;
                  }
                  goto _L0;
                }
                goto _L0;
              }
              goto _L0;
            }
          }
          else if (uVar2 != 0x1fe) {
            if (uVar2 < 0x1ff) {
              if (uVar2 == 0x22) goto _L95;
              if (uVar2 < 0x23) goto _L0;
              if (uVar2 < 0x160) {
                uVar4 = 0xff;
                uVar3 = 0x25;
                goto _L0;
              }
              uVar4 = 0x1fc;
              uVar3 = 0x25;
            }
            else {
              if (uVar2 == 0x201) goto _L0;
              if (0x201 < uVar2) goto _L0;
              uVar4 = 0x200;
              uVar3 = 0x18;
            }
_L0:
            if (uVar2 != uVar4) {
              return 6;
            }
            goto _L0;
          }
        }
      }
_L0:
      uVar3 = 0x25;
    }
    else {
      if (uVar2 < 0x315) {
        if (uVar2 < 0x303) {
          if (uVar2 == 0x206) {
_L0:
            uVar3 = 0x41;
            goto _L0;
          }
          if (uVar2 < 0x207) goto _L0;
          if (uVar2 != 0x300) {
            if (0x300 < uVar2) goto _L0;
            if (uVar2 != 0x207) {
              return 6;
            }
          }
        }
        else {
          uVar2 = 1 << (uVar2 - 0x303 & 0x1f);
          if ((uVar2 & 0x3058f) != 0) {
_L0:
            uVar3 = 0x18;
            goto _L0;
          }
          if ((uVar2 >> 4 & 0x783) != 0) goto _L0;
          if ((uVar2 >> 6 & 0x209) == 0) {
            return 6;
          }
        }
        goto _L0;
      }
      if (uVar2 < 0x409) {
        if (uVar2 < 0x407) {
          if (uVar2 == 0x400) {
_L0:
            uVar3 = 0x2a;
            goto _L0;
          }
          if (uVar2 < 0x400) {
            return 6;
          }
          if (0x404 < uVar2) goto _L95;
        }
      }
      else {
        if (uVar2 < 0x417) {
          if (0x40c < uVar2) goto _L0;
          goto _L0;
        }
        if (uVar2 < 0x42e) {
          uVar4 = 0x41f;
          goto _L0;
        }
        if (0xb < (uVar2 - 0x430 & 0xffff)) {
          return 6;
        }
      }
_L0:
      uVar3 = 0x22;
    }
    goto _L0;
  }
  if (uVar2 == 0x807) {
_L0:
    uVar3 = 0x19;
  }
  else {
    if (uVar2 < 0x808) {
      if (uVar2 == 0x801) goto _L0;
      if (0x801 < uVar2) {
        uVar3 = 0x1d;
        if (uVar2 == 0x806) goto _L0;
        goto _L0;
      }
      if (uVar2 != 0x605) {
        if (uVar2 < 0x606) {
          if (uVar2 < 0x602) {
            if (0x5ff < uVar2) goto _L0;
            if (uVar2 != 0x45c) {
              uVar4 = 0x500;
              goto _L124;
            }
          }
          else if (uVar2 != 0x604) {
_L0:
            uVar3 = 0x20;
            goto _L0;
          }
_L0:
          uVar3 = 0x21;
          goto _L0;
        }
        if (uVar2 == 0x800) goto _L0;
        if (0x609 < uVar2) {
          uVar2 = uVar2 - 0x700;
          goto _L114;
        }
        if (uVar2 == 0x606) goto _L0;
      }
    }
    else {
      if (0xb15 < uVar2) {
        if (uVar2 < 0xc0d) {
          if (0xc08 < uVar2) goto _L0;
          if (uVar2 < 0xc05) {
            uVar4 = 0xc00;
            if (uVar2 < 0xc01) {
              uVar3 = 0x2a;
              goto _L0;
            }
          }
          else if (uVar2 < 0xc07) goto _L95;
        }
        else {
          if (0xc2d < uVar2) {
            if (uVar2 < 0xc3c) {
              uVar4 = 0xc2f;
_L0:
              uVar3 = 0x22;
_L0:
              if (uVar2 <= uVar4) {
                return 6;
              }
              goto _L0;
            }
            if (0x1b < (uVar2 - 0xc40 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          if (uVar2 < 0xc20) {
            if (3 < (uVar2 - 0xc0d & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
        }
        goto _L0;
      }
      if (uVar2 < 0xb01) {
        if (uVar2 < 0xa15) {
          if (uVar2 < 0xa00) {
            uVar2 = uVar2 - 0x900;
_L114:
            if (0xff < (uVar2 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          uVar2 = 1 << (uVar2 - 0xa00 & 0x1f);
          if ((uVar2 & 0xa000a) == 0) {
            if ((uVar2 & 0x50005) == 0) {
              if ((uVar2 & 0x100010) == 0) {
                return 6;
              }
              goto _L0;
            }
            goto _L0;
          }
        }
        else if (uVar2 != 0xb00) {
          return 6;
        }
_L95:
        uVar3 = 0xe2;
        goto _L0;
      }
      uVar4 = uVar4 << (uVar2 - 0xb01 & 0x1f);
      if ((uVar4 >> 0xf & 0x2d) != 0) goto _L0;
      if ((uVar4 & 0x10001) == 0) {
        uVar4 = 0xb14;
_L124:
        if (uVar2 != uVar4) {
          return 6;
        }
        goto _L0;
      }
    }
_L0:
    uVar3 = 0x30;
  }
_L0:
  eVar1 = ezb_zcl_cluster_desc_add_manuf_attr(uVar3,0);
  return eVar1;
}

