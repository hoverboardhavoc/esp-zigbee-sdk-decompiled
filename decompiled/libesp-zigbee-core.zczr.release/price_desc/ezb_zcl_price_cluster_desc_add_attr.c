/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> price_desc.o -> ezb_zcl_price_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zcl_price_cluster_desc_add_attr(short *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == (short *)0x0) {
    return 2;
  }
  uVar4 = 2;
  if (*param_1 != 0x700) {
    return 2;
  }
  uVar3 = (uint)*(byte *)(param_1 + 1);
  uVar1 = 1;
  if (1 < (uVar3 - 1 & 0xffff)) {
    uVar3 = 0;
    uVar1 = 0;
    param_2 = __assert_func(0,0,param_3);
  }
  if (uVar3 != uVar1) {
    if (uVar1 < param_2) goto _L0;
    goto _L0;
  }
  if (param_2 == 0x621) goto _L0;
  if (param_2 < 0x622) {
    if (param_2 == 0x204) {
_L0:
      uVar2 = 0x18;
      goto _L0;
    }
    if (0x204 < param_2) {
      if (param_2 == 0x616) {
        uVar2 = 0x21;
        goto _L0;
      }
      if (param_2 < 0x617) {
        if (param_2 < 0x307) {
          if (param_2 < 0x300) {
            return 6;
          }
          uVar4 = 1 << (param_2 - 0x300 & 0x1f);
          if ((uVar4 & 0x16) == 0) {
            if ((uVar4 & 0x21) == 0) {
              uVar4 = uVar4 & 0x48;
              uVar2 = 0x18;
              goto _L0;
            }
_L0:
            uVar2 = 0x30;
            goto _L0;
          }
        }
        else {
          if (param_2 == 0x610) goto _L0;
          if (0x610 < param_2) {
            if (param_2 != 0x613) {
              if (0x613 < param_2) {
                uVar4 = 0x615;
                uVar2 = 0x30;
                goto _L0;
              }
              goto _L0;
            }
            goto _L0;
          }
          if (param_2 < 0x530) {
            if (param_2 < 0x50f) {
              param_2 = param_2 - 0x400;
              goto _L135;
            }
          }
          else if (1 < (param_2 - 0x5fe & 0xffff)) {
            return 6;
          }
        }
      }
      else {
        if (param_2 == 0x617) goto _L0;
        if (param_2 == 0x619) goto _L0;
        uVar4 = 0x620;
_L145:
        if (param_2 != uVar4) {
          return 6;
        }
      }
_L0:
      uVar2 = 0x23;
      goto _L0;
    }
    if (0x16e < param_2) {
      if (param_2 < 0x1cf) {
        uVar4 = 0x1bf;
        if (0x1bf < param_2) goto _L0;
        if (param_2 < 0x19f) {
          uVar4 = 399;
          if (399 < param_2) goto _L0;
          if (param_2 != 0x17f) {
            if (param_2 < 0x180) {
              uVar4 = 0x16f;
            }
            goto _L0;
          }
        }
        else if (param_2 != 0x1af) {
          if (param_2 < 0x1b0) {
            uVar4 = 0x19f;
          }
          goto _L0;
        }
      }
      else if (param_2 < 0x1ff) {
        uVar4 = 0x1ef;
        if (0x1ef < param_2) goto _L0;
        if (param_2 != 0x1df) {
          if (param_2 < 0x1e0) {
            uVar4 = 0x1cf;
          }
          goto _L0;
        }
      }
      else {
        if (0x200 < param_2) goto _L0;
        if (param_2 != 0x1ff) goto _L0;
      }
      goto _L0;
    }
    if (param_2 < 0x160) {
      if (0x10e < param_2) {
        if (param_2 < 0x13f) {
          uVar4 = 0x12f;
          if (0x12f < param_2) goto _L0;
          if (param_2 != 0x11f) {
            if (param_2 < 0x120) {
              uVar4 = 0x10f;
            }
            goto _L0;
          }
        }
        else if (param_2 != 0x14f) {
          if (param_2 < 0x150) {
            uVar4 = 0x13f;
          }
          else {
            uVar4 = 0x15f;
          }
_L0:
          if (param_2 != uVar4) goto _L0;
        }
_L0:
        uVar2 = 0x20;
        goto _L0;
      }
      if (param_2 < 0x100) {
        if ((5 < param_2) && (0x29 < (param_2 - 6 & 0xffff))) {
          return 6;
        }
        goto _L0;
      }
    }
_L0:
    uVar2 = 0x25;
    goto _L0;
  }
  if (param_2 < 0x833) {
    if (param_2 < 0x820) {
      if (param_2 != 0x802) {
        if (param_2 < 0x803) {
          if (param_2 != 0x702) {
            if (param_2 < 0x703) {
              if (param_2 != 0x700) {
                if (param_2 != 0x701) {
                  if (param_2 != 0x622) {
                    return 6;
                  }
                  goto _L0;
                }
_L0:
                uVar2 = 0x22;
                goto _L0;
              }
            }
            else {
              if (param_2 == 0x704) goto _L0;
              if (param_2 < 0x705) goto _L0;
              if (param_2 != 0x800) {
                uVar4 = 0x801;
                goto _L0;
              }
            }
          }
          goto _L0;
        }
        if (param_2 != 0x80a) {
          if (param_2 < 0x80a) {
            return 6;
          }
          if (param_2 != 0x810) {
            if (param_2 < 0x811) {
              uVar4 = 0x80b;
_L0:
              if (param_2 != uVar4) {
                return 6;
              }
              goto _L0;
            }
            if (1 < (param_2 - 0x811 & 0xffff)) {
              return 6;
            }
            goto _L0;
          }
          goto _L0;
        }
      }
      uVar2 = 0x2b;
      goto _L0;
    }
    uVar3 = uVar3 << (param_2 - 0x820 & 0x1f);
    if ((uVar3 & 0x10001) != 0) goto _L0;
    if ((uVar3 & 0x20002) == 0) {
      if ((uVar3 & 0x40004) == 0) {
        return 6;
      }
_L0:
      uVar2 = 0x41;
      goto _L0;
    }
  }
  else if (param_2 < 0x8204) {
    if (0x8200 < param_2) goto _L0;
    if (param_2 < 0x8030) {
      if ((short)param_2 < 0) goto _L0;
      if (0x12 < (param_2 - 0x840 & 0xffff)) {
        return 6;
      }
      uVar4 = 1 << (param_2 - 0x840 & 0x1f);
      if ((uVar4 & 0x10001) != 0) goto _L0;
      if ((uVar4 & 0x20002) == 0) {
        uVar4 = uVar4 & 0x40004;
        uVar2 = 0x41;
_L0:
        if (uVar4 == 0) {
          return 6;
        }
        goto _L0;
      }
    }
    else {
      if (param_2 < 0x810f) {
        if (param_2 < 0x8100) {
          return 6;
        }
        goto _L0;
      }
      if (param_2 != 0x8200) {
        return 6;
      }
    }
  }
  else {
    if (param_2 == 0x8627) goto _L0;
    if (param_2 < 0x8628) {
      if (param_2 < 0x8614) {
        uVar4 = 0x8610;
        if (0x8610 < param_2) goto _L0;
        if (0x852f < param_2) {
          uVar2 = 0x41;
          goto _L0;
        }
        if (param_2 < 0x850f) {
          param_2 = param_2 + 0x7c00;
_L135:
          if (0xff < (param_2 & 0xffff)) {
            return 6;
          }
        }
      }
      else if (param_2 != 0x8625) {
        if (param_2 != 0x8626) {
          uVar4 = 0x8615;
          goto _L0;
        }
        goto _L0;
      }
      goto _L0;
    }
    if (param_2 != 0x8702) {
      if (0x8702 < param_2) {
        if (param_2 != 0x8703) {
          uVar4 = 0x8704;
          goto _L145;
        }
        goto _L0;
      }
      if (param_2 != 0x8700) {
        uVar4 = 0x8701;
        uVar2 = 0x22;
_L0:
        if (param_2 != uVar4) {
          return 6;
        }
        goto _L0;
      }
    }
  }
_L0:
  uVar2 = 0xe2;
_L0:
  uVar2 = ezb_zcl_cluster_desc_add_manuf_attr(uVar2,0);
  return uVar2;
}

