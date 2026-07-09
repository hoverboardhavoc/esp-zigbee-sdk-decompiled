/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_set_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_set_attr_value(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = zcl_get_attr_desc();
  if (iVar1 == 0) {
    iVar2 = 1;
  }
  else {
    iVar2 = 1;
    if (param_6 != 0) {
      if (param_7 != 0) {
        if ((*(byte *)(iVar1 + 3) & 2) == 0) {
          return 0x88;
        }
        if ((*(byte *)(iVar1 + 3) & 0x40) != 0) {
          return 0x8c;
        }
      }
      iVar2 = zcl_cluster_template_find(param_2,param_3);
      if (iVar2 != 0) {
        if ((*(code **)(iVar2 + 4) != (code *)0x0) &&
           (iVar3 = (**(code **)(iVar2 + 4))(param_4,param_1,param_6), iVar3 != 0)) {
          return iVar3;
        }
        if (*(code **)(iVar2 + 8) != (code *)0x0) {
          (**(code **)(iVar2 + 8))(param_1,param_4,param_6,param_5);
        }
      }
      zcl_write_attr_value(*(undefined4 *)(iVar1 + 8),param_6,*(undefined1 *)(iVar1 + 2));
      zcl_reporting_mark_attr_change(param_1,param_2,param_3,param_4,param_5);
      iVar2 = 0;
    }
  }
  return iVar2;
}

