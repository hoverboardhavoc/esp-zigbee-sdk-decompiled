/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> power_config_desc.o -> ezb_zcl_power_config_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_power_config_cluster_desc_add_attr
                    (ezb_zcl_cluster_desc_t cluster_desc,uint16_t attr_id,void *value)

{
  ezb_err_t eVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar2 = CONCAT22(in_register_0000202e,attr_id);
  if (cluster_desc == (ezb_zcl_cluster_desc_t)0x0) {
    return 2;
  }
                    /* WARNING: Load size is inaccurate */
  if (*cluster_desc != 1) {
    return 2;
  }
  uVar5 = (uint)*(byte *)((int)cluster_desc + 2);
  uVar3 = 1;
  if (1 < (uVar5 - 1 & 0xffff)) {
    uVar5 = 0;
    uVar3 = 0;
    uVar2 = __assert_func(0,0,value);
  }
  if (uVar5 != uVar3) {
    return 6;
  }
  if (uVar2 != 0x40) {
    if (uVar2 < 0x41) {
      if (uVar2 != 0x21) {
        if (uVar2 < 0x22) {
          if (uVar2 != uVar5) {
            if (uVar5 < uVar2) {
              if (uVar2 == 0x10) goto _L0;
              if (uVar2 < 0x10) {
                return 6;
              }
              if (0x13 < uVar2) {
                if (uVar2 != 0x20) {
                  return 6;
                }
                goto _L0;
              }
            }
            goto _L0;
          }
        }
        else {
          if (uVar2 == 0x35) {
_L0:
            uVar4 = 0x18;
            goto _L0;
          }
          if (uVar2 < 0x36) {
            if (uVar2 == 0x31) goto _L0;
            if (uVar2 < 0x32) {
              if (uVar2 != 0x30) {
                return 6;
              }
              goto _L0;
            }
            if (uVar2 == 0x32) goto _L0;
          }
          else {
            if (uVar2 == 0x3e) {
_L0:
              uVar4 = 0x1b;
              goto _L0;
            }
            if (uVar2 == 0x3f) {
              return 6;
            }
          }
        }
      }
    }
    else if (uVar2 != 0x60) {
      if (uVar2 < 0x61) {
        if (uVar2 == 0x52) {
_L0:
          uVar4 = 0x21;
          goto _L0;
        }
        if (uVar2 < 0x53) {
          if (uVar2 == 0x50) goto _L0;
          if (uVar2 == 0x51) {
_L0:
            uVar4 = 0x30;
            goto _L0;
          }
          uVar3 = 0x41;
_L58:
          if (uVar2 != uVar3) {
            return 6;
          }
        }
        else if (uVar2 != 0x56) {
          if (uVar2 < 0x57) {
            uVar3 = 0x55;
_L0:
            if (uVar2 == uVar3) goto _L0;
          }
          else if (0x5d < uVar2) {
            uVar4 = 0x1b;
            if (uVar2 != 0x5e) {
              return 6;
            }
            goto _L0;
          }
        }
      }
      else {
        if (uVar2 == 0x72) goto _L0;
        if (uVar2 < 0x73) {
          if (uVar2 != 0x70) {
            if (uVar2 != 0x71) {
              uVar3 = 0x61;
              goto _L58;
            }
            goto _L0;
          }
_L0:
          uVar4 = 0x42;
          goto _L0;
        }
        if (uVar2 != 0x76) {
          if (uVar2 < 0x77) {
            uVar3 = 0x75;
            goto _L0;
          }
          if (0x7d < uVar2) {
            if (uVar2 != 0x7e) {
              return 6;
            }
            goto _L0;
          }
        }
      }
    }
  }
_L0:
  uVar4 = 0x20;
_L0:
  eVar1 = ezb_zcl_cluster_desc_add_manuf_attr(uVar4,0);
  return eVar1;
}

