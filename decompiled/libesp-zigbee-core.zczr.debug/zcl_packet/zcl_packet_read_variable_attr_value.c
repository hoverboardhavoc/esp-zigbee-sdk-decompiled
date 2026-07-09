/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_read_variable_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

size_t zcl_packet_read_variable_attr_value
                 (int param_1,undefined2 *param_2,undefined4 param_3,int param_4)

{
  size_t __size;
  void *pvVar1;
  size_t sVar2;
  
  if (param_1 == 0) {
    __size = 0xffff;
  }
  else if (param_2 == (undefined2 *)0x0) {
    __size = 0xffff;
  }
  else if (param_4 == 0) {
    __size = 0xffff;
  }
  else {
    __size = zcl_packet_read_variable_attr_actual_size(*param_2);
    if (((__size - 1 & 0xffff) < 0xfffe) && (pvVar1 = calloc(1,__size), pvVar1 != (void *)0x0)) {
      sVar2 = af_read_bytes(param_1,param_2,__size,pvVar1);
      if (sVar2 == __size) {
        zcl_read_attr_value(param_4,pvVar1,param_3);
      }
      else {
        __size = 0xffff;
      }
      mm_free(pvVar1);
    }
  }
  return __size;
}

