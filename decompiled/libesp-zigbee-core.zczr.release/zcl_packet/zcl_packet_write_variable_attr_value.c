/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_write_variable_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_packet_write_variable_attr_value
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  puVar3 = &local_30;
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  iVar1 = zcl_attr_type_is_composite(param_3);
  if (iVar1 == 0) {
    uVar2 = zcl_get_attr_value_size(param_3,0);
    if (0x10 < uVar2) {
      __assert_func(0,0,0,0);
    }
    zcl_write_attr_value(&local_30,param_4,param_3);
  }
  else {
    uVar2 = zcl_get_attr_value_size(param_3,param_4);
    puVar3 = (undefined4 *)param_4;
  }
  zmsg_write_bytes(param_1,param_2,uVar2,puVar3);
  return;
}

