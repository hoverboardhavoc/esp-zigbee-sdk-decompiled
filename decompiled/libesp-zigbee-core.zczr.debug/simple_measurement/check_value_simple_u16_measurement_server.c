/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> simple_measurement.o -> check_value_simple_u16_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
check_value_simple_u16_measurement_server
          (undefined4 param_1,uint param_2,undefined4 param_3,ushort *param_4,ushort *param_5)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  
  uVar1 = *param_4;
  if (3 < param_2) {
    return 0;
  }
  if (uVar1 == 0xffff) {
    return 0;
  }
  if (param_2 == 3) {
    uVar4 = param_5[2];
    uVar5 = param_5[3];
    goto _L0;
  }
  uVar4 = *param_5;
  uVar5 = param_5[1];
  if ((param_2 == 0) || (param_2 == 2)) {
    iVar3 = simple_measurement_srv_get_attr_desc(param_3,param_1,1);
    if ((iVar3 != 0) && (*(ushort **)(iVar3 + 8) != (ushort *)0x0)) {
      uVar2 = **(ushort **)(iVar3 + 8);
      if (uVar2 != 0xffff) {
        uVar4 = uVar2;
      }
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/simple_measurement.c",
                  0x68,"check_value_simple_u16_measurement_server",
                  "attr_desc != ((void *)0) && attr_desc->data_p != ((void *)0)");
  }
  else {
_L0:
    if (1 < param_2) goto _L0;
  }
  iVar3 = simple_measurement_srv_get_attr_desc(param_3,param_1,2);
  if ((iVar3 == 0) || (*(ushort **)(iVar3 + 8) == (ushort *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/simple_measurement.c",
                  0x70,"check_value_simple_u16_measurement_server",
                  "attr_desc != ((void *)0) && attr_desc->data_p != ((void *)0)");
    return 1;
  }
  uVar2 = **(ushort **)(iVar3 + 8);
  if (uVar2 != 0xffff) {
    uVar5 = uVar2;
  }
_L0:
  if (uVar1 < uVar4) {
    return 1;
  }
  if (uVar1 <= uVar5) {
    return 0;
  }
  return 1;
}

