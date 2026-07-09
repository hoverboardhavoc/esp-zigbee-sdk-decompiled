/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> electrical_measurement_desc.o -> ezb_zcl_electrical_measurement_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
ezb_zcl_electrical_measurement_cluster_desc_add_attr(short *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == (short *)0x0) {
    return 2;
  }
  if (*param_1 != 0xb04) {
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
    return 6;
  }
  if (param_2 < 0x518) {
    if (0x510 < param_2) goto _L0;
    if (param_2 == 0x306) {
_L0:
      uVar2 = 0x23;
      goto _L0;
    }
    if (param_2 < 0x307) {
      if (0x108 < param_2) {
        if (0x303 < param_2) {
          uVar2 = 0x2b;
          goto _L0;
        }
        if ((param_2 != 0x303) && (uVar1 = 0x300, param_2 < 0x301)) {
          if (param_2 < 0x206) {
            uVar1 = 0x1ff;
            goto _L84;
          }
_L13:
          if (param_2 != uVar1) {
            return 6;
          }
        }
        goto _L0;
      }
      if (param_2 < 0x100) {
        uVar2 = 0x1b;
        if (param_2 != 0) {
          return 6;
        }
        goto _L0;
      }
      uVar1 = 1 << (param_2 - 0x100 & 0x1f);
      if (((uVar1 & 0x1b6) == 0) && ((uVar1 & 0x49) == 0)) {
        return 6;
      }
    }
    else if (param_2 < 0x406) {
      if (0x403 < param_2) {
_L0:
        uVar2 = 0x28;
        goto _L0;
      }
      if (0x401 < param_2) goto _L0;
      if (0x312 < param_2) {
        if (1 < (param_2 - 0x400 & 0xffff)) {
          return 6;
        }
        goto _L0;
      }
    }
    else if (param_2 != 0x50b) {
      if (param_2 < 0x50c) {
        if ((0x507 < param_2) || (uVar1 = 0x505, 0x505 < param_2)) goto _L0;
        if ((0x503 < param_2) || (uVar1 = 0x501, param_2 < 0x502)) goto _L13;
      }
      else {
        if (param_2 == 0x510) goto _L0;
        if ((param_2 != 0x50e) && (param_2 == 0x50f)) goto _L0;
      }
    }
  }
  else if (param_2 < 0x80b) {
    if (param_2 < 0x807) {
      if (param_2 < 0x703) {
        uVar1 = 0x700;
        if (param_2 < 0x701) {
          if (0x605 < param_2) {
            uVar2 = 0x18;
_L0:
            if (param_2 != uVar1) {
              return 6;
            }
            goto _L0;
          }
          uVar1 = 0x5ff;
_L84:
          if (param_2 <= uVar1) {
            return 6;
          }
          goto _L0;
        }
      }
      else {
        if (param_2 == 0x800) {
          uVar2 = 0x19;
          goto _L0;
        }
        if (5 < (param_2 - 0x801 & 0xffff)) {
          return 6;
        }
      }
    }
  }
  else {
    if (param_2 == 0xa01) goto _L0;
    if (param_2 < 0xa02) {
      if (param_2 != 0x90e) {
        if (param_2 < 0x90f) {
          if (param_2 != 0x908) {
            if (param_2 < 0x909) {
              if ((param_2 == 0x905) || ((0x905 < param_2 || (param_2 == 0x901)))) goto _L0;
              if (1 < (param_2 - 0x902 & 0xffff)) {
                return 6;
              }
            }
            else if ((param_2 != 0x90b) && (param_2 < 0x90c)) goto _L0;
            goto _L0;
          }
        }
        else {
          if (param_2 == 0x910) goto _L0;
          if (0x910 < param_2) {
            iVar4 = -0x911;
_L91:
            if (6 < (iVar4 + param_2 & 0xffff)) {
              return 6;
            }
          }
        }
_L0:
        uVar2 = 0x21;
        goto _L0;
      }
    }
    else if (param_2 != 0xa0e) {
      if (0xa0e < param_2) {
        if (param_2 == 0xa10) goto _L0;
        if (0xa10 < param_2) {
          iVar4 = -0xa11;
          goto _L91;
        }
        goto _L0;
      }
      if (param_2 < 0xa0b) {
        if (((0xa08 < param_2) || (param_2 == 0xa08)) || (uVar1 = 0xa05, 0xa05 < param_2)) goto _L0;
        if (0xa03 < param_2) {
          uVar2 = 0x21;
          goto _L0;
        }
      }
    }
  }
_L0:
  uVar2 = 0x29;
_L0:
  uVar2 = ezb_zcl_cluster_desc_add_manuf_attr(uVar2,0);
  return uVar2;
}

