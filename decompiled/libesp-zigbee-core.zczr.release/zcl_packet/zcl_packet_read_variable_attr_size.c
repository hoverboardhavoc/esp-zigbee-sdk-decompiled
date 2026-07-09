/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_read_variable_attr_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_packet_read_variable_attr_size(undefined4 param_1,undefined2 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined2 uStack_22;
  uint auStack_20 [5];
  
  if (param_3 < 0x2f) {
    if (param_3 < 0x1a) {
      if (param_3 == 10) {
        return 4;
      }
      if ((param_3 - 0xc & 0xff) < 3) {
        return 8;
      }
    }
    else {
      uVar2 = 1 << (param_3 - 0x1a & 0x1f);
      if ((uVar2 & 0x1c1c1c) != 0) {
        return 8;
      }
      if ((uVar2 & 0x10101) != 0) {
        return 4;
      }
    }
  }
  auStack_20[0] = 0;
  auStack_20[1] = 0;
  auStack_20[2] = 0;
  auStack_20[3] = 0;
  uStack_22 = param_2;
  iVar1 = zcl_attr_type_is_composite(param_3);
  if (iVar1 == 0) {
    uVar2 = zcl_get_attr_value_size(param_3,0);
    return uVar2;
  }
  if ((param_3 - 0x41 & 0xff) < 2) {
    af_read_bytes(param_1,&uStack_22,auStack_20);
    return (auStack_20[0] & 0xff) + 1;
  }
  if ((param_3 - 0x43 & 0xff) < 2) {
    af_read_bytes(param_1,&uStack_22,2,auStack_20);
    auStack_20[0] = auStack_20[0] & 0xffff;
  }
  else {
    if (param_3 == 0x49) {
      af_read_bytes(param_1,&uStack_22,2,auStack_20);
      auStack_20[0] = ((auStack_20[0] & 0xffff) + 1) * 2;
      goto _L13;
    }
    if (param_3 != 0x4a) {
      return 0;
    }
    af_read_bytes(param_1,&uStack_22,2,auStack_20);
    auStack_20[0] = (auStack_20[0] & 0xffff) << 2;
  }
  auStack_20[0] = auStack_20[0] + 2;
_L13:
  return auStack_20[0] & 0xffff;
}

