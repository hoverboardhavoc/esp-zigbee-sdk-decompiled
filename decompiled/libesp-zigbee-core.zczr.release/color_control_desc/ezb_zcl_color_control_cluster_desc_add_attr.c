/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> color_control_desc.o -> ezb_zcl_color_control_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_color_control_cluster_desc_add_attr
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
  if (*cluster_desc != 0x300) {
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
  if (uVar2 < 0x2a) {
    if (uVar2 < 0xf) {
      if (uVar2 < 5) {
        if (uVar2 < 3) {
          if (uVar2 == uVar5) goto _L0;
          uVar4 = 0x20;
          if (uVar2 != 2) goto _L0;
        }
      }
      else {
        if (uVar2 == 6) {
          uVar4 = 0x42;
          goto _L0;
        }
        if (uVar2 < 7) goto _L0;
        if (uVar2 != 7) {
          uVar3 = 8;
          goto _L0;
        }
      }
    }
    else {
      uVar5 = uVar5 << (uVar2 - 0xf & 0x1f);
      if ((uVar5 & 0x6660ccc) == 0) {
        if ((uVar5 & 0x881112) == 0) {
          if ((uVar5 & 1) == 0) {
            return 6;
          }
          uVar4 = 0x18;
          goto _L0;
        }
        goto _L0;
      }
    }
  }
  else if (uVar2 < 0x4004) {
    uVar3 = 0x4001;
    if (0x4001 < uVar2) {
_L0:
      uVar4 = 0x20;
      goto _L0;
    }
    if (uVar2 < 0x3d) {
      uVar5 = uVar5 << (uVar2 - 0x2a & 0x1f);
      if ((uVar5 & 0x333c0) == 0) {
        if (((uVar5 >> 10 & 0x111) == 0) && ((uVar5 & 1) == 0)) {
          return 6;
        }
        goto _L0;
      }
    }
    else if (uVar2 != 0x4000) {
_L0:
      if (uVar2 != uVar3) {
        return 6;
      }
_L0:
      uVar4 = 0x30;
      goto _L0;
    }
  }
  else {
    if (uVar2 == 0x400a) {
      uVar4 = 0x19;
      goto _L0;
    }
    if (uVar2 < 0x400b) {
      if ((uVar2 != 0x4004) && (uVar5 < (uVar2 - 0x4005 & 0xffff))) {
        return 6;
      }
    }
    else {
      if (uVar2 == 0xeff0) {
        uVar4 = 0;
        goto _L0;
      }
      if (0xeff0 < uVar2) {
        return 6;
      }
      if ((0x400d < uVar2) && (uVar2 != 0x4010)) {
        return 6;
      }
    }
  }
  uVar4 = 0x21;
_L0:
  eVar1 = ezb_zcl_cluster_desc_add_manuf_attr(uVar4,0);
  return eVar1;
}

