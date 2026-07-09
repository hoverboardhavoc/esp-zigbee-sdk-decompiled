/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
poll_control_cluster_srv_check_value_handler(uint param_1,undefined4 param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 extraout_a1;
  uint uVar3;
  uint uVar4;
  
  if (param_3 == (uint *)0x0) {
    param_1 = __assert_func(0,0,0);
    param_2 = extraout_a1;
  }
  if (param_1 == 2) {
    uVar1 = (ushort)*param_3;
    iVar2 = zcl_get_attr_desc(param_2,0x20,1,0);
    if (iVar2 != 0) {
      if (uVar1 == 0) {
        return 0x87;
      }
      uVar4 = (uint)(ushort)*param_3;
      uVar3 = **(uint **)(iVar2 + 8);
_L0:
      if (uVar3 < uVar4) {
        return 0x87;
      }
      return 0;
    }
  }
  else if (param_1 < 3) {
    uVar4 = *param_3;
    if (param_1 == 0) {
      if (uVar4 == 0) {
        return 0;
      }
      iVar2 = zcl_get_attr_desc(param_2,0x20,1,4,0);
      if (iVar2 == 0) {
        uVar1 = (ushort)(uVar4 < 0x6e0001);
      }
      else {
        uVar1 = 0;
        if (uVar4 < 0x6e0001) {
          uVar1 = *param_3 < **(uint **)(iVar2 + 8) ^ 1;
        }
      }
      iVar2 = zcl_get_attr_desc(param_2,0x20,1,0);
      if (iVar2 != 0) {
        if (uVar1 == 0) {
          return 0x87;
        }
        if (**(uint **)(iVar2 + 8) <= *param_3) {
          return 0;
        }
        return 0x87;
      }
    }
    else {
      iVar2 = zcl_get_attr_desc(param_2,0x20,1,5,0);
      if (iVar2 == 0) {
        uVar1 = (ushort)(uVar4 - 4 < 0x6dfffd);
      }
      else {
        uVar1 = 0;
        if (uVar4 - 4 < 0x6dfffd) {
          uVar1 = *param_3 < **(uint **)(iVar2 + 8) ^ 1;
        }
      }
      iVar2 = zcl_get_attr_desc(param_2,0x20,1,0,0);
      if ((iVar2 != 0) && (uVar1 != 0)) {
        uVar1 = **(uint **)(iVar2 + 8) < *param_3 ^ 1;
      }
      iVar2 = zcl_get_attr_desc(param_2,0x20,1,2,0);
      if (iVar2 != 0) {
        if (uVar1 == 0) {
          return 0x87;
        }
        uVar4 = (uint)**(ushort **)(iVar2 + 8);
        uVar3 = *param_3;
        goto _L0;
      }
    }
  }
  else {
    if (param_1 != 3) {
      return 0;
    }
    uVar1 = (ushort)*param_3;
    iVar2 = zcl_get_attr_desc(param_2,0x20,1,6,0);
    if (iVar2 != 0) {
      if (uVar1 == 0) {
        return 0x87;
      }
      uVar4 = (uint)(ushort)*param_3;
      uVar3 = (uint)**(ushort **)(iVar2 + 8);
      goto _L0;
    }
  }
  if (uVar1 == 0) {
    return 0x87;
  }
  return 0;
}

