/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> electrical_measurement_desc.o -> ezb_zcl_electrical_measurement_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_electrical_measurement_cluster_desc_add_attr
                    (ezb_zcl_cluster_desc_t cluster_desc,uint16_t attr_id,void *value)

{
  ezb_err_t eVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = CONCAT22(in_register_0000202e,attr_id);
  if (cluster_desc == (ezb_zcl_cluster_desc_t)0x0) {
    return 2;
  }
                    /* WARNING: Load size is inaccurate */
  if (*cluster_desc != 0xb04) {
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
  if (uVar2 < 0x518) {
    if (0x510 < uVar2) goto _L0;
    if (uVar2 == 0x306) {
_L0:
      uVar4 = 0x23;
      goto _L0;
    }
    if (uVar2 < 0x307) {
      if (0x108 < uVar2) {
        if (0x303 < uVar2) {
          uVar4 = 0x2b;
          goto _L0;
        }
        if ((uVar2 != 0x303) && (uVar3 = 0x300, uVar2 < 0x301)) {
          if (uVar2 < 0x206) {
            uVar3 = 0x1ff;
            goto _L84;
          }
_L13:
          if (uVar2 != uVar3) {
            return 6;
          }
        }
        goto _L0;
      }
      if (uVar2 < 0x100) {
        uVar4 = 0x1b;
        if (uVar2 != 0) {
          return 6;
        }
        goto _L0;
      }
      uVar2 = 1 << (uVar2 - 0x100 & 0x1f);
      if (((uVar2 & 0x1b6) == 0) && ((uVar2 & 0x49) == 0)) {
        return 6;
      }
    }
    else if (uVar2 < 0x406) {
      if (0x403 < uVar2) {
_L0:
        uVar4 = 0x28;
        goto _L0;
      }
      if (0x401 < uVar2) goto _L0;
      if (0x312 < uVar2) {
        if (1 < (uVar2 - 0x400 & 0xffff)) {
          return 6;
        }
        goto _L0;
      }
    }
    else if (uVar2 != 0x50b) {
      if (uVar2 < 0x50c) {
        if ((0x507 < uVar2) || (uVar3 = 0x505, 0x505 < uVar2)) goto _L0;
        if ((0x503 < uVar2) || (uVar3 = 0x501, uVar2 < 0x502)) goto _L13;
      }
      else {
        if (uVar2 == 0x510) goto _L0;
        if ((uVar2 != 0x50e) && (uVar2 == 0x50f)) goto _L0;
      }
    }
  }
  else if (uVar2 < 0x80b) {
    if (uVar2 < 0x807) {
      if (uVar2 < 0x703) {
        uVar3 = 0x700;
        if (uVar2 < 0x701) {
          if (0x605 < uVar2) {
            uVar4 = 0x18;
_L0:
            if (uVar2 != uVar3) {
              return 6;
            }
            goto _L0;
          }
          uVar3 = 0x5ff;
_L84:
          if (uVar2 <= uVar3) {
            return 6;
          }
          goto _L0;
        }
      }
      else {
        if (uVar2 == 0x800) {
          uVar4 = 0x19;
          goto _L0;
        }
        if (5 < (uVar2 - 0x801 & 0xffff)) {
          return 6;
        }
      }
    }
  }
  else {
    if (uVar2 == 0xa01) goto _L0;
    if (uVar2 < 0xa02) {
      if (uVar2 != 0x90e) {
        if (uVar2 < 0x90f) {
          if (uVar2 != 0x908) {
            if (uVar2 < 0x909) {
              if ((uVar2 == 0x905) || ((0x905 < uVar2 || (uVar2 == 0x901)))) goto _L0;
              if (1 < (uVar2 - 0x902 & 0xffff)) {
                return 6;
              }
            }
            else if ((uVar2 != 0x90b) && (uVar2 < 0x90c)) goto _L0;
            goto _L0;
          }
        }
        else {
          if (uVar2 == 0x910) goto _L0;
          if (0x910 < uVar2) {
            iVar6 = -0x911;
_L91:
            if (6 < (iVar6 + uVar2 & 0xffff)) {
              return 6;
            }
          }
        }
_L0:
        uVar4 = 0x21;
        goto _L0;
      }
    }
    else if (uVar2 != 0xa0e) {
      if (0xa0e < uVar2) {
        if (uVar2 == 0xa10) goto _L0;
        if (0xa10 < uVar2) {
          iVar6 = -0xa11;
          goto _L91;
        }
        goto _L0;
      }
      if (uVar2 < 0xa0b) {
        if (((0xa08 < uVar2) || (uVar2 == 0xa08)) || (uVar3 = 0xa05, 0xa05 < uVar2)) goto _L0;
        if (0xa03 < uVar2) {
          uVar4 = 0x21;
          goto _L0;
        }
      }
    }
  }
_L0:
  uVar4 = 0x29;
_L0:
  eVar1 = ezb_zcl_cluster_desc_add_manuf_attr(uVar4,0);
  return eVar1;
}

