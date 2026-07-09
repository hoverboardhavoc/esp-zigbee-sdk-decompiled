/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> simple_measurement.o -> check_value_simple_s16_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
check_value_simple_s16_measurement_server
          (undefined4 param_1,uint param_2,undefined4 param_3,short *param_4,short *param_5)

{
  short sVar1;
  short sVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  
  sVar1 = *param_4;
  if (3 < param_2) {
    return 0;
  }
  if (sVar1 == -0x8000) {
    return 0;
  }
  if (param_2 == 3) {
    sVar4 = param_5[2];
    sVar5 = param_5[3];
    goto _L0;
  }
  sVar4 = *param_5;
  sVar5 = param_5[1];
  if ((param_2 == 0) || (param_2 == 2)) {
    iVar3 = simple_measurement_srv_get_attr_desc(param_3,param_1,1);
    if ((iVar3 != 0) && (*(short **)(iVar3 + 8) != (short *)0x0)) {
      sVar2 = **(short **)(iVar3 + 8);
      if (sVar2 != -0x8000) {
        sVar4 = sVar2;
      }
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/simple_measurement.c",
                  0x91,"check_value_simple_s16_measurement_server",
                  "attr_desc != ((void *)0) && attr_desc->data_p != ((void *)0)");
  }
  else {
_L0:
    if (1 < param_2) goto _L0;
  }
  iVar3 = simple_measurement_srv_get_attr_desc(param_3,param_1,2);
  if ((iVar3 == 0) || (*(short **)(iVar3 + 8) == (short *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/simple_measurement.c",
                  0x99,"check_value_simple_s16_measurement_server",
                  "attr_desc != ((void *)0) && attr_desc->data_p != ((void *)0)");
    return 1;
  }
  sVar2 = **(short **)(iVar3 + 8);
  if (sVar2 != -0x8000) {
    sVar5 = sVar2;
  }
_L0:
  if (sVar1 < sVar4) {
    return 1;
  }
  if (sVar1 <= sVar5) {
    return 0;
  }
  return 1;
}

