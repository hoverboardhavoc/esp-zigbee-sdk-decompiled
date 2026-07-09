/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
poll_control_cluster_srv_check_value_handler(uint param_1,undefined4 param_2,uint *param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (param_3 == (uint *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/poll_control.c",0xfa,
                  "poll_control_cluster_srv_check_value_handler","value");
_L0:
    uVar3 = 0;
  }
  else {
    if (param_1 == 2) {
      uVar4 = *param_3;
      bVar1 = (ushort)uVar4 != 0;
      iVar2 = zcl_get_attr_desc(param_2,0x20,1,0);
      if (iVar2 != 0) {
        if ((ushort)uVar4 == 0) {
          return 0x87;
        }
        if ((uint)(ushort)*param_3 <= **(uint **)(iVar2 + 8)) {
          return 0;
        }
        return 0x87;
      }
    }
    else if (param_1 < 3) {
      if (param_1 == 0) {
        uVar4 = *param_3;
        if (uVar4 == 0) {
          return 0;
        }
        bVar1 = uVar4 < 0x6e0001;
        iVar2 = zcl_get_attr_desc(param_2,0x20,1,4,0);
        if (iVar2 != 0) {
          if (uVar4 < 0x6e0001) {
            if (*param_3 < **(uint **)(iVar2 + 8)) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
          }
          else {
            bVar1 = false;
          }
        }
        iVar2 = zcl_get_attr_desc(param_2,0x20,1,0);
        if (iVar2 != 0) {
          if (!bVar1) {
            return 0x87;
          }
          if (**(uint **)(iVar2 + 8) <= *param_3) {
            return 0;
          }
          return 0x87;
        }
      }
      else {
        if (param_1 != 1) goto _L0;
        uVar4 = *param_3;
        bVar1 = uVar4 - 4 < 0x6dfffd;
        iVar2 = zcl_get_attr_desc(param_2,0x20,1,5,0);
        if (iVar2 != 0) {
          if (uVar4 - 4 < 0x6dfffd) {
            if (*param_3 < **(uint **)(iVar2 + 8)) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
          }
          else {
            bVar1 = false;
          }
        }
        iVar2 = zcl_get_attr_desc(param_2,0x20,1,0,0);
        if (iVar2 != 0) {
          if (bVar1) {
            if (**(uint **)(iVar2 + 8) < *param_3) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
          }
          else {
            bVar1 = false;
          }
        }
        iVar2 = zcl_get_attr_desc(param_2,0x20,1,2,0);
        if (iVar2 != 0) {
          if (!bVar1) {
            return 0x87;
          }
          if ((uint)**(ushort **)(iVar2 + 8) <= *param_3) {
            return 0;
          }
          return 0x87;
        }
      }
    }
    else {
      if (param_1 != 3) {
        return 0;
      }
      uVar4 = *param_3;
      bVar1 = (ushort)uVar4 != 0;
      iVar2 = zcl_get_attr_desc(param_2,0x20,1,6,0);
      if (iVar2 != 0) {
        if ((ushort)uVar4 == 0) {
          return 0x87;
        }
        if ((ushort)*param_3 <= **(ushort **)(iVar2 + 8)) {
          return 0;
        }
        return 0x87;
      }
    }
    if (bVar1) {
      uVar3 = 0;
    }
    else {
      uVar3 = 0x87;
    }
  }
  return uVar3;
}

