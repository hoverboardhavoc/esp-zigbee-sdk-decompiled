/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> power_config_desc.o -> ezb_zcl_power_config_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
ezb_zcl_power_config_cluster_desc_add_attr(short *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == (short *)0x0) {
    return 2;
  }
  if (*param_1 != 1) {
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
  if (param_2 != 0x40) {
    if (param_2 < 0x41) {
      if (param_2 != 0x21) {
        if (param_2 < 0x22) {
          if (param_2 != uVar3) {
            if (uVar3 < param_2) {
              if (param_2 == 0x10) goto _L0;
              if (param_2 < 0x10) {
                return 6;
              }
              if (0x13 < param_2) {
                if (param_2 != 0x20) {
                  return 6;
                }
                goto _L0;
              }
            }
            goto _L0;
          }
        }
        else {
          if (param_2 == 0x35) {
_L0:
            uVar2 = 0x18;
            goto _L0;
          }
          if (param_2 < 0x36) {
            if (param_2 == 0x31) goto _L0;
            if (param_2 < 0x32) {
              if (param_2 != 0x30) {
                return 6;
              }
              goto _L0;
            }
            if (param_2 == 0x32) goto _L0;
          }
          else {
            if (param_2 == 0x3e) {
_L0:
              uVar2 = 0x1b;
              goto _L0;
            }
            if (param_2 == 0x3f) {
              return 6;
            }
          }
        }
      }
    }
    else if (param_2 != 0x60) {
      if (param_2 < 0x61) {
        if (param_2 == 0x52) {
_L0:
          uVar2 = 0x21;
          goto _L0;
        }
        if (param_2 < 0x53) {
          if (param_2 == 0x50) goto _L0;
          if (param_2 == 0x51) {
_L0:
            uVar2 = 0x30;
            goto _L0;
          }
          uVar1 = 0x41;
_L58:
          if (param_2 != uVar1) {
            return 6;
          }
        }
        else if (param_2 != 0x56) {
          if (param_2 < 0x57) {
            uVar1 = 0x55;
_L0:
            if (param_2 == uVar1) goto _L0;
          }
          else if (0x5d < param_2) {
            uVar2 = 0x1b;
            if (param_2 != 0x5e) {
              return 6;
            }
            goto _L0;
          }
        }
      }
      else {
        if (param_2 == 0x72) goto _L0;
        if (param_2 < 0x73) {
          if (param_2 != 0x70) {
            if (param_2 != 0x71) {
              uVar1 = 0x61;
              goto _L58;
            }
            goto _L0;
          }
_L0:
          uVar2 = 0x42;
          goto _L0;
        }
        if (param_2 != 0x76) {
          if (param_2 < 0x77) {
            uVar1 = 0x75;
            goto _L0;
          }
          if (0x7d < param_2) {
            if (param_2 != 0x7e) {
              return 6;
            }
            goto _L0;
          }
        }
      }
    }
  }
_L0:
  uVar2 = 0x20;
_L0:
  uVar2 = ezb_zcl_cluster_desc_add_manuf_attr(uVar2,0);
  return uVar2;
}

