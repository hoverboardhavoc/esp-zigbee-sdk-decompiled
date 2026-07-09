/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_report_attr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

void zb_zcl_report_attr_handler(byte *param_1,code *param_2)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  uint local_30 [5];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  local_30[0] = (uint)*param_1;
  convert_ezb_address_to_esp_zb_zcl_addr(local_30 + 1,*(undefined4 *)(param_1 + 8));
  local_30[4] = *(undefined4 *)(*(int *)(param_1 + 8) + 0x14);
  if (*(undefined2 **)(param_1 + 0xc) != (undefined2 *)0x0) {
    uStack_1c = CONCAT22(uStack_1c._2_2_,**(undefined2 **)(param_1 + 0xc));
    iVar3 = *(int *)(param_1 + 0xc);
    uStack_18 = CONCAT31(uStack_18._1_3_,*(undefined1 *)(iVar3 + 2));
    uStack_14 = *(undefined4 *)(iVar3 + 4);
    uVar2 = ezb_zcl_get_attr_value_size(*(undefined1 *)(iVar3 + 2),*(undefined4 *)(iVar3 + 4));
    uStack_18 = CONCAT22(uVar2,(undefined2)uStack_18);
  }
  if (param_2 != (code *)0x0) {
    (*param_2)(5,local_30);
    bVar1 = esp_err_to_zcl_status();
    param_1[0x10] = bVar1;
  }
  return;
}

