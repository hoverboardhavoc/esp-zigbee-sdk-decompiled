/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
poll_control_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  ushort uVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  int iVar3;
  undefined3 in_register_0000202d;
  undefined4 uVar4;
  undefined4 extraout_a1;
  uint uVar5;
  
  uVar4 = CONCAT31(in_register_0000202d,endpoint);
  uVar2 = CONCAT22(in_register_0000202a,attr_id);
  if (value == (void *)0x0) {
    uVar2 = __assert_func(0,0,0);
    uVar4 = extraout_a1;
  }
  if (uVar2 == 2) {
                    /* WARNING: Load size is inaccurate */
    uVar1 = (ushort)*value;
    iVar3 = zcl_get_attr_desc(uVar4,0x20,1,0);
    if (iVar3 != 0) {
      if (uVar1 == 0) {
        return 0x87;
      }
                    /* WARNING: Load size is inaccurate */
      uVar2 = (uint)(ushort)*value;
      uVar5 = **(uint **)(iVar3 + 8);
_L0:
      if (uVar5 < uVar2) {
        return 0x87;
      }
      return '\0';
    }
  }
  else if (uVar2 < 3) {
                    /* WARNING: Load size is inaccurate */
    uVar5 = *value;
    if (uVar2 == 0) {
      if (uVar5 == 0) {
        return '\0';
      }
      iVar3 = zcl_get_attr_desc(uVar4,0x20,1,4,0);
      if (iVar3 == 0) {
        uVar1 = (ushort)(uVar5 < 0x6e0001);
      }
      else {
        uVar1 = 0;
        if (uVar5 < 0x6e0001) {
                    /* WARNING: Load size is inaccurate */
          uVar1 = *value < **(uint **)(iVar3 + 8) ^ 1;
        }
      }
      iVar3 = zcl_get_attr_desc(uVar4,0x20,1,0);
      if (iVar3 != 0) {
        if (uVar1 == 0) {
          return 0x87;
        }
                    /* WARNING: Load size is inaccurate */
        if (**(uint **)(iVar3 + 8) <= *value) {
          return '\0';
        }
        return 0x87;
      }
    }
    else {
      iVar3 = zcl_get_attr_desc(uVar4,0x20,1,5,0);
      if (iVar3 == 0) {
        uVar1 = (ushort)(uVar5 - 4 < 0x6dfffd);
      }
      else {
        uVar1 = 0;
        if (uVar5 - 4 < 0x6dfffd) {
                    /* WARNING: Load size is inaccurate */
          uVar1 = *value < **(uint **)(iVar3 + 8) ^ 1;
        }
      }
      iVar3 = zcl_get_attr_desc(uVar4,0x20,1,0,0);
      if ((iVar3 != 0) && (uVar1 != 0)) {
                    /* WARNING: Load size is inaccurate */
        uVar1 = **(uint **)(iVar3 + 8) < *value ^ 1;
      }
      iVar3 = zcl_get_attr_desc(uVar4,0x20,1,2,0);
      if (iVar3 != 0) {
        if (uVar1 == 0) {
          return 0x87;
        }
        uVar2 = (uint)**(ushort **)(iVar3 + 8);
                    /* WARNING: Load size is inaccurate */
        uVar5 = *value;
        goto _L0;
      }
    }
  }
  else {
    if (uVar2 != 3) {
      return '\0';
    }
                    /* WARNING: Load size is inaccurate */
    uVar1 = (ushort)*value;
    iVar3 = zcl_get_attr_desc(uVar4,0x20,1,6,0);
    if (iVar3 != 0) {
      if (uVar1 == 0) {
        return 0x87;
      }
                    /* WARNING: Load size is inaccurate */
      uVar2 = (uint)(ushort)*value;
      uVar5 = (uint)**(ushort **)(iVar3 + 8);
      goto _L0;
    }
  }
  if (uVar1 == 0) {
    return 0x87;
  }
  return '\0';
}

