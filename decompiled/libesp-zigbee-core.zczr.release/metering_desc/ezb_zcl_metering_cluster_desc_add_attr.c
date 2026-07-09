/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> metering_desc.o -> ezb_zcl_metering_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zcl_metering_cluster_desc_add_attr(short *param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == (short *)0x0) {
    return 2;
  }
  if (*param_1 != 0x702) {
    return 2;
  }
  uVar2 = (uint)*(byte *)(param_1 + 1);
  uVar3 = 1;
  if (1 < (uVar2 - 1 & 0xffff)) {
    uVar2 = 0;
    param_2 = __assert_func(0,0,0,param_3);
  }
  if (uVar2 != uVar3) {
    if (7 < param_2) {
      return 6;
    }
_L0:
    uVar1 = 0x1b;
    goto _L0;
  }
  if (param_2 < 0x45c) {
    if (0x43f < param_2) {
_L0:
      uVar1 = 0x23;
      goto _L0;
    }
    if (param_2 == 0x204) {
      uVar1 = 0x1f;
      goto _L0;
    }
    if (param_2 < 0x205) {
      if (param_2 != 0xf) {
        if (param_2 < 0x10) {
          if (param_2 == 6) {
            uVar1 = 0x28;
            goto _L0;
          }
          if (param_2 < 7) {
            if (param_2 == 5) goto _L0;
          }
          else {
            if (param_2 < 0xc) {
              if (param_2 < 10) goto _L95;
              goto _L0;
            }
            if (param_2 == 0xd) goto _L0;
            uVar2 = 0xe;
_L0:
            if (param_2 == uVar2) goto _L0;
          }
        }
        else if (param_2 != 0x1f) {
          if (param_2 < 0x20) {
            if (0x16 < param_2) {
              if (param_2 < 0x1c) goto _L0;
              uVar2 = 0x1e;
              goto _L0;
            }
            if (param_2 < 0x15) {
              if (param_2 != 0x13) {
                if (param_2 != 0x14) {
                  if (1 < (param_2 - 0x11 & 0xffff)) {
                    return 6;
                  }
                  goto _L0;
                }
                goto _L0;
              }
              goto _L0;
            }
          }
          else if (param_2 != 0x1fe) {
            if (param_2 < 0x1ff) {
              if (param_2 == 0x22) goto _L95;
              if (param_2 < 0x23) goto _L0;
              if (param_2 < 0x160) {
                uVar2 = 0xff;
                uVar1 = 0x25;
                goto _L0;
              }
              uVar2 = 0x1fc;
              uVar1 = 0x25;
            }
            else {
              if (param_2 == 0x201) goto _L0;
              if (0x201 < param_2) goto _L0;
              uVar2 = 0x200;
              uVar1 = 0x18;
            }
_L0:
            if (param_2 != uVar2) {
              return 6;
            }
            goto _L0;
          }
        }
      }
_L0:
      uVar1 = 0x25;
    }
    else {
      if (param_2 < 0x315) {
        if (param_2 < 0x303) {
          if (param_2 == 0x206) {
_L0:
            uVar1 = 0x41;
            goto _L0;
          }
          if (param_2 < 0x207) goto _L0;
          if (param_2 != 0x300) {
            if (0x300 < param_2) goto _L0;
            if (param_2 != 0x207) {
              return 6;
            }
          }
        }
        else {
          uVar2 = 1 << (param_2 - 0x303 & 0x1f);
          if ((uVar2 & 0x3058f) != 0) {
_L0:
            uVar1 = 0x18;
            goto _L0;
          }
          if ((uVar2 >> 4 & 0x783) != 0) goto _L0;
          if ((uVar2 >> 6 & 0x209) == 0) {
            return 6;
          }
        }
        goto _L0;
      }
      if (param_2 < 0x409) {
        if (param_2 < 0x407) {
          if (param_2 == 0x400) {
_L0:
            uVar1 = 0x2a;
            goto _L0;
          }
          if (param_2 < 0x400) {
            return 6;
          }
          if (0x404 < param_2) goto _L95;
        }
      }
      else {
        if (param_2 < 0x417) {
          if (0x40c < param_2) goto _L0;
          goto _L0;
        }
        if (param_2 < 0x42e) {
          uVar2 = 0x41f;
          goto _L0;
        }
        if (0xb < (param_2 - 0x430 & 0xffff)) {
          return 6;
        }
      }
_L0:
      uVar1 = 0x22;
    }
    goto _L0;
  }
  if (param_2 == 0x807) {
_L0:
    uVar1 = 0x19;
  }
  else {
    if (param_2 < 0x808) {
      if (param_2 == 0x801) goto _L0;
      if (0x801 < param_2) {
        uVar1 = 0x1d;
        if (param_2 == 0x806) goto _L0;
        goto _L0;
      }
      if (param_2 != 0x605) {
        if (param_2 < 0x606) {
          if (param_2 < 0x602) {
            if (0x5ff < param_2) goto _L0;
            if (param_2 != 0x45c) {
              uVar2 = 0x500;
              goto _L124;
            }
          }
          else if (param_2 != 0x604) {
_L0:
            uVar1 = 0x20;
            goto _L0;
          }
_L0:
          uVar1 = 0x21;
          goto _L0;
        }
        if (param_2 == 0x800) goto _L0;
        if (0x609 < param_2) {
          param_2 = param_2 - 0x700;
          goto _L114;
        }
        if (param_2 == 0x606) goto _L0;
      }
    }
    else {
      if (0xb15 < param_2) {
        if (param_2 < 0xc0d) {
          if (0xc08 < param_2) goto _L0;
          if (param_2 < 0xc05) {
            uVar2 = 0xc00;
            if (param_2 < 0xc01) {
              uVar1 = 0x2a;
              goto _L0;
            }
          }
          else if (param_2 < 0xc07) goto _L95;
        }
        else {
          if (0xc2d < param_2) {
            if (param_2 < 0xc3c) {
              uVar2 = 0xc2f;
_L0:
              uVar1 = 0x22;
_L0:
              if (param_2 <= uVar2) {
                return 6;
              }
              goto _L0;
            }
            if (0x1b < (param_2 - 0xc40 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          if (param_2 < 0xc20) {
            if (3 < (param_2 - 0xc0d & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
        }
        goto _L0;
      }
      if (param_2 < 0xb01) {
        if (param_2 < 0xa15) {
          if (param_2 < 0xa00) {
            param_2 = param_2 - 0x900;
_L114:
            if (0xff < (param_2 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          uVar2 = 1 << (param_2 - 0xa00 & 0x1f);
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
        else if (param_2 != 0xb00) {
          return 6;
        }
_L95:
        uVar1 = 0xe2;
        goto _L0;
      }
      uVar2 = uVar2 << (param_2 - 0xb01 & 0x1f);
      if ((uVar2 >> 0xf & 0x2d) != 0) goto _L0;
      if ((uVar2 & 0x10001) == 0) {
        uVar2 = 0xb14;
_L124:
        if (param_2 != uVar2) {
          return 6;
        }
        goto _L0;
      }
    }
_L0:
    uVar1 = 0x30;
  }
_L0:
  uVar1 = ezb_zcl_cluster_desc_add_manuf_attr(uVar1,0);
  return uVar1;
}

